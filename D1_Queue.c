/*
 * Assignment no.D25
 *
 *  Queues are frequently used in computer programming, and a typical example is the
creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++
program for simulating job queue. Write functions to add job and delete job from
queue

 */

#include<stdio.h>

#define MAX 3


	
	int rear,front;


void delet(int [MAX]);
void insert(int[MAX]);
void display(int[MAX]);
int main()
{
	int op;
	int q[MAX];
	front=rear=-1;


do
{

	printf("\n\n\n\t\t*** MENU *** ");
	printf("\n\n\t----------------------------------------------------");
	printf("\n\n\t1.Insert new job in Queue\n\n\t2.Delete job from Queue\n\n\t3.Disply Jobes in Queue \n\n\t4.Exit");
	printf("\n\n\t----------------------------------------------------");
	printf("\n\n\tEnter your choice\t");
	scanf("%d",&op);
		switch(op)
		{
			case 1:
				insert(q);
				break;
			case 2:
				delet(q);
				break;
			case 3:
				display(q);
				break;

		}
	} while(op!=4);
return(0);

}
void insert(int q[MAX])
{

		int x;

		if(rear==MAX-1)
			printf("\n\n\t Queue is FULL");
		else
		{
			if(rear==-1)
			{

				printf("\n\n\tEnter the Job number ");
				scanf("%d",&x);
				rear=rear+1;
				q[rear]=x;
				front++;
			}
			else
			{
				printf("Enter the Job number\t");
				scanf("%d",&x);
				rear++;
				q[rear]=x;
			}
		}
		display(q);
}
void delet(int q[MAX])
{
	 int temp;
	if(front==-1)
	{
		printf("\n\n\tQueue is Empty");
	}
	else
	{
		if(front==rear)
		{
			temp= q[front] ;
			//free(temp);
			printf("\n\n\t\t%d Job is send  to execution",temp);
			front=rear=-1;
		}
		else
		{

			temp=q[front];
			 printf("\n\n\t\t%d Job is send  to execution",temp);
			 front++;
		}
	}
	display(q);
}
void display(int q[MAX])
{

  int i;
  if(rear==MAX-1)
			printf("\n\n\t Queue is FULL");
 if(front==-1)
	{
		printf("\n\n\tNo job for execution");
	}
 else
 {

	printf("\n\n\t Jobs present in queue");
	printf("\n\n\t----------------------------------------------------");
	for(i=front;i<=rear;i++)
	{
		printf("\n\n\t%d",q[i]);

	}
	printf("\n\n\t----------------------------------------------------");

 }

}
