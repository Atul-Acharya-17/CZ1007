#include <stdio.h>
void strIntersect(char *str1, char *str2, char *str3);
int main()
{
 char str1[50],str2[50],str3[50];

 printf("Enter str1: \n");
 scanf("%s",str1);
 printf("Enter str2: \n");
 scanf("%s",str2);
 strIntersect(str1, str2, str3);
 if (*str3 == '\0')
 printf("strIntersect(): null string\n");
 else
 printf("strIntersect(): %s\n", str3);
 return 0;
}
void strIntersect(char *str1, char *str2, char *str3)
{
    int i,j,k;
    k=0;
    str3[k]='\0';
    for(i=0;str1[i]!='\0';i++)
    {
        for(j=0;str2[j]!='\0';j++)
        {
            if(str1[i]==str2[j])
            {
                str3[k]=str1[i];
                k++;
            }

        }
    }
}
