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
}
