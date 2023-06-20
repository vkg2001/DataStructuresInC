#include<stdio.h>
#include<stdlib.h>

void TOH(int n,char from,char to, char temp){
    if(n==1){
        printf("Move disc 1 from %c to %c.\n",from,to);
        return;
    }
    TOH(n-1,from,temp,to);
    printf("Move disc %d from %c to %c.\n",n,from,to);
    TOH(n-1,temp,to,from);
}

int main(){
    int n;
    scanf("%d",&n);
    TOH(n,'A','B','X');
    return 0;
}

