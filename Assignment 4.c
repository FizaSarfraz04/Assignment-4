#include<stdio.h>
#include<string.h>
#include<conio.h>
struct patient{
	int ID;
	char name[10];
	char CNIC[10];
	char phonenumber[10];
	char disease[10];
	char is_admit[10];
	
}p1;
void menu();
void addpatient();
void deletepatient();
int availableID();
void search();
void update();
void display();
int main(){
	menu();
}
void menu(){
	printf("\nSelect one option\n");
	printf("****************************************\n");
    printf("1.Add Patient\n2.Delete patients\n3.Update patients\n4.Search patients\n5.Display all the patients\n");
    printf("****************************************\n");
	int select;
	puts(" ");
	printf("Enter your choice ");
	scanf("%d",&select);
	
	if(select==1){
		puts(" ");
		printf("Enter the details of patient\n");
		addpatient();
	}
	else if(select==2){
		puts(" ");
		printf("You choose deletion\n");
		deletepatient();
	}
	else if(select==3){
		puts(" ");
		 update();
	}
	else if(select==4){
		puts(" ");
		search();
	}
	else if(select==5){
		display();
	}
	else{
		printf("Enter valid option");
	}
}
void addpatient(){
	struct patient p1;
	FILE *fp;
	fp=fopen("record.txt","a");
	printf("Enter the patient's Id: ");
	scanf("%d",&p1.ID);
	printf("Enter the name of patient: ");
		fflush(stdin);
	gets(p1.name);
	printf("Enter the patient's CNIC: ");
	gets(p1.CNIC);
	printf("Enter the patient's phone number:  ");
	gets(p1.phonenumber);
	printf("Enter the patient's disease: ");
	gets(p1.disease);
	printf("Is patient  admitted or not? ");
	gets(p1.is_admit);
	fp=fopen("record.txt","a");
	fprintf(fp,"Patient's ID:%d\n",p1.ID);
	fprintf(fp,"Patient's name:%s\n",p1.name);
	fprintf(fp,"Patient's phone number:%s\n",p1.phonenumber);
	fprintf(fp,"Patient's CNIC:%s\n",p1.CNIC);
	fprintf(fp,"Patient's Disease:%s\n",p1.disease);
	fprintf(fp,"Patient is admitted?%s\n",p1.is_admit);
	puts(" ");
    fclose(fp);
	menu();
}
//function to delete record
void deletepatient(){
	struct patient p1;
	FILE *fp;
	FILE *fp2;
	//open the input file in read mode 
	fp=fopen("record.txt","rb");
        // error handling 
        if (!fp) {
                printf("Unable to open input file!!\n");       
        }
       // open temporary file in write mode 
        fp2 = fopen("TempFile.txt", "w");
        //error handling 
        if (!fp2) {
                printf("Unable to open temporary file!!\n");
                fclose(fp);
        }
          //print the records in the input file 
        printf("\nRecords in input file");
        while (!feof(fp)) {
                fscanf(fp, "%d\n",p1.ID);
                fflush(stdin);
                fscanf(fp, "%s\n",p1.name);
                fscanf(fp, "%s\n",p1.phonenumber);
                fscanf(fp, "%s\n",p1.CNIC);
                fscanf(fp, "%s\n",p1.disease);
                fscanf(fp, "%s\n",p1.is_admit);

                if (feof(fp)) {
                        continue;
                }
           printf("\nPatient's ID: %d",p1.ID);
	       printf("\nPatient's name: %s",p1.name);
	       printf("\nPatient's phone number: %s",p1.phonenumber);
	       printf("\nPatient's CNIC: %s",p1.CNIC);
           printf("\nPatient's Disease: %s",p1.disease);
	       printf("\nPatient is admitted? %s",p1.is_admit);      
        }
        // rewind file pointer of input file to start 
        rewind(fp);
        // get the record user wants to delete 
        printf("\n\nEnter the record you want to delete(ID no): ");
           int id;
        scanf("%d",&id);

        // delete the given record 
        while (!feof(fp)) {
                fscanf(fp, "\n%d",p1.ID);
                fflush(stdin);
                fscanf(fp, "\n%s",p1.name);
                fscanf(fp, "\n%s",p1.phonenumber);
                fscanf(fp, "\n%s",p1.CNIC);
                fscanf(fp, "\n%s",p1.disease);
                fscanf(fp, "\n%s",p1.is_admit);
                
                if (feof(fp)) {
                        continue;
                }
                if (id == p1.ID)
                continue;
        fprintf(fp2, "\n%d\n%s\n%s\n%s\n%s\n%s\n", p1.ID,p1.name,p1.phonenumber,p1.CNIC,p1.disease,p1.is_admit);
    }
         // open the input file after delete operation 
        fp = fopen("record.txt", "rb");

        // error handling 
        if (!fp) {
                printf("Unable to open the file %s\n", fp);
                //return 0;
        }
        //records in  input file after deletion operation 
        printf("\nRecords in input file after deletion operation:\n");
        while (!feof(fp)) {
                fscanf(fp, "\n%d",p1.ID);
                fscanf(fp, "\n%s",p1.name);
                fscanf(fp, "\n%s",p1.phonenumber);
                fscanf(fp, "\n%s",p1.CNIC);
                fscanf(fp, "\n%s",p1.disease);
                fscanf(fp, "\n%s",p1.is_admit);

                if (feof(fp)) {
                          continue;
                }
        printf("\nrecords after deletion\n");
        printf("\nPatient's ID:%d",p1.ID);
	    printf("\nPatient's name:%s",p1.name);
	    printf("\nPatient's phone number:%s",p1.phonenumber);
	    printf("\nPatient's CNIC:%s",p1.CNIC);
	    printf("\nPatient's Disease:%s",p1.disease);
    	printf("\nPatient is admitted? %s\n",p1.is_admit); 
        }
    
        // close the opened file 
        fclose(fp);
        printf("\nRECORD DELETED\n");
            menu();
}

//function to search record
void search()
{
 FILE *fp2;
 struct patient p1;
 int r, s;
 printf("\nEnter the ID you want to search : ");
 scanf("%d", &r);
 if (r!=p1.ID){
  printf("ID %d is not available in the file\n",r);
}
 else
 {
  fp2 = fopen("record.txt", "r");
  while (fread(&p1, sizeof(p1), 1, fp2))
  {
   s = p1.ID;
   if (s == r)
   {
    printf("\nID = %d", p1.ID);
    printf("\nName = %s", p1.name);
    printf("\ndisease  = %s\n", p1.disease);
    printf("\nphone num = %s", p1.phonenumber);
    printf("\nCNIC = %s", p1.CNIC);
    printf("\nAdmitted or not = %s", p1.is_admit);
   }
  }
  fclose(fp2);
 }
 menu();
}
//function to update 
void update(){
	int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter ID to update:");
 scanf("%d", &r);
 fpt=fopen("TempFile.txt","r");
    s=p1.ID;
 if (fpt==NULL)
 {
  printf("Error opening the file");
 }
 else
 {
  fpo = fopen("record.txt", "r");
  fpt = fopen("TempFile.txt", "w");
  while (fread(&p1, sizeof(p1), 1, fpo))
  {
   s = p1.ID;
   if (s != r){
   
    fwrite(&p1, sizeof(p1), 1, fpt);
}

    printf("\n\t1. Update name of ID %d", r);
    printf("\n\t2. Update  disease of ID %d", r);
    printf("\n\t3. Update phone number of ID %d", r);
    printf("\n\t4. Update CNIC of ID %d", r);
    printf("\n\t5. Update   status  of ID %d", r);
    printf("\nEnter your choice:");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name:");
     scanf("%s", &p1.name);
     break;
    case 2:
     printf("Enter name of disease : ");
     scanf("%s", &p1.disease);
     break;
    case 3:
     printf("Enter phone number: ");
     scanf("%s", &p1.phonenumber);
     break;
	 case 4:
     printf("Enter CNIC: ");
     scanf("%s", &p1.CNIC);
     break;
	 case 5:
     printf("Enter status: ");
     scanf("%s", &p1.is_admit);
     break;
    default:
     printf("Invalid Selection\n");
     break;
    }
    fwrite(&p1, sizeof(p1), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("record.txt", "w");
  fpt = fopen("TempFile.txt", "r");
  while (fread(&p1, sizeof(p1), 1, fpt))
  {
   fwrite(&p1, sizeof(p1), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("******RECORD UPDATED*****");

 menu();
}
void display(){
	struct patient p1;
	FILE *ptr;
	ptr=fopen("record.txt","r");
	while(!feof(ptr)){
	          fread(&p1,sizeof(struct patient),1,ptr);
        	if (feof(ptr)) {
                          continue;
                }
              printf("\nPatient's ID:%d",p1.ID);
	          printf("\nPatient's name:%s",p1.name);
	          printf("\nPatient's phone number:%s",p1.phonenumber);
	          printf("\nPatient's CNIC:%s",p1.CNIC);
              printf("\nPatient's Disease:%s",p1.disease);
	          printf("\nPatient is admitted? %s",p1.is_admit);    	
}
      menu();
}















