#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct times{
	char nome[10];
	char grupo;
	int vitorias;
	int empates;
	int derrota;
	int golsFeitos;
	int golsSofridos;
	int saldoDeGols;
} TTime;

int retornaGol(){
	int gols;
	
	srand (time(NULL));	
	gols = rand() % 10 + 1;
	
	return gols;
}

void faseDeGrupos(char grupo){
	switch (opcao)
	{
		//Grupo A
		case 1: printf ("Resultados do grupo A\n");

				break;
			
		//Grupo B
		case 2: printf ("Resultados do grupo B\n");

				break;
			
		//Grupo C
		case 3: printf ("Resultados do grupo C\n");
		        
				break;
			
		//Grupo D
		case 4: printf ("Resultados do grupo D\n");
		        
				break;
			
		//Grupo E
		case 5: printf ("Resultados do grupo E\n");
		        break;
			
		//Grupo F
		case 6: printf ("Resultados do grupo F\n");
		        break;
		        
		//Grupo G        
		case 6: printf ("Resultados do grupo G\n");
		        break;
		        
		//Grupo H        
		case 6: printf ("Resultados do grupo H\n");
		        break;		        		        		        
	}	
}
int main(){	
	//Fase de grupos
	
	//oitavas
	//quartas
	//semi
	//final
}
