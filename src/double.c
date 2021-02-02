#include <stdio.h>
#include<stdlib.h>
struct node
{
    struct node *prev;
    struct node *next;
    int data;
};
struct node *head;
void insert_front();
void insert_last();
void delete_front();
void delete_last();
void display();
void search();
void main()
{
    int ch=0;
    while(ch!=7)
    {
        printf("choose your option");
        printf("\n1.Insert in begining\n2.Insert at last\n 3.Delete from front\n 4.Delete from last\n 5.Search\n6.Show\n7.Exit\n");
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&ch);  
        switch(ch)  
        {  
            case 1:  
            insert_front();  
            break;  
            case 2:  
            insert_last();  
            break;  
            case 3:   
            delete_front();  
            break;  
            case 4:  
            delete_last();  
            break;  
            case 5:  
            search();  
            break;  
            case 6:  
            display();  
            break;  
            case 7:  
            exit(0);  
            break;  
            default:  
            printf("invalid choice");
        }
    }
}
                 
                 void insert_front()
                 {
                     struct node *ptr;
                     int item;
                     ptr=(struct node *)malloc(sizeof(struct node));
                     if(ptr==NULL)
                     {
                         printf("\noverflow");
                     }
                     else
                     {
                         printf("\nenter item value");
                         scanf("%d",&item);
                         
                         if(head==NULL)
                         {
                            ptr->next = NULL;  
                            ptr->prev=NULL;  
                            ptr->data=item;  
                            head=ptr;  
                         }
                         else
                         {
                             ptr->data=item;
                             ptr->prev=NULL;
                             ptr->next=head;
                             head->prev=ptr;
                             head=ptr;
                         }
                         printf("\nNode inserted\n");
                     }
                         
                 }
                 
                 
                 void insert_last()
                 {
                     struct node *ptr, *temp;
                     int item;
                     ptr=(struct node *)malloc(sizeof(struct node));
                     if(ptr==NULL)
                     {
                         printf("\n overflow");
                     }
                     else
                     {
                         printf("\n enter value");
                         scanf("%d",&item);
                         ptr->data=item;
                         if(head==NULL)
                         {
                             ptr->next=NULL;
                             ptr->prev=NULL;
                             head=ptr;
                         }
                         else
                         {
                             temp=head;
                             while(temp -> next != NULL)
                             {
                                 temp=temp->next;
                             }
                             temp->next=ptr;
                             ptr->prev=temp;
                             ptr->next=NULL;
                         }
                     }
                     printf("\nnode inserted");
                 }
                 
                 
                 void delete_last()
                 {
                     struct node *ptr;
                     if(head==NULL)
                     {
                         printf("\nunderflow");
                     }
                     else if(head->next==NULL)
                     {
                         head=NULL;
                         free(head);
                         printf("\n node deleted");
                     }
                     else
                     {
                         ptr=head;
                         if(ptr->next !=NULL)
                         {
                             ptr=ptr->next;
                         }
                         ptr->prev->next=NULL;
                         free(ptr);
                         printf("\nnode deleted\n");
                     }
                 }
                 
                 
                 void delete_front()
                 {
                     struct node *ptr;
                     if(head==NULL)
                     {
                         printf("\nunderflow");
                     }
                     else if(head->next==NULL)
                     {
                         head=NULL;
                         free(head);
                         printf("\n node deleted");
                     }
                     else
                     {
                         ptr=head;
                         head=head->next;
                         head->prev=NULL;
                         free(ptr);
                         printf("\n node deleted");
                     }
                 }
                 
                 
                 void display()
                 {
                     struct node *ptr;
                     ptr=head;
                     while(ptr != NULL)
                     {
                         printf("%d\n",ptr->data);
                         ptr=ptr->next;
                     }
                 }
                 
                 
                 void search()
                 {
                     struct node *ptr;
                     int item,i=0,flag;
                     ptr=head;
                     if(ptr==NULL)
                     {
                         printf("\n empty list");
                     }
                     else
                     {
                         printf("\n enter item to be search\n");
                         scanf("%d",&item);
                         while(ptr !=  NULL)
                         {
                             if(ptr->data==item)
                             {
                                 printf("\nitem found at the location %d",i+1);
                                 flag=0;
                                 break;
                             }
                             else
                             {
                                 flag=1;
                             }
                             i++;
                             ptr=ptr->next;
                         }
                         if(flag==1)
                         {
                             printf("\n item not found\n");
                         }
                     }
                 }
                 