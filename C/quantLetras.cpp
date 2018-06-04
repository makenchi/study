#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int quantLetras(char s[], char letra){
	int tam = strlen(s);
	int i;
	int cont;
	cont = 0;
	
	for(i=0;i<tam;i++){
		if(s[i] == letra){
			cont++;
		}
	}
	
	return cont;
}

int quantLetraRecursiv(char s[], char letra, int total,int comeco){
	if(s[comeco] == letra){
		total++;
	}
	
	if(s[comeco]=='\0'){
		return total;
	}
	else{
		quantLetraRecursiv(s,letra,total,comeco+1);
	}
}

int main(){
	
	int result;
	int result2;
	char palavra[50];
	char letra;
	
	printf("Digite uma palavra: ");
	gets(palavra);
	
	printf("Digite uma letra: ");
	scanf("%c",&letra);
	
	result = quantLetras(palavra,letra);
	result2 = quantLetraRecursiv(palavra,letra,0,0);
	
	printf("\nITERATIVO\n");
	if(result > 0){
		printf("A palavra tem %d letras %c\n",result,letra);
	}
	else{
		printf("A palavra nao tem a letra %c\n",letra);
	}
	
	printf("RECURSIVO\n");
	if(result2 > 0){
		printf("A palavra tem %d letras %c\n",result2,letra);
	}
	else{
		printf("A palavra nao tem a letra %c\n",letra);
	}	
	
	return 0;
}
