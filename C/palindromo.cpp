#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int palindromo(char s[]){
	
	int i;
	int j;
	
	for(i=0,j=strlen(s)-1;i<j;i++,j--){
		if(s[i] != s[j]){
			return 0;
		}
	}
	return 1;
}

int palindromoRecursivo(char s[],int p1, int p2){
	char s1;
	char s2;
	
	s1 = s[p1];
	s2 = s[p2];
	
	if(s1 != s2 || p2<=p1){
		return 0;
	}
	else{
		palindromoRecursivo(s,p1+1,p2-1);
	}
	return 1;
}

int main(){
	
	char palavra[30];
	int validaPalindromo;
	int validaPalindromo2;
	
	printf("Digite uma palavra: ");
	gets(palavra);
	
	validaPalindromo = palindromo(palavra);
	validaPalindromo2 = palindromoRecursivo(palavra,0,strlen(palavra)-1);
	printf("\nITERATIVO\n");
	if(validaPalindromo == 1){
		printf("Essa palavra eh um palindromo\n\n");
	}
	else{
		printf("Essa palavra nao eh um palindromo\n\n");
	}
	
	printf("RECURSIVO\n");
	if(validaPalindromo2 == 1){
		printf("Essa palavra eh um palindromo\n\n");
	}
	else{
		printf("Essa palavra nao eh um palindromo\n\n");
	}
	return 0;
}
