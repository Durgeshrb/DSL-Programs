/*
 * Assignment No C-31
 *
 * Pizza parlor accepting maximum M orders. Orders are served in first come first served
   basis. Order once placed cannot be cancelled. Write C++ program to simulate the system
   using circular queue using array.

 */


#include<stdio.h>
#include<stdlib.h>
#define MAX 5

/*typedef struct cqueue
{
	int data[MAX];
	//char name[20];
	int rear,front;
}cqueue;*/
int rear,front;
int q[MAX];

void enqueue( int x);
int dequeue( );
void display();




int main()
{
      int x,ch,token=99;
      char name1[20];
 
      front=rear=-1;
      while(1)
      {
          printf("\n\n\t\t-------------------------------------------------------");
    	  printf("\n\t\t\t\t\tPizza parlor");
    	  printf("\n\t\t-------------------------------------------------------");
          printf("\n\t\t1. Place the order \n");
          printf("\n\t\t2.Dispatch Order\n");
          printf("\n\t\t3. Order Track\n");
          printf("\n\t\t-------------------------------------------------------");
          printf("\n\n\t\tEnter the Choice\n");
          scanf("%d",&ch);
          switch(ch)
          {
              case 1:
			 if(rear>=MAX-1 && front==0)
         		 printf("\n\n\t\tSorry can't accept the order ");
			else if(rear==front-1)
				printf("\n\n\t\tSorry can't accept the order ");
			else
			{
                   		printf("\n\n\t\tplz Place the order\n\n\t\tEnter the name of item:");
               	  		 scanf("%s",name1);
                 		 token++;
                 		  printf("\n\n\t\tThank you!!! \n\t\tYour Token No is %d  ",token);
                    		enqueue(token);
			}
                   break;
              case 2:
			if(front==-1)
      					printf("\n\n\t\tThere is no order");
     			 else
     			 {
    					  printf("\n\t\t-------------------------------------------------------");
         				 printf("\n\n\t \torder is served for token no %d\n", dequeue());
         				 //printf("\n\t\t-------------------------------------------------------");
			}                  
              	     break;
              case 3:
                   display();
                   break;

          }
}
      return(0);
}
void enqueue( int x)
{
             if (rear==-1 && front==-1)
          {
        	  front=0;
           	   rear=0;
		q[rear]=x;
          }
          else
	{
        	  rear=(rear+1)%MAX;
          	q[rear]=x;
      }
}
int dequeue( )
{
      int temp;
          if(front==rear)
          {
        	  temp=q[front];
		  front=-1;
        	  rear=-1;
		return temp;
          }
          else
          {
              	temp=q[front];
		  front=(front+1)%MAX;
        	  
		return temp;
          }
      }
void display()
{
      int i;
      printf("\n\t\t-------------------------------------------------------");
      printf("\n\t\t\t\t***Pending Order***");
      printf("\n\t\t-------------------------------------------------------");
      if(front==-1)
      printf("\n\n\t\tThere is no order\n");

     else if(rear>=front)
      {
          for(i=front;i<=rear;i++)
          printf("\n\n\t\t\t%d\n",q[i]);
      }
      else
      {
          for(i=front;i<=MAX-1;i++)
          printf("\n\n\t\t\t%d\n",q[i]);
          for(i=0;i<=rear;i++)
          printf("\n\n\t\t%d\n",q[i]);
	
      }
}
