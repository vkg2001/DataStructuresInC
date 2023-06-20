#include<stdio.h>
typedef struct cell_phone
{
    char name[20];
    float price;
    float screen_size;
    int battery;
    int camera_pixel;
    int memory;
}CP;
void display(char n[20], float price, int memory);
int main()
{
    CP c1={"OnePlus",29999.99,6.5,5000,32,32};
    display(c1.name,c1.price,c1.memory);
    return 0;
}
void display(char n[20], float price, int memory)
{
    printf("Name\tPrice\t\tMemory\n");
    printf("%s\t%.2f\t%d",n,price,memory);
}
