#include <stdio.h>
#include <stdlib.h>

void montaMatriz(int **matriz[10][10]){	
	int i;
	int j;
	
	i = 0;
	j = 0;
	
	for(i=0;i<10;i++){
		for(j=0;j<i;j++){
			**matriz[i][j] = **matriz[j][i] = 0;
		}
		**matriz[i][j] = 1;
	}	
}

int main(){
	
	montaMatriz(&m1[][])
	
	
	
	return 1;
}
