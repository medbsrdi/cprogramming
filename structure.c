#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
	char name[25+1];
	int age;
	double iq;
}Person;

Person fetchStruct(void);
void showStruct(Person p);

int main(void)
{
	showStruct(fetchStruct());
	return 0;
}

Person fetchStruct(void){
	Person p;
	strcpy(p.name,"Simo Rass Bimo");
	p.age = 19;
	p.iq = 500.;
	return p;
}

void showStruct(Person p){
	printf("Name : %s \n",p.name);
	printf("age : %d \n",p.age);
	printf("IQ : %lf \n",p.iq);
}
