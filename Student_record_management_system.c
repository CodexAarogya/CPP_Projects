#include<stdio.h>
void addstudent();
void studentrecord();
void searchstudent();
void delete();
struct student
{
char first_name[20];
char last_name[20];
int roll_no;
int class[10];
char address[20];
long int contact;
};
int main()
{
int choice;
printf("\t\t\t=====STUDENT DATABASE MANAGEMENT SYSTEM=====\n");
printf("\t\t\tEnter: \n");
printf("\t\t\t 1. Add Student Records.\n");
printf("\t\t\t 2. View Student Records.\n");
printf("\t\t\t 3. Search Student.\n");
printf("\t\t\t 4. Delete Record.\n");
printf("\t\t\t 5. Exit.\n");
printf("\t\t\t ...........................................\n");
scanf("%d",&choice);
switch(choice)
{
case 1: addstudent();
break;
case 2: studentrecord();
break;
case 3: searchstudent();
break;
case 4: delete();
break;
default:
printf("!! ERROR !!");
}
return 0;
}
void addstudent()
{
char another;
FILE* fp;
struct student info;
do
{
printf("\t\t\t\t======Add Student Info=====\n");
fp=fopen("Student_info","a");
printf("Enter First Name: ");
scanf("%s",&info.first_name);
printf("Enter Last Name: ");
scanf("%s",&info.last_name);
printf("Enter Roll no.: ");
scanf("%d",&info.roll_no);
printf("Enter Class: ");
scanf("%d",&info.class);
printf("Enter Address: ");
scanf("%s",&info.address);
printf("Enter Contact Detail: ");
scanf("%ld",&info.contact);
printf("\n\t............\n");
if(fp==NULL)
{
printf("Can't open the file\n");
}
else
{
printf("Successful \n");
}
fwrite(&info,sizeof(struct student),1,fp);
fclose(fp);
printf("DO YOU WANT TO ENTER ANOTHER RECORD ? [Y/N]: ");
scanf(" %c",&another);
}
while(another=='y'|| another=='Y' );
}
void studentrecord()
{
FILE *fp;
struct student info;
fp=fopen("Student_info","r");
printf("STUDENT RECORDS..");
if(fp==NULL)
{
printf("Error");
}
else
{
printf("Records.........\n");
}
while(fread(&info,sizeof(struct student),1,fp))
{
printf("Student Name: %s %s \n",info.first_name,info.last_name);
printf("Roll no.: %d \n",info.roll_no);
printf("Class: %d \n",info.class);
printf("Address: %s \n",info.address);
printf("Contact: %ld \n",info.contact);
}
}
void searchstudent()
{
FILE *fp;
int roll_no,found=0;
struct student info;
fp=fopen("Student_info","r");
printf(" ======Search Student=====t\n");
printf("Enter roll no:");
scanf("%d",&roll_no);
while(fread(&info,sizeof(struct student),1,fp))
{
if(info.roll_no==roll_no)
{
found=1;
printf("Student Name: %s %s \n",info.first_name,info.last_name);
printf("Roll no.: %d \n",info.roll_no);
printf("Class: %d \n",info.class);
printf("Address: %s \n",info.address);
printf("Contact: %ld \n",info.contact);
}
}
if(found!=1)
{
printf("Record not found !\n");
}
fclose(fp);
}
void delete()
{
FILE *fp,*fp1;
int roll_no,found=0;
struct student info;
printf("======Delete Student Record=====\n");
fp=fopen("Student_info","r");
fp1=fopen("temp.txt","w");
printf("Enter Roll_no.: ");
scanf("%d",&roll_no);
if(fp==NULL)
{
printf("Can't Open File !\n");
}
else
{
while(fread(&info,sizeof(struct student),1,fp))
{
if(info.roll_no==roll_no)
{
found=1;
}
fwrite(&info,sizeof(struct student),1,fp1);
}
}
fclose(fp);
fclose(fp1);
if(found==1)
{
remove("Student_info");
rename("temp.txt","student_info");
printf("Record deleted successfully!!\n");
}
}