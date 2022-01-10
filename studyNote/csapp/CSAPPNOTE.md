[toc]
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
> 参考德摩根律，$ \overline{A \cup B} =  \bar{A} \cap \bar{B}, \overline{A \cap B} =  \bar{A} \cup \bar{B}$
$A \oplus B = \overline{\bar{A}B \cup A\bar{B}} = \overline{\bar{A}\bar{B}} \cap \overline{AB}$
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
    int a = !(x >> 4 ^ 0x3);//判断是否为3
    int b = x&0xF;          //取后四位
    int c = ~0xA + 1;       //-A
    int e = 0x80 << 8;
    int d = !!((b+c)&(e));  //判断是否为负数
    return a & d;
}
```
## 1.7 conditional
* 题目描述
```
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
```
* 思路
> 1、如何判断x非0？x为0时，其位表示为全0，考虑当x非0时，使其位表示为全1，具体操作如下
>> * `!!x`运算，若x为0，则结果为0，若x非0，则结果为1，对结果求补码则可实现全0或全1表示
* 代码
```c++
int conditional(int x, int y, int z){
    x = !!x;
    x = ~x + 1;
    return (x&y)|(~x&z);
}
```
## 1.8 isLessOrEqual
* 题目描述
```
* isLessOrEqual - if x <= y  then return 1, else return 0 
*   Example: isLessOrEqual(4,5) = 1.
*   Legal ops: ! ~ & ^ | + << >>
*   Max ops: 24
*   Rating: 3
*/
```
* 思路
> 1. `x<=y -> y-x >= 0`，很容易想到利用该不等式来进行判断，但要注意的是直接进行`x-y`运算很可能会溢出
>>关于如何检测补码加法中的溢出可参考CSAPP教材P65，即令s = x + y, 当且仅当x > 0, y > 0, 但s ≤ 0时，计算s发生了正溢出。当且仅当x < 0, y < 0, 但s ≥ 0时, 计算s发生了负溢出。
> 2. 考虑下面两种情况
>>* y - x >= 0, 即结果的最高位为0，flag = y + (~x + 1) >> 31 = 0，当且仅当y < 0, x > 0时发生负溢出
>>* y - x < 0, 则flag = 1，当且仅当y > 0, x < 0 时发生正溢出
* 代码
```c++
int isLessOrEqual(int x, int y){
    int a = x >> 31 & 0x1;    //取x符号位
    int b = y >> 31 & 0x1;    //取y符号位
    int f1 = (a & ~b);        //f1为1则表示x < 0, y > 0
    int f2 = (~a & b);        //f2为1则表示x > 0, y < 0
    int ret = ((y + (~x + 1)) >> 31;//计算y-x并取符号位
    ret = f1 | (!ret & !f2);
    return ret;
}

int isLessOrEqual(int x, int y){
    int diff_sgn = !(x>>31)^!(y>>31); //x, y符号不同时取1
    int a = diff_sgn & (x >> 31);     //符号不同且x < 0时取1，否则取0
    int b = !diff_sgn & !((y + (~x + 1))>>31);//符号相同且差值为小于0时取1
    int f = a | b
    return f;
}
```
## 1.9 logicalNeg
* 题目描述
```
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
```
* 思路
> 原理可见CSAPP教材P66补码的非，注意0和最小数的补码是其本身。除0和最小数之外，其余数与其非均是互为相反数，即符号位取位或结果为1。0的符号位与其补码的非位或结果为0，最小数与其补码的非位或结果为1。利用该性质可区分x != 0。
* 代码
```c++
int logicalNeg(int x){
    return ((x | (~x + 1)) >> 31) + 1; //注意，算术右移在左端补k个最高有效位
}
```
## 1.10 howManyBits
* 题目描述
```
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
```
* 思路
> 关键在于如何找出为1的最高位是第几位，再加上符号位，结果为n+1。对于负数，则需要找出其为0的最高位是第几位，对其取反后就和正数一样了，建议纸上模拟下。
* 代码
```c++
int howManyBits(int x){
    int b16, b8, b4, b2, b1, b0;
    int sign = x >> 31;
    x = (sign & ~x) | (~sign & x);//如果x为正则不变，否则按位取反，排除符号位对找最高位为1的干扰

    b16 = !!(x >> 16) << 4;       //高16位是否有1，有则b16 = 16
    x = x >> b16;                 //如果高16位有1，则至少需要16位，将原数右移16位
    b8 = !!(x >> 8) << 3;         //剩余位高8位是否有1
    x = x>>b8;                    //如果有（至少需要16+8=24位），则右移8位
    b4 = !!(x >> 4) << 2;         //同理
    x = x>>b4;
    b2 = !!(x >> 2) << 1;
    x = x >> b2;
    b1 = !!(x >> 1);
    x = x >> b1;
    b0 = x;
    return b16 + b8 + b4 + b2 + b1 + b0 + 1;//最后加上符号位
}
```
## 1.11 floatScale2
* 题目描述
```
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
```
* 思路
> 关于单精度标准浮点格式可参考CSAPP教材P78。位31：最高位为符号位、位23-31：阶码位、位0-22：尾数位。
* 代码
```c++
unsigned floatScale2(unsigned uf){
    unsigned exp = (uf & 0x7f800000) >> 23;
    unsigned sign = uf>>31 & 0x1;
    unsigned frac = uf & 0x7FFFFF;
    unsigned res;
    if(exp==0xFF)return uf;
    else if(exp==0){
        frac <<= 1;
        res = (sign << 31) | (exp << 23) | frac;
    }
    else{
        exp++;
        res = (sign << 31) | (exp << 23) | frac;
    }
    return res;
}
```
## 1.12 floatFloat2Int
* 题目描述
```
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
```
* 思路
> 解题思路可参考CSAPP教材P82练习题2.48
> 1. 若浮点数为0或小于则直接返回0（非规格化数）
> 2. 若exp=255则直接返回0x80000000u，还需要注意的是如果超出范围了也要返回0x80000000u，即当E>31时，frac部分是大于等于1的，1<<31位会覆盖符号位。
> 3. 其余情况（规格化数）：首先将frac部分补充上省略的1，接着需要判断是否溢出，当E<23时，右移(23-E)位，否则左移(E-23)位。
* 代码
```c++
int floatFloat2Int(unsigned uf) {
    unsigned exp = (uf&0x7f800000) >> 23;
    int sign = uf >> 31 & 0x1;
    unsigned frac = uf & 0x7FFFFF;
    int E = exp -127;
    if(E < 0)return 0;
    else if(E >= 31){
        return 0x80000000u;
    }
    else{
​
        frac = frac | 1 << 23;
        if(E < 23) {//需要舍入
            frac >>= (23 - E); //去掉末尾多余的0
        }else{
            frac <<= (E - 23); //左移超出23位部分
        }
​
    }
    if (sign)
        return -frac;
    else
        return frac;
}
```
## 1.13 floatPower2
* 题目描述
```
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
```
* 思路
> 1. 阶码位全为0，即非规格数
2^-149的二进制表示为0|00000000|00000000000000000000001 `//min`
2^-148的二进制表示为0|00000000|00000000000000000000010
2^-147的二进制表示为0|00000000|00000000000000000000100
……
2^-129的二进制表示为0|00000000|00100000000000000000000
2^-128的二进制表示为0|00000000|01000000000000000000000
2^-127的二进制表示为0|00000000|10000000000000000000000 `//max`
> 2. 阶码非0且不全为1，即规格数
2^-126的二进制表示为0|00000001|00000000000000000000000 `//min`
2^-125的二进制表示为0|00000010|00000000000000000000000
2^-124的二进制表示为0|00000011|00000000000000000000000
……
2^0 的二进制表示为0|01111111|00000000000000000000000
2^1 的二进制表示为0|10000000|00000000000000000000000
……
2^127 的二进制表示为0|11111110|00000000000000000000000 `//max`
> 3. 无穷大，即阶码位全为1
0|11111111|00000000000000000000000

* 代码
```c++
unsigned floatPower2(int x) {
    //无穷大
    if(x>127)   
    {
        return 0xFF<<23;
    }
    //
    else if(x<-149)return 0;
    //规格数
    else if(x>=-126)    
    {
        int exp = x + 127;//E = exp - 127
        return (exp << 23);
    } 
    else
    {
        int t = 149 + x;
        return (1 << t);
    }
}
```
# CSAPP LAB2: Bomb!