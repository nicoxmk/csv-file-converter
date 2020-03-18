#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"convert_to_csv.h"
#include"read_csv.h"


//Q3_1 find element in the file
void find_name(const char* csv_filename,const char* name){
        FILE* file=fopen(csv_filename,"rt");
        if(file==NULL)exit(1);
        int i=0;
        char line[1000];
        fgets(line,999,file);

        while(!feof(file)){
                int j=0;
                int i=0;
                while(line[i]!=','){
                        if(line[i]!=name[i]){
                                j++;
                        }
                        i++;
                }
                if(j==0){
                        printf("%s",line);
                        i++;
                }
                fgets(line,999,file);
        }
        if(i==0){
                printf("Name not found\n");
        }

        fclose(file);
}


//Q3_2 add new record at the end
void add_record(const char* csv_filename, const char* name, const int age, const char* city){
    FILE* file=fopen(csv_filename,"at");
    if(file==NULL) EXIT_FAILURE;

    char* str=(char*)malloc(1000*sizeof(char));
    //store in str
    sprintf(str,"%s, %d, %s\n", name, age, city);
    fputs(str,file);

    fclose(file);
}

//helper
int target(const char* info, const char* name){
    int contain = 0;
    int i = 0;
    for (; info[i] != ','; i++){
        if (name[i] != info[i]){
        break;
    }
 }
    if (info[i] == ','){
    contain = 1;
 }
    return contain;
}

void delete_record(const char* csv_filename, const char* name){
    int len = 1000;
    FILE* outFile;
    if ((outFile = fopen(csv_filename, "r")) == NULL) EXIT_FAILURE;

    FILE* intFile = fopen("tmp.csv", "w");
    char* buffer = (char*)malloc(len*sizeof(char));
    while (fgets(buffer,len,outFile) != NULL){
        if (target(buffer, name) == 1){
        break;
  }
    fputs(buffer, intFile);
 }
    while (fgets(buffer,len,outFile) != NULL){
        fputs(buffer, intFile);
 }
    fclose(outFile);
    fclose(intFile);
    remove(csv_filename);
    rename("tmp.csv", csv_filename);
    free(buffer);
    return;
}

int main(void)
{
//Q1
load_and_convert("input.txt");

//Q2
read_csv("output.csv");
printf("\n");

//Q3_1
find_name("output.csv", "Maria");
find_name("output.csv", "Jason");
printf("\n");

//Q3_2
add_record("output.csv","Jason",36,"Skookumchuk");
read_csv("output.csv");
printf("\n");

//Q3_3
delete_record("output.csv","Maria");
read_csv("output.csv");
return 0;
}

