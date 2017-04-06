/* CS261- HW1 - Program2.c*/

/* Name: Austin Sanders
 * Date: 4.5.17
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>/*so i can error check malloc*/
#include <time.h>/*used to seed random*/

int foo(int* a, int* b, int c){
    /* Increment a */
	
	(*a)++;    /*dereference then increment a*/

    /* Decrement  b */

	(*b)--;	/*dereference then decrement b*/
    
    /* Assign a-b to c */
    
	c = (*a) - (*b);	/*dereference both pointers so I am manipulating their values not using pointer arithmetic*/

    /* Return c */

	return c; /*return C's value*/
}

int main(){

	srand(time(NULL));
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	int *x, *y;

	x = (int *) malloc(sizeof(int));
	assert(x != NULL);

	y = (int *) malloc(sizeof(int));
	assert(y != NULL);

	int z;
	*x = rand()%10+1;
	*y = rand()%10+1;
	z = rand()%10+1;

    /* Print the values of x, y and z */

	printf("x:%d\ny:%d\nz:%d\n\n", *x, *y, z);
    
    /* Call foo() appropriately, passing x,y,z as parameters */
    
	int rVal = foo(x,y,z);

    /* Print the values of x, y and z */

	printf("Here are the values after foo is called.\nx:%d\ny:%d\nz:%d\n\n", *x, *y, z);
    
    /* Print the value returned by foo */
		
	printf("Here is the value returned by foo: %d\n", rVal);
 
    /* Is the return value different than the value of z?  Why? */

	/* Yes there is a different return value because the c in foo only exists during its execution, while the pointers
		arent local data types. The pointers point to a memory address already created before the function call so
		any and all modifications to the data will be permanent at that address, while c and its data will be deleted
		after foo is done being called. if the paramter list was foo( int *a, int *b, int &c); all changes to z would
		be saved */

    return 0;
}
    
    
