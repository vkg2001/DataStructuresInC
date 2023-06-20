#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char text[100],pattern[100];

int brute()
{
    int i,j,m,n;
    n=strlen(text);
    m=strlen(pattern);
    for(i=0;i<n;i++)
    {   j=0;
        while(j<m && text[i+j]==pattern[j])
        {
            j++;
            if(j==m)
                return i+1;
        }
    }
    return 0;
}

int main()
{   int found;
    printf("Enter text:\n");
    scanf("%s",text);
    printf("\nEnter pattern to search:\n");
    scanf("%s",pattern);
    found=brute();
    if(found>0)
        printf("\nPattern found at %d position",found);
    else
        printf("\nPattern not found");
    return 0;
}
