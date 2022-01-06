#include<stdio.h>
#include<string.h>
int main()
{
	char str[80],c;
	int i,j,flag=0;
	gets(str); 
	scanf("%c",&c);
	for(i=0;str[i]!='\0';i++)
	{
		if(str[i]==c)
		{
			for(j=i;str[j]!='\0';j++)
			{
				printf("%c",str[j]);
				flag=1;
			}
			break;
		}
	}
	if(!flag)
			printf("Not found");
	return 0;
}
