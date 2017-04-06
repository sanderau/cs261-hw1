/* CS261- HW1 - Program4.c*/
/* Name: Austin Sanders
 * Date: 4.5.2017
 * Solution description: create an array of n students, and print all of them out. Pass student and the size of the array. The function uses bubble sort to
	sort the initials. Once the function is done the student array is printed out once again in order.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define true 1
#define false 0


struct student{
	char initials[2];
	int score;
};

void sort(struct student* stu, int n)
{
     /*Sort the n students based on their initials*/     
	if(stu == NULL) return;

	int sorted = 0, i;
	do
	{
		sorted = 0;
		for(i = 0; i < n-1; i++)
		{
			if(stu[i].initials[0] > stu[i+1].initials[0])/*if the first initial is larger than the switch the two*/
			{
				/*store one students data in temporary data types*/
				char c1, c2;
				int sc;
				c1 = stu[i].initials[0];
				c2 = stu[i].initials[1];
				sc = stu[i].score;
	
				/*swaps the data between two students*/

				stu[i].initials[0] = stu[i+1].initials[0];
				stu[i].initials[1] = stu[i+1].initials[1];
				stu[i].score = stu[i+1].score;

				/*swaps the temp values*/

				stu[i+1].initials[0] = c1;
				stu[i+1].initials[1] = c2;
				stu[i+1].score = sc;

				/*sets sorted to true*/

				sorted = 1;
			}		

			if(stu[i].initials[0] == stu[i+1].initials[0]) /*if the people have the same initial then check to the second*/
			{
				if(stu[i].initials[1] > stu[i+1].initials[1])/*if the second one is out of order swap the same way as last time*/
				{
					char c1, c2;
					int sc;
					c1 = stu[i].initials[0];
					c2 = stu[i].initials[1];
					sc = stu[i].score;
	
					stu[i].initials[0] = stu[i+1].initials[0];
					stu[i].initials[1] = stu[i+1].initials[1];
					stu[i].score = stu[i+1].score;

					stu[i+1].initials[0] = c1;
					stu[i+1].initials[1] = c2;
					stu[i+1].score = sc;

					sorted = 1;
				}		
			}	

		}
	}while(sorted == 1);
}

int main(){
	srand(time(NULL));
	/*Declare an integer n and assign it a value.*/
	
	int n = 20; /*size of array of students*/
    
    /*Allocate memory for n students using malloc.*/
    
	/*creates an array of students and checks to make sure the memory is allocated */
	struct student *stu = (struct student *) malloc(n*sizeof(struct student));
	assert(stu != NULL);

    /*Generate random IDs and scores for the n students, using rand().*/
    
	/* assigns random data to all of the students */

	int i;

	for(i = 0; i < n; i++)
	{	
		stu[i].initials[0] = rand()%26 + 'A';
		stu[i].initials[1] = rand()%26 + 'A';
	
		stu[i].score = rand()%100+1;

	}

    /*Print the contents of the array of n students.*/


	/*prints out all of the data unsorted*/
	printf("****************************************Unsorted****************************************\n");

	for(i = 0; i < n; i++)
	{
		printf("Student %d: %c%c %d\n", i+1, stu[i].initials[0], stu[i].initials[1], stu[i].score);
	}

    /*Pass this array along with n to the sort() function*/
    
	sort(stu, n);/*sorts all of the data*/

    /*Print the contents of the array of n students.*/
    
	printf("****************************************Sorted****************************************\n");

	for(i = 0; i < n; i++)
	{
		printf("Student %d: %c%c %d\n", i+1, stu[i].initials[0], stu[i].initials[1], stu[i].score);
	}

    return 0;
}
