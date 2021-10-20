#include <stdio.h>
#include <string.h>
#define SIZE 10
void findMinMaxStr(char word[][40], char *first, char *last, int size);
int main()
{
 char word[SIZE][40];
 char first[40], last[40];
 int i, size;
 printf("Enter size: \n");
 scanf("%d", &size);
 printf("Enter %d words: \n", size);
 for (i=0; i<size; i++)
 scanf("%s", word[i]);
 findMinMaxStr(word, first, last, size);
 printf("First word = %s, Last word = %s\n", first, last);
 return 0;
}
void findMinMaxStr(char word[][40], char *first, char *last, int size)
{

 int i,j,k;
 int f=0;
 int l=0;

 for(i=1;i<size;i++)
 {
     for(j=0;word[i][j]!='\0'&&word[f][j]!='\0';j++)
     {
          if((int)word[i][j]<(int)word[f][j])
          {
              f=i;
              break;
          }
          else if((int)word[i][j]>(int)word[f][j])
            break;
         else if(word[i][j+1]=='\0'&&word[f][j+1]!='\0')
            f=i;

     }
     for(k=0;word[i][k]!='\0'&&word[l][k]!='\0';k++)
     {
          if((int)word[i][k]>(int)word[l][k])
          {
              l=i;
              break;
          }
          else if((int)word[i][k]<(int)word[l][k])
            break;
          else if(word[i][k+1]!='\0'&&word[l][k+1]=='\0')
            l=i;

     }
 }
 strcpy(first,word[f]);
 strcpy(last,word[l]);
}
