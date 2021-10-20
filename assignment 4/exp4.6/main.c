#include <stdio.h>
#include <string.h>
struct account {
 struct
 {
 char lastName[10];
 char firstName[10];
 } names;
 int accountNum;
 double balance;
};
void nextCustomer(struct account *acct);
void printCustomer(struct account acct);
int main()
{
 struct account record;
 int flag = 0;
 do {
 nextCustomer(&record);
 if ((strcmp(record.names.firstName, "End") == 0) &&
 (strcmp(record.names.lastName, "Customer") == 0))
 flag = 1;
 if (flag != 1)
 printCustomer(record);
 } while (flag != 1);
}
void nextCustomer(struct account *acct)
{
 printf("Enter names (firstName lastName):\n");
 scanf("\n%s%s",&acct->names.firstName,&acct->names.lastName);
if ((strcmp(acct->names.firstName, "End") != 0) &&
 (strcmp(acct->names.lastName, "Customer") != 0))
 {
 printf("Enter account number:\n");
 scanf("\n%d",&acct->accountNum);
 printf("Enter balance:\n");
 scanf("\n%lf",&acct->balance);
 }
}
void printCustomer(struct account acct)
{
 printf("Customer record:\n");
 printf("%s %s %d %.2lf", acct.names.firstName,acct.names.lastName,acct.accountNum,acct.balance);
 printf("\n");
}
