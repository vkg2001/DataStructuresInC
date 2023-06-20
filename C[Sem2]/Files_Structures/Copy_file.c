#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fptr1, *fptr2;
    char filename[100], i;
    printf("ENTER THE FILE NAME TO BE OPENED FOR READING:\n");
    scanf("%s", filename);
    fptr1=fopen(filename,"r");
    if(fptr1==NULL)
    {
        printf("CANNORT OPEN FILE %s.\n", filename);
        exit (0);
    }
    printf("ENTER THE FILE NAME TO BE OPENED FOR WRITING:\n");
    scanf("%s", filename);
    fptr2=fopen(filename,"w");
    if(fptr2==NULL)
    {
        printf("CANNOT OPEN FILE %s.\n", filename);
        exit (0);
    }
    fscanf(fptr1,"%c",&i);
    while(i!=EOF)
    {
        fprintf(fptr2,"%c",i);
        i=fscanf(fptr1,"%c",&i);
    }
    printf("CONTENTS COPIED TO %s", filename);
    fclose(fptr1);
    fclose(fptr2);
}
