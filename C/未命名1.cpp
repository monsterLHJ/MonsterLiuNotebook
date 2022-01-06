#include<stdio.h>

enum color{ red, yellow, green};
void f(enum color c);
int main(void)
{
    enum color t = red;
    scanf("%d",&t);
    f(t);
    
    return 0;
}

void f(enum color c)
{
    printf("%d\n",c);
}

/*
枚举量可以作为值
枚举类型可以跟上enum作为类型
但是实际上是以整数来做内部计算和外部输入输出的
*/
