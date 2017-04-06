/* CS261- HW1 - Program3.c*/
/* Name: Austin Sanders
 * Date: 4.5.2017
 * Solution description: used bubble sort to sort the array of of integers
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
			/*bubble sort: if the number to the left is larger than the other then swap the two. Keep doing it till there is no more data to swap*/
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
    	int n = 20;/*size of array*/
    /*Allocate memory for an array of n integers using malloc.*/
    	int *arr = (int *) malloc(n*sizeof(int));
	assert( arr != NULL);/*allocates memory to the array and then checks to make sure it is allocated*/
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
		if(i == n-1) printf("%d", arr[i]);
		else printf("%d, ", arr[i]);
	}

	printf("\n");

    /*Pass this array along with n to the sort() function of part a.*/

	sort(arr, n);
    
    /*Print the contents of the array.*/    
    
	printf("***************************Sorted*****************************************\n");

	for(i = 0; i < n; i++)
	{
		if(i == n-1) printf("%d", arr[i]);
		else printf("%d, ", arr[i]);
	}

	printf("\n");

	free(arr);

    return 0;
}
