#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    char word[50];
    FILE *fptr1;
    FILE *fptr2;
    if((fptr1=fopen(argv[1],"r"))==NULL){
        printf("Can't open file.");
        return -1;
    }
    if((fptr2=fopen("temp.txt","w"))==NULL){
        printf("Can't open file.");
        return -1;
    }
    while(feof(fptr1)==0){
        fscanf(fptr1, "%s", &word);
        if(strlen(word)>=5 && strlen(word)<=8){
            fprintf(fptr2, "%s\n", &word);
            
        }
    }
    fclose(fptr1);
    remove(argv[1]);
    fclose(fptr2);
    rename("temp.txt", argv[1]);



    return 0;
}