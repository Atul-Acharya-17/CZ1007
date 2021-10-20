#include <stdio.h>
#include<math.h>
int reverseDigits1(int num);
void reverseDigits2(int num, int *result);
int main()
{
 int num, result=999;
 printf("Enter a number: \n");
 scanf("%d", &num);
 printf("reverseDigits1(): %d\n", reverseDigits1(num));
 reverseDigits2(num, &result);
 printf("reverseDigits2(): %d\n", result);
 return 0;
}
int reverseDigits1(int num)
{
 int base = 1;
 int remainder ;
 int reverse = 0;
 int temp = num;
 while(temp!=0)
 {
   temp/=10;
   base*=10;
 }

 while(num!=0)
 {
    base/=10;
    remainder = num%10;
    reverse = reverse + remainder*base;
    num/=10;
 }
return reverse;
}
void reverseDigits2(int num, int *result)
{
 int base = 1;
 int remainder;
 *result = 0;
 int temp = num;
 while(temp!=0)
 {
   temp/=10;
   base*=10;
 }

 while(num!=0)
 {
    base/=10;
    remainder = num%10;
    *result = *result + remainder*base;
    num/=10;
 }
}
