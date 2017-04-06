/* CS261- HW1 - Program4.c*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/  

	int sorted = 0;
	int i;
	do{
		sorted = 0;
		for(i = 0; i < n-1; i++)
		{
			if(number[i] < number[i+1])
			{
				int temp;
				temp = number[i];
				number[i] = number[i+1];
				number[i+1] = temp;
				sorted = 1;
			}
		}

	}while(sorted == 1);
   
}

int main(){
	srand(time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
    	int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    	int *arr = (int *) malloc(n*sizeof(int));
	assert( arr != NULL);
    /*Fill this array with random numbers, using rand().*/
    	int i;
	for(i = 0; i < n; i++)
	{
		arr[i] = rand()%100+1;
	}
    /*Print the contents of the array.*/

	printf("*******************************Unsorted********************************\n");
	
	for(i = 0; i < n; i++)
	{
		printf("%d, ", arr[i]);
	}

	printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/

	sort(arr, n);
    
    /*Print the contents of the array.*/    
    
	printf("***************************Sorted*****************************************\n");

	for(i = 0; i < n; i++)
	{
		printf("%d, ", arr[i]);
	}

	printf("\n");

	free(arr);

    return 0;
}
