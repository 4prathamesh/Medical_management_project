#include<stdio.h>
#include"Customer_Menu.h"
#include"Medicine_menu.h"
#include"Supplier_menu.h"
#include"Bill_menu.h"
int main()
{
    printf("\n\t:) :) :) :) Welcome to 'PRATHAMESH medical' store :) :) :) :)\n\n");

    int choice;

    do
    {
        printf("\n****************************************************************\n");
        printf("*\t\t1.Customer related work:                       *\n");
        printf("*\t\t2.Medicine related work:                       *\n");
        printf("*\t\t3.Supplier information:                        *\n");
        printf("*\t\t4.Billing:                                     *\n");
        printf("*\t\t5.About:                                       *\n");
        printf("*\t\t6.Exit:                                        *\n");
        printf("****************************************************************\n");

        printf("enter the choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            customer();
            break;
            case 2:
            medicine();
            break;
            case 3:
            supplier();
            break;
            case 4:
            bill();
            break;
            // case 5:
            // exit1();
            // break;  
        }
    }while(choice!=5);
}