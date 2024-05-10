#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Bank database.h"
#define MAX_CUSTOMERS 3

customer_t customer[MAX_CUSTOMERS];
int counter=0;

int main()
{
int choice;


while(1)
{
    printf("\n************************************************************");
    printf("\nEnter the number of operation: \n\n1-Add a new customer<press 1>\n2-Edit a customer<press 2>\n3-Delete a customer<press 3>\n4-Print a customer data<press 4>\n5-Transfer cash from customer to another<press 5>\n6-Exit<press 6>\n");
    scanf("%i",&choice);

    switch (choice){

    case 1:
    if (counter <= MAX_CUSTOMERS-1)
    {create_customer();}
    else
        printf("\n**Customer data base is full\n");
        break;

    case 2:
        edit_customer();
        break;

    case 3:
        delete_customer();
        break;

    case 4:
        print_data();
        break;

    case 5:
        transfer_cash();
        break;

    case 6:
        return 0;
    }

}
}
