#include<stdio.h>
void alpha(char str[]);
void main()
{
char s[150];
int i, j;
printf("ENTER A STRING : \n");
gets(s);
alpha(s);
printf("RESULTANT STRING : \n");
puts(s);
}
void alpha(char str[150])
{
    int i,j;
    for(i=0;str[i]!='\0';++i)
        {
            while(!((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z')||str[i]=='\0'))
            {
                for(j=i;str[j]!='\0';++j)
                    {
                        str[j]=str[j+1];
                    }
                str[j]='\0';
            }
        }

}
