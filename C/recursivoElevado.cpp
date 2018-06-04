#include <stdio.h>
#include <stdlib.h>

int potencia(int numero, int elevado){
	if(elevado > 0){
		return numero*potencia(numero,elevado-1);
	}
	else{
		return 1;
	}
}

int main(){
	int num;
	int elev;
	int resp;
	
	num = 0;
	elev = 0;
	resp = 0;
	
	printf("Digite um numero: ");
	scanf("%d",&num);
	printf("Vai ser elevado a quanto? ");
	scanf("%d",&elev);
	
	resp = potencia(num,elev);
	
	printf("Valor de %d elevado a %d = %d",num,elev,resp);
	return 0;
}
