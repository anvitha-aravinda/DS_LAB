#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int sem;
    char name[50];
    char usn[50];
    struct node *next;
};
struct node *head= NULL;
int c=0;
void Insert()
{
    struct node *newnode;
    struct node *temp;
    int s;
    char n[30],u[30];
    printf("Enter your name  : ");
    scanf("%s",n);
    printf("Enter your semester  : ");
    scanf("%d",&s);
    printf("Enter your usn  : ");
    scanf("%s",u);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->sem =s;
    strcpy(newnode->name,n);
    strcpy(newnode->usn,u);
    if (head==NULL)
    { 
      newnode->next=NULL;
      head=newnode; 
      printf("first node of linked list created\n");
      c++;
    }
     else 
     {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=NULL;
        c++;
        printf("Node created\n");
     }  
}
void deletebeg()
{
    struct node *ptr;  
        if(head == NULL)  
        {  
            printf("\nList is empty");  
        }  
        else   
        {  
            ptr = head;  
            head = ptr->next;  
            free(ptr);  
            printf("\n Node deleted from the begining ...");  
        }  
}
void deletemid()
{
char key[20];
    printf("enter the usn of student to be deleted\n");
    scanf("%s",key);
    struct node *temp = head, *prev; 
    if (temp != NULL && strcmp(temp->usn,key)==0) 
    { 
        head = temp->next;   
        free(temp);             
        return; 
    } 
    while (temp != NULL && strcmp(temp->usn,key)!=0) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
 
    if (temp == NULL)
    {
    printf("student not in the list\n");
    return;
    }
    prev->next = temp->next; 
  
    free(temp); 
} 
void deleteend()
{
    
    struct node *toDelLast, *preNode;
    if(head == NULL)
    {
        printf(" There is no element in the list.");
    }
    else
    {
        toDelLast = head;
        preNode = head;
        while(toDelLast->next != NULL)
        {
            preNode = toDelLast;
            toDelLast = toDelLast->next;
        }
        if(toDelLast == head)
        {
            head = NULL;
        }
        else
        {
            preNode->next = NULL;
        }
        free(toDelLast);
    }
}

void display()
{
    struct node *ptr;
    ptr=head;
    int i=1;
     
    if(ptr==NULL)
    {
        printf("Linked list is empty!\n");
    }
    else
    {
        while(ptr!= NULL)
        {
            printf("----NODE %d----\n",i);
            printf("Name: %s\n",ptr->name);
            printf("USN: %s\n",ptr->usn);
            printf("Sem: %d\n",ptr->sem);
            printf("\n");
            i++;
            ptr=ptr->next;
        }
       
    }
    
}           
        

int main()
{
    int choice,pos;
    do
    {
        
        printf("\n1. Insert node \n2. delete node in the beg of the list\n3. delete at the end of list\n4.delete a given node \n5. display list\n6.exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            Insert(); 
            break;
            
            case 2:
            deletebeg();
            break;
            
            case 3: 
            deleteend(); 
            break;
            
            case 4: 
            deletemid();
            break;

            case 5:
            display();
            break;
            
            case 6:
            break;
            
            default:
            printf("Wrong choice!\n");
            break;
        }
    }while(choice!=6);
    return 0;
}
