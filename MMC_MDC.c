
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void configureLanguage(){
	
	setlocale(LC_ALL, "Portuguese");
	
}

void read(int *n1, int *n2){
	
	printf("Write the first number: ");
	scanf("%d", &*n1);
	
	printf("Write the second number: ");
	scanf("%d", &*n2);
	
}

int mmc(int n1, int n2){
	
	int i;
	
	for(i=1; i<=(2*n2); i++){
		
		int tmp = n1*i;
		
		if(tmp%n2==0){
			return tmp;
		}
		
	}
	
	return -1;
	
}

int mdc(int mmc, int n1, int n2){
	
	return (n1*n2)/mmc;
	
}

void show(int n1, int n2, int mmc, int mdc){
	
	printf("Números: %d %d\n", n1, n2);
	
	printf("MMC: %d\n", mmc);
	
	printf("MDC: %d\n", mdc);
	
}

int main(){
	
	int n1, n2;
	int var_mmc, var_mdc;
	
	configureLanguage();
	
	read(&n1, &n2);
	
	var_mmc = mmc(n1, n2);
	
	var_mdc = mdc(var_mmc, n1, n2);
	
	show(n1, n2, var_mmc, var_mdc);
	
	return 0;
	
}
