/* Read a text file, decode it, store it in a data structure and print
the results using standard library
*/
#include <cstdio>
const int maxstring = 1024;

int main(){
    const char * file_name = "items.txt";
    puts("reading the file");
    char buf[maxstring];

    FILE * file_read = fopen(file_name, "r");
    while(fgets(buf, maxstring, file_read)) {
        //fputs(buf, stdout);
        //printf("this: %d desc:%s", 2,buf);
        //fprintf(stdout, "1- %s", buf);
    }

    fclose(file_read);
    remove(file_name);

    puts("done");
    
    return 0;
}