//素数plus
#include<stdio.h>
int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes);
int main(void)
{
    const int number = 100;
    int prime[100] = {2};  //初始化,编译会出错https://bbs.csdn.net/topics/390277028
    int count = 1;
    int i = 3;
    while( count < number ){
        if( isPrime(i, prime, count) ){
            prime[count++] = i; //注意count++
        }
        //调试
        {
            printf("i=%d \tcnt=%d\t",i,count);
            int i;
            for( i=0; i<number; i++){
                printf("%d\t",prime[i]);
            }
            printf("\n");
        }
        i++;
    }
    for( i=0; i<number; i++ ){		//格式控制
        printf("%d",prime[i]);
        if( (i+1)%5 ) printf("\t");
        else printf("\n");
    }
    return 0;
}

int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes)
{
    int ret = 1;
    int i;
    for( i=0; i<numberOfKnownPrimes; i++ ){
        if( x % knownPrimes[i] == 0){
            ret = 0;
            break;
        }
    }
    return ret;
}
