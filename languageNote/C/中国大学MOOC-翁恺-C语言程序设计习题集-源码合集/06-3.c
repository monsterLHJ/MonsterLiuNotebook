#include<stdio.h>
int main()
{
	char c=' ';
	int flag=0,count=0;
	for(;c!='.';)
	{
	  scanf("%c",&c);
	  if(c!=' '&&c!='.')
		  count++;
	  else
	  {
		  if(count)
		  {
			  if(flag)
				printf(" ");
			  printf("%d",count);
			  count=0;
			  flag=1;
		  }
	  }
	}
	return 0;
}