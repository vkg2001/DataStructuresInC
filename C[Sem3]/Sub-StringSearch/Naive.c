#include<stdio.h>
#include<string.h>

void search(char *pat,char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	for (int i=0;i<=N-M ;i++)
	{
		int j;
		for (j=0;j<M ; j++)
		{
			if(txt[i+j] !=pat[j])
				break;
		}
		if(j==M)
			printf("Pattern found at index %d \n",i);
	}
}

int main()
{
    char txt[100],pat[100];
    printf("\n ENTER THE TEXT    : ");
    gets(txt);
    printf("\n ENTER THE PATTERN : ");
    gets(pat);

	search(pat,txt);

	return 0;
}
