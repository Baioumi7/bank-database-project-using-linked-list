
#ifndef bank_H
#define bank_H
#include <stdio.h>
#include <stdlib.h>

typedef struct customer
{
    char name[50];
    double cash ;
    char type[7] ;
    int id ;
    struct customer *next;
}customer_t ;

int check_id(customer_t *head,int id);
void create_new_customer(customer_t **head_ptr);
void  edit_customer(customer_t *head,int id);
void print_customer_data(customer_t *head,int id);
 void transfer_money(customer_t *head,int source_id ,int destination_id,double money);
 void delete_customer_data(customer_t **head_ptr,customer_t *head,int id );
#endif
