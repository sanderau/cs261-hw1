/* CS261- HW1 - Program5.c*/
/* Name:
 * Date:
 * Solution description:
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

	int sorted = 0, i;
	do
	{
		sorted = 0;
		for(i = 0; i < n-1; i++)
		{
			if(stu[i].initials[0] > stu[i+1].initials[0])
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

			if(stu[i].initials[0] == stu[i].initials[0])
			{
				if(stu[i].initials[1] > stu[i+1].initials[1])
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
    /*Declare an integer n and assign it a value.*/
	
	int n = 20;
    
    /*Allocate memory for n students using malloc.*/
    
	struct student *stu = (struct student *) malloc(n*sizeof(struct student));
	assert(stu != NULL);

    /*Generate random IDs and scores for the n students, using rand().*/
    
	int i;

	for(i = 0; i < n; i++)
	{	
		stu[i].initials[0] = rand()%26 + 'A';
		stu[i].initials[1] = rand()%26 + 'A';
	
		stu[i].score = rand()%100+1;

	}

    /*Print the contents of the array of n students.*/

	printf("****************************************Unsorted****************************************\n");

	for(i = 0; i < n; i++)
	{
		printf("Student %d: %c%c %d\n", i+1, stu[i].initials[0], stu[i].initials[1], stu[i].score);
	}

    /*Pass this array along with n to the sort() function*/
    
	sort(stu, n);

    /*Print the contents of the array of n students.*/
    
	printf("****************************************Sorted****************************************\n");

	for(i = 0; i < n; i++)
	{
		printf("Student %d: %c%c %d\n", i+1, stu[i].initials[0], stu[i].initials[1], stu[i].score);
	}

    return 0;
}
