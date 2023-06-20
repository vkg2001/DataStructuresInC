#include <stdio.h>
typedef struct complex
{
    float real;
    float imaginary;
}cx;
cx add(cx m,cx n);
void print(cx);
cx read(cx);
int main()
{
    cx m,n;
    printf("Enter real and imaginary parts for 1st number: \n");
    m=read(m);
    printf("Enter the real and imaginary parts for 2nd number: \n");
    n=read(n);
    cx sum=add(m,n);
    print(sum);
    return 0;
}
cx read(cx a)
{
    cx sum;
    printf("Enter real part for number: ");
    scanf("%f",&a.real);
    printf("Enter imaginary part for number: ");
    scanf("%f",&a.imaginary);
    return a;
}
void print(cx a)
{
    if(a.imaginary<0)
        {
            printf("Sum= %.2f %.2fi",a.real,a.imaginary);
        }
        else if(a.imaginary>=0)
        {
            printf("Sum= %.2f +%.2fi",a.real,a.imaginary);
        }
}
cx add(cx m,cx n)
{
    cx ans;
    ans.real=m.real+n.real;
    ans.imaginary=m.imaginary+n.imaginary;
    return(ans);
}
