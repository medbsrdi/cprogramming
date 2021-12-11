#include<stdlib.h>
#include<stdio.h>

#define SIZE 100


void UpperCaseEsp(char *p,size_t length){
	int i;
	for(i = 0 ; i < length ; i++)
	{
		if(p[i] >= 'a' && p[i] <= 'z'){
			p[i] -= 'a'-'A';
		}
		if(p[i] == ' ')
		{
			p[i] = '-';
		}
	}
}

void modify(char *p){
	while(*p){
		*p = toupper(*p);
		if(*p == ' '){
			*p = '_';
		}
		p++;
	}
}

void modifyA(char *p)
{
	int i = 0;
	while(p[i])
	{
		p[i] = toupper(p[i]);
		if(p[i] == ' ') p[i] = '_';
		i++;
	}
}

int main(void){
	char array[SIZE];
	printf("string :");
	fgets(array,99,stdin);
	printf("befor \n");
	puts(array);
	UpperCaseEsp(array,strlen(array));
	puts(array);

	
	return 0;	
}
