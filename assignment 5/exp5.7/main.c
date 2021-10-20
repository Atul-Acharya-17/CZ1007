#include <stdio.h>
#include <string.h>
int rStrLen(char *s);
int main()
{
 char str[80];
 printf("Enter the string: \n");
 gets(str);
 printf("rStrLen(): %d\n", rStrLen(str));
 return 0;
}
int rStrLen(char *s)
{
 if(*s!='\0')
    return 1+rStrLen(s+1);
 else
    return 0;
}
