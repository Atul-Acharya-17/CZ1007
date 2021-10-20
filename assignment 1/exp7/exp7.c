#include <stdio.h>
float power1(float num, int p);
void power2(float num, int p, float *result);
int main()
{
 int power;
 float number, result=-1;

 printf("Enter the number and power: \n");
 scanf("%f %d", &number, &power);
 printf("power1(): %.2f\n", power1(number, power));
 power2(number,power,&result)
 printf("power2(): %.2f\n", result);

 int x;
 char y;
 printf("Hi\n")
 scanf("%d%c", &x &y)
 printf("%d : %c",x,y)

 return 0;
}
float power1(float num, int p)
{
 float answer = 1;
 int exponent = (p>0)?p:-1*p;

 for(int i=1; i<=exponent ; i++)
 {
   answer*=num;
 }
 if(p > 0)
    return answer;
 else
    return (1.0/answer);
}
void power2(float num, int p, float *result)
{
 float answer = 1;
 int exponent = (p>0)?p:-1*p;

 for(int i=1; i<=exponent ; i++)
 {
   answer*=num;
 }
 if(p>0)
    *result=answer;
 else
    *result= (1.0/answer);
}
