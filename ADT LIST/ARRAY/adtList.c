#include <stdio.h>

typedef struct {
	char fName[20];
	char lName[20];
}studName;

typedef struct{
	int month;
	int year;
}bDay;

typedef struct{
	studName name;
	bDay birthday;
	int age;
	int idNum;
}studentInfo;

typedef struct{
	studentInfo studList[20];
	int studCount;
}classRecord;

void insertFront(studentInfo newStud, classRecord* classList);
void insertRear(studentInfo newStud, classRecord* classList);
void insertAt(studentInfo newStud, classRecord* classList, int index);
void insertSorted(studentInfo newStud, classRecord* classList);
void DeleteFront(classRecord* classList);
void DeleteRear(classRecord* classList);
void DeleteAt(classRecord* classList, int index);

int main(){
	int i, index;
	classRecord classList;
	classList.studCount = 0;
	studentInfo stud1 = {{"Zenno", "Abellana"}, {2, 2001}, 23, 21104304};	
	studentInfo stud2 = {{"Onnez", "Abellana"}, {2, 2001}, 23, 21101234};
	studentInfo stud3 = {{"Jethro", "Engutan"}, {2, 2003}, 21, 21114521};
	studentInfo newStud;
	int input;
	
	do{
		printf("0. EXIT\n");
		printf("1. Insert Front\n");
		printf("2. Insert Rear\n");
		printf("3. Insert At\n");
		printf("4. Insert Sorted\n");
		printf("5. Delete Front\n");
		printf("6. Delete Rear\n");
		printf("7. Delete At\n");
		printf("8. Display List\n");
		printf("Input: ");
		scanf("%d", &input);
		
		switch(input){
			case 1:
				printf("Enter Student First Name: ");
				scanf("%s", &newStud.name.fName);
				printf("Enter Student Last Name: ");
				scanf("%s", &newStud.name.lName);
				printf("Enter Student BirthMonth: ");
				scanf("%d", &newStud.birthday.month);
				printf("Enter Student BirthYear: ");
				scanf("%d", &newStud.birthday.year);
				printf("Enter Student Age: ");
				scanf("%d", &newStud.age);
				printf("Enter Student ID Number: ");
				scanf("%d", &newStud.idNum);
				
				insertFront(newStud, &classList);
				break;
				
			case 2:
				printf("Enter Student First Name: ");
				scanf("%s", &newStud.name.fName);
				printf("Enter Student Last Name: ");
				scanf("%s", &newStud.name.lName);
				printf("Enter Student BirthMonth: ");
				scanf("%d", &newStud.birthday.month);
				printf("Enter Student BirthYear: ");
				scanf("%d", &newStud.birthday.year);
				printf("Enter Student Age: ");
				scanf("%d", &newStud.age);
				printf("Enter Student ID Number: ");
				scanf("%d", &newStud.idNum);
				
				insertRear(newStud, &classList);
				break;
				
			case 3:
				printf("Enter Student First Name: ");
				scanf("%s", &newStud.name.fName);
				printf("Enter Student Last Name: ");
				scanf("%s", &newStud.name.lName);
				printf("Enter Student BirthMonth: ");
				scanf("%d", &newStud.birthday.month);
				printf("Enter Student BirthYear: ");
				scanf("%d", &newStud.birthday.year);
				printf("Enter Student Age: ");
				scanf("%d", &newStud.age);
				printf("Enter Student ID Number: ");
				scanf("%d", &newStud.idNum);
				printf("Insert Index: ");
				scanf("%d", &index);
				
				insertAt(newStud, &classList, index);
				break;
				
			case 4:
				printf("Enter Student First Name: ");
				scanf("%s", &newStud.name.fName);
				printf("Enter Student Last Name: ");
				scanf("%s", &newStud.name.lName);
				printf("Enter Student BirthMonth: ");
				scanf("%d", &newStud.birthday.month);
				printf("Enter Student BirthYear: ");
				scanf("%d", &newStud.birthday.year);
				printf("Enter Student Age: ");
				scanf("%d", &newStud.age);
				printf("Enter Student ID Number: ");
				scanf("%d", &newStud.idNum);
			
				insertSorted(newStud, &classList);
				break;
				
			case 5:
				DeleteFront(&classList);
				break;
				
			case 6:
				DeleteRear(&classList);
				break;	
				
			case 7:
				printf("Enter index to delete: ");
				scanf("%d", &index);
				DeleteAt(&classList, index);
				break;
				
			case 8:
				printf("STUD Count: %d\n", classList.studCount);
				for(i=0;i<classList.studCount;i++){
					printf("Name: %s %s\n", classList.studList[i].name.fName, classList.studList[i].name.lName);
					printf("Birthday: %d, %d\n", classList.studList[i].birthday.month, classList.studList[i].birthday.year);
					printf("Age: %d\n", classList.studList[i].age);
					printf("ID Num: %d\n\n", classList.studList[i].idNum);
				}
				break;
		}
		
		system("pause");
		system("cls");
	}
	while(input!=0);


	
	return 0;
}

void insertFront(studentInfo newStud, classRecord* classList){
	int i;
	
	if(classList->studCount<20){
		for(i = classList->studCount; i>0; i--){
			classList->studList[i] = classList->studList[i-1];
		}
		
		classList->studList[i] = newStud;
		classList->studCount++;
	}
	
}

void insertRear(studentInfo newStud, classRecord* classList){
	if(classList->studCount<20){
		classList->studList[classList->studCount] = newStud;
		classList->studCount++;
	}
}

void insertAt(studentInfo newStud, classRecord* classList, int index){
	
	
	if(index<classList->studCount){
		int i;
		for(i = classList->studCount; i>index; i--){
			classList->studList[i] = classList->studList[i-1];
		}
		
		classList->studList[i] = newStud;
		classList->studCount++;
	}
}

void insertSorted(studentInfo newStud, classRecord* classList){
	
	int i, j;
	if(classList->studCount<20){
		for(i=0;newStud.age>classList->studList[i].age && i<classList->studCount;i++){}
		for(j = classList->studCount; j>i; j--){
			classList->studList[j] = classList->studList[j-1];
		}
		
		classList->studList[j] = newStud;
		classList->studCount++;
	}
}

void DeleteFront(classRecord* classList){
	if(classList->studCount>0){
		int i;
		for(i=0;i<classList->studCount;i++){
			classList->studList[i] = classList->studList[i+1];
		}
		classList->studCount--;
	}
	
}

void DeleteRear(classRecord* classList){
	
	if(classList->studCount>0){
		classList->studCount--;
	}
}

void DeleteAt(classRecord* classList, int index){
	
	if(index<classList->studCount){
		int i;
		for(i=index;i<classList->studCount;i++){
			classList->studList[i] = classList->studList[i+1];
		}
		classList->studCount--;
	}
}


