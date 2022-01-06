# CSAPP LAB1: DataLab
## 1.1 bitXor(x, y)
* 题目描述
```
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
```
* 思路
> **待整理**
* 代码
```c++
int bitXor(int x, int y) {
  return ~(~x&~y)&~(x&y);
}
```
## 1.2 tmin
* 题目描述
```
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
```
* 思路
> C语言中`int`类型是四字节32位。补码的tmin就是符号位即最高位为1，其余位为0，所以将0x1左移31位即可。
* 代码
```c++
int tmin(void) {
  return 0x1<<31;
}
```
## 1.3 isTmax(x)
* 题目描述
```
/* isTmax - returns 1 if x is the maximum, two's complement number,
*     and 0 otherwise 
*   Legal ops: ! ~ & ^ | +
*   Max ops: 10
*   Rating: 1
*/
```
* 思路
> 补码最大值tmax即符号位为0，其余位全为1，若考虑8位的补码最大值，即0111 1111，将tmax加1后得1000 0000，再取反得0111 1111即tmax本身。因题目不允许使用=，故需利用其它手段进行判断。这里可利用tmax^tmax=0，即自己与自己做异或运算得0的性质来判断是否为补码最大值，即`!((~(x+1)^x))`为1即是最大值。要注意得是，`x = -1`，即`-1=1111 1111`也满足上面的判断式，故要针对-1进行特殊处理，可利用`!!(x+1)`对-1和tmax进行区分。
* 代码
```c++
int isTmax(int x) {

  return !((~(x+1)^x))&!!(x+1);
}
```
## 1.4 allOddBits
* 题目描述
```
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
```
* 思路
> 只需判断`x & 0xAAAAAAAA == 0xAAAAAAAA`即可，其中`==`可用`!(a^b)`代替
* 代码
```c++
int allOddBits(int x){
    int a = 0xAA << 8;
    int b = a | 0xAA;
    int c = b << 16 | b;
    return !((x&c)^(c));
}
```
## 1.5 negate
* 题目描述
```
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
```
* 思路
> 由`x + ~x = -1`及`x + (-x) = 0`，得`-x = ~x + 1`.
* 代码
```c++
int negate(int x){
    return ~x+1 ;
}
```
## 1.6 isAsciiDigit
* 题目描述
```
* isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
*   Example: isAsciiDigit(0x35) = 1.
*            isAsciiDigit(0x3a) = 0.
*            isAsciiDigit(0x05) = 0.
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 15
*   Rating: 3
*/
```
* 思路
> 观察0x30\~0x39可发现，前四位必须为3，即0011，将x>>4后与0x3做异或运算可实现判断。后四位必须位于0\~9，可通过下述操作进行判断  
>> 1. 对后四位做`- 0xA`运算，判断结果是否为负数
>> 2. 将计算结果与0x8000做与运算可判断是否为负数

* 代码
```c++
int isAsciiDigit(int x){
    int a = !(x >> 4 ^ 0x3);
    int b = x&0xF;      //取后四位
    int c = ~0xA + 1;   //-A
    int e = 0x80 << 8;
    int d = !!((b+c)&(e));
    return a & d;
}
```
## 1.7 conditional
* 题目描述
```

```
* 思路
> 
* 代码
```c++

```
## 1.8 isLessOrEqual
* 题目描述
```

```
* 思路
> 
* 代码
```c++

```
## 1.9 logicalNeg
* 题目描述
```

```
* 思路
> 
* 代码
```c++

```
## 1.10 howManyBits
* 题目描述
```

```
* 思路
> 
* 代码
```c++

```
## 1.11 floatScale2
* 题目描述
```

```
* 思路
> 
* 代码
```c++

```
## 1.12 floatFloat2Int
* 题目描述
```

```
* 思路
> 
* 代码
```c++

```
## 1.13 floatPower2
* 题目描述
```

```
* 思路
> 
* 代码
```c++

```