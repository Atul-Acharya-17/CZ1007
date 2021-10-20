#include <stdio.h>
#include <string.h>
#define INIT_VALUE -1
int countSubstring(char str[], char substr[]);
int main()
{
 char str[80], substr[80], *p;
 int result=INIT_VALUE;

 printf("Enter the string: \n");
 fgets(str, 80, stdin);
 if (p=strchr(str,'\n')) *p = '\0';
 printf("Enter the substring: \n");
 fgets(substr, 80, stdin);
 if (p=strchr(substr,'\n')) *p = '\0';
 result = countSubstring(str, substr);
 printf("countSubstring(): %d\n", result);
 return 0;
}

int countSubstring(char str[], char substr[])
{
 int i,j,k;
 int length =0;
 int check = 0;
 int count = 0;
 for(i=0;substr[i]!='\0';i++)
    length++;


 for(i=0;str[i]!='\0';i++)
 {
     check=0;
     if(str[i]==substr[0])
     {
         k=i;
         for(j=0;substr[j]!='\0'&&str[k]!='\0';j++)
         {
             if(substr[j]==str[k])
                check++;
             if(check==length)
                count++;
             k++;
         }

     }
 }
 return count;
}
