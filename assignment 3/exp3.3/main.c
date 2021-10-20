#include <stdio.h>
#include <string.h>
#include<ctype.h>
int longWordLength(char *s);
int main()
{
 char str[80], *p;

 printf("Enter a string: \n");
 fgets(str, 80, stdin);
 if (p=strchr(str,'\n')) *p = '\0';
 printf("longWordLength(): %d\n", longWordLength(str));
 return 0;
}
int longWordLength(char *s)
{
 int count = 0;
 int longest = 0;
 int i;
 for(i=0; s[i]!='\0';i++)
 {
    if(s[i+1]!='\0'&&isalpha(s[i]))
        count++;
     else
     {
         if(s[i+1]=='\0'&&isalpha(s[i]))
            count++;
         if(longest<count)
            longest = count;
         count = 0;
     }
 }
 return longest;
}
