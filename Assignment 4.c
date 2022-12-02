#include<stdio.h>
#include<string.h>
#include<conio.h>
struct patient{
	char ID[10];
	char name[20];
	char CNIC[12];
	char phonenumber[12];
	char disease[30];
	char is_admit[10];
	
}*p1;
void menu();
void addpatient();
int main(){
	printf("********************************************\n");
	menu();
	
}
void menu(){
	printf("select one option\n");
    printf("1.Add Patient\n2.Delete patients\n3.Update patients\n4.Search patients\n5.Display all the patients\n");
	int select;
	printf("Enter your choice");
	scanf("%d",&select);
	if(select==1){
		printf("**************************************\n");
		printf("Enter the details of patient\n");
		addpatient();
	}	
}
void addpatient(){
	struct patient p1;
	FILE *fptr;
	fptr=fopen("record.txt","w");
	fflush(stdin);
	printf("Enter the patient's Id: ");
	gets(p1.ID);
	printf("Enter the name of patient: ");
	gets(p1.name);
	printf("Enter the patient's CNIC: ");
	gets(p1.CNIC);
	printf("Enter the patient's phone number:  ");
	gets(p1.phonenumber);
	printf("Enter the patient's disease: ");
	gets(p1.disease);
	printf("Is patient is admitted or not?");
	gets(p1.is_admit);
	fptr=fopen("record.txt","a");
	fprintf(fptr,"Patient's ID:%s\n",p1.ID);
	fprintf(fptr,"Patient's name:%s\n",p1.name);
	fprintf(fptr,"Patient's CNIC:%s\n",p1.CNIC);
	fprintf(fptr,"Patient's phone number:%s\n",p1.phonenumber);
	fprintf(fptr,"Patient's Disease:%s\n",p1.disease);
	fprintf(fptr,"Patient is admitted?%s\n",p1.is_admit);
	
	menu();
	
}












