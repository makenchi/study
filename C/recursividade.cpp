#include <stdio.h>
#include <stdlib.h>

int fatorial(int x){
	
	if(x > 0){
		//caso geral da recursão
		return x*fatorial(x-1);
	}
	else{
		//caso base da recursão
		return 1;
	}	
}

int main(){
	int n;
	int resp;
	n = 0;
	resp = 0;
	
	printf("Digite um numero para ser feito seu fatorial: ");
	scanf("%d",&n);
	
	resp = fatorial(n);
	//Quando printar a resposta não confundir n com &n
	//n = valor da variavel
	//&n = endereço de memoria da variavel
	printf("Resposta do fatorial de %d: %d",n,resp);
	
	return 0;
}
