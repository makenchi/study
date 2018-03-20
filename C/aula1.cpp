#include <stdio.h>
#include <stdlib.h>

int somaAte(int ate){
	int soma;
	int i;
	
	i = 0;
	soma = 0;
	
	for(i; i<ate;i++){
		soma += i+1;
	}
	
	return soma;
}

int main(){
	int valorUsu;
	int result;
	
	valorUsu = 0;
	result = 0;
	
	printf("Escreva o numero fim: ");
	scanf("%d",&valorUsu);
	
	result = somaAte(valorUsu);
	printf("Valor do resultado: %d",result);
	
	return 1;
}
