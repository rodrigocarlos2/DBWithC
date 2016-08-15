#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person{
	int age;
	char name[40];
};

typedef struct person Person;
// Here was create a alias

void read(Person *people, int index){
	
	if(index>4){
		return;
		// Condition break
	}
	else{
		
		Person tmp;
		
		fflush(stdin);
		
		printf("Write your name: ");
		gets(tmp.name);
		
		printf("Write your age: " );
		scanf("%d", &tmp.age);
		
		people[index] = tmp;
		
		index++;
		
		read(people, index);
		
	}
	
}

void show(Person *people, int index){
	
	if(index>4){
		return;
	}
	else{
		
		printf("Name: %s\n", people[index].name);
		printf("Age: %d\n", people[index].age);
		
		index++;
		
		show(people, index);
		
	}
	
}

int main() {
	
	Person *people;
	// Declaration
	
	people = (Person *)malloc(5*sizeof(Person));
	// Allocation
	
	if(people==NULL){
		printf("No memory space!\n");
		exit(1);
		// Verify if no have memory
	}
	
	fflush(stdin);
	
	read(people, 0);
	
	show(people, 0);
	
	return 0;
}
