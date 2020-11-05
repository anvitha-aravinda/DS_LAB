#include<stdio.h>
#include<stdlib.h>
#define max 5
int insertq ( int queue[max], int *rear , int *data,int *front)
{
      if ( *rear == max -1 )
            return(-1);
      else
      {     if(*front==-1)
            *front=0;
            *rear = *rear + 1;
            queue[*rear] = *data;
            return(1);
      }
}
int delq( int queue[max], int *front, int *rear)
{
    
      if ( *front == *rear)
            return(-1);
      else
      {
            
            
            printf("deleted:%d",queue[*front]);
            (*front)++;
            if(*front==*rear)
            *front=*rear=-1;
            return(1);
      }
}
void display(int queue[max],int *front,int *rear)
{
    int i;
    if(*rear==-1)
        printf("Queue is empty\n");
    else
    {
        printf("\n Queue contents:");
        for(i=*front;i<=*rear;i++)
            printf("%d", queue[i]);
    }
}
int main()
{
      int queue[max],data,i;
      int front,rear,reply,option;
      front =-1;
      rear = -1;
      printf("\tMenu");
      printf("\n----------------------------");
      printf("\n 1. Insert element in queue");
      printf("\n 2. Delete element from queue");
      printf("\n 3.Display");
      printf("\n 4. Exit");
      printf("\n----------------------------");
      do
      {
            printf("\nChoose operation : ");
            scanf("%d",&option);
            switch(option)
            {
                  case 1 :
                        printf("\nEnter Number : ");
                        scanf("%d",&data);
                        reply = insertq(queue,&rear,&data,&front);
                        if ( reply == - 1)
                              printf("Queue is full");
                        break;
                  case 2 : 
                        reply = delq(queue,&front,&rear);
                        if ( reply == -1 )
                              printf("Queue is empty ");
                              break;
                  case 3:
                        display(queue,&front,&rear);
                        break;

                  case 4 : exit(0);
            }
      }while(option!=4);
}
