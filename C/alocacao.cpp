#include <stdio.h>
#include <string.h>

int main(){
	
	int c;
	int l;
	int m[];
	
	printf("Entre com o numero de linhas e colunas: ");
	scanf("%d %d",&l,&c);
	
	m = (int**)malloc(l*sizeof(int*));
	for(i=0;i<l;i++){
		m[i] = (int*) malloc(c*sizeof(int));
	}
	
	return 0;
}
