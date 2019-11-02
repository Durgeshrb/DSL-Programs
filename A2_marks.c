/*
 *                                       Assignment No. A2
 * Write C/C++ program to store marks scored for first test of subject 'Data Structures and Algorithms' for N students.
 * Compute
 * I. The average score of class
 * II. Highest score and lowest score of class
 * III. Marks scored by most of the students
 * IV. List of students who were absent for the test
 *
 */

#include<stdio.h>
#define MAX 20

int main()
{
	int stud_roll[MAX], stud_marks[MAX];
	char status[MAX];
	int n, cnt=0,i;
	float avg, total=0;
	printf("\n\t\t---------------------------------------------");
	printf("\n\nEnter number of students in class :: ");
	scanf("%d",&n);
	printf("\n\nEnter roll number and marks of DSA \n\nPlease enter '-1' for absent student :: ");
	for(i=0;i<n;i++)
	{
		printf("\n\nEnter roll number :: ");
		scanf("%d",&stud_roll[i]);
		printf("\nEnter marks for roll number %d :: ",stud_roll[i]);
		scanf("%d",&stud_marks[i]);

		if(stud_marks[i]>=40)
			status[i]= 'P';

		else if(stud_marks[i]<40 && stud_marks[i]>=0)
			status[i] = 'F';
		else
			status[i] = 'A';
	}


	//Display result
	printf("\n\t\t---------------------------------------------");
	printf("\n\n\n\t\t***** RESULT ANALYSIS ***** \n");
	printf("\n\n\n\t Marks 40 and above is pass. The marks '-1' shows student is absent  :: \n");
	printf("\n\t\t---------------------------------------------");
	printf("\n\n\t\tRoll No.\t\t Marks\t\t Status");
	printf("\n\t\t---------------------------------------------");

	for(i=0; i<n; i++)
	{
		printf("\n\t\t\t%d\t\t  %d\t\t  %c",stud_roll[i],stud_marks[i],status[i]);
	}
	printf("\n\t\t---------------------------------------------");



//Average Score of Class
	
	for( i=0;i<n;i++)
	{
		if(stud_marks[i]>-1)
		{
			total += stud_marks[i];
			cnt++;
		}
	}
	avg = total/cnt;
	
	printf("\n\n\t1. Average score of class :: %f",avg);

	int min, max1;
	max1 = stud_marks[0];
	min = stud_marks[0];
	

	// Minimum Marks
	for( i=0;i<n;i++)
	{
		if(stud_marks[i]<min && stud_marks[i]>-1)

			min=stud_marks[i];

	}


	//Maximum Marks
	for(i=0;i<n;i++)
	{
		if(stud_marks[i]>max1)

			max1=stud_marks[i];

	}
	printf("\n\n\n\t2. Highest Score :: %d \tLowest Score :: %d",max1,min);


//Marks scored by most students

	printf("\n\n\n\t3. The DSA marks scored by most student data. \n\n\t\t List of student who scored above average marks :: \n");
	printf("\n\t\t---------------------------------------------");
	printf("\n\n\t\t\tRoll No. \t Marks ");
	printf("\n\t\t---------------------------------------------");
	for(i=0;i<n;i++)
	{
		if(stud_marks[i]>=avg)
			printf("\n\t\t\t %d  \t\t  %d  ",stud_roll[i],stud_marks[i]);
	}
	printf("\n\t\t---------------------------------------------");


// List Absent Students
	cnt = 0;
	printf("\n\n\n\t4. Roll numbers of Absent Students :: ");
	for(i=0;i<n;i++)
	{
		if(stud_marks[i]<=-1)
		{
			printf("\t%d",stud_roll[i]);
			cnt++;
		}
	}
	printf("\n\n ");
	if(cnt==0)
		printf("\n\n\tNo students were absent for test\n\n");

	return 0;
}

