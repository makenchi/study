#include <stdio.h>
#include <stdlib.h>

void main(){
	file *arq; // cria a variável do arquivo
	
	arq = fopen("endereço do arquivo","a");//segundo parametro é o método de abertura w= write, r= read, a=append
	if(arq == null){
		printf()//printar que houve um erro ao abrir o arquivo		
	}
	else{
		//começa a manipular o arquivo
		fclose(arq);//fecha o arquivo ao final da manipulação
	}
}


