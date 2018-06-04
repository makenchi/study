#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int copiarArquivo(char *arqOrigem, char *arqDestino){
	FILE *O, *D;
	int num;	
	
	O = fopen(arqOrigem,"r");
	D = fopen(arqDestino,"w");
	
	if((O==NULL)||(D==NULL)){
		return 0;
	}
	else{
		while(!feof(O)){
			fscanf(O,"%d\n",&num);			
			fprintf(D,"%d\n",num);
		}
		
		fclose(O);
		fclose(D);
		
		return 1;
	}	
}

int inserirItem(char *nomeArq, int numero){
	FILE *A, *T;
	int num;
	int verifica;
	int resp;
	
	A = fopen(nomeArq,"r");
	T = fopen("temp.txt","w");
	
	if((A==NULL)||(T==NULL)){
		return 0;
	}
	else{
		verifica = 0;
		while(!feof(A)){
			fscanf(A,"%d\n",&num);
			if((numero < num)&&(verifica==0)){
				fprintf(T,"%d\n",numero);
				verifica = 1;
			}
			
			fprintf(T,"%d\n",num);
		}
		
		fclose(A);
		fclose(T);
		resp = copiarArquivo("temp.txt",nomeArq);
		if(resp = 1){
			printf("\nDados foram inseridos com sucesso.\n");
		}
		else{
			printf("\nErro ao copiar os arquivos.\n");
		}
		return 1;
	}
}

int removerItem(char *nomeArq, int numero){
	FILE *A, *T;
	int num;
	int cont;
	int resp;
	
	A = fopen(nomeArq,"r");
	T = fopen("temp.txt","w");
	cont = 0;
	
	if((A==NULL)||(T==NULL)){
		return 0;
	}
	else{
		while(!feof(A)){
			fscanf(A,"%d\n",&num);
			if(num != numero){
				fprintf(T,"%d\n",numero);
			}
			else{
				cont++;
			}			
		}
		
		fclose(A);
		fclose(T);
		resp = copiarArquivo("temp.txt",nomeArq);
		
		if(resp = 1){
			printf("\nDados foram inseridos com sucesso.\n");
		}
		else{
			printf("\nErro ao copiar os arquivos.\n");
		}
		
		return cont; //retorna quantos numeros removeu
	}	
}

int alterarItem(char *nomeArq, int valorAntigo, int valorNovo){
	int cont;
	int i;
	int resp;
	
	cont = removerItem(nomeArq,valorAntigo);
	for(i=0;i<cont;i++){
		resp = inserirItem(nomeArq,valorNovo);
		if(resp == 0){
			printf("Ocorrera um erro ao inserir o numero %d",valorNovo);
		}
	}
	
	return cont;
}

int criaArquivo(char *nomeArq){
	FILE *A;
	
	A = fopen(nomeArq,"a");
	
	if(A==NULL){
		return 0;
	}
	else{
		fclose(A);
		return 1;
	}
}

int montaMenu(){
	int escolha;
	escolha = 0;
	system("cls");
	printf("==========================================\n");
	printf("Escolha uma opção:\n");
	printf("1 - Inserir numero\n\n");
	printf("2 - Alterar numero\n\n");
	printf("3 - Remover numero\n\n");
	printf("0 - Sair\n");
	printf("==========================================\n");
	scanf("%d",&escolha);
	if((escolha != 1) && (escolha != 2) && (escolha != 3)){
		return 0;
	}
	else{
		return escolha;
	}
}

int main(){
	char arquivoCriado[50];
	int resp;
	int checa;
	
	printf("Digite o nome do arquivo que deseja criar: ");
	gets(arquivoCriado);
	fflush(stdin); //limpa o buffer
	
	resp = criaArquivo(arquivoCriado);
	if(resp == 1){
		resp = montaMenu();
		while(resp != 0){
			if(resp == 1){ //inserir
				int numInsere;
				
				printf("Digite o numero que quer inserir: ");
				scanf("%d\n",&numInsere);
				
				checa = inserirItem(arquivoCriado,numInsere);
				
				if(checa = 1){
					printf("Dado inserido com sucesso!\n");
				}
			}
			else if(resp == 2){ //Alterar
				int numNovo;
				int numVelho;
				
				printf("Digite o valor que quer alterar: ");
				scanf("%d\n",&numVelho);
				printf("Digite o novo valor: ");
				scanf("%d\n",&numNovo);
				
				checa = alterarItem(arquivoCriado,numVelho,numNovo);
				
				printf("Foram alterados %d itens\n",checa);
			}
			else if(resp == 3){ //Remover
				int numRemove;
				
				printf("Digite o valor que quer remover: ");
				scanf("%d\n",&numRemove);
				
				checa = removerItem(arquivoCriado,numRemove);
				
				printf("Foram removidos %d itens\n",checa);
			}
			resp = montaMenu();
		}
		printf("\nFim do pograma");
	}
	else{
		printf("\nOcorreu um erro ao criar arquivo\n");
		scanf("%d");
	}
	
	return 0;
}
