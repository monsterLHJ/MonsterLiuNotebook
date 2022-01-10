#include<stdio.h>
int main()
{
	char str1[100],str2[10];
	int i,sum=0,temp;
	gets(str1);
	for(i=0;str1[i]!='\0';i++)
	{
	  temp=str1[i]-48;
	  sum=sum+temp;
	 }
	sprintf(str2,"%d",sum);
	for(i=0;str2[i]!='\0';i++)
	{
		temp=str2[i]-48;
		 switch (temp)
	    {
				case 0:
					printf("ling");
					break;
				case 1:
					printf("yi");
					break;
				case 2:
					printf("er");
					break;
				case 3:
					printf("san");
					break;
				case 4:
					printf("si");
					break;
				case 5:
					printf("wu");
					break;
				case 6:
					printf("liu");
					break;
				case 7:
					printf("qi");
					break;
				case 8:
					printf("ba");
					break;
				case 9:
					printf("jiu");
					break;
			}
		 if (str2[i+1]!='\0')
			printf(" ");
	}
	return 0;
}

