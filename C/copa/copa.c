#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Trabalho feito por
//Lucas Silva dos Santos
//Gabriel Ferreira

typedef struct {
	char nome[20];
	char grupo;
	int vitorias;
	int empates;
	int derrotas;
	int pontos;
	int golsFeitos;
	int golsSofridos;
} TTime;

void populaGrupos(TTime * grupos[]){
	FILE *A;
	char linha[30];
	int prox;
	
	prox = 0;
	A = fopen("faseinicial.txt","r");
	
	if(A==null){
		printf("Erro ao abrir o arquivo inicial");
		return;
	}
	else{
		while(!feof(A)){
			fscanf(A,"%s\n",&linha);
			int j;
			int separador;
			
			j = 0;
			separador=0;
			
			for(j=0;j < strlen(linha);j++)	{
				if(linha[j] == ";"){
					separador++;
				}
				else{
					switch (separador)
					{
						//Sele��o
						case 0:
					        * grupos[prox].nome[j] = linha[j];
						break;
					
						//Grupo
						case 1:
							* grupos[prox].nome[j-1] = "\0"; 
							* grupos[prox].grupo = linha[j];
						break;
	
						//Vitoria
						case 2: 
							* grupos[prox].vitorias = (int) linha[j];
						break;
						
						//Empate
						case 3: 
							* grupos[prox].empates = (int) linha[j];
						break;
						
						//Derrota
						case 4: 
							* grupos[prox].derrotas = (int) linha[j];
						break;
	
						//Pontos
						case 5: 
							* grupos[prox].pontos = (int) linha[j];
						break;
						
						//Gols feitos
						case 6: 
							* grupos[prox].golsFeitos = (int) linha[j];
						break;
						
						//Gols sofridos
						case 7: 
							* grupos[prox].golsSofridos = (int) linha[j];
						break;					
					}					
				}
			}
			prox++;
		}
		fclose(A);		
	}	
}

void criaArquivoGrupo(char nomeDoGrupo,TTime grupoCriar[]){
	FILE *A;
	int i;
	char linha[30];
	
	A = fopen("grupo"+nomeDoGrupo+".txt","a");
	if((A==null)){
		printf("Erro ao criar o arquivo do grupo %c\n",nomeDoGrupo);		
		return;
	}
	else{
		for(i=0;i<4;i++){
			//cria a linha
			int j;
			j=0;
			for(j=0;j<strlen(grupoCriar[i].nome);j++){
				linha[j] = grupoCriar[i].nome[j];
			}
			linha[j] = ";"
			j++;
			linha[j] = grupoCriar[i].grupo;
			j++;
			linha[j] = ";"
			j++;
			linha[j] = (char) grupoCriar[i].vitorias;
			j++;
			linha[j] = ";"
			j++;
			linha[j] = (char) grupoCriar[i].empates;
			j++;
			linha[j] = ";"
			j++;
			linha[j] = (char) grupoCriar[i].derrotas;
			j++;
			linha[j] = ";"
			j++;
			linha[j] = (char) grupoCriar[i].pontos;
			j++;
			linha[j] = ";"
			j++;
			linha[j] = (char) grupoCriar[i].golsFeitos;
			j++;
			linha[j] = ";"
			j++;
			linha[j] = (char) grupoCriar[i].golsSofridos;
			j++;
			linha[j] = "\0";
			//printa a linha
			fprintf(A,"%s\n",linha);
		}
		fclose(A);
		return;
	}	
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
	
	printf("\nAperte enter para continuar\n");
	scanf("%d",null);
}

int retornaGol(){
	int gols;
	
	srand (time(NULL));	
	gols = rand() % 10 + 1;
	
	return gols;
}

int disputaPenaltis(){
	int gols1;
	int gols2;
	int vencedor;
	int cobrancas;
	
	gols1 = 0;
	gols2 = 0;
	vencedor = 0;
	
	srand (time(NULL));
	
	while(vencedor == 0){
		gols1 += rand() % 2;
		gols2 += rand() % 2;
		cobrancas++;
		if(cobrancas>=5){
			if(gols1>gols2){
				vencedor = 1;
			}
			else if(gols2>gols1){
				vencedor = 2;
			}
		}
	}	
	
	return vencedor;
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
		*time2.derrotas++;
		
		*time1.pontos = *time1.pontos + 3;				
	}else {
		if(gol1 < gol2){
			*time2.vitorias++;
			*time1.derrotas++;
			
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
	// lembrete esse grupoAtual[] j� � vetor de 4 sele��es logo grupo[4]
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
	
	escreveResultadosGrupos(grupoAtual);
	criaArquivoGrupo(nomeGrupo,grupoAtual);
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

void escreveOitavas(TTime timeSel){
	FILE *A;
	int i;
	char linha[30];
	
	A = fopen("oitavas.txt","a");
	if((A==null)){
		printf("Erro ao criar o arquivo das oitavas de final\n");		
		return;
	}
	else{		
		//cria a linha

		for(i=0;i<strlen(timeSel.nome);i++){
			linha[i] = timeSel.nome[i];
		}
		linha[i] = ";"
		i++;
		linha[i] = timeSel.grupo;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.vitorias;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.empates;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.derrotas;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.pontos;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.golsFeitos;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.golsSofridos;
		i++;
		linha[i] = "\0";
		
		//printa a linha
		fprintf(A,"%s\n",linha);
		
		fclose(A);
		return;
	}		
}

void oitavasDeFinal(char grupos[]){
	TTime timesOitavas[16];
	int i;
	int mudaGrupo;
	int ganhadorOitavas;			
	
	mudaGrupo = 0;
	ganhadorOitavas = 0;
	
	printf("\n Inicio das Oitavas de final\n");
	
	for(i=0;i<8;i++){
		recuperaOitavas(grupos[i],timesOitavas[mudaGrupo],timesOitavas[mudaGrupo+1]);
		mudaGrupo = mudaGrupo+2;
	}
	
	mudagrupo = 0;
	
	for(i=0;i<4;i++){
		printf("\n %s       X       %s\n",timesOitavas[mudaGrupo].nome,timesOitavas[mudaGrupo+3].nome);
		ganhadorOitavas = disputaOitavas(timesOitavas[mudaGrupo],timesOitavas[mudaGrupo+3]);
		
		if(ganhadorOitavas == 1){
			printf("VENCEDOR: %s\n",timesOitavas[mudaGrupo]);
			escreveOitavas(timesOitavas[mudaGrupo]);
			escreveOitavas(timesOitavas[mudaGrupo+3]);
		}
		else{
			printf("VENCEDOR: %s\n",timesOitavas[mudaGrupo+3]);
			escreveOitavas(timesOitavas[mudaGrupo+3]);
			escreveOitavas(timesOitavas[mudaGrupo]);
		}
		
		printf("\n %s       X       %s\n",timesOitavas[mudaGrupo+1].nome,timesOitavas[mudaGrupo+2].nome);
		ganhadorOitavas = (timesOitavas[mudaGrupo+1],timesOitavas[mudaGrupo+2]);

		if(ganhadorOitavas == 1){
			printf("VENCEDOR: %s\n",timesOitavas[mudaGrupo+1]);
			escreveOitavas(timesOitavas[mudaGrupo+1]);
			escreveOitavas(timesOitavas[mudaGrupo+2]);	
		}
		else{
			printf("VENCEDOR: %s\n",timesOitavas[mudaGrupo+2]);
			escreveOitavas(timesOitavas[mudaGrupo+2]);
			escreveOitavas(timesOitavas[mudaGrupo+1]);
		}
		
		mudaGrupo = mudaGrupo+4;
	}		
}

void recuperaOitavas(char grupo, TTime * primeiroTime, TTime * segundoTime){
	FILE *A;
	int i;
	char linha[30];
	int prox;
	
	A = fopen("grupo"+grupo+".txt","r");
	
	if(A==null){
		printf("Erro ao abrir o arquivo do grupo %c\n",grupo);
		return 0;
	}
	else{
		for(i=0;i<2;i++){
			fscanf(A,"%s\n",&linha);
			int j;
			int separador;
			TTime aux;
			
			j = 0;
			separador=0;
			
			for(j=0;j < strlen(linha);j++)	{
				if(linha[j] == ";"){
					separador++;
				}
				else{
					switch (separador)
					{
						//Sele��o
						case 0:
					        aux.nome[j] = linha[j];
						break;
					
						//Grupo
						case 1:
							aux.nome[j-1] = "\0"; 
							aux.grupo = linha[j];
						break;
	
						//Vitoria
						case 2: 
							aux.vitorias = (int) linha[j];
						break;
						
						//Empate
						case 3: 
							aux.empates = (int) linha[j];
						break;
						
						//Derrota
						case 4: 
							aux.derrotas = (int) linha[j];
						break;
	
						//Pontos
						case 5: 
							aux.pontos = (int) linha[j];
						break;
						
						//Gols feitos
						case 6: 
							aux.golsFeitos = (int) linha[j];
						break;
						
						//Gols sofridos
						case 7: 
							aux.golsSofridos = (int) linha[j];
						break;					
					}					
				}
			}			
			if(i==0){
				* primeiroTime = aux;
			}
			else{
				* segundoTime = aux;
			}
		}
		return;
	}	
}

int disputaOitavas(TTime * time1,TTime * time2){
	int gol1,gol2;
	int ganhador;
		
	gol1 = retornaGol();
	gol2 = retornaGol();
	
	*time1.golsFeitos = *time1.golsFeitos + gol1;
	*time2.golsFeitos = *time2.golsFeitos + gol2;
	
	*time1.golsSofridos = *time1.golsSofridos + gol2;
	*time2.golsSofridos = *time2.golsSofridos + gol1;
	
	if(gol1 > gol2){
		*time1.vitorias++;
		*time2.derrotas++;
		ganhador = 1;
	}else {
		if(gol1 < gol2){
			*time2.vitorias++;
			*time1.derrotas++;
			ganhador = 2;
		}else{
			if(disputaPenaltis() == 1){
				*time1.vitorias++;
				*time2.derrotas++;
				ganhador = 1;				
			}
			else{
				*time2.vitorias++;
				*time1.derrotas++;
				ganhador = 2;
			}
		}
	}
	
	return ganhador;
}

void quartasDeFinal(){
	TTime times[8];
	int i;
	int vencedor;
	int prox;
	
	prox = 0;
	recuperaQuartas(times);
	
	printf("\n Inicio das Quartas de final\n");
	
	for(i=0;i<4;i++){
		printf("\n %s       X       %s\n",times[prox].nome,times[prox+1].nome);
		vencedor = disputaQuartas(times[prox],times[prox+1]);
		if(vencedor == 1){
			printf("VENCEDOR: %s\n",times[prox].nome);
			escreveQuartas(times[prox]);
			escreveQuartas(times[prox+1]);
		}
		else{
			printf("VENCEDOR: %s\n",times[prox+1].nome);
			escreveQuartas(times[prox+1]);
			escreveQuartas(times[prox]);
		}
		prox=prox+2;
	}
}

int disputaQuartas(TTime * time1,TTime * time2){
	int gol1,gol2;
	int ganhador;
		
	gol1 = retornaGol();
	gol2 = retornaGol();
	
	*time1.golsFeitos = *time1.golsFeitos + gol1;
	*time2.golsFeitos = *time2.golsFeitos + gol2;
	
	*time1.golsSofridos = *time1.golsSofridos + gol2;
	*time2.golsSofridos = *time2.golsSofridos + gol1;
	
	if(gol1 > gol2){
		*time1.vitorias++;
		*time2.derrotas++;
		ganhador = 1;
	}else {
		if(gol1 < gol2){
			*time2.vitorias++;
			*time1.derrotas++;
			ganhador = 2;
		}else{
			if(disputaPenaltis() == 1){
				*time1.vitorias++;
				*time2.derrotas++;
				ganhador = 1;				
			}
			else{
				*time2.vitorias++;
				*time1.derrotas++;
				ganhador = 2;
			}
		}
	}
	
	return ganhador;
}

void recuperaQuartas(TTime * timesQuartas[]){
FILE *A;
	char linha[30];
	int prox;
	
	prox = 0;
	A = fopen("oitavas.txt","r");
	
	if(A==null){
		printf("Erro ao abrir o arquivo das oitavas");
		return;
	}
	else{
		while(!feof(A)){
			fscanf(A,"%s\n\n",&linha);
			int j;
			int separador;
			
			j = 0;
			separador=0;
			
			for(j=0;j < strlen(linha);j++)	{
				if(linha[j] == ";"){
					separador++;
				}
				else{
					switch (separador)
					{
						//Sele��o
						case 0:
					        * timesQuartas[prox].nome[j] = linha[j];
						break;
					
						//Grupo
						case 1:
							* timesQuartas[prox].nome[j-1] = "\0"; 
							* timesQuartas[prox].grupo = linha[j];
						break;
	
						//Vitoria
						case 2: 
							* timesQuartas[prox].vitorias = (int) linha[j];
						break;
						
						//Empate
						case 3: 
							* timesQuartas[prox].empates = (int) linha[j];
						break;
						
						//Derrota
						case 4: 
							* timesQuartas[prox].derrotas = (int) linha[j];
						break;
	
						//Pontos
						case 5: 
							* timesQuartas[prox].pontos = (int) linha[j];
						break;
						
						//Gols feitos
						case 6: 
							* timesQuartas[prox].golsFeitos = (int) linha[j];
						break;
						
						//Gols sofridos
						case 7: 
							* timesQuartas[prox].golsSofridos = (int) linha[j];
						break;					
					}					
				}
			}
			prox++;
		}
		fclose(A);		
	}	
}

void escreveQuartas(TTime timeSel){
	FILE *A;
	int i;
	char linha[30];
	
	A = fopen("quartas.txt","a");
	if((A==null)){
		printf("Erro ao criar o arquivo das quartas de final\n");		
		return;
	}
	else{		
		//cria a linha

		for(i=0;i<strlen(timeSel.nome);i++){
			linha[i] = timeSel.nome[i];
		}
		linha[i] = ";"
		i++;
		linha[i] = timeSel.grupo;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.vitorias;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.empates;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.derrotas;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.pontos;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.golsFeitos;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.golsSofridos;
		i++;
		linha[i] = "\0";
		
		//printa a linha
		fprintf(A,"%s\n",linha);
		
		fclose(A);
		return;
	}		
}

void semiFinal(){
	TTime times[4];
	int i;
	int vencedor;
	int prox;
	
	prox = 0;
	recuperaSemi(times);
	
	printf("\n Inicio das Semi finais\n");
	
	for(i=0;i<2;i++){
		printf("\n %s       X       %s\n",times[prox].nome,times[prox+1].nome);
		vencedor = disputaSemi(times[prox],times[prox+1]);
		if(vencedor == 1){
			printf("VENCEDOR: %s\n",times[prox].nome);
			escreveSemi(times[prox]);
			escreveSemi(times[prox+1]);
		}
		else{
			printf("VENCEDOR: %s\n",times[prox+1].nome);
			escreveSemi(times[prox+1]);
			escreveSemi(times[prox]);
		}
		prox=prox+2;
	}	
}

int disputaSemi(TTime * time1,TTime * time2){
	int gol1,gol2;
	int ganhador;
		
	gol1 = retornaGol();
	gol2 = retornaGol();
	
	*time1.golsFeitos = *time1.golsFeitos + gol1;
	*time2.golsFeitos = *time2.golsFeitos + gol2;
	
	*time1.golsSofridos = *time1.golsSofridos + gol2;
	*time2.golsSofridos = *time2.golsSofridos + gol1;
	
	if(gol1 > gol2){
		*time1.vitorias++;
		*time2.derrotas++;
		ganhador = 1;
	}else {
		if(gol1 < gol2){
			*time2.vitorias++;
			*time1.derrotas++;
			ganhador = 2;
		}else{
			if(disputaPenaltis() == 1){
				*time1.vitorias++;
				*time2.derrotas++;
				ganhador = 1;				
			}
			else{
				*time2.vitorias++;
				*time1.derrotas++;
				ganhador = 2;
			}
		}
	}
	
	return ganhador;
}

void recuperaSemi(TTime * timesSemi[]){
FILE *A;
	char linha[30];
	int prox;
	
	prox = 0;
	A = fopen("quartas.txt","r");
	
	if(A==null){
		printf("Erro ao abrir o arquivo das quartas");
		return;
	}
	else{
		while(!feof(A)){
			fscanf(A,"%s\n\n",&linha);
			int j;
			int separador;
			
			j = 0;
			separador=0;
			
			for(j=0;j < strlen(linha);j++)	{
				if(linha[j] == ";"){
					separador++;
				}
				else{
					switch (separador)
					{
						//Sele��o
						case 0:
					        * timesSemi[prox].nome[j] = linha[j];
						break;
					
						//Grupo
						case 1:
							* timesSemi[prox].nome[j-1] = "\0"; 
							* timesSemi[prox].grupo = linha[j];
						break;
	
						//Vitoria
						case 2: 
							* timesSemi[prox].vitorias = (int) linha[j];
						break;
						
						//Empate
						case 3: 
							* timesSemi[prox].empates = (int) linha[j];
						break;
						
						//Derrota
						case 4: 
							* timesSemi[prox].derrotas = (int) linha[j];
						break;
	
						//Pontos
						case 5: 
							* timesSemi[prox].pontos = (int) linha[j];
						break;
						
						//Gols feitos
						case 6: 
							* timesSemi[prox].golsFeitos = (int) linha[j];
						break;
						
						//Gols sofridos
						case 7: 
							* timesSemi[prox].golsSofridos = (int) linha[j];
						break;					
					}					
				}
			}
			prox++;
		}
		fclose(A);		
	}	
}

void escreveSemi(TTime timeSel){
	FILE *A;
	int i;
	char linha[30];
	
	A = fopen("semi.txt","a");
	if((A==null)){
		printf("Erro ao criar o arquivo das semi finais\n");		
		return;
	}
	else{		
		//cria a linha

		for(i=0;i<strlen(timeSel.nome);i++){
			linha[i] = timeSel.nome[i];
		}
		linha[i] = ";"
		i++;
		linha[i] = timeSel.grupo;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.vitorias;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.empates;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.derrotas;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.pontos;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.golsFeitos;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.golsSofridos;
		i++;
		linha[i] = "\0";
		
		//printa a linha
		fprintf(A,"%s\n",linha);
		
		fclose(A);
		return;
	}		
}

void finalCopa(){
	TTime times[2];
	int i;
	int vencedor;
	int prox;
	
	prox = 0;
	recuperaFinal(times);
	
	printf("\n Inicio da GRANDE FINAL\n");
	
	printf("\n %s       X       %s\n",times[0].nome,times[1].nome);
	vencedor = disputaFinal(times[0],times[1]);
	printf("PARABENS AO GRANDE ");
	if(vencedor == 1){
		printf("VENCEDOR: %s!!!!!!!\n",times[0].nome);
		escreveFinal(times[0]);
		escreveFinal(times[1]);
	}
	else{
		printf("VENCEDOR: %s!!!!!!!\n",times[1].nome);
		escreveFinal(times[1]);
		escreveFinal(times[0]);
	}	
}

void recuperaFinal(TTime * timesFinal[]){
FILE *A;
	char linha[30];
	int prox;
	
	prox = 0;
	A = fopen("semi.txt","r");
	
	if(A==null){
		printf("Erro ao abrir o arquivo das semi finais");
		return;
	}
	else{
		while(!feof(A)){
			fscanf(A,"%s\n\n",&linha);
			int j;
			int separador;
			
			j = 0;
			separador=0;
			
			for(j=0;j < strlen(linha);j++)	{
				if(linha[j] == ";"){
					separador++;
				}
				else{
					switch (separador)
					{
						//Sele��o
						case 0:
					        * timesFinal[prox].nome[j] = linha[j];
						break;
					
						//Grupo
						case 1:
							* timesFinal[prox].nome[j-1] = "\0"; 
							* timesFinal[prox].grupo = linha[j];
						break;
	
						//Vitoria
						case 2: 
							* timesFinal[prox].vitorias = (int) linha[j];
						break;
						
						//Empate
						case 3: 
							* timesFinal[prox].empates = (int) linha[j];
						break;
						
						//Derrota
						case 4: 
							* timesFinal[prox].derrotas = (int) linha[j];
						break;
	
						//Pontos
						case 5: 
							* timesFinal[prox].pontos = (int) linha[j];
						break;
						
						//Gols feitos
						case 6: 
							* timesFinal[prox].golsFeitos = (int) linha[j];
						break;
						
						//Gols sofridos
						case 7: 
							* timesFinal[prox].golsSofridos = (int) linha[j];
						break;					
					}					
				}
			}
			prox++;
		}
		fclose(A);		
	}	
}

int disputaFinal(TTime * time1,TTime * time2){
	int gol1,gol2;
	int ganhador;
		
	gol1 = retornaGol();
	gol2 = retornaGol();
	
	*time1.golsFeitos = *time1.golsFeitos + gol1;
	*time2.golsFeitos = *time2.golsFeitos + gol2;
	
	*time1.golsSofridos = *time1.golsSofridos + gol2;
	*time2.golsSofridos = *time2.golsSofridos + gol1;
	
	if(gol1 > gol2){
		*time1.vitorias++;
		*time2.derrotas++;
		ganhador = 1;
	}else {
		if(gol1 < gol2){
			*time2.vitorias++;
			*time1.derrotas++;
			ganhador = 2;
		}else{
			if(disputaPenaltis() == 1){
				*time1.vitorias++;
				*time2.derrotas++;
				ganhador = 1;				
			}
			else{
				*time2.vitorias++;
				*time1.derrotas++;
				ganhador = 2;
			}
		}
	}
	
	return ganhador;
}

void escreveFinal(TTime timeSel){
	FILE *A;
	int i;
	char linha[30];
	
	A = fopen("final.txt","a");
	if((A==null)){
		printf("Erro ao criar o arquivo da final\n");		
		return;
	}
	else{		
		//cria a linha

		for(i=0;i<strlen(timeSel.nome);i++){
			linha[i] = timeSel.nome[i];
		}
		linha[i] = ";"
		i++;
		linha[i] = timeSel.grupo;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.vitorias;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.empates;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.derrotas;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.pontos;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.golsFeitos;
		i++;
		linha[i] = ";"
		i++;
		linha[i] = (char) timeSel.golsSofridos;
		i++;
		linha[i] = "\0";
		
		//printa a linha
		fprintf(A,"%s\n",linha);
		
		fclose(A);
		return;
	}		
}

int main(){	
	//Fase de grupos
	TTime faseGrupos[32];
	populaGrupos(&faseGrupos);
	faseDeGrupos("A",faseGrupos);
	faseDeGrupos("B",faseGrupos);
	faseDeGrupos("C",faseGrupos);
	faseDeGrupos("D",faseGrupos);
	faseDeGrupos("F",faseGrupos);
	faseDeGrupos("G",faseGrupos);
	faseDeGrupos("H",faseGrupos);
	system ("cls");	
	//oitavas
	char totalGrupos[8];
	strcpy(totalGrupos, "ABCDEFGH");
	oitavasDeFinal(totalGrupos);
	system ("cls");
	//quartas
	quartasDeFinal();
	system ("cls");
	//semi
	semiFinal();
	system ("cls");
	//final
	finalCopa();
	system ("cls");
	return 1;
}
