#include<stdio.h>
typedef struct person{
	char name[11];
	char birth[11];
	char sex[2];
	char tel[17];
	char mobile[17];
}person;

int main(){
	int npeople=0;
	int K,index,i;
	int flag=0;
	person per[10];
	scanf("%d",&npeople);
    for(i=0;i<npeople;i++)
	{
		scanf("%s%s%s%s%s",&per[i].name,&per[i].birth,&per[i].sex,
			&per[i].tel,&per[i].mobile);
	 }
	scanf("%d",&K);
	for(i=0;i<K;i++)
	{
		scanf("%d",&index);
		if(index>(npeople-1)||index<0)
		   printf("Not Found\n");
		else
		  printf("%s %s %s %s %s\n",per[index].name,per[index].tel,
		  per[index].mobile,per[index].sex,per[index].birth);
	}
    return 0;
}