#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct times{
	char nome[10];
	char grupo;
	int vitorias;
	int empates;
	int derrota;
	int pontos;
	int golsFeitos;
	int golsSofridos;

} TTime;

//funcao void jogarGrupos(TTime * time1,TTime * time2) - aqui ele vai pegar os dois times , vai usara a funcao retornaGol() para calcular gol, e vai guarda la nas informações do ponteiro , quem ganho ou empato, o numero de gols feitos e recebidos

//funçao void grupo(TTime grupo1[]) - aqui vai ser a faze 1 com todos os 32 times, porem claro pegando os grupo de 4 em 4 por vez, vai fazer cada Time jogar com os outros 3 participantes desse grupo e vai ordena o vetor de acordo com as regras de vitoria derrota e empate + a regras de desempate, ela fazer o vetor ficar ordenado na ordem de vencedores  (exemplo de parametro TTime vetor[4]; tamanho 4 )

//funçao TTime * juntarVencedor(TTime grupo1[],TTime grupo2[]) aqui vc vai pegar o priemrio e segundo ganahdor do grupo A e juntar com o primeiro e segundo do grupo B ""ele salva os 4 vencedores no arquivo "" , ele retorna um vetor do tipo TTime que tem os vencedores pra usar no jogoEliminatoria()

//funcao void Eliminatoria(TTime grupo1[])  -  aqui vc vai fazer o vetor que tem 4 seleções e nele vai "jogar"(jogarEliminatoria()) a seleção da casa 0 do vetor com a casa 3  , e a casa 1 com a casa 2 do vetor(para jogar cruzado) e aqui ele calcula com as vitorias e derrotas quem ficou em 1º , 2º, e ordena o ventor dos vencedores

//função int jogarEliminatoria(TTime time1,TTime time2) - aqui vai pegar os nomes do time e vai usar retornaGol(), se der empate vai simular um penalti com algum rando de 0 e 1, o primeiro time que receber o 0 perde, logo ele retor um numero que vai ser 1 se o primeiro time ganhou ouuu 2 se o segundo time ganhou (obs a parti daqui os dados de gols vitoris derrotas e etc nem são mais salvos só vale o nome)

//OBS os arquivos a parti das eliminatorias não vão conter mais o numero de gols nem vitorias nem derrotas , apenas vão ter os nomes das seleçoes classificadas


int retornaGol(){
	int gols;
	
	srand (time(NULL));	
	gols = rand() % 10 + 1;
	
	return gols;
}

void jogarGrupos(TTime * time1,TTime * time2){
	int gol1,gol2;
	
	gol1 = retornaGol();
	gol2 = retornaGol();
	
	*time1.golsFeitos = *time1.golsFeitos + gol1;
	*time2.golsFeitos = *time2.golsFeitos + gol2;
	
	*time1.golsSofridos = *time1.golsSofridos + gol2;
	*time2.golsSofridos = *time2.golsSofridos + gol1;
	
	if(gol1 > gol2){
		*time1.vitorias++;
		*time2.derrota++;
		
		*time1.pontos = *time1.pontos + 3;
				
	}else {
		if(gol1 < gol2){
			*time2.vitorias++;
			*time1.derrota++;
			
			*time2.pontos = *time2.pontos + 3;
			
		}else{
			*time1.empates++;
			*time2.empates++;
			
			*time1.pontos = *time1.pontos + 1;
			*time2.pontos = *time2.pontos + 1;
			
		}
	}
	
	
}


void grupo(TTime grupo1[]) {
	// lembrete esse grupo1[] já é vetor de 4 seleções logo grupo[4]
	int i,j,k,l,max;
	
	TTime aux;
	
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++){
			
			jogarGrupos(&grupo1[i],&grupo1[j]);
			
		}
	}
	
	// esse for ordena com as regras , e considere a moeda de cara o coroa com a sorte que ele ordena
	for (k = 0; k < 3; k++) {
		max = k;
		for (l = (k+1); l < 4; l++) {
			if(grupo1[l].pontos > grupo1[max].pontos) {
				max = l;
			}else{
				if(grupo1[l].pontos == grupo1[max]pontos){
					if(grupo1[l].golsFeitos > grupo1[max].golsFeitos){
						max = l;
					}else{
						// nesse if a baixo eu considero que os gol feitos tem que ser iguais , logo vai ver quem recebeu menos gol
						if((grupo1[l].golsFeitos == grupo1[max].golsFeitos) && (grupo1[l].golsSofridos < grupo1[max].golsSofridos)){
							max = l;
						}
						// assim teria uma possibildiade de golsofrido serem iguais tbm , mas ai nesse caso mantem assim , como se tive-se jogado a moeda, ai ja oredena na sorte
					}
				}
			}
		}
		if (grupo1[k] != grupo1[max]) {
			aux = grupo1[k];
			grupo1[k] = grupo1[max];
			grupo1[max] = aux;
	    }
	}
	

  }
	
	
	
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
