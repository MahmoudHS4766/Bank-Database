#ifndef bank
#define bank
typedef struct customer
{
    char name[100];
    int id;
    char type[7];
    double cash;
}customer_t;


void create_customer(void);
void edit_customer(void);
void delete_customer(void);
void print_data(void);
void transfer_cash(void);


#endif
