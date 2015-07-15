/*Program Name:c-virt-inst.c                     */
/*This program installs VMs on KVM and Xen       */
/*                                               */

#include <stdio.h>
#include <sys/sysinfo.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*#define XEN 'xen'*/

void clear_kb(void);
void delete_lv(void);
void create_lv(void);
void get_vcpu(void);
void get_ram(void);
char *find_hyper(void);

int main (void){
    char ch;
    char *current_hyper;
    /* Provide machine's hardware info using sysinfo from glibc(e.g RAM and vCPUs)*/    
    puts("-------------------------------------");
    get_ram();
    get_vcpu();
    puts("-------------------------------------");    
  

    /* Display LVs and give option to delete */    
    system ("lvs");
    int num_lv;
    FILE *fp2 = popen("lvs | wc -l","r");
    fscanf(fp2, "%d", &num_lv);
    pclose(fp2);
    if (num_lv >= 2)
        delete_lv();
        
        create_lv();
    
   clear_kb();
    /* initialize the tc_ip array to a value of 0 so we can check if it's empty down when installing VMs*/
    char tc_ip[40];  
    tc_ip[0] = 0; 

    printf("\tInstall VMs? [y/n]:"); 
    ch = getchar(); 
   
    while ( ch == 'y' || ch == 'Y'){
     char vm_name[20],vm_mode[20], vm_disk[30], vm_variant[20],inst_path[34],vm_autoyast[50],vm_bridge[5];
     int vm_mem = 0, vm_vcpus=0,vm_arch=0;
     char cmdl[500];
            

      if (tc_ip[0]==0){      
         printf ("\tTC IP: ");
         scanf("%s", tc_ip);
      }
        current_hyper = find_hyper();  
         /*printf("Current Hyper:%s\n", current_hyper); */
      if (strcmp(current_hyper, "kvm")==0){
        strcpy(vm_mode,"hvm");
      }
      
      printf("\tVM Name: ");
      scanf("%s", vm_name);
            
      if (strcmp(current_hyper, "xen")==0){
         printf("\tFull or Para Virt (hvm/paravirt): ");
         scanf("%s", vm_mode);
      } 
      printf("\tVM Mem(MB): ");
      scanf("%d", &vm_mem);

      printf("\tVM vcpus: ");
      scanf("%d", &vm_vcpus);

      printf("\tVM Disk(/dev/lsys/lv1)): ");
       scanf("%s", vm_disk);

      printf("\tVM OS Variant(sles11/sles12/win2k12): ");
       scanf("%s", vm_variant);
      if (strcmp(vm_variant, "sles11")==0){
         printf("\t64 or 32 bit?: ");
         scanf("%d", &vm_arch);
         if (vm_arch == 64){
            strcpy(inst_path,"SLES-11-SP3-DVD-x86_64-GM-DVD1");
            strcpy(vm_autoyast,"SLES11_SP3-x86_64-single_disk-GRUB.xml");
            strcpy(vm_bridge, "br0");   
         
         }
         if (vm_arch == 32){
            strcpy(inst_path,"SLES-11-SP3-DVD-i586-GM-DVD1");
            strcpy(vm_autoyast,"SLES11_SP3-i586-single_disk-GRUB.xml");
            strcpy(vm_bridge,"br0");
         }
sprintf(cmdl, "virt-install --virt-type %s --%s --name %s --memory %d --vcpus=%d --disk %s --os-variant %s --network=bridge=%s --location=nfs://%s/home/InstSource/%s/ --extra-args=autoyast=nfs://%s/opt/suse/testKits/system/autoyast/%s --graphics vnc &",current_hyper, vm_mode, vm_name, vm_mem, vm_vcpus, vm_disk, vm_variant, vm_bridge, tc_ip,inst_path, tc_ip, vm_autoyast  ); 

system(cmdl);

      }else if (strcmp(vm_variant, "sles12")==0){
            strcpy(inst_path,"SLE-12-Server-DVD-x86_64-GM-DVD1");
            strcpy(vm_autoyast,"SLE_12-Server-x86_64-single_disk-GRUB.xml");
            strcpy(vm_bridge, "br0");  

sprintf(cmdl, "virt-install --virt-type %s --%s --name %s --memory %d --vcpus=%d --disk %s --os-variant %s --network=bridge=%s --location=nfs://%s/home/InstSource/%s/ --extra-args=autoyast=nfs://%s/opt/suse/testKits/system/autoyast/%s --graphics vnc &",current_hyper, vm_mode, vm_name, vm_mem, vm_vcpus, vm_disk, vm_variant, vm_bridge, tc_ip,inst_path, tc_ip, vm_autoyast  ); 

system(cmdl);    

      }else if (strcmp(vm_variant,"win2k12")==0){
            strcpy(vm_bridge, "br1");
            
sprintf(cmdl, "virt-install --virt-type %s --%s --name %s --memory %d --vcpus=%d --disk %s --os-variant %s --network=bridge=%s --cdrom=/home/win2012_x64.iso --graphics vnc &",current_hyper, vm_mode, vm_name, vm_mem, vm_vcpus, vm_disk, vm_variant, vm_bridge); 

system(cmdl);  

      }/*else if*/


  
sleep(15);    
      

      printf("Install Additional VMs? [y/n]:" );
           clear_kb();
           ch = getchar();  
    }/*while*/
printf ("Good Bye\n");
    return 0;
}/*Main */

/*find_hyper is a pointer to type char.  This has to be done to be able to return a string */
char *find_hyper(){ 
   FILE *fp, *fp2;
   char cmd1[40], cmd2[40];
   char data[512],data2[512];   
   char *loc, *loc2;
   char my_xen[]="xen";
   char my_kvm[]="kvm";
   /* static preserves the value of '*hyper' outside of the function.  */
   static char *hyper;  
   
   sprintf(cmd1,"uname -a | grep xen");
   fp = popen(cmd1,"r");
   if (!fp){
      fprintf(stderr, "Could not open pipe for output.\n");
   }
   fgets(data, 512, fp);
   /*fprintf(stdout, "%s\n",data); This is good for debug*/

/*   data[strlen(data)-1] = 0;  strip new line char */
   loc = strstr(data, my_xen);
   if (loc == NULL ){
      /* printf("No xen found in string.\n"); */
      sprintf(cmd2,"lsmod | grep kvm");
      fp2 = popen(cmd2,"r");
      if (!fp2){
      fprintf(stderr, "Could not open pipe for output.\n");
      }
      fgets(data2, 512, fp2);
      loc2 = strstr(data2,my_kvm);
         if (loc2 == NULL){
            printf("No XEN or KVM kernel found. Please install a hypervisor.\n");         
         
         }
         else{
            printf("KVM hypervisor found !\n");
            hyper ="kvm";
         } 
   /*fprintf(stdout, "%s\n",data); This is good for debug*/
   pclose(fp2);
   }/*if*/
   else{
      /*printf("%s was found at position %d.\n", my_xen, loc-data); */
      printf ("XEN hypervisor found !\n");
      hyper = "xen";
}
 
pclose(fp);
return hyper;

}/*find_hyper*/

void get_vcpu(void){
    int num_vcpu;
    FILE *fp = popen("lscpu --extended=CPU | grep ^[0-9] | wc -l","r");
    fscanf(fp, "%d", &num_vcpu);
    printf("vCPUs: %d\n", num_vcpu);
    pclose(fp);

}/*get_vcpu*/

void get_ram(void){
    struct sysinfo myinfo;
    unsigned long total_bytes;    

    sysinfo( &myinfo );
    total_bytes = myinfo.mem_unit * myinfo.totalram;
  
    printf("Memory: %lu MB\n", total_bytes/1024/1024);
}/*get_ram*/

void clear_kb(void){
    char junk[80];
    fgets(junk,80,stdin);
}/*clear_kb*/

void delete_lv(void){

        char input[20], lv_name[20], ch, cmd[100];
             
        printf("Delete any LVs? [y/n]:" );
        ch = getchar(); 
        while ( ch == 'y' || ch == 'Y'){
           clear_kb();
           printf("Name of LV to delete: " );
           fgets(input,20,stdin);
           if (sscanf(input,"%s", lv_name) != 1){
                printf("Error entering LV name");
                
            } /*if*/
           printf("  OK, LV to delete is: %s\n", lv_name);
           sprintf(cmd, "lvremove -f /dev/lsys/%s", lv_name); 
           system (cmd);
           printf("Delete additional LVs? [y/n]:" );
           /*clear_kb();*/
           ch = getchar();  
        }/*  while */    
    

    
clear_kb();
}/*delete_lv*/

void create_lv(void){
int ch; 
      
        printf("Create any LVs? [y/n]:" );
        ch = getchar();
        int lv_size, new_lv,i; 
        while ( ch == 'y' || ch == 'Y'){
            clear_kb();
            printf("Size of LVs (GB): ");
            scanf("%d",&lv_size);
            printf("Number of LVs to create: ");
            scanf("%d", &new_lv);
            for (i=1; i <= new_lv; i++){
                char cmd2[100];
                sprintf(cmd2, "lvcreate -L %dG -n lv%d lsys", lv_size, i);
                system (cmd2);
            }
        
            printf("Create additional LVs? [y/n]:" );
           clear_kb();
           ch = getchar();  
        }/*while*/



}/*create_lv*/
