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

void populaGrupos(TTime * grupos[]){
	
}

void escreveResultadosGrupos(TTime timesListados[]){
	int i;
	int saldoGols;
	
	i=0;
	saldoGols=0;
	
	printf("Time        |Pontos     |V  |E  |D  |GP  |GS  |SG\n");
	for(i=0;i<4;i++){
		saldoGols = timesListados[i].golsFeitos - timesListados[i].golsSofridos;
		printf("%s        |%d     |%d  |%d  |%d  |%d  |%d  |%d\n",timesListados[i].nome,timesListados[i].pontos,timesListados[i].vitorias,timesListados[i].empates,timesListados[i].derrotas,timesListados[i].golsFeitos,timesListados[i].golsSofridos,saldoGols);
	}
}
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


void executaGrupo(TTime grupoAtual[],char nomeGrupo) {
	// lembrete esse grupoAtual[] já é vetor de 4 seleções logo grupo[4]
	int i,j,k,l,max;
	
	TTime aux;
	
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++){			
			jogarGrupos(&grupoAtual[i],&grupoAtual[j]);			
		}
	}
	
	// esse for ordena com as regras , e considere a moeda de cara o coroa com a sorte que ele ordena
	for (k = 0; k < 3; k++) {
		max = k;
		for (l = (k+1); l < 4; l++) {
			if(grupoAtual[l].pontos > grupoAtual[max].pontos) {
				max = l;
			}else{
				if(grupoAtual[l].pontos == grupoAtual[max]pontos){
					if(grupoAtual[l].golsFeitos > grupoAtual[max].golsFeitos){
						max = l;
					}else{
						// nesse if a baixo eu considero que os gol feitos tem que ser iguais , logo vai ver quem recebeu menos gol
						if((grupoAtual[l].golsFeitos == grupoAtual[max].golsFeitos) && (grupoAtual[l].golsSofridos < grupoAtual[max].golsSofridos)){
							max = l;
						}
						// assim teria uma possibildiade de golsofrido serem iguais tbm , mas ai nesse caso mantem assim , como se tive-se jogado a moeda, ai ja oredena na sorte
					}
				}
			}
		}
		if (grupoAtual[k] != grupoAtual[max]) {
			aux = grupoAtual[k];
			grupoAtual[k] = grupoAtual[max];
			grupoAtual[max] = aux;
	    }
	}
	
	escreveResultadosGrupos(grupoAtual[]);
}

void faseDeGrupos(char grupo,TTime times[]){
	TTime auxGrupo[4];
	int i;
	
	i = 0;
	
	printf ("Resultados do grupo %c\n\n",grupo);
	for(i=0;i<4;i++){
		if(times[i].grupo == grupo){
			auxGrupo[i] = times[i];						
		}					
	}
	executaGrupo(auxGrupo[],grupo);
}

int main(){	
	//Fase de grupos
	TTime faseGrupos[32];
	populaGrupos(&faseGrupos[]);
	//oitavas
	//quartas
	//semi
	//final
}
