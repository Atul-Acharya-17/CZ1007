#include <stdio.h>
#include <math.h>
#define INIT_VALUE 999
int extEvenDigits1(int num);
void extEvenDigits2(int num, int *result);
int main()
{
 int number, result = INIT_VALUE;

 printf("Enter a number: \n");
 scanf("%d", &number);
 printf("extEvenDigits1(): %d\n", extEvenDigits1(number));
 extEvenDigits2(number, &result);
 printf("extEvenDigits2(): %d\n", result);
 return 0;
}
int extEvenDigits1(int num)
{
 int base = 1;
 int remainder;
 int even = 0;
 while(num!=0)
 {
    remainder=num%10;
    if(remainder%2==0)
    {
        even+= remainder*base;
        base*=10;
    }
    num/=10;
 }
 if(base!=1)
    return even;
 else
    return -1;
}
void extEvenDigits2(int num, int *result)
{
 *result=0;
 int remainder;
 int base=1;
 while(num!=0)
 {
    remainder=num%10;
    if(remainder%2==0)
    {
        *result= *result + remainder*base;
        base*=10;
    }
    num/=10;
 }
 if(base==1)
    *result = -1;
}
