#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct cloud
{
    char name[20],project_name[20],os_name[20],srn[20],processor_name[20];
    int sem,ram,storage;
}CL;

void read_details(FILE *,int);
void avg_ram(FILE *,int);
void biohazard(FILE *,int);

int main()
{
    int n;
    printf("Enter number of students:\n");
    scanf("%d",&n);
    FILE *fp;
    if(n>3)
    {
        read_details(fp,n);
        avg_ram(fp,n);
        biohazard(fp,n);
    }
    else
    {
        printf("N should be greater than 3.");
    }
    return 0;
}

void read_details(FILE *fp,int n)
{
    CL c[20];
    printf("Enter student's name, SRN, project name, semester, OS, RAM, storage & processor:\n");
    fp=fopen("studentcloud.txt","w");
    for(int i=0;i<n;i++)
    {
        scanf("%s%s%s%d%s%d%d%s",c[i].name,c[i].srn,c[i].project_name,&c[i].sem,c[i].os_name,&c[i].ram,&c[i].storage,c[i].processor_name);
        fprintf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\t\t%s\n",c[i].name,c[i].srn,c[i].project_name,c[i].sem,c[i].os_name,c[i].ram,c[i].storage,c[i].processor_name);
    }
    fclose(fp);
}

void avg_ram(FILE *fp,int n)
{
    int i;
    CL c[20];
    fp=fopen("studentcloud.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s\t\t%s\t\t%s\t\t%d\t\t%s\t\t%d\t\t%d\t\t%s\n",c[i].name,c[i].srn,c[i].project_name,&c[i].sem,c[i].os_name,&c[i].ram,&c[i].storage,c[i].processor_name);
        i++;
    }
    float sum=0.0,avg;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(strcmp(c[i].os_name,"Windows10")==0)
        {
            sum=sum+c[i].ram;
            count++;
        }
        avg=sum/count;
    }
    printf("Average RAM allocated for Windows10 Virtual machines:\n%0.2f gigabytes.",avg);
    printf("\n\n");
    fclose(fp);
}

void biohazard(FILE *fp,int n)
{
    CL c[20];
    int i;
    fp=fopen("studentcloud.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%s\t%s\t%s\t%d\t%s\t%d\t%d\t%s\n",c[i].name,c[i].srn,c[i].project_name,&c[i].sem,c[i].os_name,&c[i].ram,&c[i].storage,c[i].processor_name);
        i++;
    }
    printf("Student Details working on Biohazard project:\n");
    for(int i=0;i<n;i++)
    {
        if(strcmp(c[i].project_name,"Biohazard")==0)
        {
            printf("%s %s %s %d\n",c[i].name,c[i].srn,c[i].project_name,c[i].sem);
        }
    }
    fclose(fp);
}
