#include <stdio.h>
#include <string.h>
int countWords(char *s);
int main()
{
 char str[50], *p;
 printf("Enter the string: \n");
 fgets(str, 80, stdin);
 if (p=strchr(str,'\n')) *p = '\0';
 printf("countWords(): %d", countWords(str));
 return 0;
}
int countWords(char *s)
{
 int i;
 int count =0;
 int check =0;
 for(i=0;s[i]!='\0';i++){

    if(s[i]!=' ')
        check =1;

     if(s[i]==' ' && check){
            count++;
            check = 0;
    }

    if(s[i+1]=='\0'&&check)
        count++;

 }
 return count;
}
