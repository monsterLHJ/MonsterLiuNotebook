#include<stdio.h>
int  n_wei(int num)
{
	int count=1,i,temp;
	for(i=1;;i++)
	{
		temp=num/10;
		if (temp!=0)
		{
			count++;
			num=temp;
		}
		else
			break;
	}
	return count;
}
int result(int shu,int mici)
{
	int i;
	for(i=1;mici>0;mici--)
		i=i*shu;
	return i;
}

void nianshuzi(int n_wei,int num)
{
	int temp,i,count=0;
	int weishu=n_wei;
	for(i=1;n_wei>0;i++,n_wei--)
	{
	    temp=num/result(10,n_wei-1);
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
		count++;
		if (count<weishu)
			printf(" ");
		num=num-temp*result(10,n_wei-1);
		
	}
}

int main(){
	int n,count=0,weishu;
	scanf("%d",&n);
	if (n==0)
		{
			printf("ling");
		}
	else if(n<0)
	{
		printf("fu ");
		weishu=n_wei(-n);
		nianshuzi(weishu,-n);
	}
	else
	{
		weishu=n_wei(n);
		nianshuzi(weishu,n);
	}
	return 0;
}

