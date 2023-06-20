#include<stdio.h>
int main()
{
    int a1,a2,a3,a4,a5,cakea,cakeb;
    cakea=0;
    cakeb=0;
    printf("Enter the Outcomes:");
    scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5);
    if(a1==1)
        cakea=cakea++;
    else
        cakeb=cakeb++;
    if(a2==1)
        cakea=cakea++;
    else
        cakeb=cakeb++;
    if(a3==1)
        cakea=cakea++;
    else
        cakeb=cakeb++;
    if(a4==1)
        cakea=cakea++;
    else
        cakeb=cakeb++;
    if(a5==1)
        cakea=cakea++;
    else
        cakeb=cakeb++;
    {if(cakea>cakeb)
        printf("A will get Cake");
    else
        printf("B will get Cake");
}}
