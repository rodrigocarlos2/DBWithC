#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void readVector(int *vector, int size){
	
	int i;
	
	for(i=0; i<size; i++){
		
		printf("Write the %d value: ", i+1);
		scanf("%d", &vector[i]);
		
	}
	
}

void readSize(int *size){
	
	printf("Write the size: ");
	scanf("%d", &*size);
	
}

void showVector(int *vector, int size){
	
	int i;
	
	for(i=0; i<size; i++){
		
		printf(" %d ", vector[i]);
		
	}
	
	printf("\n");
	
}

void bubble_sort(int *vector, int size){
	
	int i;
	
	int comp;
	
	int number_comparations=0;
	int number_swap=0;
	
	comp = size-1;
	
	while(comp>0){
		
		for(i=0; i<comp; i++){
			
			number_comparations++;
			
			if(vector[i]>vector[i+1]){
				int tmp = vector[i];
				vector[i]=vector[i+1];
				vector[i+1]=tmp;
				number_swap++;
			}
			
		}
		
		comp--;
		
	}
	
	printf("Number of comparations: %d\n", number_comparations);
	printf("Number of swaps: %d\n", number_swap);
	
}

int main() {
	
	int *vector, size;
	
	readSize(&size);
	
	vector = (int *)malloc(size*sizeof(int));
	
	if(vector==NULL){
		exit(1);
	}
	
	readVector(vector, size);
	
	bubble_sort(vector, size);
	
	showVector(vector, size);
	
	free(vector);
	
	return 0;
}
