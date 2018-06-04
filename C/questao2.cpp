#include <stdio.h>
#include <stdlib.h>

void itemA(float m[30][30], int l1, int l2, int l3){	
	inf j;
	
	for(j=0;j<30;j++){
		m[l3][j] = m[l1][j]+m[l2][j];
	}
}

void itemB(float m[30][30], int l, int c){
	
}

int main(){
	return 0;
}
