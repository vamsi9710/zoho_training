#include<stdio.h>
#include<stdlib.h>

#define MAX 10     //maximum number of elements that can be stored
int top=-1,stack[MAX];
void push();
void pop();
void display();

void main()
{
    int ch;
    while(ch!=4)    
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit\n");
        printf("\n enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("\nwrong choice\n");
        }
    }
}


//function for pushing elements into stack
void push(int valu)
{
    if(top==MAX-1)
    {
        printf("\nstack is full\n");
    }
    else
    {
        top=top+1;
        stack[top]=valu;
    }
}



//function for poping elements from stack
void pop()
{
    if(top==-1)
    {
        printf("\n stack is empty\n");
    }
    else
    {
        printf("\ndeleted element is %d",stack[top]);
        top=top-1;
    }
}



//function for displaying elements in the stack
void display()
{
    int i;
    if(top==-1)
    {
        printf("\nstack is empty\n");
    }
    else
    {
        printf("\nelements in the stack:");
        for(i=top;i>=0;--i)
            printf("%d\n",stack[i]);
    }

