#include<stdlib.h>
#include<stdio.h>

int isPrimeN(int n)
{
	int i;
	for(i = 2 ; i < n/2 ; i++)
	{
		if(n%i == 0) return 0; 
	}
	return 1;
}

int * primeArray(){
	static int Arr[10],i,j;
	for(i =1 ,j=0; i < 10 ; i++)
	{
		if(isPrimeN(i)) Arr[j++] = i;
	}
	return Arr;
}

char *repeat(char r)
{
	int i;
	static char string[32];
	
	for(i = 0 ; i < 32 ; i++)
	{
		string[i] = r;
	}
	
	return string;
}

int main(int argc,char **argv)
{
	int *p;
	p = primeArray();
	int i;
	for(i = 0 ; i < 10 ; i++)
	{
		printf("%d  ",p[i]);
	}
	return 0;
}
