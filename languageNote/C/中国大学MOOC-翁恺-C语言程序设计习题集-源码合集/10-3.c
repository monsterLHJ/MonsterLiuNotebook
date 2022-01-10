#include<stdio.h>
#include<string.h>
int main()
{
	char str[6];
	int i;
	gets(str); 
	for( i = (int)strlen(str)-1;i>=0;i--)
	{
		printf("%c",str[i]);
	}
	return 0;
}
