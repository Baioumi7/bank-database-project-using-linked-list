#include "bank database project.h"
int counter ;
int check_id(customer_t *head,int id)
{ int check=-1 ;
   if(head==NULL)
   {
    check=1 ;
   }
    while(head!=NULL)
    {
        if(head->id==id)
        {
            check=2 ;
            break ;
        }
        head=head->next ;
    }
    return check ;
}



void create_new_customer(customer_t **head_ptr)
{
       customer_t *new_customer;

    new_customer =(customer_t*)malloc(sizeof(customer_t));
    printf("please enter the name of the customer number %i:",counter+1);
    fflush(stdin);
    gets(new_customer->name);

  label:  printf("please enter the cash of the customer number %i:",counter+1);
    scanf("%lf",&(new_customer->cash));
    if(new_customer->cash<0)
    {
      printf("the cash money should be positive number and greater than or equal zero  \n");
      goto label ;
    }

    printf("please enter the type of the customer number %i (debit or credit):",counter+1);
    fflush(stdin);
    gets(new_customer->type);


    printf("please enter the id of the customer number %i:",counter+1);
    scanf("%i",&(new_customer->id));
    new_customer->next=*head_ptr;
    *head_ptr=new_customer;
    printf("\n\n");
    counter++ ;
}

void  edit_customer(customer_t *head,int id)
{
    if(head==NULL)
    {
        printf("the linked list is empty\n");
        return ;
    }
    while(head!=NULL)
    {
        if(head->id==id)
    {
    printf("please enter the new name :");
    fflush(stdin);
    gets(head->name);

    printf("please enter the new cash :");
    scanf("%lf",&(head->cash));

    printf("please enter the new type (Debit or credit):");
    fflush(stdin);
    gets(head->type);

    printf("please enter the new id :");
    scanf("%i",&(head->id));
    break ;
    }
    head=head->next ;
    }
    printf("\n\n");

      }




void print_customer_data(customer_t *head,int id)
    {         if(head==NULL)
    {
        printf("the linked list is empty \n");
        return ;
    }

    while (head!=NULL)
    {  if (head->id==id)
    {
     printf("the name of the customer number%i is :%s\n",counter+1,head->name);
            printf("the cash of the customer number%i is :%0.2lf\n",counter+1,head->cash);
            printf("the type of the customer number%i is :%s\n",counter+1,head->type);
            printf("the id of the customer number%i is :%i\n",counter+1,head->id);
            printf("\n\n");
            break;
    }


         head=head->next;
         }
         }
 void transfer_money(customer_t *head,int source_id ,int destination_id,double money)
     {
         customer_t *temp=head;

         if(head==NULL)
    {
        printf("the linked list is empty \n");
        return ;
    }
    if(head->next==NULL)
    {
        printf("the linked list is containing just one element and to transfer money it must be at least 2 elements \n");
        return ;
    }
    while(head!=NULL)
{

 if(head->id==source_id)
 {
     if(head->cash-money<0)
     {
         printf("the transfered money is more than client money\n");
         return ;
     }
     head->cash=head->cash-money;
     break;
 }
    head=head->next;
}
    while(temp!=NULL)
{

 if(temp->id==destination_id)
 {
     temp->cash=temp->cash+money;
     break;
 }
    temp=temp->next;
}
}
void delete_customer_data(customer_t **head_ptr,customer_t *head,int id )
{ int i=0;
int j;
  customer_t *temp;
  customer_t *temp2=head;
   if(head==NULL)
   {
       printf("the linked list is empty \n");
      return ;
   }
   if(head->next==NULL)
   {
    free(*head_ptr);
    *head_ptr=NULL ;
    counter--;
    return ;
   }
   while(head!=NULL)
   {
       if(head->id==id)
       {
         break;
       }
       head=head->next;
       i++;
   }
   if(i==0)
   {
    *head_ptr=(*head_ptr)->next;
    free(temp2);
       counter--;
       return;
   }
          for(j=0;j<i-1;j++)
          {
              temp2=temp2->next;
          }
          printf("i=%i",i);
          printf("j=%i",j);
          temp=temp2->next;
          temp2->next=temp->next;
          free(temp);
          counter--;

   }
