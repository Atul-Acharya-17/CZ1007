#include <stdio.h>
float rPower1(float num, int p);
void rPower2(float num, int p, float *result);
int main()
{
 int power;
 float number, result;

 printf("Enter the number and power: \n");
 scanf("%f %d", &number, &power);
 printf("rPower1(): %.2f\n", rPower1(number, power));
 rPower2(number, power, &result);
 printf("rPower2(): %.2f\n", result);
 return 0;
}
float rPower1(float num, int p)
{
 if(p==0)
    return 1;
 if(p>=1)
 {
     if(p==1)
    return num;
 else
    return num*rPower1(num,p-1);
 }
 else
 {
     if(p==-1)
        return 1/num;
     else
        return 1/num*rPower1(num,p+1);
 }
}
void rPower2(float num, int p, float *result)
{
 int n = (p>0)?p:(-p);
 if(n==0)
    *result = 1;
 else if(n==1)
    *result = num;
 else
 {
    rPower2(num,n-1,result);
    *result *= num;
 }
if(p<0)
    *result = 1/(*result);
}
