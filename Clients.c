#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "Servers.h"

/* Main Program*/
int main()
{
       printf("\n\t\t\t------------------------- WELCOME -----------------------------\n");
       Sleep(900);   // Delays the Program for 900 milliseconds
       printf("\n\t\t \t~~~~~~~~~~~~~~~~~~~~~~ BANK APPLICATION ~~~~~~~~~~~~~~~~~~~~~~\n");
       Sleep(900);
       printf("\n\t\t\t_______________________________________________________________\n");
       Sleep(900);
       char reply;
       printf("\n  Are You Ready To Open Your Bank Account ?  Y/N:  ");
       scanf("%c",&reply);
       if(reply=='Y' || reply=='y')
       {
        Sleep(500);
       printf("\n\t\t\t\t\t\t W E L C O M E "); Sleep(300);
       }
        else if(reply == 'N' || reply == 'n')
       {
        printf("\n Thank You ! ");
        return 0;
        }
       display_options();
       printf("\n");
    char option;
    int num_acc=0;
    while(1)
    {
       printf("\n\n");
       printf("ENTER ANY OPTION ~  1 , 2 , 3 , 4 , 5 , 6, 7, 8 ");
       printf("TO CONTINUE : ");
 
        option = getch();
        printf("%c \n", option);
        switch(option)
        {
          case '1': Create_new_account();
                    break;
          case '2': cash_deposit();
                    break;
          case '3': cash_withdrawal();
                    break; 
          case '4': Account_information();
                    break;
          case '5': upi_register();
                    break;
          case '6': upi_display();
                    break;
          case '7': return 0;
          case '8': system("cls");
                    break;
          default : system("cls");
                    printf("Please enter one of the options");
                    printf("(1  2  3  4  5  6  7  8) to continue \n ");
                    break;
        }
    }
    return 0;
}