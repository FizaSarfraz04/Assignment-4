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
int main(){
	menu();
}
void menu(){
	printf("Select one option\n");
	printf("********************************************\n");
    printf("1.Add Patient\n2.Delete patients\n3.Update patients\n4.Search patients\n5.Display all the patients\n");
    printf("********************************************\n");
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
		deletepatient();
	}
	/*else if(select==3){
		puts(" ");
		 update();
	}*/
	else if(select==3){
		puts(" ");
		search();
	}
}
void addpatient(){
	struct patient p1;
	FILE *fp;
	fp=fopen("Record.txt","a");
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
	fp=fopen("Record.txt","a");
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
	fp=fopen("Record.txt","rb");
        // error handling 
        if (!fp) {
                printf("Unable to open input file!!\n");       
        }
       // open temporary file in write mode 
        fp2 = fopen("TempFile.txt", "a");
        //error handling 
        if (!fp2) {
                printf("Unable to open temporary file!!\n");
                fclose(fp);
        }
          //print the records in the input file 
        printf("Records in input file:\n");
        while (!feof(fp)) {
                fscanf(fp, "%d\n",p1.ID);
                fscanf(fp, "%s\n",p1.name);
                fscanf(fp, "%s\n",p1.phonenumber);
                fscanf(fp, "%s\n",p1.CNIC);
                fscanf(fp, "%s\n",p1.disease);
                fscanf(fp, "%s\n",p1.is_admit);

                if (feof(fp)) {
                        continue;
                }
           printf("\nPatient's ID:%d",p1.ID);
	       printf("\nPatient's name:%s",p1.name);
	       printf("\nPatient's phone number:%s",p1.phonenumber);
	       printf("\nPatient's CNIC:%s",p1.CNIC);
           printf("\nPatient's Disease:%s",p1.disease);
	       printf("\nPatient is admitted? %s",p1.is_admit);      
        }
        // rewind file pointer of input file to start 
        rewind(fp);
        // get the record user wants to delete 
        printf("\nEnter the record you want to delete(ID no):");
           int id;
        scanf("%d",&id);

        // delete the given record 
        while (!feof(fp)) {
               fscanf(fp, "\n%d",p1.ID);
                fscanf(fp, "\n%s",p1.name);
                fscanf(fp, "\n%s",p1.phonenumber);
                fscanf(fp, "\n%s",p1.CNIC);
                fscanf(fp, "\n%s",p1.disease);
                fscanf(fp, "\n%s",p1.is_admit);
                fflush(stdin);
                if (feof(fp)) {
                        continue;
                }
                if (id == p1.ID)
                continue;
        fprintf(fp2, "\n%d\n%s\n%s\n%s\n%s\n%s\n", p1.ID,p1.name,p1.phonenumber,p1.CNIC,p1.disease,p1.is_admit);
    }
         // open the input file after delete operation 
        fp = fopen("Record.txt", "rb");

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
  fp2 = fopen("Record.txt", "rb");
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















