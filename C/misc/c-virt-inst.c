/*Program Name:c-virt-inst.c                     */
/*This program installs VMs on KVM and Xen       */
/*                                               */

#include <stdio.h>
#include <sys/sysinfo.h>
#include <stdlib.h>
#include <string.h>

void clear_kb(void);

int main (void){
    struct sysinfo myinfo;
    unsigned long total_bytes;
    int num_vcpu,num_lv;

    sysinfo( &myinfo );
    total_bytes = myinfo.mem_unit * myinfo.totalram;

    puts("-------------------------------------");    
    printf("Memory: %lu MB\n", total_bytes/1024/1024);
    
    FILE *fp = popen("lscpu --extended=CPU | grep ^[0-9] | wc -l","r");
    fscanf(fp, "%d", &num_vcpu);
    printf("vCPUs: %d\n", num_vcpu);
    pclose(fp);

    puts("-------------------------------------");

    system ("lvs");

    FILE *fp2 = popen("lvs | wc -l","r");
    fscanf(fp2, "%d", &num_lv);
    pclose(fp2);
    if (num_lv >= 2){
        int ch;    
             
        printf("Delete any LVs? [y/n]:" );
        ch = getchar(); 
        while ( ch == 'y' || ch == 'Y'){
           puts("Inside while loop");

           printf("Delete additional LVs? [y/n]:" );
           clear_kb();
           ch = getchar();  
        }    
/*
char input[]="y";
        do{
            puts("Delete any LVs? [y/n]:" );
            fgets(input,10,stdin); 
            puts("INSIDE DO");           
        }        
        while(strcmp(input,"y")== 0);

*/      /*while*/
    }/*if*/




    return 0;
}

void clear_kb(void){
    char junk[80];
    fgets(junk,80,stdin);
}
