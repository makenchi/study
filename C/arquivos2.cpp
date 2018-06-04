#include <stdio.h>
#include <stdlib.h>

int gerarArquivo(char *nomeArq, int n){
	file *A;
	int i;
	
	A = fopen(nomeArq,"w");
	if((A==null) || (n<=0)){
		return 0;
	}
	else{
		for(i=1;i<=n;i++){
			fprintf(A,"%d\n",i);
		}
		fclose(A);
		return 1;
	}
}

int somaArquivo(char *nome){
	file *A;
	int soma;
	int num;
	
	A = fopen(nome,"r");
	
	if(A==null){
		return 0;
	}
	else{
		while(!feof(A)){
			fscanf(A,"%d\n",&num);
			soma = soma+num
		}
		return soma;
	}
}
