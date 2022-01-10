#include<stdio.h>
#include<string.h>
int main()
{
	char str1[6],str2[6];
	char temp;
	int nstr2,i,j;
	gets(str1);
	gets(str2);
	for(;;)
	{
       char *p=strstr(str1,str2);
	   nstr2=(int)strlen(str2);
	   if(p)
	   {
		   int left=strlen(p)-nstr2;
		   for(i=0;i<left;i++)
			   p[i]=p[i+nstr2];
		   str1[strlen(str1)-nstr2]='\0';
	   }
	   else
	   {
			printf("%s",str1);
			break;
	   }
	}
	return 0;
}

