#include<stdio.h>
#include<math.h>
void main()
{
    int x1,x2,y1,y2;
    float dist;
    printf("Enter coordinates of 2 points(x1,y1),(x2,y2):");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    dist=sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));
    printf("Distance between points:%f", dist);
}
