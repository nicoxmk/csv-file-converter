#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void read_csv(const char* csv_filename)
{
    FILE* file=fopen(csv_filename,"rt");
    char* line =NULL;
    size_t len=0;
    ssize_t read;
    char delim[]=",\n";
    if(file==NULL) EXIT_FAILURE;
    while ((read=getline(&line,&len,file))!=EOF){
        char* tok = strtok(line,delim);
        int i=0;
        while (tok!=NULL){
            if(i<2) printf("%s,",tok);
            else printf("%s\n",tok);
            tok=strtok(NULL,delim);
            i=i+1;
        }
    }
fclose(file);
EXIT_SUCCESS;

}

