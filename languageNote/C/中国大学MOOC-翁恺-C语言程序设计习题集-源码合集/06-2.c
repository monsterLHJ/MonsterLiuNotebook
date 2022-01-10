#include<stdio.h>
int main()
{
	char str[40];
	int i;
	gets(str);
	for(i=0;str[i]!='#';i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
			str[i]=str[i]+32;
		else if(str[i]>='a'&&str[i]<='z')
			str[i]=str[i]-32;
	}
	for(i=0;str[i]!='#';i++)
	{
		printf("%c",str[i]);
	}
	return 0;
}
