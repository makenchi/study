#include <stdio.h>
#include <stdlib.h>

void main(){
	file *arq; // cria a vari�vel do arquivo
	
	arq = fopen("endere�o do arquivo","a");//segundo parametro � o m�todo de abertura w= write, r= read, a=append
	if(arq == null){
		printf()//printar que houve um erro ao abrir o arquivo		
	}
	else{
		//come�a a manipular o arquivo
		fclose(arq);//fecha o arquivo ao final da manipula��o
	}
}


