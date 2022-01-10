#include<stdio.h>
int main()
{
	char str[80];
	int i,j,Last=1;
	gets(str); 
	for(i = 80;i>0;i--)
	{
		if(str[i]==' '&&Last)
		{
			for(j=i+1;str[j]!='\0';j++)
			{
		     printf("%c",str[j]);
			}
			Last=0;
			printf(" ");
		}
		else if(str[i]==' '&&!Last)
		{
			for(j=i+1;str[j]!=' ';j++)
			{
		     printf("%c",str[j]);
			}
			printf(" ");
		}
	}
	for(j=0;str[j]!=' '&&str[j]!='\0';j++)  //输出第一个字母
			 printf("%c",str[j]);       
	return 0;
}
