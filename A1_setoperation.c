
/* Assignment No A1-set Operation

 Second year Computer Engineering class of M students, set A of students play cricket and
set B of students play badminton. Write C/C++ program to find and display-
i.Set of students who play either cricket or badminton or both
ii.Set of students who play both cricket and badminton
iii. Set of students who play only cricket
iv.Set of students who play only badminton
v.Number of students who play neither cricket nor badminton
(Note- While realizing the set duplicate entries are to avoided)

 */




//header files
#define MAX 30
#include<stdio.h>
#include<stdlib.h>
//declaration
void insert(int []);
void display(int []);
void Union(int [],int [],int []);
void difference(int [],int[] ,int[]);



int total;

int main()
{
	int setA[MAX],setB[MAX],setC[MAX],setT[MAX],setC1[MAX],setC2[MAX],setC3[MAX],setC4[MAX],setC5[MAX];

	int x,ch;
	int ch1;

	setA[0]=setB[0]=setC[0]=setT[0]=setC1[0]=setC2[0]=setC3[0]=setC4[0]=setC5[0]=0;
	//Menu
	do
	{
		printf("\n\n\t\t------------------------------------------------------------");
		printf("\n\n\t\t\t*** MENU ***");
		printf("\n\n\t\t1.Enter the choice of student\n\n\t\t2.Student Who play Badminton \n\n\t\t3.Student Who play Cricket");
		printf("\n\n\t\t4.Student Who play Badminton ,Cricket Or Both\n\n\t\t5.Student Who play neither Badminton nor Cricket ");
		printf("\n\n\t\t6.Student Who play only Badminton(A-B)\n\n\t\t7.Student Who play only Cricket(B-A)\n\n\t\t8.Student Who play Both Games \n\n\t\t9.Exit");
		printf("\n\n\t\t------------------------------------------------------------");
		printf("\n\n\n\t\tEnter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:


				printf("\n\n\t\t Enter  students present in class");
				insert(setT);
				printf("\n\n\t\t  Student Who play Badminton \n\n");
				insert(setA);
				printf("\n\n\t\t  Student Who play Cricket \n\n");
				insert(setB);
				break;
		case 2:

				printf("\n\n\n\t\t  ***  Student Who play Badminton *** :\n\n");
				printf("\n\n\n\t\t Roll No of Students  :-->\n");
				display(setA);
				break;
		case 3:

				printf("\n\n\n\t\t  *** Student Who play Cricket*** :\n\n");
				printf("\n\n\n\t\t Roll No of Students :-->\n");
				display(setB);
				break;
		case 4:


				Union(setA,setB,setC);
				printf("\n\n\n\t\t Student Who play Badminton ,Cricket Or Both(AUB):-->\n");
				display(setC);
				break;
		case 5:


			    difference(setT,setC,setC1);
				printf("\n\n\n\t\t Student Who play neither Badminton nor Cricket:-->\n");
				display(setC1);
				break;
		case 6:


				difference(setA,setB,setC2);
				printf("\n\n\n\t\t Student Who play only Badminton (A-B):-->\n");
				display(setC2);
				break;
		case 7:

				difference(setB,setA,setC3);
				printf("\n\n\n\t\t Student Who play only Cricket (B-A):-->\n");
				display(setC3);
				break;
		case 8:

				//Union(setC2,setC3,setC4);
				difference(setA,setC2,setC5);
				printf("\n\n\n\t\t Student Who both the game:-->\n");
				display(setC5);
				break;
		case 9:
				exit(0);

	 }
	printf("\n\n\n\t\tDo u want to continue............");
	scanf("%d",&ch1);

	if(ch1==0)
		break;

  }while(ch!=8);

return 0;
}


// Function definations
//defination for insert
 void insert(int set[])
 {
	   int n,i,x;
	   set[0]=0;
	   printf("\n\n\t\tEnter No. of Students  :\t");
	   scanf("%d",&n);
	   set[0]=n;
	   printf("\n\n\n\t\tEnter Roll no of Student :\n");
	   for(i=1;i<=n;i++)
			scanf("%d",&set[i]);
 }
 void  display(int set[])
 {
	int i,n;
	n=set[0];

	if(n==0)
		printf("\n\n\n\t\t\tNULL SET");
	else
	{
		printf("\n\n\t\t{ ");
		for(i=1;i<=n;i++)
				printf("%d  ",set[i]);
		printf("}");
	}
  }
/*Defination for union */
void Union(int setA[],int setB[],int setC[])
{
	int i,n,n1,m,j,flag;
	n=setA[0];
	for(i=0;i<=n;i++)
		setC[i]=setA[i];
	m=n;
	m++;
	n1=setB[0];
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(setB[i]!=setA[j])
			{
				flag=1;
			}
			else
			{   flag=0;
				break;
			}

		}
		if(flag==1)
		{
		   setC[0]++;
			setC[m]=setB[i];
			m++;
		}
	}

}


/*defination for difference */
void difference(int setA[],int setB[],int setC[])
{
	int i,n,n1,m=1,j,flag=1;
	n=setA[0];
	n1=setB[0];
	setC[0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n1;j++)
		{
			if(setA[i]!=setB[j])
				flag=1;
			else
			{
				flag=0;
				break;
			}
		}
		if(flag==1)
		{
			setC[m]=setA[i];
			setC[0]++;
			m++;
		}
	}
}

