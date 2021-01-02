#include <stdio.h>
#define size 5
int top=-1;
void push(int [], int);
int pop(int[]);
void display(int []);
int main()
{
    int a[5];

    int choice,element;
    int ch;
    do
    {
    printf("Enter your choice\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("Enter the element to be pushed \n");
                scanf("%d",&element);
                push(a,element);
                break;
        case 2: element=pop(a);
                if(element==-1)
                    printf("Stack Underflow cannot remove\n");
                else
                   printf("Poped element is %d \n",element);
                break;
        case 3: display(a);
                break;
        default: printf("Invalid choice\n");
    }
    printf("Do you want to continue:click-1\n");
    scanf("%d",&ch);
    } while(ch==1);
    return 0;
}

void push(int a[], int ele)
{
    if (top==size-1)
    {
        printf("Stack overflow cannot push\n");
    }
    else
    {
        top++;
        a[top]=ele;
    }
}

int pop(int a[])
{
    int ele;
    if(top==-1)
    
       return -1;
      
    else
    {
        ele=a[top];
        top--;
        return (ele);
    }
     
     
}

void display(int a[])
{
    int i;
    printf("The stack elements\n");
    for(i=top;i>=0;i--)
    {
        
        printf("%d\t",a[i]);
    }
    printf("\n");
}
