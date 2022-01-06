[TOC]

# 第一周：程序设计与C语言

## 1.1 计算机和编程语言

**程序的执行**

解释：借助一个程序，那个程序能试图理解你的程序，然后按照你的要求执行。

编译：借助一个程序，就像一个翻译，把你的程序翻译成计算机真正能懂的语言——机器语言——写的程序，然后，这个机器语言写的程序就能直接执行了。

## 1.3 第一个C程序

```c
#include<stdio.h>

int main()
{
    printf("Hello World\n")
    return 0;
}
```

# 第二周：计算

## 2.1 变量

**变量定义**的一般形式：

<类型名称><变量名称>;

变量需要一个名字，变量的名字是一种“标识符”，意思是它用来识别这个和那个的不同的名字。标识符有标识符的构造规则。基本的原则是：==**标识符只能由字母、数字和下划线组成，数字不可以出现在第一个位置上，C语言的关键字（有的地方叫它们保留字）不可以用做标识符。**==

**变量类型：**

C是一种有类型的语言，所有的变量在使用之前必须定义或声明，所有的变量必须具有确定的数据类型。数据类型表示在变量中可以存放什么样的数据，变量中只能存放指定类型，程序运行过程中也不能改变变量的类型。

**定义一个常量变量：**

```c
const int Amount = 100;
```

**浮点数**

当浮点数和整数放到一起运算时，C会将整数转换成浮点数，然后进行浮点数的运算。

```c
(foot + inch / 12.0) * 0.3048
```

## 2.2 表达式

| 优先级 | 运算符 |   运算   | 结合关系 |  举例  |
| :----: | :----: | :------: | :------: | :----: |
|   1    |   +    | 单目不变 | 自右向左 | a * +b |
|   1    |   -    | 单目取负 | 自右向左 | a * -b |
|   2    |   *    |    乘    | 自左向右 | a * b  |
|   2    |   /    |    除    | 自左向右 | a / b  |
|   2    |   %    |   取余   | 自左向右 | a % b  |
|   3    |   +    |    加    | 自左向右 | a + b  |
|   3    |   -    |    减    | 自左向右 | a - b  |
|   4    |   =    |   赋值   | 自右向左 | a = b  |

| 表达式  |    运算    |   表达式的值    |
| :-----: | :--------: | :-------------: |
| count++ | 给count加1 |  count原来的值  |
| ++count | 给count加1 | count+1以后的值 |
| count-- | 给count减1 |  count原来的值  |
| --count | 给count减1 | count-1以后的值 |

# 第三周：判断

## 3.1 判断

关系运算符的优先级：

比算术运算符低，但比赋值运算符高。判断是否相等的==和！=的优先级比其他的低，而连续的关系运算是从左到右进行的。

**==if语句==**

```c
if(total > count){
	total += amount + 10;
}
```

if语句这一行结束的时候并没有表示语句结束的“；”,而后面的赋值语句写在if的下一行，并且缩进了，在这一行结束的时候有一个表示语句结束的“；”。这表明这条赋值语句是if语句的一部分，if语句拥有和控制这条赋值语句，决定它是否要被执行。

==嵌套的判断：==当if的条件满足或者不满足的时候要执行的语句也可以是一条if或if-else语句，这就是嵌套的if语句。

==else的匹配：==else总是和最近的那个if匹配

==tips:== 在if或else后面总是用{}，即使只有一条语句的时候。

常见错误：

1. 忘了大括号
2. if后面的括号
3. 错误使用==和=（if只要求(）里的值是零或非零）
4. 使人困惑的else

建议：

1. 在if和else之后必须加上大括号形成语句块；
2. 大括号内的语句缩进一个tab的位置

```c
//计算时间差
#include <stdio.h>

int main()
{
	int hour1, minute1;
	int hour2, minute2;

	scanf("%d %d", &hour1, &minute1);
	scanf("%d %d", &hour2, &minute2);

	int ih = hour2 - hour1;
	int im = minute2 - minute1;
	if ( im <0 ) {
		im = 60 + im;
		ih --;
	}
	
	printf("时间差是%d小时%d分。\n", ih, im);
	
	return 0;
}

//判断三个数的最大值

//	max3.c
#include <stdio.h>

int main()
{
	int a,b,c;
	scanf("%d %d %d", &a, &b, &c);

	int max = 0;

	if ( a>b ) {
		if ( a>c ) {
			max = a;
		} else {
			max = c;
		}
	} else {
		if ( b>c ) {
			max = b;
		} else {
			max = c;
		}
	}

	printf("The max is %d\n", max);

	return 0;
}


//else if
#include <stdio.h>

int main()
{
	int x;

	scanf("%d", &x);

	int f=0;
	if ( x < 0 ) {
		f = -1;
	} else if ( x == 0 ) {
		f = 0;
	} else if ( x >5 ) {
		f = 2 * x;
	} else {
		f = 3*x;
	}

	printf("%d\n", f);

	return 0;
}
```

## 3.2 分支

==**级联的if-else if**==

```c
if(x < 0){
	f = -1;
}else if(x == 0){
	f = 0;
}esle{
	f = 2 * x;
}
```

==**多路分支switch-case**==

```C
switch(控制表达式){
    case 常量:
        语句
        ......
    case 常量:
    	语句
        ......
    default:
		语句
        ......
}
```



- 控制表达式只能是整数型的结果
- 常量可以是常数，也可以是常数计算的表达式
- 根据表达式的结果，寻找匹配的case，并执行case后面的语句，一直到break为止
- 如果所有的case都不匹配，那么就执行default后面的语句；如果没有default，那么就什么都不做
- switch语句可以看作是一种基于计算的跳转，计算控制表达式的值后，程序会跳转到相匹配的case（分支标号）处。分支标号只是说明switch内部位置的路标，在执行完分支中的最后一条语句后，如果后面没有break，就会顺序执行到下面的case里去，直到遇到一个break，或者switch结束为止。

```c
#include <stdio.h>

int main()
{
	printf("输入成绩（0-100）");
	int grade;
	scanf("%d", &grade);
	grade /=10;
	switch ( grade ) {
	case 10:
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 6:
		printf("D\n");
		break;
	default:
		printf("F\n");
		break;
	}

	return 0;
}#include <stdio.h>

int main()
{
	printf("请输入月份：");
	int month;
	scanf("%d", &month);
	switch ( month )
	{
		case 1: printf("January\n"); break;
		case 2: printf("February\n"); break;
		case 3: printf("March\n"); break;
		case 4: printf("April\n"); break;
		case 5: printf("May\n"); break;
		case 6: printf("June\n"); break;
		case 7: printf("July\n"); break;
		case 8: printf("August\n"); break;
		case 9: printf("September\n"); break;
		case 10:printf("October\n"); break;
		case 11:printf("November\n"); break;
		case 12:printf("December\n"); break;
	}

	return 0;
}



#include <stdio.h>

int main()
{
	printf("请输入月份：");
	int month;
	scanf("%d", &month);
	switch ( month )
	{
		case 1: printf("January\n"); break;
		case 2: printf("February\n"); break;
		case 3: printf("March\n"); break;
		case 4: printf("April\n"); break;
		case 5: printf("May\n"); break;
		case 6: printf("June\n"); break;
		case 7: printf("July\n"); break;
		case 8: printf("August\n"); break;
		case 9: printf("September\n"); break;
		case 10:printf("October\n"); break;
		case 11:printf("November\n"); break;
		case 12:printf("December\n"); break;
	}

	return 0;
}
```

# 第四周：循环

## 4.1 循环

验证：测试程序常使用边界数据，如有效范围两端的数据、特殊的倍数等，个位数、10、0、负数。

==**do while 和while 的区别：**==

do-while循环和while循环很像，区别是在循环体执行结束的时候才来判断条件。也就是说，无论如何，循环都会执行至少一遍，然后再来判断条件。与while循环相同的是，条件满足时执行循环，条件不满足时结束循环。

## 4.2 循环的应用

**==整数的分解：==**

- 一个整数是由1至多位数字组成的，如何分解出整数的各个位的数字，然后加义计算
- 对一个整数做%10的操作，就得到它的个位数；
- 对一个整数做/10的操作，就去掉了它的个位数；
- 然后再对2的结果做%10，就得到原来数的十位数了；
- 依此类推。

```c
//求平均数

#include <stdio.h>

int main()
{
	int sum = 0;
	int count = 0;
	int number;

	scanf("%d", &number);
	while ( number != -1 ) {
		sum += number;
		count ++;              //计数器
		scanf("%d", &number);
	}

	double dsum = sum;
	printf("The average is %f.\n", dsum / count);

	return 0;
}

//猜数字游戏

#include <stdio.h>

int main()
{
	int number = rand()%100+1;
	int count = 0;
	int a = 0;
	printf("我已经想好了一个1到100之间的数。");
	do {
		printf("请猜这个1到100之间数：");
		scanf("%d", &a);
		if ( a > number ) {
			printf("你猜的数大了。");
		} else if ( a < number ) {
			printf("你猜的数小了。");
		}
		count ++;
	} while (a != number);
	printf("太好了，你用了%d次就猜到了答案。\n", count);

	return 0;
}

//整数逆序
#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	int digit;
	int ret = 0;

	while ( x> 0 ) {
		digit = x%10;
		printf("%d", digit);
		ret = ret*10 + digit;
		// printf("x=%d,digit=%d,ret=%d\n", x, digit, ret);
		x /= 10;
	}
	// printf("%d", ret);
	
	return 0;
}
```

## 习题解析

```c
/*4-0 求符合给定条件的整数集
给定不超过6的正整数A，考虑从A开始的连续4个数字。请输出所有由它们组成的无重复数字的3位数。
输入格式：
输入在一行中给出A。
输出格式：
输出满足条件的的3位数，要求从小到大，每行6个整数。整数间以空格分隔，但行末不能有多余空格。*/
#include<stdio.h>
int main()
{
    int a;
    scanf("%d",&a);
    int i,j,k;
    int cnt = 0;
    i = a;
    while( i<=a+3 ){
        j = a;
        while( j<=a+3 ){
            k = a;
            while( k<=a+3 ){
                if(i!=j && i!=k && j!=k ){
					cnt++;
                	printf("%d%d%d",i,j,k);
                	if( cnt==6 ){
                        printf("\n");
                        cnt = 0;
                    }else{
                        printf(" ");
                    }
                }
                k++;
            }
            j++;
        }
        i++;
    }
    return 0;
}

/*水仙花数是指一个N位正整数（N>=3），它的每个位上的数字的N次幂之和等于它本身。例如：153 = 13 + 53+ 33。本题要求编写程序,计算所有N位水仙花数。*/
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int first = 1;
    int i = 1;
    while( i<n ){
        first *= 10;
        i++;
    }
    printf("first=%d\n",first);
    //若n为3，则需遍历100-999
    i = first;
    while( i<first*10 ){
        int t = i;
        int sum = 0;
        do{
            int d = t%10;
            t/=10;
            int p = 1;
            int j = 0;
            while( j<n ){
                p *= d;
                j++;
            }
            sum += p;
        }while( t>0 );
        if(sum == i){
            printf("%d",i);
        }
    }
    return 0;
}

//九九乘法表
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    n = 9;
    int i,j;
    i = 1;
    while( i<=n ){
        j = 1;
        while( j<=i ){
			printf("%d*%d=%d",j,i,i*j);
            if( i*j<10 ){
                printf("   ");
            }else{
                printf("  ");
            }
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}
//本题要求统计给定整数M和N区间内素数的个数并对它们求和。
#include<stdio.h>
int main()
{
    int m,n;
    int i;
    int cnt = 0;
    int sum = 0;
    
    scanf("%d %d",&m,&n);
    if( m==1 )
        m = 2;
    for( i=m; i<=n; i++){
		int isPrime = 1;
        int k;
     	for( k = 2; k<i-1; k++){
            if( i%k == 0){
                isPrime = 0;
                break;
            }
        }
        //判断是否素数
        if(isPrime){
            cnt++;
            sum += i;
        }
    }
    printf("%d %d\n",cnt,sum);
    return 0;
}
//猜数字游戏
/*猜数字游戏是令系统随机产生一个100以内的正整数，用户输入一个数对其进行猜测，需要你编写程序自动对其与随机产生的被猜数进行比较，并提示大了（“Too big”），还是小了（“Too small”），相等表示猜到了。如果猜到，则结束程序。程序还要求统计猜的次数，如果1次猜出该数，提示“Bingo!”；如果3次以内猜到该数，则提示“Lucky You!”；如果超过3次但是在N（>3）次以内（包括第N次）猜到该数，则提示“Good Guess!”；如果超过N次都没有猜到，则提示“Game Over”，并结束程序。如果在到达N次之前，用户输入了一个负数，也输出“Game
Over”，并结束程序。*/
#include<stdio.h>
int main()
{
    int number,n;
    int inp;
    int finished = 0;
    int cnt = 0;
    scanf("%d %d",&number,&n);
    do{
        scanf("%d",&inp);
        cnt++;
        if(inp<0){
            printf("Game Over\n");
            finisher = 1;
        }else if(inp > number){
            printf("Too big\n");
        }else if(inp < number){
            printf("Too small\n");
        }else{
            if(cnt == 1){
                printf("Bingo!\n");
            }else if(cnt <= 3){
                printf("Lucky You!\n");
            }else{
                printf("Good Guess!\n");
            }
            finished = 1;
        }
		if(cnt == n){
            if(!finished){
                printf("Game Over\n");
                finished = 1;
            }
        }        
    }while(!finished);
    return 0;
}
```



# 第五周：循环控制

## 5.1 第三种循环

==**for循环**==

for循环像一个计数循环：设定一个计数器，初始化它，然后在计数器到达某值之前，重复执行循环体，而每执行一轮循环，计数器以一定步进进行调整，比如加1或者减1。

```c
for(count = 10;count > 0;count--)
```

就读成：“对于一开始的count = 10，当count > 0时，重复做循环体，每一轮循环在做完循环体内语句后，使得count--。”

```c
for(int i = 1;i <= n; i++){
	fact *= i;
}

int i = 1;
while(i<=n){
	fact *= i;
	i++;
}
//以上两个循环等价
```

for(初始动作；条件；每轮的动作)｛｝

- for中的每一个表达式都是可以省略的         ==**for（；条件；） == while(条件)**==

**==循环次数==**

```c
for(i = 0;i < n;i++)
```

循环的次数是n，而循环结束以后，i的值是n。循环的控制变量i，是选择从0开始还是从1开始，是判断i<n还是判断i<=n，对循环的次数，循环结束后变量的值都有影响。

==**Tips for loops**==

- 如果有固定次数，用for
- 如果必须执行一次，用do-while
- 其他情况用while

## 5.2 循环控制

==**break和continue**==

- break：跳出循环
- continue：跳出循环这一轮剩下的语句进入下一轮

```c
//1块钱可以由几个一毛，几个两毛，几个五毛组成

#include <stdio.h>

int main()
{
	int x;
	int one, two, five;
	
	scanf("%d", &x);
	for ( one = 1; one < x*10; one++ ) {
		for ( two = 1; two < x*10/2; two++ ) {
			for ( five = 1; five < x*10/5; five++ ) {
				if ( one + two*2 + five*5 == x*10 ) {
					printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n", 
						one, two, five, x);
					break;    //仅跳出当前for循环，将继续第二个for循环
				}
			}
		}
	}
	
	return 0;
}

//接力break
#include <stdio.h>

int main()
{
	int x;
	int one, two, five;
	int exit = 0;
	
	scanf("%d", &x);
	for ( one = 1; one < x*10; one++ ) {
		for ( two = 1; two < x*10/2; two++ ) {
			for ( five = 1; five < x*10/5; five++ ) {
				if ( one + two*2 + five*5 == x*10 ) {
					printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n", 
						one, two, five, x);
					exit = 1;   //设置出口，满足条件则出去
					break;		//跳出第三个循环
				}
			}
			if ( exit == 1 ) break;//跳出第二个循环
		}
		if ( exit == 1 ) break;//跳出第一个循环
	}
	
	return 0;
}

#include <stdio.h>

int main()
{
	int x;
	int one, two, five;
	
	scanf("%d", &x);
	for ( one = 1; one < x*10; one++ ) {
		for ( two = 1; two < x*10/2; two++ ) {
			for ( five = 1; five < x*10/5; five++ ) {
				if ( one + two*2 + five*5 == x*10 ) {
					printf("可以用%d个1角加%d个2角加%d个5角得到%d元\n", 
						one, two, five, x);
					goto out;   //利用goto直接跳出去
				}
			}
		}
	}
out:	       //goto的出口
	return 0;
}

//寻找素数

#include <stdio.h>

int main()
{
	int x;

	scanf("%d", &x);
	
	int i;
	int isPrime = 1;	//	x是素数
	for ( i=2; i<x; i++ ) {
		if ( x % i == 0 ) {
			isPrime = 0;
			break;
		}
	}
	if ( isPrime == 1 ) {
		printf("是素数\n");
	} else {
		printf("不是素数\n");
	}
	return 0;
}
//输出100以内的所有素数
#include <stdio.h>

int main()
{
	int x;
	
	for ( x=1; x<=100; x++ ) {    //1到100
		int i;
		int isPrime = 1;	//	x是素数
		for ( i=2; i<x; i++ ) {
			if ( x % i == 0 ) {
				isPrime = 0;
				break;
			}
		}
		if ( isPrime == 1 ) {
			printf("%d ", x);
		} 
	}
	printf("\n");
	return 0;
}
//输出前50个素数
#include <stdio.h>

int main()
{
	int x;
	int cnt = 0;     //计数器

	x = 1;
	while ( cnt <50 ) { 
		int i;
		int isPrime = 1;	//	x是素数
		for ( i=2; i<x; i++ ) {   //判断一个素数n，从2到n-1，若能被整除，则不是素数
			if ( x % i == 0 ) {
				isPrime = 0;
				break;            //不是素数则跳出当前循环，执行x++，开始判断下一个数
			}
		}
		if ( isPrime == 1 ) {
			cnt ++;                 //若是素数则计数器加1
			printf("%d\t", x);     //   \t对齐输出
			if ( cnt %5 == 0 ) {   //控制输出格式，每5个换行
				printf("\n");
			}
		} 
		x++;
	}
	return 0;
}

```

## 5.3 循环应用

```c
//两数的最大公约数
//枚举法
#include <stdio.h>

int main()
{
	int a,b;
	int min;
	
	scanf("%d %d", &a, &b);
	if ( a<b ) {
		min = a;
	} else {
		min = b;    //确定小的那个数，最大公约数不能大于小数
	}
	int ret = 0;
	int i;
	for ( i = 1; i < min; i++ ) {
		if ( a%i == 0 ) {
			if ( b%i == 0 ) {
				ret = i;
			}
		}
	}
	printf("%d和%d的最大公约数是%d.\n", a, b, ret);
	
	return 0;
}

//辗转相除法
/*1、如果b等于0，计算结束，a就是最大公约数；
  2、否则，计算a除以b的余数，让a等于b，而b等于那个余数；
  3、回到第一步。*/
#include <stdio.h>

int main()
{
	int a,b;
	int t;
	
	scanf("%d %d", &a, &b);
	int origa = a;
	int origb = b;
	while ( b != 0 ) {
		t = a%b;
		a = b;
		b = t;
	}
	printf("%d和%d的最大公约数是%d.\n", origa, origb, a);
	
	return 0;
}

//逆序分解

inx x;
scanf("%d",&x);
do{
    int d = x % 10;
    printf("%d ",d);
    x /= 10;
}while(x > 0)    
//如果按照上面的程序，最后会多一个空格，怎么解决？如下
inx x;
scanf("%d",&x);
do{
    int d = x % 10;
    printf("%d",d);   //注意，%d后的空格去掉了
    if(x > 9){
        printf(" ")  //设置一个输出空格必须满足的条件
    }
    x /= 10;
}while(x > 0)   
  
//正序分解整数
/* 输出一个非负整数，正序输出它的每一位数字，例如输入13425，则应输出1 3 4 2 5*/
    
//方法一，两次逆序，但只适用于末尾没有0的数字
#include<stdio.h>
{
inx x;
scanf("%d",&x);

x = 13425;
int t = 0;
do{
    int d = x % 10;
    t = t * 10 + d;
    x /= 10;
}while(x > 0);
printf("x=%d,t=%d\n",x,t);
x = t;
do{
    int d = x % 10;
    printf("%d",d);   //注意，%d后的空格去掉了
    if(x > 9){
        printf(" ")  //设置一个输出空格必须满足的条件
    }
    x /= 10;
}while(x > 0)  
return 0;
}

//方法二

13425 / 10000 -> 1
13425 % 10000 -> 3425        
10000 / 10 -> 1000
3425 / 1000 -> 3    
3425 % 1000 -> 425
1000 / 10 -> 100
425 / 100 -> 4
425 % 100 -> 25
100 / 10 -> 10    
25 / 10 -> 2    
25 % 10 -> 5    
10 / 10 ->1    
5 / 1 -> 5    
5 % 1 -> 0
1 / 10 ->0    
    
#include <stdio.h>

int main()
{
	int x;
	scanf("%d", &x);

	int mask = 1;
	int t = x;
//如果用do-while循环，则当x为个位数时，mask还是等于10，而我们要求mask应该等于1
	while ( t>9 ) { 	
		t /= 10;
		mask *=10;
	} 
	printf("x=%d, mask=%d\n", x, mask);
	do {
		int d = x / mask;
		printf("%d", d);
		if ( mask > 9 ) {    //若条件是x>0,空格输出位置会出错
			printf(" ");
		}
		x %= mask;
		mask /= 10;
	} while ( mask > 0 );   //若条件是x>0，当x等于70000时,最后只会输出7
	printf("\n");

	return 0;
}

//求和
#include <stdio.h>

int main()
{
	int n;
	int i;
	double ret=0.0;

	scanf("%d", &n);
	for ( i=1; i<=n; i++ ) {
		ret += 1.0/i;
	}
	printf("%f\n", ret);

	return 0;
}

//正负数求和
#include <stdio.h>

int main()
{
	int n;
	int i;
	double ret=0.0;
	int sign = 1;

	scanf("%d", &n);
	for ( i=1; i<=n; i++ ) {
		ret += 1.0*sign/i;
		sign = -sign;    //变换符号
	}
	printf("%f\n", ret);

	return 0;
}

```

## 习题解析

```c
//本题要求编写程序,计算序列 2/1+3/2+5/3+8/5+... 的前N项之和。注意该序列从第2项起，每一项的分子是前一项分子与分母的和，分母是前一项的分子。
#include<stdio.h>
int main()
{
    int n;
    double dividend,divisor;  //注意是用的浮点数
    double sum = 0.0;
    int i;
    double t;
    
    scanf("%d",&n);
    //n = 20000;
    dividend = 2;
    divisor = 1;
    for( i=1; i<=n; i++){
        sum +=dividend/divisor;
        t = dividend;
        dividend = dividend + divisor;
        divisor = t;
    }
    printf("%.2f\n",sum);
    return 0;
}
//最简分式（实际上是求最大公约数）
#include<stdio.h>
int main()
{
    int dividend,divisor;
    scanf("%d/%d",&dividend,&divisor);
    
    int a = dividend;
    int b = divisor;
    int t;
    while(b>0){
        t = a % b;
        a = b;
        b = t;
    }
    printf("%/%d\n",dividend/a,divisor/a);
    return 0;
}
//输入一个整数，输出每个数字对应的拼音。当整数为负数时，先输出“fu”字。
#include<stdio.h>
int main()
{
    int x;
    scanf("%d",&x);
    if( x<0 ){
        printf(“fu ”);
        x = -x;
    }
    
    int mask = 1;
    int t = x;
    while( t>9 ){
        t /= 10;
        mask *= 10;
    }
    do{
        int d = x / mask;
        switch(d){
            case 0:printf("ling");break;
            case 1:printf("yi");break;
            case 2:printf("er");break;
        	case 3:printf("san");break;
        	case 4:printf("si");break;
        	case 5:printf("wu");break;
            case 6:printf("liu");break;
            case 7:printf("qi");break;
            case 8:printf("ba");break;
            case 9:printf("jiu");break;          
            }
        	if( mask>9 ) printf(" ");
        	x %= mask;
        	mask /= 10;
       }while( mask>0 );
    	printf("\n");
    return 0;
}
//输入两个整数a和n，a的范围是[0,9]，n的范围是[1,8]，求数列之和S = a+aa+aaa+...+aaa...a（n个a）。如a为2、n为8时输出的是2+22+222+...+22222222的和。
#include<stdio.h>
int main（）
{
	int a,n;
	scanf("%d %d",&a,&n);
	
	int sum = 0;
	int i;
	int t = 0;
	for( i=0;i<n;i++){
		t = t*10+a;
		sum += t;
	}
	printf("%d",sum);
	return 0;
}
```

# 第六周：数据类型

## 6.1 数据类型

**类型不同**

- 类型名称：int、long、double
- 输入输出时的格式化：%d、%ld、%lf
- 所表达的数的范围：char<short<int<float<double
- 内存中所占据的大小：1个字节到16个字节
- 内存中的表达形式：二进制数（补码）、编码

`sizeof` ——运算符，给出某个类型或变量在内存中所占据的字节数

**整数的范围**

- char ：1字节（8比特） -128 ~ 127
- short ：2字节  -32768 ~ 32767
- int：取决于编译器（CPU），通常的意义是“一个字”，int就是用来表示寄存器的
- long：取决于编译器（CPU），通常的意义是“一个字”
- long long：8字节

==**补码**==

- 考虑-1，我们希望-1+1—>0。如何能做到？
- 0—>0000 0000
- 1—>0000 0001
- 1111 1111 + 0000 0001 —>1 0000 0000
- 因为0-1—>-1，所以，-1=
- （1）0000 0000 - 0000 0001—> 1111 1111
- 1111 1111被当作**纯二进制**看待时，是255，被当作**补码**看待时是-1
- 同理，对于-a，其补码就是0-a，实际是2^n - a，n是这种类型的位数

==**数的范围**==

**重点是自己怎么看待数，比如说，如果看作是纯二进制数，那么就不存在负数的说法，但如果看作是整数的话，那么就会出现负数（补码）**

- 对于有<u>**一个字节（8位）**</u>，可以表达的是：0000 0000 - 1111 1111
  - 其中：0000 0000 —> 0
  - 1111 1111 - 1000 0000 —> -1  ~  -128
  - 0000 0001 - 0111 1111 —> 1 ~ 127   **从0111 1111（即127）翻过去就到了1000 0000（即-128）**

`unsigned`

- 如果一个字面量常数想要表达自己是`unsigned`，可以在后面加u或U
  - 255U
  - 用l或L表示long（long）
  - `*unsigned`的初衷并非扩展数能表达的范围，而是为了做纯二进制运算，主要是为了移位

- **整数越界**
  - 整数是以纯二进制方式进行计算的，所以：
  - 1111 1111 + 1 —> 1 0000 0000 —> 0
  - 0111 1111 + 1 —> 1000 0000 —> -128
  - 1000 0000 - 1—> 0111 1111—> 127

```c
#include<stdio.h>

int main()
{
    char c = 127;
    int i = 255;
    c = c+1;
    printf("c=%d,i=%d\n",c,i);
    return 0;
}

//运行结果：c = -128，i = 255

#include<stdio.h>

int main()
{
    char c = -128;
    int i = 255;
    c = c-1;
    printf("c=%d,i=%d\n",c,i);
    return 0;
}

//运行结果：c = 127，i = 255

#include<stdio.h>

int main()
{
    unsigned char c = 127;
    int i = 255;
    c = c+1;
    printf("c=%d,i=%d\n",c,i);
    return 0;
}

//运行结果：c = 128，i = 255

int main()
{
    unsigned char c = 255;
    int i = 255;
    c = c+1;
    printf("c=%d,i=%d\n",c,i);
    return 0;
}

//运行结果：c = 0，i = 255

int main()
{
    unsigned char c = 0;
    int i = 255;
    c = c-1;
    printf("c=%d,i=%d\n",c,i);
    return 0;
}

//运行结果：c = 255，i = 255
```

**整数的输入输出**

- 只有两种形式：int或 long long
  - %d : int
  - %u : unsigned
  - %ld : long long
  - %lu: unsigned long long

```c
#include<stdio.h>

int main()
{
    char c = -1;
    int i = -1;
    printf("c=%u,i=%u",c,i);  // %u会将char转换成int
    return 0;
}

//输出c=4294967295,i=4294967295
```

**选择整数类型**

==没有特殊需要，就选择`int`==

**浮点类型**

|  类型  | 字长 |                     范围                     | 有效数字 |
| :----: | :--: | :------------------------------------------: | :------: |
| float  |  32  | +-（1.20*10^-38^~3.40 * 10^38^）,0,+-inf,nan |    7     |
| double |  64  | +-(2.2*10^-308^~1.79 * 10^308^),0,+-inf,nan  |    15    |

```c
#include<stdio.h>

int main()
{
    printf("%.3f\n",-0.0049);  //四舍五入输出
    printf("%.30f\n",-0.0049);
    printf("%.3f\n",-0.00049);
    printf("%e\n",-0.0049);  //科学计数法
}

/*  -0.005
	-0.00489999999.....
    -0.000
    -4.9e-3
*/
```

**浮点运算的精度**

- 带小数点的字面量是double而非float
- float需要用f或F后缀来表明身份

```c
float a,b,c

a = 1.345f;
b = 1.123f;
```

**选择浮点类型**

==如果没有特殊需要，只使用`double`==

**字符类型**

- 'a' - 'A'可以得到两段之间的距离，于是
  - a + 'a' - 'A' 可以把一个大写字母变成小写字母
  - a + 'A' - 'a'可以把一个小写字母变成大写字母

**逃逸字符**

用来表达无法印出来的控制字符或特殊字符，它由一个反斜杠"\\\"开头，后面跟上另一个字符，这两个字符合起来，组成了一个字符

```c
printf("请分别输入身高的英尺和英寸，""如输入\"5 7\"表示5英尺7英寸：")；
```

| 字符 |      意义      | 字符 |    意义    |
| :--: | :------------: | :--: | :--------: |
|  \b  |    回退一个    | \\"  |   双引号   |
|  \t  | 到下一个表格位 | \\'  |   单引号   |
|  \n  |      换行      | \\\\ | 反斜杠本身 |
|  \r  |      回车      |      |            |

**自动类型转换**

- 当运算符的两边出现不一致的类型时，会自动转换成较大的类型
  - 大的意思是能表达的数的范围更大
  - char -> short -> int -> long -> long long
  - int -> float -> double
- 对于printf，任何小于int的类型会被转换成int；float会被转换成double
- 但是scanf不会，要输入short，需要%hd

**强制类型转换**

- 要把一个量强制转换成另一个类型（通常是较小的类型），需要：
  - （类型）值
    - 比如（int）10.2
    - （short）32
- 注意这时候的安全性，小的变量不总能表达大的量
  - （short）32768
- 强制类型转换的优先级高于四则运算

## 6.2 其他运算：逻辑、条件、逗号

**bool**

- `#include<stdbool.h>`
- 之后就可以使用bool和true、false

**逻辑运算**

- 逻辑运算是对逻辑量进行的运算，结果只有0或1
- 逻辑量是关系运算或逻辑运算的结果

| 运算符 |  描述  |   示例   |                             结果                             |
| :----: | :----: | :------: | :----------------------------------------------------------: |
|   ！   | 逻辑非 |   ！a    |      如果a是true结果就是false，如果a是false结果就是true      |
|   &&   | 逻辑与 |  a && b  |        如果a和b都是true，结果就是true；否则就是false         |
|  \|\|  | 逻辑或 | a \|\| b | 如果a和b有一个是true，结果为true；两个都是false，结果为false |

**优先级**

| 优先级 |      运算符      |         结合性         |
| :----: | :--------------: | :--------------------: |
|   1    |       （）       |        从左到右        |
|   2    |   ！+ - ++ --    | 从右到左（单目的+和-） |
|   3    |      * / %       |        从左到右        |
|   4    |       + -        |        从左到右        |
|   5    |    < <= > >=     |        从左到右        |
|   6    |      == !=       |        从左到右        |
|   7    |        &&        |        从左到右        |
|   8    |       \|\|       |        从左到右        |
|   9    | = += -= *= /= %= |        从右到左        |

**短路**

- 逻辑运算是自左向右进行的，如果左边的结果已经能够决定结果了，就不会做右边的计算
  - a\==6 && b\==1
  - a \==6 && b\+=1
  - 不要把赋值，包括复合赋值组合进表达式
- 对于&&，左边是false时就不做右边了
- 对于||，左边是true时就不做右边了

**条件运算符**

条件运算符的优先级高于赋值运算符，但是低于其他运算符

```c
count = (count>20)?count - 10:count + 10;
//条件、条件满足时的值和条件不满足时的值
//等价于
if(count > 20)
    count = count - 10;
else
    count = count + 10;
```

**逗号运算符**

逗号用来连接两个表达式，并以其右边的表达式的值作为它的结果。逗号的优先级是所有的运算符中最低的，所以**它两边的表达式会先计算**；逗号的组合关系是自左向右，所以左边的表达式会先计算，而右边的表达式的值就留下来作为逗号运算的结果。

一般在for中使用，如

```C
for(i=0,j=10;i<j;i++,j--)
```

# 第七周：函数

## 7.1 函数的定义和使用

 **调用函数**

- 函数名（参数值）
- （）起到了表示函数调用的重要作用
  - 即使没有参数也需要（）
- 如果有参数，则需要给出正确的数量和顺序
- 这些值会被按照顺序依次用来初始化函数中的参数

**没有返回值的函数**

- void函数名（参数表）
- 不能使用带值的return
  - 可以没有return
- 调用的时候不能做返回值的赋值，如果函数有返回值，则必须使用带值的return

## 7.2 函数的参数和变量

**函数原型**

```C
double max(double a,double b);//函数原型

int main()
{
    int a,b,c;
    a = 5;
    b = 6;
    c = max(10,12);
    printf("%d\n",c);
    max(12,13);
    
    return 0;
}

double max(double a, double b)//实际的函数头
```

- 函数头，以分号"；"结尾，就构成了函数的原型
- 函数原型的目的是告诉编译器这个函数长什么样
  - 名称
  - 参数（数量及类型）
  - 返回类型
- 旧标准习惯把函数原型写在调用它的函数里面
- 现在一般写在调用它的函数前面
- 原型里可以不写参数的名字，但是一般仍然写上

==**C语言在调用函数时，永远只能传值给函数**==

**本地变量（局部变量）**

- 函数的每次运行，就产生了一个独立的变量空间，在这个空间中的变量，是函数的这次运行所独有的，称作本地变量
- 定义在函数内部的变量就是本地变量，参数也是本地变量

**变量的生存期和作用域**

- 生存期：什么时候这个变量开始出现了，到什么时候它消亡了
- 作用域：在（代码的）什么范围内可以访问这个变量（这个变量可以起作用）
- 对于本地变量，这两个问题的答案是统一的：大括号——块

**本地变量的规则**

- 本地变量是定义在块内的
  - 它可以使定义在函数的块内
  - 也可以定义在语句的块内
  - 甚至可以随便拉一对大括号来定义变量
- 程序运行进入这个块之前，其中的变量不存在，离开这个块，其中的变量就消失了
- 块外面定义的变量在里面仍然有效
- 块里面定义了和外面同名的变量则掩盖了外面的
- 不能在一个块内定义同名的变量
- 本地变量不会被默认初始化
- 参数在进入函数的时候被初始化了

# 第八周：数组

## 8.1 数组

**定义数组**

- <类型>变量名称[元素数量]
  - int grades[100];
  - double weight[20];
- 元素**数量**必须是整数
- C99之前：元素数量必须是编译时刻确定的字面量
- 数组是一种**容器**（放东西的东西），特点是：
  - 其中所有的元素具有相同的数据类型
  - 一旦创建，不能改变大小
  - *(数组中的元素在内存中是连续依次排列的)

**有效的下标范围**

- 编译器和运行环境都不会检查数组下标是否越界，无论是对数组单元做读还是写
- 一旦程序运行，越界的数组访问可能造成问题，导致程序崩溃
  - segmentation fault
- 但是也可能运气好，没造成严重的后果，所以这是程序员的责任——保证程序只使用有效的下标值：
- ==**[0，数组的大小 - 1]**==

```C
//写一个程序，输入数量不确定的[0，9]范围内的整数，统计每一种数字出现的次数，输入-1表示结束
#include<stdio.h>

int main(void)
{
    const int nubmer = 10;  //数组的大小
    int x;
    int count[nubmer] = {0};		//定义数组,初始化数组
    int i;
    
  /*  for( i=0; i <number; i++ ){
        count[i] = 0		//初始化数组
    }*/
    scanf("%d",&x);
    while( x!= -1 ){
        if( x>=0 && x<=9 ){
            count[x] ++;	//数组参与运算
        }
        scanf("%d",&x);
    }
    for( i=0; i<number; i++ ){	//遍历数组输出
        printf("%d:%d\n",i,count[i]);
    }
    return 0;
}
```

## 8.2 数组运算

```C
#include<stdio.h>

/**
找出key在数组a中的位置
@param key 要寻找的数字
@param a 要寻找的数组
@param length 数组a的长度
@return 如果找到，返回其在a中的位置；如果找不到则返回-1
*/
int search(int key, int a[], int length);

int main(void)
{
    int a[] = {2,4,6,7,1,3,5,9,11,13,23,14,32};
    int x;
    int loc;
    printf("请输入一个数字：");
    scanf("%d",&x);
    loc = search(x,a,sizeof(a)/sizeof(a[o]));
    if( loc != -1 ){
        printf("%d在第%d个位置上\n", x, loc);     
    }else{
        printf("%d不存在\n", x);
    }
    return 0;
}

int search(int key, int a[], int length)
{
    int ret = -1;
    int i;
    for( i=0; i<length; i++){
        if( a[i] == key ){
            ret = i;
            break;
        }
    }
    return ret;
}

/*
数组作为函数的参数时：
1、不能在[]中给出数组的大小
2、不能再利用sizeof来计算数组的元素个数！
*/
```

**数组的集成初始化**

`int a[] = {2,3,6,7,1,3,5,9,11,13,23,14,32}`

- 直接用大括号给出数组的所有元素的初始值
- 不需要给出数组的大小，编译器替你数数

`int b[20] = {2};`

- 如果给出了数组的大小，但是后面的初始值数量不足，则其后的元素被初始化为0

**集成初始化时的定位**

`int a[10] = {[0] = 2, [2] = 3, 6, };`

- 用`[n]`在初始化数据中给出定位
- 没有定位的数据接在前面的位置后面
- 其他位置的值补零
- 也可以不给出数组大小，让编译器算
- 特别适合初始数据稀疏的数组

==**数组的大小**==

- sizeof给出整个数组所占据的内容的大小，单位是字节

  ​			`sizeof(a)/sizeof(a[0])`

- `sizeof(a[0])`给出数组中单个元素的大小，于是相除就得到了数组的单元个数

- 这样的代码，一旦修改数组中初始的数据，不需要修改遍历的代码

**数组的赋值**

- 数组变量本身不能被赋值

- 要把一个数组的所有元素交给另一个数组，必须采用遍历

  ```C
  for( i=0; i<length; i++ ){
  	b[i] = a[i]
  }
  ```

**遍历数组**

- 通常都是使用for循环，让循环变量i从0到<数组的长度，这样循环体内最大的i正好是数组最大的有效下标
- 常见错误是：
  - 循环结束条件是<=数组长度，或；
  - 离开循环后，继续用i的值来做数组元素的下标！

**二维数组的初始化**

`int a[][5] = {{0,1,2,3,4},{2,3,4,5,6},};` 

- 列数是必须给出的，行数可以由编译器来数
- 每行一个{}，逗号分隔
- 最后的逗号可以存在，有古老的传统
- 如果省略，表示补零
- 也可以用定位

```C
/*
tic-tac-toe游戏
读入一个3*3的矩阵，矩阵中的数字为1表示该位置上有一个X，为0表示为O
程序判断这个矩阵中是否有获胜的一方，输出表示获胜一方的字符X或O，或输出无人获胜
*/
#include<stdio.h>

int main(void)
{
    const int size = 3;
    int board[size][size];
    int i,j;
    int numOfX;
    int numOfO;
    int result = -1;  		//-1：没人赢，1：X赢，0：O赢
    //读入矩阵
    
    for( i=0; i<size; i++ ){
        for( j=0; j<size; j++ ){
            scanf("%d",&board[i][j]);
        }
    }
    //检查行
    for( i=0; i<size && result == -1;i++ ){
        numOfO = numOfX = 0;
        for( j=0; j<size; j++ ){
            if(board[i][j] == 1 ){
                numOfX ++;
            }else{
                numOfO ++;
            }
        }
        if( numOfO == size ){
            result = 0;
        }else if( numOfX == size ){
            result = 1;
        }
    }
    //检查列
    if( result == -1){
        for( j=0; j<size && result == -1; j++ ){
            numOfO = numOfX = 0;
            for( i=0; i<size; i++ ){
                if( board[i][j] == 1 ){
                    numOfX ++;
                }else{
                    numOfO ++;
                }
            }
            if( numOfO == size ){
                result = 0;
            }else if( numOfX == size ){
                result = 1;
            }
        }
    }
    //检查对角线
    numOfO = numOfX = 0;
    for( i=0; i<size; i++ ){
        if(board[i][i] == 1){
            numOfX ++;
        }else{
            numOfO ++;
        }
    }
    if( numOfO == size ){
        result = 0;
    }else if( numOfX == size ){
        result = 1;
    }
    numOfO = numOfX = 0;
    for( i=0; i<size; i++ ){
        if( board[i][size-i-1] == 1 ){
            numOfX ++;
        }else{
            numOfO ++;
        }
    }
    printf("%d",result)
    return 0;
}
//如何用一个两重循环实现行和列的检查
int result = -1;
int board[SIZE][SIZE];
int a_x[SIZE] = {0},b_x[SIZE] = {0};//x代表行累计，y代表列累计（例如a_x[2]代表a在第二行的棋子
int a_y[SIZE] = {0},b_y[SIZE] = {0};//数 ）
for( int i = 0; i<SIZE && result == -1; i++ ){
    for( int j = 0; j<SIZE; j++ ){
        if(board[i][j] == 0){
            a_x[i] ++;
            a_y[j] ++;
        }else{
            b_x[i] ++;
            b_t[j] ++;
        }if( a_x[i] == SIZE || a_y[j] == SIZE){
            result = 0;
            break;
        }else if(b_x[i] == SIZE || b_y[j] == SIZE){
            result = 1;
        }
    }
}

```

```C
//素数plus
#include<stdio.h>
int isPrime(int x, int knownPrimes[], int numberOfKnownPrimes);
int main(void)
{
    const int number = 100;
    int prime[number] = {2};  //初始化,编译会出错https://bbs.csdn.net/topics/390277028
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
```

**构造素数表算法：**

欲构造n以内的素数表

1. 令x为2
2. 将2x、3x、4x直至ax<n的数标记为非素数
3. 令x为下一个没有被标记为非素数的数，重复2；直到所有的数都已经尝试完毕

**伪代码**

1. 开辟prime[n]，初始化其所有元素为1，prime[x]为1表示x是素数
2. 令x=2
3. 如果x是素数，则对于（i=2;x*i<n;i++）令prime[i\*x]=0
4. 令x++，如果x<n，重复3，否则结束

```C
#include<stdio.h>

int main()
{
    const int maxNumber = 25;
    int isPrime[maxNumber];
    int i;
    int x;
    for( i=0; i<maxNumber; i++ ){
        isPrime[i] = 1;      //初始化
    }
    // for test
    printf("\t");
    for( i=2;i<maxNumber; i++ ){
        printf("%d\t",i);
    }
    printf("\n");
    // for test
    for( x=2; x<maxNumber;x++ ){
        if( isPrime[x] ){
            for( i=2; i*x<maxNumber; i++ ){
                isPrime[i*x] = 0;
            }
        }
        //for test
        printf("%d\t",x);
        for( i=2; i<maxNumber;i++ ){
            printf("%d\t",isPrime[i]);
        }
        printf("\n");
        //for test
    }
    for( i=2; i<maxNumber; i++ ){
        if( isPrime[i] ){
            printf("%d\t",i); 
        }
    }
    return 0;
}
```

# 第九周：指针

## 9.1 指针

**运算符&**

- `scanf("%d",&i);`里的`&`
- 获得变量的地址，它的操作数必须是变量
  - `int i; printf("%x",&i);`
- 地址的大小是否与int相同取决于编译器
  - `int i; printf("%p",&i);`
- &不能对没有地址的东西取地址
  - &(a+b)?
  - &(a++)?

==**指针**==

**就是保存地址的变量**

`int i; int* p = &i; int* p,q; int *p,q;`

**指针变量**

- 变量的值是内存的地址
  - 普通变量的值是实际的值
  - 指针变量的值是具有实际值的变量的地址

**作为参数的指针**

- `void f(int *p)`
- 在被调用的时候得到了某个变量的地址
  - `int i=0;f(&i);`
- 在函数里面可以通过这个指针访问外面的这个i

**访问那个地址上的变量***

- *是一个单目运算符，用来访问指针的值所表示的地址上的变量
- 可以做右值也可以做左值
  - `int k = *p;`
  - `*p = k+1;`

```c
#include<stdio.h>

void f(int *p);
void g(int k);

int main(void)
{
    int i = 6;
    printf("&i=%p\n",&i);
    f(&i);
    g(i);
    
    return 0;
}

void f(int *p)
{
    printf(" p=%p\n",p);
    printf("*p=%d\n",*p);
    *p = 26;
}

void g(int k)
{
    printf("k=%d\n",k);
}
```

***左值之所以叫左值**

- 是因为出现在赋值号左边的不是变量，而是值，是表达式计算的结果：
  - a[0] = 2;
  - *p = 3;
- 是特殊的值，所以叫做左值

**指针的运算符&***

- 互相反作用
  - *&yptr -> *(&yptr) -> *(yptr的地址) -> 得到那个地址上的变量 -> yptr
  - &*yptr -> &(\*yptr) -> &(y) -> 得到y的地址，也就是yptr -> yptr

**指针应用场景**

```C
//the first example:swap
#include<stdio.h>

void swap(int *pa, int *pb);

int main(void)
{
    int a = 5;
    int b = 6;
    swap(&a,&b);
    printf("a=%d,b=%d\n",a,b);
    
    return 0;
}

void swap(int *pa, int *pb)
{
    int t = *pa;
    *pa = *pb;
    *pb = t;
}

/*指针应用场景二：
函数返回多个值，某些值就只能通过指针返回
传入的参数实际上是需要保存带回的结果的变量*/

#include<stdio.h>

void minmax(int a[], int len, int *man, int *min);

int main(void)
{
    int a[] = {1,2,3,4,5,6,7,8,9,12,13,14,15,17,21,23,55,};
    int min,max;
    minmax(a, sizeof(a)/sizeof(a[0]), &min, &max);
    printf("min=%d,max=%d\n",min,max);
    
    return 0;
}

void minmax(int a[], int len, int *min, int *max)
{
    int i;
    *min = *max = a[0];
    for( i=1; i<len; i++ ){
        if( a[i] < *min ){
            *min = a[i];
        }
        if( a[i] > *max ){
            *max = a[i];
        }
    }
}
```

**指针应用场景二b**

- 函数返回运算的状态，结果通过指针返回
- 常用的套路是让函数返回特殊的不属于有效范围内的值来表示出错：
  - ==-1或0==（在文件操作会看到大量的例子）
- 但是当任何数值都是有效的可能结果时，就得分开返回了

```C
#include<stido.h>

/**
	@return 如果除法成功，返回1；否则返回0
*/
int divide(int a, int b, int *result);

int main(void)
{
    int a = 5;
    int b = 2;
    int c;
    if( divide(a,b,&c) ){
        printf("%d/%d=%d\n",a,b,c);
    }
    return 0;
}

int divide(int a, int b, int *result)
{
    int ret = 1;
    if( b == 0 ) ret = 0;
    else{
        *result = a/b;
    }
    return ret;
}
```

==**指针最常见的错误：定义了指针变量，还没有指向任何变量，就开始使用指针**==

**传入函数的数组到底是什么？数组变量是特殊的指针**

- 函数参数表中的数组实际上是指针
  - sizeof(a) == sizeof(int*)
  - 但是可以用数组的运算符[]进行运算
- 数组变量本身表达地址，所以
  - `int a[10]; int *p = a;`无需用&取地址
  - 但是数组的单元表达的是变量，需要用&取地址
  - `a == &a[0]`
- []运算符可以对数组做，也可以对指针做：
  - p[0] <==> a[0]
- *运算符可以对指针做，也可以对数组做：
  - `*a = 25;`
- 数组变量是const的指针，所以不能被赋值
  - int a[] <==> int *const a=...

**数组参数**

- 以下四种函数原型是等价的：
  - `int sum(int *ar, int n);`
  - `int sum(int *, int);`
  - `int sum(int ar[], int n);`
  - `int sum(int [], int);`

**指针和const**

- 指针是const
  - 表示一旦得到了某个变量的地址
    - `int * const q = &i; //q是const`
    - *q = 26;//OK
    - q++;      // ERROR
- 所指是const
  - 表示不能通过这个指针去修改那个变量（并不能使得那个变量成为const）
    - `const int *p = &i;`
    - `*p = 26;//ERROR! (\*p)是const`
    - `i = 26;//OK`
    - `p = &j;//OK`
- 何如判断哪个被const了的标志是const在*的前面还是后面
  - `int i;`
  - `const int* p1 = &i;`const在*前面，表示不能通过这个指针去修改那个变量
  - `int const* p2 = &i;`const在*前面，表示不能通过这个指针去修改那个变量
  - `int *const p3 = &i;`const在*后面，表示指针不能被修改，如p3++

**转换**

- 总是可以把一个非const的值转换成const的

  ```c
  void f(const int* x);
  int a = 15;
  f(&a);//ok
  const int b = a;
  
  f(&b);//ok
  b = a + 1;//Error!
  ```

- 当要传递的参数的类型比地址大的时候，这是常用的手段：既能用比较少的字节数传递值给参数，又能避免函数对外面的变量的修改

**const数组**

- `const int a[] = {1,2,3,4,5,6,};`
- 数组变量已经是const的指针了，这里的const表明数组的每个单元都是const int
- 所以必须通过初始化进行赋值

**保护数组值**

- 因为把数组传入函数时传递的是地址，所以那个函数内部可以修改数组的值
- 为了保护数组不被函数破坏。可以设置参数为const
  - `int sum(const int a[], int length);`

## 9.2 指针运算

**1+1=2？**

- 给一个指针加1表示要让指针指向下一个变量
  - `int a[10]`
  - `int *p = a`
  - `*(p+1) -> a[1]`

- 如果指针不是指向一片连续分配的空间，如数组，则这种运算没有意义

```C
#include<stdio.h>

int main(void)
{
	char ac[] = {0,1,2,3,4,5,6,7,8,9,};
	char *p = ac;
    char *p1 = &ac[5];
	printf("p=%p\n", p);
	printf("p+1=%p\n", p+1);
	printf("*(p+1)=%d\n", *(p+1));
    printf("p1-p=%d\n", p1-p);
	// *(p+n) <-> ac[n]
    
    int ai[] = {0,1,2,3,4,5,6,7,8,9,};
    int *q = ai;
    int *q1 = &ai[6];
    printf("q=%p\n",q);
    printf("q+1=%p\n",q+1);
    printf("*(q+1)=%d\n",*(q+1));
    printf("q1-q=%d\n", q1-q);
    return 0;
}
```

**指针计算**

- 给指针加、减一个整数（+，+=，-，-=）
- 递增递减（++/--）
- 两个指针相减

***p++**

- 去除p所指的那个数据来，完事之后顺便把p移到下一个位置去
- *的优先级虽然高，但是没有++高
- 常用于数组类的连续空间操作
- 在某些CPU上，这可以直接被翻译成一条汇编指令

```C
#include<stdio.h>

int main(void)
{
    char ac[] = {0,1,2,3,4,5,6,7,8,9,-1};
    char *p = &ac[0];
    int i;
    for( i=o; i<sizeof(ac)/sizeof(ac[0]); i++ ){
        printf("%d\n",ac[i]);
    }
    //for( p=ac; *p!=-1; ){
    while( *p != -1 ){
        printf("%d\n",*p++);
    }
    return 0;
}
```

**指针比较**

- <, <=, ==, >, >=, !=都可以对指针做
- 比较它们在内存中的地址
- 数组中的单元的地址肯定是线性递增的

**0地址**

- 当然你的内存中有0地址，但是0地址通常是个不能随便碰的地址，所以你的指针不应该具有0值
- 因此可以用0地址来表示特殊的事情：
  - 返回的指针是无效的
  - 指针没有被真正初始化（先初始化为0）
- NULL是一个预定定义的符号，表示0地址
  - 有的编译器不愿意你用0来表示0地址

**指针的类型**

- 无论指向什么类型，所有的指针的大小都是一样的，因为都是地址
- 但是指向不同类型的指针是不能直接互相赋值的
- 这是为了避免用错指针

**指针的类型转换**

- `void*` 表示不知道指向什么东西的指针，计算时与`char*`相同（但不相通）
- 指针也可以转换类型
  - `int *p = &i;void *q = (void*)p;`
- 这并没有改变p所指的变量的类型，而是让后人用不同的眼光通过p看它所指的变量
  - 我不再当你是int啦，我认为你就是个void!

**==用指针来做什么==**

- 需要传入较大的数据时用作参数

- 传入数组后对数组做操作

- 函数返回不止一个结果

  - 需要用函数来修改不止一个变量

- 动态申请的内存

  - malloc

    - ```C
      #include<stdlib.h>
      void* malloc(size_t size);
      
      //向malloc申请的空间的大小是以字节为单位的，返回的结果是void*，需要类型转换为自己需要的类型
      (int*)malloc(n*sizeof(int))
      ```

  - free()

    - 把申请得来的空间还给“系统”
    - 申请过的空间，最终都应该要还
    - 只能还申请来的空间的首地址

**函数间传递指针**

- 好的模式
  - 如果程序中要用到动态分配的内存，并且会在函数之间传递，不用让函数申请内存后返回给调用者
  - 因为十有八九调用者会忘了free，或找不到合适的时机来free
  - 好的模式是让调用者自己申请，传递值进函数，函数再返回这个地址出来
  - 除非函数的作用就是分配空间，否则不要在函数中malloc然后传出去用
- 函数返回指针？
  - 返回指针没问题，关键是谁的地址？
    - 本地变量（包括参数）？函数离开后这些变量就不存在了，指针所指的是不能用的内存
    - 传入的指针？没问题
    - 动态申请的内存？没问题
- 函数返回数组？
  - 如果一个函数的返回类型是数组，那么它实际返回的也是数组的地址
  - 如果这个数组是这个函数的本地变量，那么回到调用函数那里，这个数组就不存在了
  - 所以只能返回
    - 传入的参数：实际就是在调用者那里
    - 全局变量或动态分配的内存

# 第十周：字符串

## 10.1 字符串

**字符串**

- 以0（整数0）结尾的一串字符
  - 0或‘\0’是一样的，但是和‘0’不同
- 0标志字符串的结束，但它不是字符串的一部分
  - 计算字符串长度的时候不包含这个0
- 字符串以数组的形式存在，以数组或指针的形式访问
  - 更多的是以指针的形式
- string.h里有很多处理字符串的函数

- “Hello”
  - "Hello"会被编译器变成一个字符数组放在某处，这个数组的长度是6，结尾还有表示结束的0
- 两个相邻的字符串常量会被自动连接起来
- C语言的字符串是以字符数组的形态存在的
  - 不能用运算符对字符串做运算
  - 通过数组的方式可以遍历字符串
- 唯一特殊的地方是**字符串字面量可以用来初始化字符数组**
- 以及标准库提供了一系列字符串函数

**字符串常量**

```C
char* s = "Hello, world!";
```

- s是一个指针，初始化为指向一个字符串常量
  - 由于这个常量所在的地方，所以实际上s是`const char* s`（只能读不能写），但是由于历史的原因，编译器接受不带const的写法
  - 但是试图对s所指的字符串做写入会导致严重的后果
- 如果需要修改字符串，应该用数组：

```C
char s[] = "Hello, world!";
```

**用指针还是数组？**

```C
char *str = "Hello";
char word[] = "Hello";
```

- 数组：这个字符串在这里
  - 作为本地变量空间自动被回收
- 指针：这个字符串不知道在哪里
  - 处理参数
  - 动态分配空间

==如果要构造一个字符串——用数组==

==如果要处理一个字符串——用指针==

**char* 是字符串？**

- 字符串可以表达为char*的形式
- char*不一定是字符串
  - 本意是指向字符的指针，可能指向的是字符的数组（就像int*一样）
  - 只有它所指的字符数组有结尾的0，才能说它所指的是字符串

**字符串的输入输出？**

```C
char string[8];
scanf("%7s", string);//最多只能读7个字符
ptintf("%7s", string);
```

- scanf读到一个单词（到空格、tab或回车为止）
- scanf是不安全的，因为不知道要读入的内容的长度

**安全的输入**

```C
char string[8];
scanf("%7s",string);
```

- 在%和s之间的数字表示最多允许读入的字符的数量，这个数字应该比数组的大小小一
  - 下一次scanf从哪里开始

**常见错误**

```C
char *string;
scanf("%s",string);
```

- 以为char*是字符串类型，定义了一个字符串类型的变量string就可以直接使用了
  - 由于没有对string初始化为0，所以不一定每次运行都出错

```C
//空字符串
char buffer[100] = "";
```

- 这是一个空的字符串，`buffer[0]=='\0'`

```C
char buffer[] = "";
```

- 这个数组的长度只有1！

**字符串数组**

- char **a
  - a是一个指针，指向另一个指针，那个指针指向一个字符（串）
- char a\[][]
  - a是一个二维数组，第二个维度的大小不知道，不能编译
- char a\[][10]
  - a是一个二维数组，a[x]是一个char[10]
- char *a[]
  - a是一个一维，a[x]是一个char*

```C
char a[][10];//代表a[0]的大小是char [10]，长度为10
char *a[];//a[0]表示指向某一字符串的指针

#include<stdio.h>

int main(void)
{
    int month = 0;
    char *months[] ={"January","February","March","April","May","June","July"};
    return 0;
}
    
```

**程序参数**

- `int main(int argc, char const *argv[])`
- argv[0]是命令本身
  - 当使用Unix的符号链接时，反映符号链接的名字

```C
#include<stdio.h>

int main(int argc, char const *argv[])
{
	int i;
	for( i=0; i<argv; i++ ){
		printf("%d:%s\n",i,argv[i]);
	}
	return 0;
}
```

## 10.2 字符串函数

**putchar**

- `int putchar(int c);`
- 向标准输出写一个字符
- 返回写了几个字符，EOF（-1）表示写失败

**getchar**

- `int getchar(void);`
- 从标准输入读入一个字符
- 返回类型是int是为了返回EOF（-1）
  - Windows——>Ctrl-Z
  - Unix——>Ctrl-D

```C
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int ch;
    while((ch = getchar()) != EOF ){
        putchar(ch);
    }
    printf("EOF\n");
    return 0;
}
```

**string.h**

- **strlen**
  - size_t strlen(const char *s);
  - 返回s的字符串长度（不包括结尾的0）

```c
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char line[]="Hello";
    printf("strlen=%lu\n",strlen(line));
  //printf("strlen=%lu\n",mylen(line));
    printf("sizeof=%lu\n",sizeof(line));
    
    return 0;
}

//strlen等价于以下函数
int mylen(const char* s)
{
    int idx = 0;
    while( s[idx] != '\0' ){
        idx++;
    }
    return idx;
}
```

- **strcmp**
  - int strcmp( const char *s1, const char *s2);
  - 比较两个字符串，返回：
    - 0：s1 == s2
    - 1: s1 > s2
    - -1: s1 < s2

```C
#include<stdio.h>
#include<string.h>

int mycmp(const* s1, const char* s2)
{
    //int idx = 0;
    //while( s1[idx] == s2[idx] && s1[idx] != '\0'){
    //    idx ++;
    //}
    while( *s1 == *s2 && *s1 != '\0' ){
        s1++;
        s2++;
    }
    return *s1 - *s2; 
}

int main(int argc, char const *argv[])
{
    char s1[] = "abc";
    char s2[] = "abc";
    printf("%d\n",strcmp(s1,s2));
    //printf("%d\n",mycmp(s1,s2));
    
    return 0;
}
```

- **strcpy**

  - char* strcpy(char *restrict dst, const char *restrict src);

  - 把src的字符串拷贝到dst

    - restrict表明src和dst不重叠（C99）

  - 返回dst

    - 为了能链起代码来

  - 复制一个字符串

  - ```C
    char *dst = (char*)malloc(strlen(src)+1);//记得加1！！！！
    strcpy(dst, src);
    ```

```c
#include<stdio.h>
#include<string.h>

char* mycpy(char* dst, const char* src)
{
    //int idx = 0;
    //while( src[idx] ){
    //   dst[idx] = src[idx];
    //    idx++;
    //}
    //dst[idx] = '\0';
    char* ret = dst;
    while( *dst++ = *src++ )//看不懂回去看视频10.2的第四个视频9分40秒
    	;
    *dst = '\0';
    return ret;
}

int main(int argc, char const *argv[])
{
    char s1[] = "abc";
    char s2[] = "abc";
    strcpy(s1,s2);
    
    return 0;
}
```

- **strcat**
  - char* strcat(char *restrict s1, const char *restrict s2);
  - 把s2拷贝到s1的后面，接成一个长的字符串
  - 返回s1
  - s1必须具有足够的空间

```C
#include<stdio.h>
#include<string.h>

char* mycat(char *dst, const char *src)
{
    int idx = 0;
    while( src[idx] != '\0'){
        dst[strlen(s1)] = src[idx];
        idx ++;
    }
    //while( dst[strlen(dst)] = *src++)
    //	;
    return s1;    
}
```

**安全问题**

- strcpy和strcat都可能出现安全问题
  - 如果目的地没有足够的空间？
- 安全版本
  - char* strncpy(char *restrict dst, const char *restrict src, size_t n);
  - char* strncat(char *restrict s1, const char *restrict s2, size_t n);
  - int strncmp(const char *s1, const char *s2,size_t n);

**字符串中找字符**

- char* strchr(const char *s, int c);
- char* strrchr(const char *s, int c);
- 返回NULL表示没有找到
- 如何找第二个？

```C
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello";
    char *p = strchr(s,'l');
    p = strchr(p+1,'l');
    printf("%s\n",p);
    return 0;
}

#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello";
    char *p = strchr(s,'l');
    char *t = (char*)malloc(strlen(p)+1);
    strcpy(t,p);//把l后面的赋值到t
    printf("%s\n",t);
    free(t);
    return 0;
}

#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char s[] = "hello";
    char *p = strchr(s,'l');
    char c = *p;
    *p = '\0';
    char *t = (char*)malloc(strlen(s)+1);
    strcpy(t,s);//把l前面的赋值到t
    printf("%s\n",t);
    free(t);
    
    return 0;
}
```

**字符串中找字符串**

- char* strstr(const chat *s1, const char *s2);
- char* strcasestr(const char *s1, const char *s2);//忽略大小写

# 第十一周：结构类型

## 11.1 枚举

- 枚举是一种用户定义的数据类型，它用关键字==enum==以如下语法来声明：

  ​	            ==enum 枚举类型名字｛名字0，...，名字n｝;==

- 枚举类型名字通常并不真的使用，要用的是在大括号里的名字，因为它们就是常量符号，它们的类型是int，值则依次从0到n。如：

  ​				==enum colors{red,yellow,greed};==

- 就创建了三个常量，red的值是0，yellow是1，而green是2。

- 当需要一些可以排列起来的常量值时，定义枚举的意义就是给了这些常量值名字。

- 虽然枚举类型可以当做类型使用，但是实际上很少（不好）用

- 如果有意义上排比的名字，用枚举比const int方便

- 枚举比宏（macro）好，因为枚举有int类型

```C
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

//套路：自动计数的枚举
//这样需要遍历所有的枚举量或者需要建立一个用枚举量做下标的数组的时候就很方便了
#include<stdio.h>

enum COLOR{RED, YELLOW, GREEN, NumCOLORS};
int main(int argc, char const *argv[])
{
    int color = -1;
    char *ColorNames[NumCOLORS] = {"red", "yellow", "green",};
    char *colorName  = NULL;
    printf("输入你喜欢的颜色的代码：");
    scanf("%d",&color);
    if( color >= 0 && color < NumCOLORS ){
        colorName = ColorNames[color];
    }else{
        colorName = "unknown";
    }
    printf("你喜欢的颜色是%s\n",colorName);
    return 0;
}
```

  **枚举量**

- 声明枚举量的时候可以指定值
  - enum COLOR{RED = 1, YELLOW, GREEN = 5};

## 11.2 结构

**声明结构类型**

```C
#include<stdio.h>

struct date{
    int month;
    int day;
    int year;
};
int main(int argc, char const *argv[])
{
    struct date today;
    
    today.month = 07;
    today.day = 31;
    today.year = 2014;
    
    printf("Today's date is %i-%i-%i.\n",today.year,today.month,today.day);
    
    return 0;
}

/*
和本地变量一样，在函数内部声明的结构类型只能在函数内部使用
所以通常在函数外部声明结构类型，这样就可以被多个函数所使用了
*/
```

**声明结构的形式**

![声明结构的形式](H:%5C%E6%88%91%E7%9A%84%E6%96%87%E4%BB%B6%5C%E5%AD%A6%E4%B9%A0%E7%9B%B8%E5%85%B3%5C%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0%5CC%5C%E5%A3%B0%E6%98%8E%E7%BB%93%E6%9E%84%E7%9A%84%E5%BD%A2%E5%BC%8F.png)

**结构的初始化**

```C
#include<stdio.h>

struct date{
    int month;
    int day;
    int year;
};
int main(int argc, char const *argv[])
{
    struct date today = {07,31,2014};
    struct date thismonth = {.month=7, .year=2014};//day没赋值，默认为0
    struct date *pDate = &today;
    printf("Today's date is %i-%i-%i.\n",today.year,today.month,today.day);
    printf("this month is %i-%i-%i.\n",thismonth.year,thismonth.month,thismonth.day);
    printf("address of today is %p\n",pDate);
    
    return 0;
}
```

**结构成员**

- 结构和数组有点像
- 数组用[]运算符和下标访问其成员，a[0]=10;
- 结构用 . 运算符和名字访问其成员
  - today.day
  - student.firstName

**结构运算**

- 要访问整个结构，直接用结构变量的名字
- 对于整个结构，可以做赋值、取地址，也可以传递给函数参数
  - p1 = (struct point){5,10};  //相当于p1.x = 5;p1.y = 10;
  - p1 = p2; //相当于p1.x = p2.x;p1.y = p2.y;
  - 数组无法做以上两种运算

**结构指针**

- 和数组不同，结构变量的名字并不是结构变量的地址，必须使用&运算符
- struct date *pDate = &today;

**结构作为函数参数**

`int numberOfDays(struct date d)`

- 整个结构可以作为参数的值传入函数
- 这时候是在函数内新建一个结构变量，并复制调用者的结构的值
- 也可以返回一个结构
- 这与数组完全不同

```c
#include<stdio.h>
#include<stdbool.h>

struct date{
    int month;
    int day;
    int year;
};

bool isLeap(struct date d);
int numberOfDays(struct date d);

int main(int argc, char const *argv[])
{
    struct date today,tomorrow;
    
    printf("Enter today's date(mm dd yyyy):");
    scanf("%i %i %i",&today.month,&today.day,&today.year);
    if( today.day != numberOfDays(today) ){
        tomorrow.day = today.day + 1;
        tomorrow.month = today.month;
        tomorrow.year = today.year;
    }else if( today.month == 12 ){
        tomorrow.day = today.day + 1;
        tomorrow.month = 1;
        tomorrow.year = today.year + 1;
    }else{
        tomorrow.day = 1;
        tomorrow.month = today.month + 1;
        tomorrow.year = today.year;
    }
    printf("Tomorrow's date is %i-%i-%i.\n",
          tomorrow.year,tomorrow.month,tomorrow.day);
    
    return 0;
}
int numberOfDays(struct date d)
{
    int days;
    const int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if( d.month == 2 && isLeap(d) )
        days = 29;
    else
        days = daysPerMonth[d.month-1];
    return days;
}
bool isLeap(struct date d)
{
    bool leap = false;
    if( (d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0 )
        leap = true;
    return leap;
}
```

**输入结构**

![输入结构](H:%5C%E6%88%91%E7%9A%84%E6%96%87%E4%BB%B6%5C%E5%AD%A6%E4%B9%A0%E7%9B%B8%E5%85%B3%5C%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0%5CC%5C%E8%BE%93%E5%85%A5%E7%BB%93%E6%9E%84.png)

![解决的方案](H:%5C%E6%88%91%E7%9A%84%E6%96%87%E4%BB%B6%5C%E5%AD%A6%E4%B9%A0%E7%9B%B8%E5%85%B3%5C%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0%5CC%5C%E8%A7%A3%E5%86%B3%E7%9A%84%E6%96%B9%E6%A1%88.png)

**指向结构的指针**

```C
struct date{
    int month;
    int day;
    int year;
} myday;

struct date *p = &myday;

(*p).month = 12;
p->month = 12;
//用->表示指针所指的结构变量中的成员
```

**结构指针参数**

```C
void main()
{
    struct point y = {0,0};
    inputPoint(&y);
    output(y);
}
struct point* inputPoint(struct point *p)
{
	scanf("%d",&(p->x));
    scanf("%d",&(p->y));
    return p;
}


#include<stdio.h>

struct point {
    int x;
    int y;
};

struct point* getStruct(struct point*);
void output(struct point);
void print(const struct point *p);

int main(int argc, char const *argv[])
{
    struct point y = {0,0};
    getStruct(&y);
    output(y);
    output(*getStruct(&y));
    print(getStruct(&y));
}

struct point* getStruct(struct point *p)
{
    scanf("%d",&p->x);
    scanf("%d",&p->y);
    printf("%d, %d",p->x, p->y);
    return p;
}
void output(struct point p)
{
    printf("%d, %d",p.x,p.y);
}
void print(const struct point *p)
{
    printf("%d, %d",p->x, p->y);
}
```

**结构数组**

- struct date dates[100];
- struct date dates[] = {{4,5,2005},{2,4,2005}};

**结构中的结构**

```c
struct dateAndTime{
    struct date sdate;
    struct time stime;
};

struct point{
    int x;
    int y;
};
struct rectangle{
    struct point pt1;
    struct point pt2;
};

如果有变量
    struct rectangle r;
就可以有:
	r.pt1.x, r.pt1.y
    r.pt2.x, r.pt2.y

如果有变量定义：
	struct rectangle r,*rp;
	rp = &r;
那么下面的四种形式是等价的：
    r.pt1.x
    rp->pt1.x
    (r.pt1).x
    (rp->pt1).x
但是没有rp->pt1->x（因为pt1不是指针）
    
```

**结构中的结构的数组**

![结构中的结构的数组](H:%5C%E6%88%91%E7%9A%84%E6%96%87%E4%BB%B6%5C%E5%AD%A6%E4%B9%A0%E7%9B%B8%E5%85%B3%5C%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0%5CC%5C%E7%BB%93%E6%9E%84%E4%B8%AD%E7%9A%84%E7%BB%93%E6%9E%84%E7%9A%84%E6%95%B0%E7%BB%84.png)

## 11.3 联合

**自定义数据类型（typedef）**

- C语言提供了一个叫做typedef的功能来声明一个已有的数据类型的新名字。比如：

  - typedef int Length;
  - 使得Length成为int类型的别名

- 这样，Length这个名字就可以代替int出现在变量定义和参数声明的地方了：

  - Length a,b,len;
  - Length numbers[10];

![typedef1](H:%5C%E6%88%91%E7%9A%84%E6%96%87%E4%BB%B6%5C%E5%AD%A6%E4%B9%A0%E7%9B%B8%E5%85%B3%5C%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0%5CC%5Ctypedef1.png)

![typedef2](H:%5C%E6%88%91%E7%9A%84%E6%96%87%E4%BB%B6%5C%E5%AD%A6%E4%B9%A0%E7%9B%B8%E5%85%B3%5C%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0%5CC%5Ctypedef2.png)

```C
#include<stdio.h>

typedef union{
	int i;
	char ch[sizeof(int)];
}CHI;

int main(int argc, char const *argv[])
{
	CHI chi;
	int i;
	chi.i = 1234;
	for( i=0; i<sizeof(int); i++ ){
		printf("%02hhX",chi.ch[i]);
	}
	printf("\n");
	
	return 0;
}
```

# 第十二周：程序结构

## 12.1 全局变量

- 定义在函数外面的变量是全局变量
- 全局变量具有全局的生存期和作用域
  - 它们与任何函数都无关
  - 在任何函数内部都可以使用它们

```C
#include<stdio.h>
int f(void);
int gAll = 12;

int main(int argc, char const *argv[])
{
    printf("int %s gAll=%d\n", _func_,gAll);
    f();
    printf("agn in %s gAll=%d\n", _func_, gAll);
    return 0;
}
int f(void)
{
    printf("in %s gAll=%d\n", _func_, gAll);
    gAll += 2;
    printf("in %s gAll-%d\n", _func_, gAll);
    return gAll;
}
```

**全局变量初始化**

- 没有做初始化的全局变量会得到0值
  - 指针会得到NULL值
- 只能用编译时刻已知的值来初始化全局变量
- 它们的初始化发生在main函数之前
- 如果函数内部存在与全局变量同名的变量，则全局变量被隐藏

```C
#include<stdio.h>
int f(void);
int gAll = 12;

int main(int argc, char const *argv[])
{
    printf("int %s gAll=%d\n", _func_,gAll);
    f();
    printf("agn in %s gAll=%d\n", _func_, gAll);
    return 0;
}
int f(void)
{
    int gAll = 1;
    printf("in %s gAll=%d\n", _func_, gAll);
    gAll += 2;
    printf("in %s gAll-%d\n", _func_, gAll);
    return gAll;
}
```

**静态本地变量**

- 在本地变量定义时加上static修饰符就成为静态本地变量
- 当函数离开的时候，静态本地变量会继续存在并保持其值
- 静态本地变量的初始化只会在第一次进入这个函数时做，以后进入函数时会保持上次离开时的值

```C
#include<stdio.h>
int f(void);
int gAll = 12;

int main(int argc, char const *argv[])
{
    f();
    f();
    f();
    return 0;
}
int f(void)
{
    int all =1    //不加static
    printf("in %s all=%d\n", _func_, all);
    all += 2;
    printf("in %s all-%d\n", _func_, all);
    return all;
}

#include<stdio.h>
int f(void);
int gAll = 12;

int main(int argc, char const *argv[])
{
    f();
    f();
    f();
    return 0;
}
int f(void)
{
    static int all =1  //加上static
    printf("in %s all=%d\n", _func_, all);
    all += 2;
    printf("in %s all-%d\n", _func_, all);
    return all;
}
```

- 静态本地变量实际上是特殊的全局变量
- 它们位于相同的内存区域
- 静态本地变量具有全局的生存期，函数内的局部作用域
  - static在这里的意思是局部作用域（本地可访问）

```C
#include<stdio.h>
int f(void);
int gAll = 12;
int main(int argc, char const *argv[])
{
    f();
    return 0;
}
int f(void)
{
    int k = 0;
    static int all =1;  //加上static,静态本地变量
    printf("&gAll=%p\n", &gAll);//全局变量
    printf("&all =%p\n", &all);//静态本地变量
    printf("&k   =%p\n", &k);//本地变量
    printf("in %s all=%d\n", _func_, all);
    all += 2;
    printf("in %s all-%d\n", _func_, all);
    return all;
}
```

***返回指针的函数**

- 返回本地变量的地址是危险的
- 返回全局变量或静态本地变量的地址是安全的
- 返回在函数内malloc的内存是安全的，但是容易造成问题
- 最好的做法是返回传入的指针

```C
//返回本地变量的地址是危险的
#include<stdio.h>
int* f(void);
void g(void);

int main(int argc, char const *argv[])
{
    int *p = f();
    printf("*p=%d\n", *p);
    g();
    printf("*p=%d\n", *p);
    
    return 0;
}

int* f(void)
{
    int i = 12;
    return &i;
}

void g(void)
{
    int k =24;
    printf("k=%d", k);
}
```

**tips**

- 不要使用全局变量来在函数间传递参数和结果
- 尽量避免使用全局变量
- *使用全局变量和静态本地变量的函数是线程不安全的

## 12.2 编译预处理和宏

**编译预处理指令**

- #开头的是编译预处理指令
- 它们不是C语言的成分，但是C语言程序离不开它们
- #define用来定义一个宏

**#define**

- #define<名字><值>
- **注意没有结尾的分号，因为不是C的语句**

- 名字必须是一个单词，值可以使各种东西
- 在C语言的编译器开始编译之前，编译预处理程序（cpp）会把程序中的名字换乘值
  - 完全的文本替换
- gcc --save-temps

**宏**

- 如果一个宏的值中有其他的宏的名字，也是会被替换的
- 如果一个宏的值超过一行，最后一行之前的行末需要加\
- 宏的值后面出现的注释不会被当作宏的值的一部分

```C
#include<stdio.h>

#define PI 3.14159
#define FORMAT "%f\n"
#define PI2 2*PI  // pi * 2
#define PRT printf("%f ", PI);\
			printf("%f\n", PI2)

int main(int argc, char const *argv[])
{
    printf(FORMAT,PI2*3.0);
    PRT;
    return 0;
}
```

**没有值的宏**

- #define _DEBUG
- 这类宏是用于条件编译的，后面有其他的编译预处理指令来检查这个宏是否已经被定义过了

**预定义的宏**

- \__LINE__
- \__FILE__
- \__DATE__
- \__TIME__
- \__STDC__

```c
#include<stdio.h>
int main(int argc, char const *argv[])
{
    printf("%s:%d\n", __FILE__, __LINE__);
    printf("%s,%s", __DATE__, __TIME__);
    return 0;
}
```

**带参数的宏**

- **像函数的宏**
  - #define cube(x) ((x)*(x)\*(x))
  - 宏可以带参数

```C
#include<stdio.h>
#define cube(x) ((x)*(x)*(x))

int main(int argc, char const *argv[])
{
    printf("%d\n", cube(5)); //cube(5)被替换为（（5）*（5）*（5））
    return 0;
}
```

- **错误定义的宏**
  - #define RADTODEG(x) (x*57.29578)
  - #define RADTODEG(x) (x)*57.29578

```C
#include<stdio.h>

#define RADTODEG1(x) (x*57.29578)
#define RADTODEG2(x) (x)*57.29578

int main(int argc, char const *argv[])
{
    printf("%f\n",RADTODEG1(5+2));//展开为5+2*57.29578
    printf("%f\n",180/RADTODEG2(1));//展开为180/(1) * 57.29578
    return 0;
}
```

- **带参数的宏的原则**
  - 一切都要括号
    - 整个值要括号
    - 参数出现的每个地方都要括号
  - #define RADTODEG(x) ((x) * 57.29578)
- **带参数的宏**
  - 可以带多个参数
    - #define MIN(a,b) ((a)>(b)?(b):(a))  //外围有括号，里面所以参数都有括号
  - 也可以组合（嵌套）使用其他宏
  - 在大型程序的代码中使用非常普遍
  - 可以非常复杂，如“产生”函数
    - 在#和##这两个运算符的帮助下
  - 存在中西方文化差异
  - 部分宏会被inline函数替代

## 12.3 大程序结构

**项目**

- 在Dev C++中新建一个项目，然后把几个源代码文件加入进去
- 对于项目，Dev C++的编译会把一个项目中所有的源代码文件都编译后，链接起来
- 有的IDE有分开的编译和构建两个按钮，前者是对单个源代码文件编译，后者是对整个项目做链接

**编译单元**

- 一个.c文件是一个编译单元
- 编译器每次编译只处理一个编译单元

**头文件**

- 把函数原型放到一个头文件（以.h结尾）中，在需要调用这个函数的源代码文件（.c文件）中#include这个头文件，就能让编译器在编译的时候知道函数的原型
- 在使用和定义这个函数的地方都应该有#include这个头文件
- 一般的做法就是任何.c都有对应的同名的.h，把所有对外公开的函数的原型和全局变量的声明都放进去

**不对外公开的函数**

- 在函数前面加上static就使得它成为只能在所在的编译单元中使用的函数
- 在全局变量前面加上static就使得它成为只能在所在的编译单元中被使用的全局变量

**#include**

- #include是一个编译预处理指令，和宏一样，在编译之前就处理了
- 它把那个文件的全部文本内容原封不动地插入到它所在的地方
  - 所以也不是一定要在.c文件的最前面#include

**“ ”还是<>**

- #include有两种形式来指出要插入的文件
  - “ ”要求编译器首先在当前目录（.c文件所在的目录）寻找这个文件，如果没有，到编译器指定的目录去找
  - <>让编译器只在指定的目录去找
- 编译器自己知道自己的标准库的头文件在哪里
- 环境变量和编译器命令行参数也可以指定寻找头文件的目录

**#include的误区**

- #include不是用来引入库的
- stdio.h里只有printf的原型，printf的代码在另外的地方，某个.lib（Windows）或.a(Unix)中
- 现在C语言编译器默认会引入所有的标准库
- #include<stdio.h>只是为了让编译器知道printf函数的原型，保证你调用时给出的参数值是正确的类型

**声明**

**变量的声明**

- int i;是变量的定义
- extern int i;是变量的声明

**声明和定义**

- 声明是不产生代码的东西
  - 函数原型、变量声明、结构声明、宏声明、枚举声明、类型声明、inline函数

- 定义是产生代码的东西

**头文件**

- 只有声明可以被放在头文件中
  - 是规则不是法律
- 否则会造成一个项目中多个编译单元里有重名的实体
  - *某些编译器允许几个编译单元中存在同名的函数，或者用weak修饰符来强调这种存在

**重复声明**

- 同一个编译单元里，同名的结构不能被重复声明
- 如果你的头文件里有结构的声明，很难这个头文件不会在一个编译单元里被#include多次
- 所以需要“标准头文件结构”

**标准头文件结构**

```C
#ifndef __LIST_HEAD__
#define __LIST_HEAD__

#include "node.h"

typedef struct _list{
    Node* head;
    Node* tail;
}List;

#
```

- 运用条件编译和宏，保证这个头文件在一个编译单元中只会被#include一次
- #pragma once也能起到相同的作用，但是不是所有的编译器都支持

***前向声明**

```C
#ifndef __LIST_HEAD__
#define __LIST_HEAD__

struct Node;

typedef struct _list{
    struct Node* head;
    struct Node* tail;
}List;

#endif
```

- 因为在这个地方不需要具体知道Node是怎样的，所以可以用struct Node来告诉编译器Node是一个结构

# 第十三周：文件

## 13.1 文件

**格式化输入输出**

- printf
  - %[flags]\[width][.prec]\[hlL]type

|  Flag   |     含义     |
| :-----: | :----------: |
|    -    |    左对齐    |
|    +    | 在前面放+或- |
| (space) |   正数留空   |
|    0    |    0填充     |

```C
#include<stdio.h>

int main(int argc, char const *argv[])
{
    printf("%+09d\n",123);
    printf("%-9d\n",123);
    
    return 0;
}
```

| width或prec |            含义            |
| :---------: | :------------------------: |
|   number    |         最小字符数         |
|      *      |     下一个参数是字符数     |
|   .number   |       小数点后的位数       |
|     .*      | 下一个参数是小数点后的位数 |

```C
#include<stdio.h>

int main(int argc, char const *argv[])
{
    printf("%*d\n",6,123);//输出占6个字符
    printf("%9.2f\n",123.0);//输出占9个字符，其中小数占两位
    return 0;
}
```

| 类型修饰 |    含义     |
| :------: | :---------: |
|    hh    |  单个字节   |
|    h     |    short    |
|    l     |    long     |
|    ll    |  long long  |
|    L     | long double |

```C
#include<stdio.h>

int main(int argc, char const *argv[])
{
    printf("%hhd\n",12345);
    printf("%9.2f\n",123.0);
    return 0;
}
```

| type |        用于        | type |      用于       |
| :--: | :----------------: | :--: | :-------------: |
| i或d |        int         |  g   |      float      |
|  u   |    unsigned int    |  G   |      float      |
|  o   |       八进制       | a或A |  十六进制浮点   |
|  x   |      十六进制      |  c   |      char       |
|  X   | 字母大写的十六进制 |  s   |     字符串      |
| f或F |      float,6       |  p   |      指针       |
| e或E |        指数        |  n   | 读入/写出的个数 |

```C
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int num;
    printf("%*dty%n\n",12345,&num);//输出占6个字符
    printf("%d\n",num);
    return 0;
}
```

- scanf
  - %[flag]type

| flag |    含义    | flag |    含义     |
| :--: | :--------: | :--: | :---------: |
|  *   |    跳过    |  l   | long,double |
| 数字 | 最大字符数 |  ll  |  long long  |
|  hh  |    char    |  L   | long double |
|  h   |   short    |      |             |

```C
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    scanf("%*d%d",&num);
    printf("%d\n",num);
    return 0;
}
```

|  type   |             用于             | type  |      用于      |
| :-----: | :--------------------------: | :---: | :------------: |
|    d    |             int              |   s   | 字符串（单词） |
|    i    | 整数，可能为十六进制或八进制 | [...] |  所允许的字符  |
|    u    |         unsigned int         |   p   |      指针      |
|    o    |            八进制            |       |                |
|    x    |           十六进制           |       |                |
| a,e,f,g |            float             |       |                |
|    c    |             char             |       |                |

**printf和scanf的返回值**

- 输出的字符数
- 读入的项目数
- 在要求严格的程序中，应该判断每次调用scanf或printf的返回值，从而了解程序运行中是否存在问题

```C
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    int i1 = scanf("%i", &num);
    int i2 = printf("%d\n", num);
    printf("%d:%d\n", i1, i2);
    return 0;
}
```

**文件输入输出**

**FILE**

- FILE* fopen(const char* restrict path, const char* restrict mode);

- int fclose(FILE *stream);

- fscanf(FILE*,...)

- fprintf(FILE*,...)

- 打开文件的标准代码

- ```C
  FILE* fp = fopen("file","r");//fopen有两个参数
  if(fp){
      fscanf(fp,...);
      fclose(fp);
  }else{
      ...
  }
  
  //example
  #include<stdio.h>
  int main(int argc, char const *argv[])
  {
      FILE *fp = fopen("12.in","r");
      if( fp ){
          int num;
          fscanf(fp, "%d", &num);
          printf("%d\n", num);
          fcolse(fp);
      }else{
          printf("无法打开文件\n");
      }
      return 0;
  }
  ```

|  r   | 打开只读                                           |
| :--: | -------------------------------------------------- |
|  r+  | 打开读写，从文件头开始                             |
|  w   | 打开只写。如果不存在则新建，如果存在则清空         |
|  w+  | 打开读写。如果不存在则新建，如果存在则清空         |
|  a   | 打开追加。如果不存在则新建，如果存在则从文件尾开始 |
| ..x  | 只新建，如果文件已存在则不能打开                   |

**二进制文件**

- 其实所有的文件最终都是二进制的
- 文本文件无非是用最简单的方式可以读写的文件
  - more、tail
  - cat
  - vi
- 而二进制文件是需要专门的程序来读写的文件
- 文本文件的输入输出是格式化，可能经过转码

**文本vs二进制**

- 文本的优势是方便人类读写，而且跨平台
- 文本的缺点是程序输入输出要经过格式化，开销大
- 二进制的缺点是人类读写困难，而且不跨平台
  - int的大小不一致，大小端的问题...
- 二进制的优点是程序读写快

**二进制读写**

- size_t fread(void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
- size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
- 注意FILE指针是最后一个参数
- 返回的是成功读写的字节数
- 为什么用nitem?
  - 因为二进制文件的读写一般都是通过对一个结构变量的操作来进行的
  - 于是nitem就是用来说明这次读写几个结构变量

**在文件中定位**

- long ftell(FILE *stream);
- int fseek(FILE *stream, long offset, int whence);
  - SEEK_SET: 从头开始
  - SEEK_CUR: 从当前位置开始
  - SEEK_END: 从尾开始（倒过来）

**可移植性**

- 这样的二进制文件不具有可移植性
  - 在int为32位的机器上写成的数据文件无法直接在int为64位的机器上正确读出
- 解决方案之一是放弃使用int，而是typedef具有明确大小的类型
- 更好的方案是用文本

## 13.2 位运算

|  &   |  按位的与  |
| :--: | :--------: |
|  \|  |  按位的或  |
|  ~   |  按位取反  |
|  ^   | 按位的异或 |
|  <<  |    左移    |
| \>>  |    右移    |

**按位与&**

- 如果（x）~i~ == 1并且（y）~i~==1，那么（x & y）~i~=1
- 否则的话（x & y）~i~=0
- 按位与常用于两种应用
  - 让某一位或某些位为0：x & 0xFE
  - 取一个数中的一段：x & 0xFF

**按位或|**

- 如果（x）~i~=\=1或（y） ~i~==1，那么（x | y）~i~=1
- 否则的话，（x | y）~i~==0
- 按位或常用于两种应用：
  - 使得一位或几个位为1：x | 0x01
  - 把两个数拼起来： 0x00FF | 0xFF00

**按位取反~**

- （\~x）~i~ = 1 - （x）~i~
- 把1位变0，0位变1
- 想得到全部位为1的数：~0
- 7的二进制是0111，x | 7使得低三位为1，而
- x & ~7，就使得低三位为0

**逻辑运算vs按位运算**

- 对于逻辑运算，它只看到两个值：0和1
- 可以认为逻辑运算相当于把所有非0值都变成1，然后做按位运算
  - 5 & 4——>4而 5 && 4——> 1 & 1——>1
  - 5 | 4——>5而 5 || 4——> 1 | 1——>1
  - ~4——>3而！4——>!1——>0

**按位异或^**

- 如果（x）~i~ ==（y）~i~，那么（x ^ y）~i~ = 0
- 否则的话，（x ^ y）~i~ ==1
- 如果两个位相等，那么结果为0；不相等，结果为1
- 如果x和y相等，那么x^y的结果为0
- 对一个变量用同一个值异或两次，等于什么也没做
  - x\^y^y ---->x

**移位运算**

- **左移<<**
  - i << j
  - i中所有的位向左移动j个位置，而右边填入0
  - 所有小于int的类型，移位以int的方式来做，结果是int
  - x <<= 1 等价于 x *= 2
  - x <<= n 等价于x *= 2^n^
- **右移>>**
  - i >> j
  - i中所有的位向右移j位
  - 所有小于int的类型，移位以int的方式来做，结果是int
  - 对于unsigned的类型，左边填入0
  - 对于signed的类型，左边填入原来的最高位（保持符号不变）
  - x >>= 1 等价于 x /= 2
  - x >>= n 等价于 x /= 2^n^
- 移位的位数不要用负数，这是没有定义的行为
  - x << -2   //NO

**位运算例子**

```C
//输出一个数的二进制
#include<stdio.h>
int main(int argc, char const *argv[])
{
    int number;
    scanf("%d",&number);
    unsigned mask = 1u<<31;
    for( ; mask; mask >>= 1 ){
        printf("%d",number & mask?1:0);
    }
    printf("\n");
    
    return 0;
}
```

**位段**

```C
//把一个int的若干位组合成一个结构
struct{
    unsigned int leading : 3;
    unsigned int FLAG1: 1;
    unsigned int FLAG2: 1;
    int trailing: 11;
};
```



- 可以直接用位段的成员名称来访问
  - 比移位、与、或还方便
- 编译器会安排其中的位的排列，不具有可移植性
- 当所需的位超过一个int时会采用多个int

# 第十四周：链表

## 14.1 可变数组

```C
----------------------------array.h--------------------------------------------------
#ifndef _ARRAY_H_
#define _ARRAY_H_

typedef struct{
    int *array;
    int size;
}Array;

Array array_create(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a, int index);
void array_inflate(Array *a, int more_size);

#endif
-----------------------------array.c-------------------------------------------------
#include "array.h"
#include<stdio.h>
#include<stdlib.h>
    
const BLOCK_SIZE = 20;
  
//typedef struct{
//    int *array;
//    int size;
//}Array;

Array array_create(int init_size)
{
    Array a;
    a.size = init_size;
    a.array = (int*)malloc(sizeof(int)*a.size);
    return a;
}

void array_free(Array *a)
{
    free(a->array);
    a->array = NULL;
    a->size = 0;
}
//封装
int array_size(const Array *a)
{
    return a->size;
}
int* array_at(Array *a, int index)
{
    if( index >= a->size ){
        array_inflate(a, (index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
    }
    return &(a->array[index]);
}
void array_inflate(Array *a, int more_size)
{
    int *p = (int*)malloc(sizeof(int)*(a->size + more_size));
    int i;
    for( i=0; i<a->size; i++ ){
        p[i] = a->array[i];
    }
    free(a->array);
    a->array = p;
    a->size += more_size;
}

int main(int argc, char const *argv[])
{
    Array a = array_create(100);
    printf("%d\n", array_size(&a));
    *array_at(&a,0) = 10;
    printf("%d\n",*array_at(&a,0));
    int number = 0;
    int cnt = 0;
    while(number != -1){
        scanf("%d",&number);
        if( number != -1)
            *array_at(&a, cnt++) = number;
    }
    array_free(&a);
    
    return 0;
}
```

## 14.2 链表

**可变数组的缺陷**

- Allocate new memmory each time it inflates is an easy and clean way. But, it takes time to copy, and may fail in memory restricted situation.

==**链表**==

```C
---------------------------------node.h----------------------------------------------
#ifndef _NODE_H_
#define _NODE_H_
    
typedef struct _node{
    int value;
    struct _node *next;
}Node;
#endif

--------------------------------linked-list.c----------------------------------------
#include "node.h"
#include<stdio.h>
#include<stdlib.h>

//typedef struct _node{
//    int value;
//    struct _node *next;
//}Node;
typedef struct _list{
    Node* head;
}List;
void add(Node*head, int number);
void print(List *pList);
    
int main(in argc, char const *arv[])
{
    List list;
    int number;
    list.head = NULL;
    do{
        scanf("%d",&number);
        if( number != -1 ){
            add(&list, number);
        }
    }while( number != -1);
    //遍历输出各节点的值
    print(&list);
    //链表的删除
    scanf("%d", &number);
    Node *p;
    int isFound = 0;
    for( p=list.head; p; p=p->next){
        if( p->value == number ){
            printf("找到了\n");
            isFound = 1;
            break;
        }
    }
    if( !=isFound ){
        printf("没找到\n")
    }
    Node *p;
    for( q=NULL, p=list.head; p; q=p,p=p->next ){
        if( p->value == number ){
            if( q ){
                q->next = p->next;
            }else{
                list.head = p->next;
            }
            free(p);
            break;
        }
    }
    //链表的清除
    for( p=head; p; p=q ){
        q = p->next;
        free(p);
    }
    return 0;
}

void add(List* pList, int number)
{
//add to linked-list,将得到的数加到链表记录
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	//find the last
	Node *last = pList->head;
	if( last ){
		while( last->next ){
			last = last->next;
		}
		//attach
		last->next = p;
	}else{
		pList->head = p;
	}
}

void print(List *pList)
{
	Node *p;
    for( p=pList->head; p; p= p->next){
        printf("%d\t", p->value);
    }
    printf("\n");
}
```

**How do we find the boundary?**

==Any pointer at the left of -> must be checked.==

