#include<stdio.h>
#include<math.h>
typedef struct two_D
{
    int x,y;
}D;
D read(D p1);
void display(D p1,D p2);
void displayqu(D p1);
void main()
{
    D p1,p2;
    p1=read(p1);
    p2=read(p2);
    displayqu(p1);
    displayqu(p2);
    display(p1,p2);
}
D read(D p1)
{
    printf("Enter the x and y respectively ");
    scanf("%d %d",&p1.x,&p1.y);
    return p1;
}
void displayqu(D p1)
{
    printf("%d %d\n",p1.x,p1.y);
    if(p1.x>0&&p1.y>0)
        printf("Point lie in 1st quadrant\n");
    else if(p1.x>0&&p1.y<0)
        printf("Point lie in 4th quadrant\n");
    else if(p1.x<0&&p1.y>0)
        printf("Point lie in 2nd quadrant\n");
    else if(p1.x<0&&p1.y<0)
        printf("Point lie in 3rd quadrant\n");
}
void display(D p1,D p2)
{
    float d,m,a,b;
    d=sqrt((pow((p2.x-p1.x),2))+pow((p2.y-p1.y),2));
    a=(p2.y-p1.y);
    b=(p2.x-p1.x);
    m=a/b;
    printf("Distance between two points %f\nSlope between two points %f",d,m);
}
