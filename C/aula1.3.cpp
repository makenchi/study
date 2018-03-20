#include <stdio.h>
#include <stdlib.h>

void maiorMenor(float vetor[]), int tam, float *menor, float *maior{	
	*maior = vetor[0];
	*menor = vetor[0];
	
	for(i=1;i<tam;i++){
		if(vetor[i] > *maior){
			*maior = vetor[i];
		}
		
		if(vetor[i] < *menor){
			*menor = vetor[i];
		}
	}
}

int main(){
	float v1[10]{3,10,8,1,34,24,5,12,63,52};
	float v2[20];
	float ma1;
	float me1;
	float ma2;
	float me2;
	int i;
	
	return 1;
}
