
#include <stdio.h>
#include <stdlib.h>

int size;

struct behavior{
	int id;
	char name[20];
};

typedef struct behavior Behavior;

struct people{
	int id;
	char name[30];
	int age;
	int exist;
};

typedef struct people People;

struct people_behavior{
	int idPeople;
	int Behavior;
};

typedef struct people_behavior People_Behavior;

People* insertPeople(People *allPeoples, People p){
	
	if(allPeoples==NULL){
		
		allPeoples = (People*)malloc(1*sizeof(People));
		
		p.id = 0;
		
		p.exist=1;
		
		allPeoples[0] = p;
		
		size=1;
		
	}
	else{
		
		int searchBlank = -1;
		
		int j;
		
		for(j=0; j<size; j++){
			
			if(allPeoples[j].exist==0){
				searchBlank=1;
				break;
			}
			
		}
		
		if(searchBlank==-1){
		
			p.id = size;
			
			p.exist=1;
			
			size++;
			
			allPeoples = (People*)realloc(allPeoples, size*sizeof(People));
			
			allPeoples[size-1] = p;
		
		}
		
		else{
			
			p.id = searchBlank;
			
			p.exist = 1;
			
			allPeoples[searchBlank] = p;
			
		}
		
	}
	
	return allPeoples;
	
}

void showPeoples(People *allPeoples){
	
	int i;
	
	for(i=0; i<size; i++){
		
		if(allPeoples[i].exist==1){
		
			printf("-----------------------\n");
			
			printf("People\n");
			printf("Id: %d\n", allPeoples[i].id);
			printf("Name: %s\n", allPeoples[i].name);
			printf("Age: %d\n", allPeoples[i].age);
			
			printf("-----------------------\n");
		
		}
		
	}
	
}

int menu(){
	
	int r;
	
	printf("1. Insert People\n");
	printf("2. Show Peoples\n");
	printf("3. Delete People\n");
	printf("4. End\n");
	
	scanf("%d", &r);
	
	return r;
	
}

void readPeople(People *p){
	
	fflush(stdin);
	
	printf("Write your name: ");
	scanf("%[^\n]", p->name);
	
	printf("Write your age: ");
	scanf("%d", &p->age);
	
}

void deletePeople(People* allPeoples, int id){
	
	int i;
	
	for(i=0; i<size; i++){
		
		if(allPeoples[i].id==id){
			
			allPeoples[i].exist=0;
			break;
			
		}
		
	}
	
}

int main(){
	
	People *allPeoples = NULL;
	int op;
	
	People aid;
	int id;
	
	do{
		
		op=menu();
		
		switch(op){
			
			case 1:
				
				readPeople(&aid);
				
				allPeoples = insertPeople(allPeoples, aid);
				
				break;
				
			case 2:
				
				showPeoples(allPeoples);
				
				break;
				
			case 3:
				
				printf("Digite o Id da pessoa: ");
				scanf("%d", &id);
				
				deletePeople(allPeoples, id);
				
				break;
			
		}
		
	}while(op!=4);
	
	return 0;
	
}
