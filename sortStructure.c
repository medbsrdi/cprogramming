#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char day[15+1];
	double temperature;
}Statistic;

// only the = operation are allowed in structure

void swapS(Statistic *t,Statistic *d){
	Statistic tmp;
	
	tmp = *t;
	*t = *d;
	*d = tmp;
}

void sortS(Statistic *t,size_t length)
{
	int i,j;
	for(i = 0 ; i < length ; i++)
	{
		for( j = i+1 ; j < length ; j++)
		{
			if(t[i].temperature >= t[j].temperature)
			{
				swapS(&t[i],&t[j]);
			}
		}
	}

}

void Display(const Statistic * arr)
{
	int i;
	for(i = 0 ; i < 7 ; i++)
	{
		printf("%s : %lf \n",arr[i].day,arr[i].temperature);
	}
}

int main(void){
	Statistic t[7] = {
		{"Monday",23.34},
		{"Friday",30},
		{"Tuersday",25},
		{"Sunday",10},
		{"Thuersday",33},
		{"Suterday",20},
		{"Wednesday",23}
	};
	
	Display(t);
	
	printf("\n Sorted based on tempuratore \n \n");
	sortS(t,7);
	Display(t);	
	return 0;
}
