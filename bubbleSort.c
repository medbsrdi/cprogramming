#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define SIZE 10

int  compare(const void *x,const void *y);

int main(void)
{
	int numbers[SIZE];
	int i,outer,inner,tmp;
	// populate the array 
	srand((unsigned)time(NULL));
	for(i = 0 ; i < SIZE ; i++)
		numbers[i] = rand()%100 + 1;
	// Display the unsorted array
	printf("unsorted Array :");
	for(i = 0 ; i < SIZE ; i++)
		printf(" %3d",numbers[i]);
	putchar('\n');
	// using qsort funciotn
	qsort(numbers,SIZE,sizeof(int),compare);
	
	// Sort the array 
//	for(outer = 0 ; outer < SIZE ; outer++)
//	{
//		for(inner = outer+1 ; inner < SIZE ; inner++)
//		{
//			if(numbers[outer] > numbers[inner])
//			{
//				 tmp = numbers[inner];
//				 numbers[inner] = numbers[outer];
//				 numbers[outer] = tmp;
//			}
//		}
//	}
	// Display sorted array
	printf("Sorted array :");
	for(i = 0 ; i < SIZE ; i++)
		printf(" %3d",numbers[i]);
	putchar('\n');
	return 0;
}

int compare(const void *x,const void *y)
{
	return (*(int *)x - *(int *)y);
}
