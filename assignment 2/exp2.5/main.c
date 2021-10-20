#include <stdio.h>
int platform1D(int ar[], int size);
int main()
{
 int i,b[50],size;
 printf("Enter array size: \n");
 scanf("%d", &size);
 printf("Enter %d data: \n", size);
 for (i=0; i<size; i++)
 scanf("%d",&b[i]);
 printf("platform1D(): %d\n", platform1D(b,size));
 return 0;
}
int platform1D(int ar[], int size)
{
 int length = 1;
 int largest = 1;
 int i;
 for(i=0;i<size;i++)
 {
     if(ar[i]== ar[i+1])
        ++length;

     else
     {
         if(length>largest)
            largest = length;
         length =1;
     }
 }
 return largest;
}
