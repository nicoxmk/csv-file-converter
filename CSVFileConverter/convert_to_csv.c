#include<stdio.h>
#include<stdlib.h>
#include"convert_to_csv.h"
#include<string.h>

void load_and_convert(const char* filename){
		
	FILE* f1=fopen(filename,"rt");
	FILE* f2=fopen("output.csv","wt");
	char name[1000],age[1000],place[1000];
        char* arr1[1000], *arr2[1000], *arr3[1000];
	fgets(name,999,f1);
	fgets(age,999,f1);
	fgets(place,999,f1);

        char delim[]=" \n";
        int i=0,j=0,k=0;
	//cut the whole string into substrings and store them in new string arrays
        char* ptr1=strtok(name,delim);
        while(ptr1!=NULL){
  		arr1[i]=ptr1;
                ptr1=strtok(NULL,delim);
                i++;

        }
	char* ptr2=strtok(age,delim);
        while(ptr2!=NULL){
                arr2[j]=ptr2;
                ptr2=strtok(NULL,delim);
                j++;

        }
	char* ptr3=strtok(place,delim);
        while(ptr3!=NULL){
                arr3[k]=ptr3;
                ptr3=strtok(NULL,delim);
                k++;

        }
      

	//formatted elements and write into the csv.file
    	int h=0;
        while(arr1[h]!=NULL){
                fprintf(f2, "%s, %s, %s\n",arr1[h],arr2[h],arr3[h]);
		h++;
        }
        fclose(f1);
        fclose(f2);

}
