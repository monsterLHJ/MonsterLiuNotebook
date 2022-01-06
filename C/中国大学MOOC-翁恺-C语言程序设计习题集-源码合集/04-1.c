#include<stdio.h>
int result(int shu,int mici)
{
	int i;
	for(i=1;mici>0;mici--)
		i=i*shu;
	return i;
}

void sxh(int N,int num)
{    
	int s,new_num;
	int mici=N;
	int sxh=0;
	new_num=num;
	for(;N>0;N--)
	{
		s=new_num/result(10,N-1);
		sxh=sxh+result(s,mici);
		new_num=new_num-s*result(10,N-1);
	}
	if (sxh==num)
		printf("%d\n",num);
}

int main()
{
	int N,i;
	scanf("%d",&N);
	for(i=result(10,N-1);i<result(10,N);i++)
		sxh(N,i);
	return 0;
}
