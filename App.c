#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "Servers.h"
#define size 1000
 
// UPI Handle Account Structure Declaration
struct upi_data
{
    char upi_name[20];
    char upi_bank[20];
    int upi_account_number;
    int number;
    char username[30];
    int password;
};
struct upi_data upis[size]; // Creating Instance of Structure upi_data
int num_acc;

// Bank Account Structure Declaration
struct acc_type
{
     char bank_name[20];
     char bank_branch[20];
     char bank_state[20];
     char IFSC[12];
     struct upi_data upi;
     char acc_holder_name[30];
     int acc_number;
     char acc_holder_address[100];
     float available_balance;   
     int flag;  
};
struct acc_type account[size];  // Creating Instance of Structure acc_type

 FILE* file;   // Pointer to File to display List of Banks
 FILE* files;  // Pointer to File to display List of States

/* Function to Display Available Options */
 void display_options()
{
    printf("\n1. Create New Bank Account \n");  Sleep(150);
    printf("2. Deposit Cash \n");  Sleep(150);
    printf("3. Withdraw Cash \n");  Sleep(150);
    printf("4. Bank Account Information \n");  Sleep(150);
    printf("5. Register for UPI Handle \n");  Sleep(150);
    printf("6. Display UPI Handle Details \n");  Sleep(150);
    printf("7. Exit Bank Application \n");  Sleep(150);
    printf("8. Back to Options \n \n ");
}

/* Function to create new Bank Account */
void Create_new_account()
{
   char bank_name[20];
   char bank_branch[20];
   char bank_state[20];
   char IFSC[12];
   char acc_holder_name[30];
   int acc_number;
   char acc_holder_address[100];
   float available_balance = 0;
   fflush(stdin);    
   printf("\nList of Indian Public Sector Banks --- \n" );
   printf("\n");
   int i;
   Sleep(1000);
   display_banks();  // Function call to display List Of Banks
   printf("\n");
   printf("\nEnter the bank name              : \n");
   scanf("%[^\n]s",&bank_name); fflush(stdin); 
   printf("\n");
   Sleep(1000);
   printf("List Of Bank States --- \n");
   printf("\n");
   Sleep(1000);
   display_states();  // Function call to display List Of States
   printf("\n");
   printf("\nEnter the state name              :\n ");
   scanf("%[^\n]s", &bank_state); fflush(stdin); 
   printf("\nEnter the bank branch            :\n ");
   scanf("%[^\n]s", &bank_branch); fflush(stdin); 
   printf("\nEnter the account holder name    : \n ");
   scanf("%[^\n]s", &acc_holder_name); fflush(stdin); 
   printf("\nEnter the account number(1 to 10)  :\n ");
   scanf("%d", &acc_number); fflush(stdin);
   printf("\nEnter the account holder address  :\n ");
   scanf("%[^\n]s", &acc_holder_address); fflush(stdin); 
   printf("\nFind Your IFSC Bank Code");
   Sleep(1000);
   system ("explorer https://www.rbi.org.in/Scripts/IFSCMICRDetails.aspx#mainsection");
   printf("\nEnter your 11 Digit IFSC Code   :\n ");
   scanf("%[^\n]s",&IFSC); fflush(stdin); 
 
   strcpy(account[acc_number-1].bank_name,bank_name);
   strcpy(account[acc_number-1].bank_branch,bank_branch);
   strcpy(account[acc_number-1].bank_state,bank_state);
   strcpy(account[acc_number-1].acc_holder_name,
   acc_holder_name);
   account[acc_number-1].acc_number=acc_number;
   strcpy(account[acc_number-1].acc_holder_address,
   acc_holder_address);
   strcpy(account[acc_number-1].IFSC,
   IFSC);
   account[acc_number-1].available_balance=available_balance;
   account[acc_number-1].flag=1;
 
   printf("\nAccount has been created successfully \n\n");
   Sleep(500);
   printf("Bank name              : %s \n" , 
   account[acc_number-1].bank_name);
   printf("Bank branch            : %s \n" , 
   account[acc_number-1].bank_branch);
   printf("Bank state             : %s \n" , 
   account[acc_number-1].bank_state);
   printf("Account holder name    : %s \n" , 
   account[acc_number-1].acc_holder_name);
   printf("Account number         : %d \n" , 
   account[acc_number-1].acc_number);
   printf("Account holder address : %s \n" , 
   account[acc_number-1].acc_holder_address);
   printf("Available balance      : %f \n" , 
   account[acc_number-1].available_balance);
}
 

 // Function to deposit cash
void cash_deposit()
{
   int acc_no;
   float add_money;
   
   printf("Enter account number you want to deposit money:");
   scanf("%d",&acc_no);
   if (account[acc_no-1].flag == 1)
   {
   printf("\nThe current balance for account %d is %f \n",acc_no, account[acc_no-1].available_balance);
   printf("\nEnter money you want to deposit :  ");
   scanf("%f",&add_money);

   while (acc_no=account[acc_no-1].acc_number)
   {
         account[acc_no-1].available_balance= account[acc_no-1].available_balance + add_money;
         printf("\nThe New balance for account %d is %f \n",acc_no, account[acc_no-1].available_balance);
         break; 
   }acc_no++;
   }
   else
   {
       printf("Account No. %d does not EXIST ",acc_no);
   }
}


// Function to withdraw cash
void cash_withdrawal()
{
   int acc_no;
   float withdraw_money;

   printf("Enter account number you want to withdraw money:");
   scanf("%d",&acc_no);
   if (account[acc_no-1].flag == 1)
   {
   printf("\nThe current balance for account %d is %f \n",acc_no, account[acc_no-1].available_balance);
   printf("\nEnter money you want to withdraw from account \n");
   scanf("%f",&withdraw_money);

   while (acc_no=account[acc_no-1].acc_number)
   {
         if (account[acc_no-1].available_balance >withdraw_money)
         {
         account[acc_no-1].available_balance = account[acc_no-1].available_balance-withdraw_money;
         }
         else
         {
         printf("Withdraw Amount exceeds Cash Deposited in Account No. %d ",acc_no);
         }
         printf("\nThe New balance for account %d is %f \n",acc_no, account[acc_no-1].available_balance);
         break; 
   }acc_no++;
   }
   else
   {
       printf("Account No. %d does not EXIST ",acc_no);
   }

}

// Function which reads from banks.txt File and displays List of Banks
void display_banks()
{
char in_name[400];
    FILE *in_file;
    int ch;

    in_file = fopen("banks.txt", "r");  // Opens banks.txt File

    if (in_file == NULL)
    {
        printf("Can't open %s for reading.\n", in_name);
    }
    else
    {
        while ((ch = fgetc(in_file)) != EOF)
        {
            printf("%c", ch);
        }
        fclose(in_file);
    }
}

// Function which reads from states.txt File and displays List of States
void display_states()
{
    char in_names[400];
    FILE* in_files;
    
    int ch1;

    in_files = fopen("states.txt", "r"); // Opens states.txt File

    if (in_files == NULL)
    {
        printf("Can't open %s for reading.\n", in_names);
    }
    else
    {
        while ((ch1 = fgetc(in_files)) != EOF)
        {
            printf("%c", ch1);
        }
        fclose(in_files);
    }
}

// Function to Display Account Information
void Account_information()
{ 
     int num_acc;
     printf("\nEnter Account Number: \n");
     scanf("%d",&num_acc);
     num_acc=num_acc-1;
     if(strlen(account[num_acc].bank_name)>0)
     {
         printf("\nBank name                : %s \n" , 
         account[num_acc].bank_name);
         printf("Bank branch              : %s \n" , 
         account[num_acc].bank_branch);
         printf("Bank state              :  %s \n" , 
         account[num_acc].bank_state);
         printf("Account holder name      : %s \n" , 
         account[num_acc].acc_holder_name);
         printf("Account number           : %d \n" , 
         account[num_acc].acc_number);
         printf("Account holder address   : %s \n" , 
         account[num_acc].acc_holder_address);
         printf("\nIFSC Code                : %s \n" , 
         account[num_acc].IFSC);
         printf("Available balance        : %f \n\n" , 
         account[num_acc].available_balance);
         
     }
}
 
// Function to Create UPI Handle Account
void upi_register()
{
  char upi_name[20];
  char z[20];
  int upi_account_number;
  int number;
  int password;
  
  printf("\n\t\t\t\t\t\tRegister for UPI Handle Below \n");
  Sleep(700);
  printf("\nEnter UPI Account Number ( 1 - 10)  : ");
  scanf("%d",&upi_account_number); fflush(stdin);
  printf("\nEnter Your Full Name with '_' as stated in Verified Documents  : \n");
  scanf("%[^\n]s",&upi_name); fflush(stdin); 
  printf("\nEnter Bank Name  : \n");
  scanf("%[^\n]s",&z); fflush(stdin); 
  printf("\nEnter your Phone Number  :\n");
  scanf("%d",&number); fflush(stdin);
  printf("\nEnter Seven Digit Password  : \n");
  scanf("%d",&password);
  int m;
  for(m=1;m<=5;m++)
  printf(" . \n");
  printf("\nSUCCESSFULLY REGISTERED UPI HANDLE FOR ACCOUNT NO.  %d \n", upi_account_number);
  
  strcpy(upis[upi_account_number-1].upi_name,upi_name);
  strcpy(upis[upi_account_number-1].upi_bank,z);
  upis[upi_account_number-1].number=upi_account_number;
  upis[upi_account_number-1].password=password;
  upis[upi_account_number-1].number=number;
}

// Function to Display UPI Handle Account Information
void upi_display()
{
    int a;
    int i;
    printf("\nEnter UPI Account Number : ");
    scanf("%d",&a);
    printf("\nLoading Your UPI Handle Details");
    for(i=1;i<=5;i++)
    {
        printf("\n . . . "); Sleep(200);
    }
    printf("\n UPI Username For Account Number %d : \n", a); Sleep(200);
    printf("%c%s",' ',upis[a-1].upi_name); printf("%c",'@');
    printf("%s",upis[a-1].upi_bank);
    printf("\n UPI Password : "); Sleep(200);
    printf("\n%c%d",' ',upis[a-1].password);
}