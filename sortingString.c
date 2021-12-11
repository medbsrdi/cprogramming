#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define SIZE 30

int compare(const void *a,const void *b);

int main(void)
{
	char String[SIZE];
	char tmp;
	int length,i,j;
	printf("enter The String :");
	fgets(String,SIZE,stdin);
	length = strlen(String);
	qsort(String,length,sizeof(char),compare);
//	for(i = 0 ; i < length ; i++)
//	{
//		for(j = i+1 ; j < length ; j++)
//		{
//			if(String[i] > String[j]){
//				tmp = String[i];
//				String[i] = String[j];
//				String[j] = tmp;
//			}
//		}
//	}
	printf("Sorted String :");
	fputs(String,stdout);	
	return 0;
}

int compare(const void *a,const void *b){
	return (*(char *)a - *(char *)b);
}
