#include <stdio.h>
typedef struct {
 char name[20];
 int age;
} Person;
void readData(Person *p);
Person findMiddleAge(Person *p);
int main()
{
 Person man[3], middle;

 readData(man);
 middle = findMiddleAge(man);
 printf("findMiddleAge(): %s %d\n", middle.name, middle.age);
 return 0;
}
void readData(Person *p)
{
 int i;
 for(i=0;i<3;i++)
 {
     printf("Enter person %d:",i+1);
     scanf("%s %d",&p->name,&p->age);
     p++;
 }
}

Person findMiddleAge(Person *p)
{
 if(p->age>(p+1)->age && p->age<(p+2)->age)
    return *p;
 else if(p->age<(p+1)->age && p->age>(p+2)->age)
    return *p;
 else if(p->age>(p+1)->age && (p+1)->age>(p+2)->age)
    return *(p+1);
 else if(p->age<(p+1)->age && (p+1)->age<(p+2)->age)
    return *(p+1);
 else if((p+2)->age>p->age && (p+2)->age<(p+1)->age)
    return *(p+2);
 else return *(p+2);
}
