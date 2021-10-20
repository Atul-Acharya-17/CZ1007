#include <stdio.h>
#include <string.h>
void insertChar(char *str1, char *str2, char ch);
int main()
{
 char a[80],b[80];
 char ch, *p;

 printf("Enter a string: \n");
 fgets(a, 80, stdin);
 if (p=strchr(a,'\n')) *p = '\0';
 printf("Enter a character to be inserted: \n");
 ch = getchar();
 insertChar(a,b,ch);
 printf("insertChar(): ");
 puts(b);
 return 0;
}
void insertChar(char *str1, char *str2, char ch)
{
 int i,j;
 i=j=0;
 for(i,j;str1[i]!='\0';i++,j++)
 {
     str2[j]=str1[i];
     if(i%3==2)
     {
         j++;
         str2[j]=ch;
     }
 }
 str2[j]='\0';
}
