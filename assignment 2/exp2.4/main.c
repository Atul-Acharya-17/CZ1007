#include <stdio.h>
void specialNumbers1D(int ar[], int num, int *size);
int main()
{
 int a[20],i,size=0,num;

 printf("Enter a number (between 100 and 999): \n");
 scanf("%d", &num);
 specialNumbers1D(a, num, &size);
 printf("specialNumbers1D(): ");
 for (i=0; i<size; i++)
 printf("%d ",a[i]);
 return 0;
}
void specialNumbers1D(int ar[], int num, int *size)
{
 int check;
 for(check = 100; check<=num;check++)
 {
     int temp = check;
     int sum = 0;
     int remainder;
     while(temp!=0)
     {
         remainder = temp%10;
         temp = temp/10;
         sum = sum + (remainder * remainder * remainder);

     }
     if(sum==check)
     {
         ar[*size]=check;
         (*size)++;
     }
 }
}
