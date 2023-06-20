#include<stdio.h>
void main()
{
    int marks;
    printf("Enter Marks:");
    scanf("%d",&marks);
    switch(marks)
    {
        case 0 ... 39: printf("Fail");
                        break;
        case 40 ... 59: printf("Pass");
                        break;
        case 60 ... 79: printf("1st Class");
                        break;
        case 80 ... 100: printf("Distinction");
                        break;
        default: printf("Invalid Marks");
    }
}
