#include <stdio.h>
#include <stdlib.h>

void mostraMultiplo(int n, int v, int base) {
	if (n*base >= v)
	{
		return;
	}
	
	printf("%d\n",n*base);
	mostraMultiplo(n,v,base+1);
}

int main() {
	int num;
	int val;

	printf("Digite um numero: ");
	scanf("%d", &num);
	printf("Agora digite o valor maxiumo ate o multiuplo do numero digitado anteriormente: ");
	scanf("%d", &val);

	mostraMultiplo(num, val, 0);

	return 0;
}
