#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int N,i;
	gets(str); 
	scanf("%d",&N);
	N=N%strlen(str);         //����Ҫע�⣡
	for( i=N;str[i]!='\0';i++)
	{
		printf("%c",str[i]);
	}
	for(i=0;i<N;i++)
	{
		printf("%c",str[i]);
	}
	return 0;
}

