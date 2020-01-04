#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

struct employee
{
    int no;
    long int id;
    char f_name[100];
    char l_name[100];
    int age;
    int  salary;
}emp[1000];
int addAccount();
int editAccount();
int deleteAccount();
int totalSalary();
int maxSaalary();
int minSalary();
int avgSalary();
void login();
void loading_print();
int printMenu();
int main()
{
    int n,k,Lg_in;
    login();
      loading_print();

    do {
        fflush(stdin);
        k = printMenu();
        switch(k){
            case 1:addAccount();
                    break;
            case 2: editAccount();
                    break;
            case 3: deleteAccount();
                    break;
            case 4: totalSalary();
                    break;
            case 5: maxSaalary();
                    break;
            case 6: minSalary();
                    break;
            case 7: avgSalary();
                    break;
            case 8: printf("Thank you for using.......");
                    break;

            default: printf("Wrong choice, try again");
                     break;
        }


    }while (k!=8);

    return 0;
}
void login()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[20]="samin";
    char pass[20]="123";
    do
{

    printf("\n>>>>>>>>>>>>>>>>>>>>>    LOG  IN    <<<<<<<<<<<<<<<<<<<<<<<<<");
    printf(" \n\n                  ENTER USERNAME:-");
	scanf("%s",&uname);
	printf(" \n\n                  ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13)
            break;
	    else
	        printf("*");
	      i++;
	}
	pword[i]='\0';

	i=0;

		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n        \t WELCOME TO Employee Record System  \n \n \t \t YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;

		getch();//holds the screen

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");

}
void loading_print()
{
    int i;
    printf("\n\n\n\n\t\tLoading...\n\t\t");

    for(i=0; i<=100; i++)
    {
        printf("\b\b\b\b\b%c%c %3d",219,219,i);
           Sleep(5);
    }
    system("cls");
}

int printMenu()
{
    printf("\n\t****************************Employee Record System**************************\n\n\n");
    int choice;
    printf("\n 1. Add Account");
    printf("\n 2. Edit Account");
    printf("\n 3. Delete Account");
    printf("\n 4. Find total balance");
    printf("\n 5. Display Max balance holder");
    printf("\n 6. Display Min balance holder");
    printf("\n 7. Display average balance");
    printf("\n 8. Exit");

    printf("\n Enter choice: ");
    scanf("%d", &choice);
    return choice;

}
int addAccount()
{
   struct employee emp;
   FILE *fp,*fq;
   char an='y';


   fp=fopen("pro.txt","a");
   fq=fopen("pro.txt","r");
   if(fopen==NULL)
   {
       printf("File doesn't exist");
       return 0;
   }
   while(an=='y')
   {
       printf("Enter number: ");
       scanf("%d",&emp.no);
       printf("Enter employee id: ");
       scanf("%ld",&emp.id);
       printf("\nEnter employee first name: ");
       scanf("%s",emp.f_name);
       printf("\nEnter employee last name: ");
       scanf("%s",emp.l_name);
       printf("\nEnter employee age: ");
       scanf("%d",&emp.age);
       printf("\nEnter employee salary: ");
       scanf("%d",&emp.salary);


       fprintf(fp,"\n%d\t%ld\t%s  %s\t%d\t%d\n",emp.no,emp.id,emp.f_name,emp.l_name,emp.age,emp.salary);
       printf("\nDo you want to enter more(y/n): ");
       fflush(stdin);

       an=getch();
   }
    fclose(fp);
    fclose(fq);

}
int editAccount()
{
    struct employee emp[1000];
    FILE *fp,*fp1;
    int ch,i,r,f=0;
    char c[1000];
    long int n;
    fp=fopen("pro.txt","r");
    fp1=fopen("temp.txt","a");
    printf("Enter ID number: \n");
    scanf("%ld",&n);
    printf("Enter first name: \n");
    scanf("%s",c);

    for(i=0; !feof(fp);i++)
    {
        fscanf(fp,"%d",&emp[i].no);
        fscanf(fp,"%ld",&emp[i].id);
        fscanf(fp,"%s %s",emp[i].f_name,emp[i].l_name);
        fscanf(fp,"%d",&emp[i].age);
        fscanf(fp,"%d",&emp[i].salary);
        r= strcmp(c, emp[i].f_name);
        if(r==0)
        {
            f=1;
             printf("\n Do you want to change the  first name ?(y/n)");
            scanf("%d",&ch);
             if(ch==1)
            {
                printf("Enter new name: ");
                scanf("%s",emp[i].f_name);
            }
             printf("\n Do you want to change the last name ?(y/n)");
            scanf("%d",&ch);

            if(ch==2)
            {
                printf("Enter new name: ");
                scanf("%s",emp[i].l_name);
            }

            printf("\n Do you want to change employee age ?(y/n)");
            scanf("%d",&ch);

            if(ch==3)
            {
                printf("Enter new age: ");
                scanf("%d",&emp[i].age);
            }

            printf("\n Do you want to change the last name ?(y/n)");
            scanf("%d",&ch);

            if(ch==4)
            {
                printf("Enter new salary: ");
                scanf("%d",&emp[i].salary);
            }
             fprintf(fp1,"\n%d\t%ld\t%s  %s\t%d\t%d\n",emp[i].no,emp[i].id,emp[i].f_name,emp[i].l_name,emp[i].age,emp[i].salary);
        }

        else
        {
             fprintf(fp1,"\n%d\t%ld\t%s  %s\t%d\t%d\n",emp[i].no,emp[i].id,emp[i].f_name,emp[i].l_name,emp[i].age,emp[i].salary);
        }

    }

    if(f==0)
    {
        printf("Not found");
    }

    fclose(fp);
    fclose(fp1);

    fp=fopen("emp.txt","w");
    fclose(fp);
    fp=fopen("emp.txt","a");
    fp1=fopen("temp.txt","r");

     for(i=0; !feof(fp1);i++)
    {
        fscanf(fp1,"%d",&emp[i].no);
        fscanf(fp1,"%ld",&emp[i].id);
        fscanf(fp1,"%s %s",emp[i].f_name,emp[i].l_name);
        fscanf(fp1,"%d",&emp[i].age);
        fscanf(fp1,"%d",&emp[i].salary);

         fprintf(fp,"\n%d\t%ld\t%s  %s\t%d\t%d\n",emp[i].no,emp[i].id,emp[i].f_name,emp[i].l_name,emp[i].age,emp[i].salary);
    }
    fclose(fp);
    fclose(fp1);

    fp=fopen("temp.txt","w");
    fclose(fp);
    getch();

}
int deleteAccount()
{
    struct employee emp[1000];
    FILE *fp,*fp1;
    int ch,i,r,f=0;
    char c[1000];
    long int n;
    fp=fopen("pro.txt","r");
    fp1=fopen("temp.txt","a");
    printf("Enter ID number: \n");
    scanf("%ld",&n);
    printf("Enter first name: \n");
    scanf("%s",c);

    for(i=0; !feof(fp);i++)
    {
        fscanf(fp,"%d",&emp[i].no);
        fscanf(fp,"%ld",&emp[i].id);
        fscanf(fp,"%s %s",emp[i].f_name,emp[i].l_name);
        fscanf(fp,"%d",&emp[i].age);
        fscanf(fp,"%d",&emp[i].salary);
        r= strcmp(c, emp[i].f_name);
        if(r==0)
        {
            f=1;

        }

        else
        {
             fprintf(fp1,"\n%d\t%ld\t%s  %s\t%d\t%d\n",emp[i].no,emp[i].id,emp[i].f_name,emp[i].l_name,emp[i].age,emp[i].salary);
        }

    }

    if(f==0)
    {
        printf("Not found");
    }

    fclose(fp);
    fclose(fp1);

    fp=fopen("emp.txt","w");
    fclose(fp);
    fp=fopen("emp.txt","a");
    fp1=fopen("temp.txt","r");

     for(i=0; !feof(fp1);i++)
    {
        fscanf(fp1,"%d",&emp[i].no);
        fscanf(fp1,"%ld",&emp[i].id);
        fscanf(fp1,"%s %s",emp[i].f_name,emp[i].l_name);
        fscanf(fp1,"%d",&emp[i].age);
        fscanf(fp1,"%d",&emp[i].salary);

         fprintf(fp,"\n%d\t%ld\t%s  %s\t%d\t%d\n",emp[i].no,emp[i].id,emp[i].f_name,emp[i].l_name,emp[i].age,emp[i].salary);
    }
    fclose(fp);
    fclose(fp1);

    fp=fopen("temp.txt","w");
    fclose(fp);
    getch();
}
int totalSalary()
{
    struct employee emp[1000];
    FILE *ft;
    int i,num[1000],sum_salary=0;
    ft=fopen("pro.txt","r");
    if(fopen==NULL)
   {
       printf("File doesn't exist");
       return 0;
   }


     for(i=0; !feof(ft) ;i++)
     {
        fscanf(ft,"%d",&emp[i].no);
        fscanf(ft,"%ld",&emp[i].id);
        fscanf(ft,"%s %s",emp[i].f_name,emp[i].l_name);
        fscanf(ft,"%d",&emp[i].age);
        fscanf(ft,"%d",&emp[i].salary);
        sum_salary=sum_salary+emp[i].salary;
     }

     printf("Total salary: %d",sum_salary);
}

int maxSaalary()
{
    struct employee emp[1000];
    FILE *fp;
    int i,index,max_salary=0;
    fp=fopen("pro.txt","r");
    if(fopen==NULL)
   {
       printf("File doesn't exist");
       return 0;
   }

     for(i=0; !feof(fp) ;i++)
     {

         fscanf(fp,"%d",&emp[i].salary);
         fscanf(fp,"%s %s",emp[i].f_name,emp[i].l_name);

        if(max_salary<emp[i].salary)
        {
            max_salary=emp[i].salary;
            index=i;
        }
     }


     printf("Maximum salary: %s",emp[index].f_name);
}
int minSalary()
{
    struct employee emp[1000];
    FILE *fp;
    int i,index,min_salary;
    fp=fopen("pro.txt","r");
    if(fopen==NULL)
   {
       printf("File doesn't exist");
       return 0;
   }
     for(i=0; !feof(fp) ;i++)
       {
           min_salary=emp[0].salary;
           fscanf(fp,"%d",&emp[i].salary);
           fscanf(fp,"%s %s",emp[i].f_name,emp[i].l_name);
        if(min_salary>emp[i].salary)
            {
             min_salary=emp[i].salary;
             index=i;
            }
       }
     printf("Minimum salary: %s",emp[index].f_name);
}
int avgSalary()
{
    struct employee emp[1000];
    FILE *fp;
    int i,sum_salary=0;
    float avg;
    fp=fopen("pro.txt","r");
    if(fopen==NULL)
   {
       printf("File doesn't exist");
       return 0;
   }

     for(i=0; !feof(fp) ;i++)
     {
         fscanf(fp,"%d",&emp[i].salary);
         sum_salary=sum_salary+emp[i].salary;
     }
     avg=(float)sum_salary/i;
     printf("Average salary: %f",avg);
}
