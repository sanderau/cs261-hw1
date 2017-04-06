/* CS261- HW1 - Program2.c*/
/* Name: Austin Sanders
 * Date: 4.4.17
 * Solution description: allocates memory for a student array. Fills in the information randomly. Outputs all information. Calculates min max and average of all the scores.
 */
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include <time.h>
#include <assert.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/	
	struct student *s_arr = (struct student *) malloc(10*sizeof(struct student));     
	assert(s_arr != NULL);/*allocate memory and check to make sure it is allocated*/

     /*return the pointer*/
	return s_arr;/*return the pointer to the memory*/
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
	The two initial letters must be capital and must be between A and Z. 
	The scores must be between 0 and 100*/

	int i;

	/*generates random number for score and two random initials*/
	for(i = 0; i < 10; i++)
	{
		char c1,c2;
		int s;
		c1 = rand()%26 + 'A';
		c2 = rand()%26 + 'A';
		s = rand()%100+1;

		students[i].initials[0] = c1;
		students[i].initials[1] = c2;
		students[i].score = s;

	}
     
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/

		printf("*****************Output Student Data**************************\n");

		int i;
		for(i = 0; i < 10; i++)
		{
			printf("Student %d: %c%c %d\n", i+1, students[i].initials[0], students[i].initials[1], students[i].score);
		}

		printf("\n\n");
}

void summary(struct student* students)
{
     /*Compute and print the minimum, maximum and average scores of the ten students*/
	printf("**************************Student Summary******************************\n");
	int i, min =100, max = 0, avg = 0;

	for(i = 0; i < 10; i++)
	{
		if(students[i].score > max) max = students[i].score;
		
		if(students[i].score < min) min = students[i].score;

		avg += students[i].score;
	} 

	avg /= 10;

	printf("Max: %d\nMin: %d\nAverage: %d\n\n",max,min,avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	free(stud);
}

int main()
{

	struct student *students = NULL;

	/*allocates memory for the student */

	students = allocate();

	/*generates random number and two randome letters*/

	generate(students);

	/*outputs this data*/

	output(students);

	/*prints out max min and average test scores*/

	summary(students);

	/*frees the memory*/

	deallocate(students);

	return 0;
}
