#include <stdio.h>
#include <string.h>
void maxCharToFront(char *str);
int main()
{
 char str[80], *p;
 printf("Enter a string: \n");
 fgets(str, 80, stdin);
 if (p=strchr(str,'\n')) *p = '\0';
 printf("maxCharToFront(): ");
 maxCharToFront(str);
 puts(str);
 return 0;
}
void maxCharToFront(char *str)
{
 char largest=str[0];
 int i = 0;
 int pos=0;
 for(i;str[i]!='\0';i++)
 {
     if((int)str[i]>(int)(largest))
     {
         largest = str[i];
         pos=i;
     }

 }

i = pos;
for(i;i>0;i--)
{
    str[i]=str[i-1];
}
str[0]=largest;
}
