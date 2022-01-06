#include<stdlib.h>
#include<stdio.h>

typedef struct{
	int *A;
	int length;
	int size;
}Array;

void Display(Array arr)
{
	int i;
	for( i = 0 ; i < arr.length ; i++)
			printf("%d ,",arr.A[i]);
	printf("\n");
}

//add(x)/Append(x)
void Append(Array *a,int elm)
{
	a->A[a->length++] = elm;
}

// insert(index,element)
void Insert(Array *a,int index,int elm)
{
	int i;
	if(!(index >= 0 && index <= a->length))
	{
		return;	
	}
	for(i = a->length ; i > index ; i--)
	{
		a->A[i] = a->A[i-1];
	}
	a->A[index] = elm;
	a->length++;
}

int Delete(Array *a,int index)
{
	int i,x;
	if(!(index >= 0 && index <= a->length))
	{
		return INT_MIN;
	}
	x = a->A[index];
	for(i = index ; i < a->length - 1 ; i++)
	{
		a->A[i] = a->A[i+1];
	}
	a->length--;
	return x;
}

int LinearSearch(Array arr,int elm)
{
	int i;
	for(i = 0 ; i < arr.length ; i++)
	{
		if(elm == arr.A[i])
		{
			return i;
		}
	}
	return -1; // element is not present on the list
}

// improving LinearSearch function using Swap 
/* 
	Whenever you search for an elemnt swap it with the previous one
	That's reduce the time complexity the idea here is that when you search
	for something in stack and you find it there is a big possibiliyt to search for
	it again
	(Transposition)
*/

// ****  Transposition **** /
int TranspositionLinearSearch(Array *arr,int elm)
{
	int i,tmp;
	for(i = 0 ; i < arr->length; i++)
	{
		if(elm == arr->A[i])
		{
			tmp = arr->A[i];
			arr->A[i] = arr->A[i-1];
			arr->A[i-1] = tmp;
			return i;	
		}
	}
	return -1;
}

void swap(int *x,int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

// Second method is swapping with first element next time
// when you will search for it you will find it in a constant time
// (move to front / move to head)

//**** move to front ****
int mvHeadLinearSearch(Array *a,int elm)
{
	int i,tmp;
	for(i = 0 ; i < a->length ; i++)
	{
		if(elm == a->A[i])
		{
			swap(&a->A[i],&a->A[0]);
			return i;
		}
	}
	return -1;
}


// Binary Search 
// The condition is that the element of an arry must be sorted
// first steps low(l = 0) , height(h = length), mid = (l+h)/2;
// if the key element is greather then the mid elemnt l = mid else h = mid

// time is taken by the BinarySearch is log(n) 
/*
	let's take for example 
			16 element in an arry we do the following step to find the key element
	1- 16/2 if found stop
	2- 16/2/2 if foun stop
	3- ........
	4- 16/2^4 maximum you can find
	2^4 = 16
	log2(16) = 4 
*/
int BinarySearch(Array arr,int elm)
{
	int l,h,mid;
	l = 0;
	h = arr.length-1;
	mid = (l+h)/2;
	while(l <= h)
	{
		if(elm == arr.A[mid])
		{
			return mid;
		}else if(elm < arr.A[mid]){
			h = mid-1;
		}else{
			l = mid+1;
		}
		mid = (l+h)/2;
	}	
	return -1;
}

// Recursive Version
int RBinarySearch(Array a,int l,int h,int elm)
{
	int mid;
	if(l<=h)
	{
		mid = (l+h)/2;
		if(elm == a.A[mid])
		{
			return mid;
		}else if (elm < a.A[mid]){
			return RBinarySearch(a,l,mid-1,elm);
		}else{
			return RBinarySearch(a,mid+1,h,elm);
		}
	}
}

// Get(index)
// first checking the valid index
// if(index>= 0 && index < length)
// time complexity is constent
// set(index , value) => same as get operation
// max(array) => traversing all the element to get the max
// Recursive Sum(array,length) => A[n] + Sum(A,n-1);


int Get(int index,Array a)
{
	if(index >= 0 && index <a.length)
	{
		return a.A[index];
	}
	return INT_MIN;
}

void Set(int index,int value,Array *a)
{
	if(index >= 0 && index < a->length){
		a->A[index] = value;
	}else{
		printf("Invalid index \n");
	}	
}

int Max(const Array arr)
{
	int max = arr.A[0];
	int i;
	for(i = 1 ; i < arr.length ; i++)
	{
		if(arr.A[i] > max)
		{
			max = arr.A[i];
		}
	}
	return max;
}

int Min(Array arr)
{
	int min = arr.A[0];
	int i;
	for(i = 1 ; i < arr.length ; i++)
	{
		if(arr.A[i] < min)
		{
			min = arr.A[i];
		}
	}
	return min;
}

int Sum(Array arr)
{
	int sum = 0;
	int i;
	for(i = 0 ; i < arr.length ; i++)
	{
		sum += arr.A[i];
	}
	return sum;
}

double Avg(Array arr)
{
	return (double)Sum(arr)/arr.length;
}

// Reversing the element of an array
// 1st method creating an auxilary array storing from last index to it
// 2st scan from two ends of an array and interchange the element 
//Shifting / Rotate
// Shifting by 1:
// ABCDE --> BCDE0
// Rotate by 1:
// ABCDE --> BCDEA

void Reverse(Array *arr)
{
	int B[arr->length];
	int i;
	for(i = arr->length-1 ; i >=0 ; i--)
	{
		B[i] = arr->A[arr->length-i-1];
	}
	for(i = 0 ; i < arr->length ; i++)
	{
		arr->A[i] = B[i];
	}
}

void ReverseT(Array *arr)
{
	int i,j;
	for(i = 0 , j = arr->length-1 ; i < j ; i++ , j--)
	{
		swap(&arr->A[i],&arr->A[j]);
	}
}

void leftShift(Array *arr)
{
	int i,tmp;
	for(i = 0 ; i < arr->length-1 ; i++)
		arr->A[i] = arr->A[i+1];
	arr->A[arr->length-1] = 0;
}



void leftRotate(Array *arr)
{
	int i,tmp;
	tmp = arr->A[0];
	leftShift(arr);
	arr->A[arr->length-1] = tmp;	
}


void RightShift(Array *arr)
{
	int i;
	for(i = arr->length -1 ; i > 0 ; i--)
	{
		arr->A[i] = arr->A[i-1];
	}
	arr->A[0] = 0;
}

void RightRotate(Array *arr)
{
	int i,tmp;
	tmp = arr->A[arr->length-1];
	RightShift(arr);
	arr->A[0] = tmp;
}

// Inserting in a sorted Array 
// Checking if an Array is Sorted
// Arranging-elms on left Side

void InsertingSorted(Array *arr,int elm)
{
	int i;
	i = arr->length-1;
	if(arr->length == arr->size)
		return;
	while(arr->A[i] > elm)
	{
		arr->A[i+1] = arr->A[i];
		i--;
	}
	arr->A[i+1] = elm;
	arr->length++;
}

int isSorted(Array arr)
{
	int i;
	for(i = 0 ; i < arr.length-1 ; i++)
	{
		if(arr.A[i] > arr.A[i+1])
		{
			return 0;
		}
	}
	return 1;
}


// Arrenging all the negative element to the left side
// O(n) 
void reArrengin(Array *arr)
{
	int i=0,j = arr->length-1;
	while(i<j)
	{
		while(arr->A[i] < 0) i++;
		while(arr->A[j] >= 0) j--;
		if(i<j)
		{
			swap(&arr->A[i],&arr->A[j]);	
		}	
	}	
}


// Merging can only be done in sorted array
Array * Merging(Array arr1,Array arr2)
{
	int i,j,k;
	i = j = k = 0;
	Array *cm;
	cm = (Array *)malloc(sizeof(Array));
	while(i < arr1.length && j < arr1.length)
	{
		if(arr1.A[i] < arr2.A[j])
			cm->A[k++] = arr1.A[i++];
		else
			cm->A[k++] = arr2.A[j++];
	}
	// there will be some element missing
	for(; i < arr1.length ; i++)
		cm->A[k++] = arr1.A[i];
	
	for(; j < arr2.length ; j++)
		cm->A[k++] = arr2.A[j];
	
	cm->length = arr1.length + arr2.length;	
	cm->size = 90;
	return cm;
}


Array * Union(Array arr1,Array arr2)
{
	int i,j,k;
	i = j = k = 0;
	Array *cm;
	cm = (Array *)malloc(sizeof(Array));
	while(i < arr1.length && j < arr1.length)
	{
		if(arr1.A[i] < arr2.A[j])
			cm->A[k++] = arr1.A[i++];
		else if(arr2.A[j] < arr1.A[i])
			cm->A[k++] = arr2.A[j++];
		else 
		{
			cm->A[k++] = arr1.A[i++];
			j++;	
		}	
	}
	// there will be some element missing
	for(; i < arr1.length ; i++)
		cm->A[k++] = arr1.A[i];
	
	for(; j < arr2.length ; j++)
		cm->A[k++] = arr2.A[j];
	
	cm->length = k;	
	cm->size = 90;
	return cm;
}


Array * Intersection(Array arr1,Array arr2)
{
	int i,j,k;
	i = j = k = 0;
	Array *cm;
	cm = (Array *)malloc(sizeof(Array));
	while(i < arr1.length && j < arr1.length)
	{
		if(arr1.A[i] < arr2.A[j])
			i++;
		else if(arr2.A[j] < arr1.A[i])
			j++;
		else 
		{
			cm->A[k++] = arr1.A[i++];
			j++;	
		}	
	}
	cm->length = k;	
	cm->size = 90;
	return cm;
}


int main(void)
{
	int choice,elm,index,r;
	Array arr1;
	printf("Size of the array :");
	scanf("%d",&arr1.size);
	arr1.A = (int *)malloc(arr1.size * sizeof(int));
	arr1.length = 0;
	do{
		printf("Menu \n");
		printf("1. Insert \n");
		printf("2. Delete \n");
		printf("3. Search \n");
		printf("4. Sum \n");
		printf("5. Display \n");
		printf("6. Exit \n");
		
		printf("Enter you Choice :");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:printf("Enter the element and index (elm index) :");
				scanf("%d %d",&elm,&index);
				Insert(&arr1,index,elm);
				break;
			case 2:
				printf("Enter the Index of the element you want to delete  :");
				scanf("%d",&index);
				r = Delete(&arr1,index);
				printf("%d was Deleted\n",r);
				break;
			case 3:
				printf("Enter the element you want to search :");
				scanf("%d",&elm);
				r = mvHeadLinearSearch(&arr1,elm);
				printf("The element is at index %d \n",r);
				break;
			case 4:
				r = Sum(arr1);
				printf("The sum of all element is %d \n",r);
				break;
			case 5:Display(arr1);
		}
	}while(choice < 6);
	
	
	return 0;
}
