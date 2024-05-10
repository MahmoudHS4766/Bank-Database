#include <stdio.h>
#include "Bank database.h"
#define MAX_CUSTOMERS 3

extern customer_t customer[MAX_CUSTOMERS];
extern int counter;

void create_customer(void)
{
    counter++;
    printf("\nEnter the name of customer %i: ",counter);
    fflush(stdin);
    gets(customer[counter].name);
    printf("Enter the id of customer %i: ",counter);
    scanf("%i", &customer[counter].id);
    printf("Enter the type of the card <credit or debit>: ");
    fflush(stdin);
    gets(customer[counter].type);
    printf("Enter the cash of customer %i: ",counter);
    scanf("%lf", &customer[counter].cash);
}
//*************************************************************************
int customer_id, i,choice ,valid=1;

void edit_customer(void)
{
    printf("\nEnter the id of the customer to edit: ");
    scanf("%i", &customer_id);

    while(valid)
    {
    for (i=0 ; i < MAX_CUSTOMERS ; i++)
    {
        if (customer_id != customer[i].id )
            {
                if (i!=MAX_CUSTOMERS-1){continue; }
                else{
            printf("The id is invalid\nEnter a correct id: ");
            scanf("%i", &customer_id);}}

        else if (customer_id == customer[i].id){
                choice = i;
                valid = 0;
                 break;}
            }
    }
    printf("The customer you want to edit is [%s]\n",customer[choice].name);
    printf("Edit name: ");
    fflush(stdin);
    gets(customer[choice].name);
    printf("\nEdit the id of customer %i: ",choice);
    scanf("%i", &customer[choice].id);
    printf("\nEdit the type of the card <credit or debit>: ");
    fflush(stdin);
    gets(customer[choice].type);
    printf("\nEdit the cash of customer %i: ",choice);
    scanf("%lf", &customer[choice].cash);
}
//************************************************************
void delete_customer(void)
{
    printf("\nchoose a customer to delete<1-%i>: ",counter);
    scanf("%i", &choice);
    if (choice>counter)
    {
        printf("invalid customer number.");
    }
    else {
        for (i=choice ; i<counter ; i++)
        {
            strcpy(customer[i].name,customer[i+1].name);
            customer[i].id=customer[i+1].id;
            strcpy(customer[i].type,customer[i+1].type);
            customer[i].cash=customer[i+1].cash;
        }
        counter--;
        if (choice == counter)
        {counter--;}
    }

}
//************************************************************
void print_data(void)
{
    printf("\nchoose a customer to print the data<1-%i>: ",counter);
    scanf("%i", &choice);
    if (choice>counter)
    {
        printf("invalid customer number.");
    }
    else {
    printf("Customer name: [%s]",customer[choice].name);
    printf("\nCustomer ID: %i",customer[choice].id);
    printf("\nCustomer card type: [%s]",customer[choice].type);
    printf("\nSaved cash: %lf",customer[choice].cash);}
}
//************************************************************
int sender,reciever;
double amount;
void transfer_cash(void)
{
    printf("Enter the number of the sender<1-counter>: ");
    scanf("%i",&sender);
    while(1)
    {
        if (sender>counter)
        {
            printf("invalid customer number.\nRewrite the sender number: ");
            scanf("%i",&sender);}
        else break;

    }
    printf("Enter the number of the reciever<1-counter>: ");
    scanf("%i",&reciever);
    while(1)
    {
        if (reciever>counter || reciever==sender)
        {
            printf("invalid customer number.\nRewrite the reciever number: ");
            scanf("%i",&reciever);}
        else break;

    }
    printf("Enter the amount to be transferred from [%s] to [%s]: ",customer[sender].name,customer[reciever].name);
    scanf("%lf",&amount);

    if (amount>customer[sender].cash)
    {
        printf("\ninsufficient balance to be transfered");
    }
    else
    {
        customer[reciever].cash += amount;
        customer[sender].cash -= amount;
        printf("%\nlf has been transfered from [%s] to [%s] account",amount,customer[sender].name,customer[reciever].name);
    }

}
