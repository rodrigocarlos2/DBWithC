
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void selectionSort(int *vector, int size){
	
	int i;
	
	for(i=0; i<size; i++){
		
		int j;
		
		for(j=i+1; j<size; j++){
			
			if(vector[i]>vector[j]){
				int tmp;
				tmp = vector[i];
				vector[i] = vector[j];
				vector[j] = tmp;
			}
			
		}
		
	}
	
}

void showVector(int *vector, int size){
	
	int i;
	
	for(i=0; i<size; i++){
		
		printf("%d\n", vector[i]);
		
	}
	
}

void read(int *size){
	
	printf("Write the size: ");
	scanf("%d", &*size);
	
}

void readVector(int *vector, int size){
	
	int i;
	
	for(i=0; i<size; i++){
		printf("Write the %d value: ", i+1);
		scanf("%d", &vector[i]);
	}
	
}

int main() {
	
	int *vector, size;
	
	read(&size);
	
	vector = (int *)malloc(size*sizeof(int));
	
	if(vector==NULL){
		exit(1);
	}
	
	readVector(vector, size);
	
	selectionSort(vector, size);
	
	showVector(vector, size);
	
	return 0;
}
