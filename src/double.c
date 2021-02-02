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
void insert_nthpos();
void delete_nthpos();
void display();
void search();
void main()
{
    int ch=0;
    while(ch!=9)
    {
        printf("choose your option");
        printf("\n1.Insert in begining\n2.Insert at last\n 3.Delete from front\n 4.Delete from last\n 5.insert at n th position\n6.delete at n th position\n 7.search\n 8.display \n 9.Exit\n");
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
            insert_nthpos();
            break;
            case 6:
            delete_nthpos();
            break;
            case 7:  
            search();  
            break;  
            case 8:  
            display();  
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("invalid choice");
        }
    }
}
                 // function for inserting elements at beginning
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
                 
                 //function for inserting elements at last
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
                 
                 //function for deleting elements at last
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
                 
                 //function for deleting elements at beginning
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
                 
                 //function for disply elements present in linked list
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
                 
                 //function for searching element in linked list
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

                
                 //function for inserting elements at nth position
                 void insert_nthpos()
                 {
                     struct node *ptr,*temp;
                     int item, loc,i;
                     ptr=(struct node *)malloc(sizeof(struct node));
                     if(ptr==NULL)
                     {
                         printf("\n overflow");
                     }
                     else
                     {
                         temp=head;
                         printf("enter the loction to add");
                         scanf("%d",&loc);
                         for(i=0;i<loc;i++)
                         {
                             temp=temp->next;
                             if(temp==NULL)
                             {
                                 printf("\n there are less than %d elements",loc);
                                 return;
                             }
                         }
                         printf("enter value");
                         scanf("%d",&item);
                         ptr->data=item;
                         ptr->next=temp->next;
                         ptr -> prev = temp;  
                         temp->next = ptr;  
                         temp->next->prev=ptr;  
                         printf("\nnode inserted\n");
                     }
                 }

                 //function for delete elements at nth position 
                 void delete_nthpos()
                 {
                     struct node *ptr, *temp;  
                     int val;  
                     printf("\n Enter the data after which the node is to be deleted ");  
                     scanf("%d", &val);  
                     ptr = head;  
                     while(ptr -> data != val)  
                     ptr = ptr -> next;  
                     if(ptr -> next == NULL) 
                     {
                        printf("\n can't delete\n");
                     }
                     else if(ptr->next->next==NULL)
                     {
                         ptr->next=NULL;
                     }
                     else
                     {
                         temp=ptr->next;
                         ptr->next=temp->next;
                         temp->next->prev=ptr;
                         free(temp);
                         printf("\n node deleted\n");
                     }
                 }
                 
