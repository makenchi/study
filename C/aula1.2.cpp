#include <stdio.h>
#include <stdlib.h>

void ordena(float *a, float *b, float *c){
	float aux;
	
	aux = 0;
	
	if(*a > *b){
		aux = *a;
		*a = *b;
		*b = aux;
	}
	
	if(*a > *c){
		aux = *a;
		*a = *c;
		*c = aux;
	}
	
	if(*b > *c){
		aux = *b;
		*b = *c;
		*c = aux;
	}		
}

int main(){
	float n1;
	float n2;
	float n3;
	
	n1 = 0;
	n2 = 0;
	n3 = 0;
	
	printf("Escreva 3 numeros: ");
	scanf("%f %f %f",&n1,&n2,&n3);
	
	printf("Antes da funcao /n");
	printf("A: %f, B: %f, C: %f",n1,n2,n3);
	
	ordena(&n1,&n2,&n3);
	
	printf("Dipois da funcao /n");
	printf("A: %f, B: %f, C: %f",n1,n2,n3);
		
	return 1;
}
