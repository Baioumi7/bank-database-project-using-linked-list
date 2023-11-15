#include "bank database project.h"
int main()
{  char choice ;
   int id_check ;
   int id_from ;
   int id_to ;
   int check1;
   int check2;

   double money_transfer ;
   customer_t *head='\0';
   while(1)
   {

    printf("please select one of the following options :\n\n1-create anew customer (press 1 to select this option)\n2-edit customer (press 2 to select this option )\n3-delete customer (press 3 to select this option)\n4-print customer data (press 4 to select this option)\n5-cash transfer from customer to another (press 5 t select this option)\n6-exit (press 6 to select this option)\n\nplease enter your choice:");
    fflush(stdin);
    scanf("%c",&choice);
    printf("\n\n");
    switch(choice)
    {
    case '1' :
        create_new_customer(&head);
        break ;

    case '2' :
  edit: printf("please enter the id of the customer who you need to change its data :");
        scanf("%i",&id_check);
        check1=check_id(head,id_check);
        if (check1==-1)
        {
           printf("please enter valid id \n");
           goto edit ;
        }

        edit_customer(head,id_check);
        break ;

    case '3' :
    L4:    printf("please enter the id of the customer who you need to delete its data :");
        scanf("%i",&id_check);
        check1=check_id(head,id_check);
        if(check1==-1)
        {
            printf("please enter valid id\n");
            goto L4 ;
        }
        delete_customer_data(&head,head,id_check);
        break;

    case '4' :
  print: printf("please enter the id of the customer who you need to print its data :");
        scanf("%i",&id_check);
        check1=check_id(head,id_check);
        if(check1==-1)
        {
            printf("please enter a valid id\n ");
            goto print ;
        }
        print_customer_data(head,id_check) ;
        break;

    case '5' :
     L1:printf("please enter the id of the customer who the money will transfer from his cash  :");
        scanf("%i",&id_from);
        check1=check_id(head,id_from);
        if(check1==-1)
        {
           printf("please enter valid id\n");
           goto L1;
        }
    L2: printf("please enter the id of the customer who the money will transfer to his cash  :");
        scanf("%i",&id_to);
        check2=check_id(head,id_to);
        if(check2==-1)
        {
           printf("please enter valid id\n");
           goto L2;
        }


   L3:  printf("please enter the money which will be transfered  :");
        scanf("%lf",&money_transfer);

         if(money_transfer<=0)
        {
            printf("the money transfered should be positive number and greater than zero \n");
            goto L3 ;
        }
        transfer_money(head,id_from,id_to,money_transfer);
        break;

    case '6' :
        exit(0);
    default:
        printf("wrong choice\n\n");

    }

   }

return 0 ;

}
