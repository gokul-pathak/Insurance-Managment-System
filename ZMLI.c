/*
Introduction to C programming 
Insurance app
Designed by Gokul Pathak (NPI000095)
Infomax College
*/
//header files
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>//time oriented function
#include <stdlib.h>
//prototypes
	//main menu functions
void menu();//main menu
int authenticate();
void details();//details of plans
void plandes();//to display plan details
void health_history();//to enter health history of patient

	//subscriber functions
void subplan_menu();//subscriber main menu for create account or log in
void create_account();// create account for subscriber
void clog_in(int);//log in menu for subscriber
void customer_menu(int);//after log in menu for select plan or view information or cliam amount
void check(int);//to check if subscriber already subscribe plan or not
void select_plan(int);//selecting plans
void plan_limit_menu();
void plan_150();
void plan_120();
void plan_200();
void info(int);//to view information for subscriber
void minfo(int);
void claim(int);//claim function 1
void updatefiles(int,int);//upadating files
void trans_file(int,int);//storing transaction records
void calcu(int,int,int);
void enterdays();//claim sub-function 2
void forget();//if user forget the password
void change(char*cpass,int);

	//admin functions
void admin_menu_pass();//admin log in menu
void admin_menu();//after login menu it shows view customer by id or customer list that are in database of system.
void viewcustomerlist();//to view all customer list
void customer_byid();//to view customer by id
void moredetail();//to view selecting plans details
void account_info();//to view the account information of lifetime subscriber and annual claim limit
void del_user();
void list_claim();
void annual();
void lifetime();

void main()//attempt validation
{
	int attempt=0,success=0;
	do
	{
		if(!success)
		{
			attempt++;
			success=authenticate();
		}
		else
		{
			menu();
			break;
		}
		if(attempt>=3)//after 3 wrong attempt the user is blocked to log in 
		{
			system("cls");
			printf("\n\tYou have exceeded maximum 3 attempts allowed.!!!"); getch(); return;
		}
	}
	while(attempt<3);
}
void menu()//main menu
{
	do{
		int option;
		system("cls");
		printf("\n\t\t\tHealth Insurance Application:\n\t----------------------------------------------------------------\n");
		printf("\n\t\t\t1.Available insurance plans details");
		printf("\n\t\t\t2.Customer servies");
		printf("\n\t\t\t3.Admin room");
		printf("\n\t\t\t4.Log out");
		printf("\n\t\t\twhich services?"); scanf("%d",&option);
		switch(option)
		{
			case 1: details(); getch(); break;
			case 2: subplan_menu(); getch(); break;
			case 3: admin_menu_pass(); getch(); break;
			case 4: printf("\nThanks for using this application!Bye!bye!\n\n");getch();return;
			default: printf("\n\nInvalid option!. Enter [1-4]!\n\n");getch(); break;
		}
	}while(1);
}
int authenticate()//system validation username zedmedilife and password insurance2021
{
	char username[20]= "admin", password[20]= "nepal123", usernamekb[20], passwordkb[20];
	{
		
		system("cls");
		printf(" \n\t Enter System Username:"); gets(usernamekb); fflush(stdin);
		printf(" \n\t Enter System password:"); gets(passwordkb); fflush(stdin);
		if(strcmp(username,usernamekb) ==0 )
		{
			if(strcmp(password,passwordkb) == 0)
			{
				system("cls");
				printf("\n\t login sucessful.\n\n\n\n\n\n\n\n\n\n\tWelcome to ZedMediLife Insurance Company Limited\n\n\n\n\tDesigned by Gokul Pathak(NPI000095)\n\n\n\n\n\n\tPress any key to continue!!!\n\t"); getch(); return 1;
			}
			else
			{
			printf("\n\t Incorrect passsword"); getch();
			}
		}
			else
			{
			printf("\n\t Incorrect username"); getch();
			}
			return 0;
			getch();
	}
	
}
void details()//only plan details 
{
	int age, options;
	system("cls");
	printf("\n\tEnter age"); scanf("%d", &age);
	if(age>=0 && age<=20)
	{
		system("cls");
		printf("\n\t--------------------\n\tYou are eligible for\n\t------------------------------------------------------------ \n\t|Plan120|\t\t|Plan150|\t\t|Plan200|");
		printf("\n\t------------------------------------------------------------");
		plandes();
	
	}
	else if(age>=21 && age<=40)
	{
		system("cls");
		printf("\n\t--------------------\n\tYou are eligible for\n\t------------------------------------------------------------ \n\t\t|Plan150|\t\t|Plan200|");
		printf("\n\t------------------------------------------------------------");
		plandes();
	}
	else if (age>=41 && age<=54)
	{
		system("cls");
		printf("\n\t--------------------\n\tYou are eligible for\n\t------------------------------------------------------------ \n\t\t\t\t|Plan200|");
		printf("\n\t------------------------------------------------------------");
		plandes();
	}
	else
	{
		system("cls");
		printf("\n\tyour age is not eligible for our plan thanks for visiting");getch();
	}
	getch();
	
}
void plandes()//plan details amount table only
{
	printf("\n\n\t\t<-Insurance Amount Table->");
	printf("\n___________________________________________________________________");
	printf("\n\t\t\t|Plan120(RM)\t|Plan150(RM)\t|Plan200(RM)");
	printf("\n____________________________________________________________________");
	printf("\nMonthly Premium|\t120\t\t150\t\t200");
	printf("\nAnnual claim limit|\t120,000\t\t150,000 \t200,000");
	printf("\nLifetime Claim Limit|\t600,000\t\t750,000\t\t1,000,000");
	printf("\n____________________________________________________________________");
	
	printf("\n\n\n\n\t\t\t\t\t\t<-Benefits Table->");
	printf("\n_________________________________________________________________________________________________");
	printf("\nTypes of claim\t\t\t|\t\tEligibility Amount (RM)");
	printf("\n\t\t\t\t|\t|Plan120|\t\t|Plan150|\t\t|Plan200|");
	printf("\n________________________________|________________________________________________________________");
	printf("\nRoom charges\t\t\t|\t|120/day|\t\t|150/day|\t\t|200/day|");
	printf("\nIntensive Care Unit(ICU)charge  |\t|250/day|\t\t|400/day|\t\t|700/day|");
	printf("\nHospital Supplies and services  |");
	printf("\nSurgical Fees\t\t\t|\t\t{As charged Subject to approval by ZeeMediLife}");
	printf("\nOther fees\t\t\t|");
	printf("\n_________________________________________________________________________________________________");
	printf("\t\t\t\tNow after knowing this benefits and amount table you can go to subscribe plan tab");
	
}
void subplan_menu()// customer menu
{
	int choice,id;
	do{
		system("cls");
		printf("\n\t\t\t--------------------\n\t\t\t|Customer Services|\n\t\t\t--------------------\n\n");
		printf("\t\t\t1.Create new account:)");
		printf("\t2.Log in to your account:)");
		printf("\t3.Forget password:)");
		printf("\n\t\t\t4.Go back:)");
		printf("\n\n\n\t\tEnter your choice: ");
		scanf("%d",&choice); fflush(stdin);
		switch(choice)
		{
			case 1:
					printf("\n--------------------\n\t<-For new customer->\n--------------------\n");
					create_account(); getch(); break;
			case 2:
					printf("\n--------------------\n\t<-Log in->\n--------------------\n");
					clog_in(id); getch(); break;
			case 3: forget();getch(); break;
			case 4:
				   system("cls");
				   printf("\tThanks for using our application.");
			       printf("\n\n\tHope you have a wonderful day.\n\n");
			       getch(); return;
			default: printf("\n Invalid choice!!\n");
			       getch(); /*return 0; */ break;
		}
		
 	}while(1);
	
}
void create_account()//creating new account for customer
{
    FILE *fpg;
	char fname[20],username[20], password[20];
	char city[20];
    int start=100, end=150,id;
    char phone[15];
    char role;
	fpg = fopen("customerlist.txt", "a");
    system("cls");
    if(fpg==NULL)
    {
    	printf("\n\tFIle could not be opened!\n"); getch(); return ;
    }
    printf("\n\t<-Enter User details:->\n\n");
    srand(time(NULL));
    id=(rand()%(end-start+1))+start;
    printf("(\t**note remember your id**)!!Your id* is:|%d|",id);
    printf("\n\tName: "); gets(fname); fflush(stdin);
    
    printf("\n\tEnter your Address:"); gets(city); fflush(stdin);
    printf("\n\tEnter your contact number: "); gets(phone); fflush(stdin);
    {
    	if(strlen(phone)!=10&&strlen(phone)!=14)
    	{
    		printf("Phone number must be 10 digit!!!");getch();create_account();
		}
		else
		printf(":)");getch();
	}
    printf("\n\tIf you are customer enter'c' and if you are admin plz enter 'a': "); scanf("%c", &role); fflush(stdin);
    printf("\n\tUsername: "); gets(username); fflush(stdin);
    printf("\n\tPassword: "); gets(password); fflush(stdin);
    fprintf(fpg,"%d %s %s %s %s %s %c\n", id, fname, username, password, city, phone, role);
    fclose(fpg);
    health_history(id);
    printf("\n\n\tData written successfully to file!!\n\n\n\n\n\n\tAccount created successfully___\n\n\n\n\n\n\n\n\tPress any key to return main menu!!!\n"); getch();
	
}
void health_history(int id)// to add health history of customer while creating account
{
	FILE*h;
	char l[20],choice;
	h=fopen("health.txt","a");
	printf("\n\tEnter your health history::");
	printf("%d",id);
	printf("\n\rif any medical probelms that doctors have diagonsed::");
	printf("\ny-yes and n-no");
	scanf("%c",&choice);fflush(stdin);
	if(choice=='y')
	{
		printf("mention that: ");
		gets(l);fflush(stdin);
		fprintf(h,"%d %s\n",id,l);
		fclose(h);
	}
	if(choice=='n')
	{
		printf("no health history");
		fprintf(h,"%d no_health_history\n",id,choice);
		fclose(h);
	}
	
	
}
void clog_in(int id)//log in for customer 
{
	FILE *fpg;
    char fname[20], usern[20], pw[20], un[20], p[20];
    char city[20];
    int idk;
    char phone[15];
    char role,ch; 
    do
    {
	    system("cls");
	    printf("\nEnter username:"); gets(un); fflush(stdin);
	    printf("\nEnter ID provided by admin:"); scanf("%d",&id); fflush(stdin);
	    printf("\nEnter password:"); gets(p); fflush(stdin); 
	    fpg = fopen("customerlist.txt", "r");
	    if(fpg==NULL)
	     {
	        printf("\nFIle could not be opened!\n"); getch(); return ;
	     }
	
	    while(fscanf(fpg, "%d %s %s %s %s %s %c", &idk, fname, usern, pw, city, phone, &role) == 7)
	    {
	       if(strcmp(un, usern) == 0 && strcmp(p, pw) == 0 && (id==idk))
		    {
			    if(role=='c')
			    {
			    	system("cls");
			    	printf("\tLog in success!!! Welcome %s\n\n\n\n\n\n\n\n\n\n\n\n\tPress any key to continue!!!",fname);getch();
			    	customer_menu(id);
			    	fclose(fpg);
					return;
			    }
			}
		}
		   printf("\n\tLogin failed:)!!"); getch();
		   fclose(fpg);
		   printf("\n\tDo you want to continue?[y-yes | n-no]");
		   scanf("%c",&ch);fflush(stdin);
		   if(ch=='y')
		   {
				continue;
		   }
		   else
		   {
				break;
		   }
	}while(1);
}
void customer_menu(int id)//after log in customer main menu
{
	int choice;
	do
	{
		system("cls");
		printf("\n\tWelcome to customer menu:");
		printf("\n\t\t\t-------------------------\n\t\t\t|Available Services 24x7|\n\t\t\t-------------------------\n\n");
		printf("\t\t\t1.<-Select plan->");
		printf("\t2.<-View my information->");
		printf("\t3.<-Claim insurance amount->");
		printf("\n\t\t\t4.<-Log out->");
		printf("\n\n\n\t\tEnter your choice:(1-4:) ");
		scanf("%d",&choice); fflush(stdin);
		switch(choice)
		{
			case 1:
					printf("\n--------------------\n\t<-For new customer->\n--------------------\n");
					check(id); getch(); break;
			case 2:
					printf("\n--------------------\n\t<-Information->\n--------------------\n");
					info(id); getch(); break;
			case 3:
					printf("\n--------------------\n\t<-Amount claim->\n--------------------\n");
					claim(id); getch(); break;
				
			case 4:
				   system("cls");
				   printf("\tThanks for using our application.");
			       printf("\n\n\tHope you have a wonderful day.\n\n");
			       getch(); return;
			default: printf("\n\t Invalid choice!!\n");
			       getch(); /*return 0; */ break;
		}
	}while(1);
}
void check(int id)//to check if the customer have alredy subscribe the package or not
{
	int idk,amount,age,choice;
	char type[20];
	FILE*fp;
	fp=fopen("selectplan.txt","r");
	if(fp==NULL)
    {
    	printf("\n\tFIle could not be opened!\n"); getch(); return ;
    }
	while(fscanf(fp,"%d %d %d %s %d",&idk, &age, &choice,type,&amount)==5)
	{
		if(id==idk)
		{
			system("cls");
			printf("\tYou have already subscribed plan please check your details \n\tor claim insurance amount according to your need!!!");getch();
			return;
		}
	}
	fclose(fp);
	system("cls");
	select_plan(id);
	getch(); return;
}
void select_plan(int id)//selecting plan process
{
	int age, choice, option, amount, type;
	FILE *fp;
	fp = fopen("selectplan.txt", "a");
    if(fp==NULL)
    {
    	printf("\n\tFIle could not be opened!\n"); getch(); return ;
    }
	printf("\n\t<Enter your details:> ");
	printf("\n\tEnter your age: "); scanf("%d",&age); fflush(stdin);
	if(age>=0 && age<=20)
	{
		printf("\n\tWhich plan do you want to subscribe");
		printf("\n\n\t\t\t|Plan120(RM)\t|Plan150(RM)\t|Plan200(RM)\t\n");
		printf("\n\tPlease enter your Plan_type in digit eg.200: ");
		scanf("%d",&choice);fflush(stdin);
		if(choice==120)
		{
			fprintf(fp,"%d %d %d ", id, age,choice);
			fclose(fp);
			plan_limit_menu();
			plan_120();
		}
		if(choice==150)
		{
			fprintf(fp,"%d %d %d ", id, age,choice);
			fclose(fp);
			plan_limit_menu();
			plan_150();
		}
		if(choice==200)
		{
			fprintf(fp,"%d %d %d ", id, age,choice);
			fclose(fp);
			plan_limit_menu();
			plan_200();
		}
		else
		{
			system("cls");
			printf("\tpress any enter key to go back/exit");
		}
	}
	else if(age>=21 && age<=40)
	{
		printf("\n\t\tWhich plan do you want to subscribe");
		printf("\n\n\t\t\t\t|Plan150(RM)\t|Plan200(RM)\t\n");
		printf("\n\tPlease enter your Plan_type in digit eg.200: ");
		scanf("%d",&choice);fflush(stdin);
		if(choice==150)
		{
			fprintf(fp,"%d %d %d ", id, age,choice);
			fclose(fp);
			plan_limit_menu();
			plan_150();
		}
		if(choice==200)
		{
			fprintf(fp,"%d %d %d ", id, age,choice);
			fclose(fp);
			plan_limit_menu();
			plan_200();
		}
		else
		{
			system("cls");
			printf("\tpress any enter key to go back/exit");
		}
	}
	else if(age>=41 && age<=54)
	{
		printf("\n\tYou have only one plan do you want to subscribe if yes");
		printf("\n\n\t\t\t|Plan200(RM)|\t\n");
		printf("\n\tPlease enter your Plan_type in digit eg.200: ");
		scanf("%d",&choice);fflush(stdin);
		if(choice==200)
		{
			fprintf(fp,"%d %d %d ", id, age,choice);
			fclose(fp);
			plan_limit_menu();
			plan_200();
		}
		else
		{
			system("cls");
			printf("\tpress any enter key to go back/exit");
		}
	}
	else
	{
		system("cls");
		printf("\n\tYou are not eligible for our plan thank you have a nice day!!!");
	}
    printf("\n\n\tData written successfully to file!!\n"); getch();
    return;
}
void plan_limit_menu()//to the claim limit for customer
{
	FILE *fp;
	char type[10];
	fp = fopen("selectplan.txt", "a");
    if(fp==NULL)
    {
    	printf("\n\tFIle could not be opened!\n"); getch(); return ;
    }
	system("cls");
	printf("\n----------------------------------------\n");	
	printf("\n\tWhich package do you want to subscribe\n");
	printf("\n----------------------------------------\n");
	printf("\t<*>|Annual Claim Limit subscription|\t\t\n");
	printf("\t<*>|Lifetime claim limit subscription|\t\t\n");//annual
	printf("\tEnter claim limit as eg. 'lifetime' in lowercase:\n");
	gets(type);fflush(stdin);
	if(strcmp(type,"annual")==0)
	{
		printf("\n%s is your claim limit",type);getch();
		fprintf(fp,"%s ",type);
		fclose(fp);return;
	}
	if(strcmp(type,"lifetime")==0)
	{
		printf("You have selected %s",type);getch();
		fprintf(fp,"%s ",type);
		fclose(fp);return;
	}
	else
	{
		printf("Invalid claim limit"); getch();plan_limit_menu();
	}
}
void plan_120()//plan 120 package
{
	system("cls");
	int amount;
	char type[20];
	FILE *fp;
	fp = fopen("selectplan.txt", "a");
    if(fp==NULL)
    {
    	printf("\nFIle could not be opened!\n"); getch(); return ;
    }
	printf("\t<-which claim limit do you want to subscribe->");
	printf("\n\t<The Annual Claim Limit subscription amount is: RM 120,000>");
	printf("\n\t<The Lifetime claim limit subscription amount is: RM 600,000>");
	printf("\n\t\t\t*Enter the amount eg.600,000::\n\t");
	scanf("%d",&amount);fflush(stdin);
	fprintf(fp,"%d\n",amount);
	fclose(fp);
}
void plan_150()//plan 150 package
{
	int amount;
	FILE *fp;
	fp = fopen("selectplan.txt", "a");
    if(fp==NULL)
    {
    	printf("\nFIle could not be opened!\n"); getch(); return ;
    }
	system("cls");
	printf("\t<-which claim limit do you want to subscribe->");
	printf("\n\t<The Annual Claim Limit subscription amount is: RM 150,000>");
	printf("\n\t<The Lifetime claim limit subscription amount is: RM 750,000>");
	printf("\n\t\t\t*Enter the amount eg.600,000::\n\t");
	scanf("%d",&amount);fflush(stdin);
	fprintf(fp,"%d\n",amount);
	fclose(fp);
}
void plan_200()//plan 200 package
{
	int amount;
	FILE *fp;
	fp = fopen("selectplan.txt", "a");
    if(fp==NULL)
    {
    	printf("\nFIle could not be opened!\n"); getch(); return ;
    }
	system("cls");
	printf("\t<-which claim limit do you want to subscribe->");
	printf("\n\t<The Annual Claim Limit subscription amount is: RM 200,000>");
	printf("\n\t<The Lifetime claim limit subscription amount is: RM 1,000,000>");
	printf("\n\t\t\t*Enter the amount eg.600,000::\n\n\t\t");
	scanf("%d",&amount);fflush(stdin);
	fprintf(fp,"%d\n",amount);
	fclose(fp);
	
}
void info(int id)//to display information for customer about their username password details
{
	int idf,amount,age,choice;
	char fname[20],username[20], password[20],type[20];
	char phone[15];
	char city[20], role;

	FILE*fpg,*fp;
	system("cls");
	fpg=fopen("customerlist.txt","r");
	if(fpg==NULL){
		printf("\nFile could not opened!please verify your information!!"); getch; return;
	}
	while(fscanf(fpg, "%d %s %s %s %s %s %c", &idf, fname, username, password, city, phone, &role) == 7)
	{
		if(id==idf)
		{
			printf("\t\t\t\t<-<:Welcome %s:>->\n\n",fname);
			printf("\n\t=========================================================================================================================\n\n");
			printf("\n\t|ID| |customer name| \t|Username| \t|Password|     |Address|\t\t|Phone no.| |Role|");
			printf("\n\t|%d|    |%s|      |%s|      |%s|      |%s|            |%s|    |%c|",id, fname, username, password, city, phone, role);
			printf("\n\t=========================================================================================================================\n\n");getch();
			fclose(fpg);
			minfo(id);
			return; 
		}
	}
	fclose(fpg);
	printf("\n\tDetails could not:)::) \n\tfound thanks for visting!!!");
	getch();return;
}
void minfo(int id)//to display claim history and their plan account information
{
	int idf,idk,amount,balance,age,choice,tr_id,day,month,year;
	char type[20];
	FILE *fp,*fp1;
	system("cls");
	fp=fopen("selectplan.txt","r");
	fp1=fopen("transaction.txt","r");
	if(fp==NULL){
		printf("\n\tFile could not opened!please verify your information!!"); getch; return;
	}
	while(fscanf(fp,"%d %d %d %s %d",&idf,&age, &choice,type,&amount)==5)
	{
		if(id==idf)
		{
			printf("\n\t<-Other information->\n");
			printf("\n\t=========================================================================================================================\n\n");
			printf("\n\t|ID| |Age| |Plan type| |Claim limit| |Balance|");
			printf("\n\t|%d| |%d| |%d| \t|%s|    |%d|",idf, age, choice, type, amount);
			printf("\n\t=========================================================================================================================\n\n");
			getch();
		}
	}
	fclose(fp);
	printf("\n\t<-For other information->\n");
	printf("\nYour transaction history is :");
    printf("\n------------------------------------------------------");
    //1 19 16300 23 7 2021
	printf("\n\t|tID| |ID| |Claimed amt| |Date| |Month| |Year|");
    while(fscanf(fp1, "%d %d %d %d %d %d", &tr_id, &idk, &balance, &day, &month, &year)==6)
	{
		if( id == idk)
		{
			printf("\n\t   %d \t%d   %d   \t      %d   %d   %d\n",tr_id,idk, balance, day, month, year);
			
		}
	}
	fclose(fp1);getch();return;
	system("cls");
	printf("\n\tDetails could not found\n\tPlease be make sure you have to select our plan package\n\n\n\t thanks for visting:):):):)\n\n\n\n\n\tZee_mediLife insurance co.\n\n\n\n\n\n\n\n\tPress any key to go back!!!\n");
	getch();return;
	
}
void claim(int id)//claim history and claim processing menu or form
{
	int idk,total,hospital,icu,ward,plan_type,surgical,supplies,other,age,choice;
	int balance,amount,amoun, day, month, year, tr_id;
	char type[20];
	FILE*fp,*fp1;
	fp=fopen("selectplan.txt","r");
	fp1=fopen("transaction.txt","r");
	
    printf("\nYour transaction history is :");
    printf("\n------------------------------------------------------");
    //1 19 16300 23 7 2021
	printf("\n\t|tID| |ID| |Claimed amt| |Date| |Month| |Year|");
    while(fscanf(fp1, "%d %d %d %d %d %d", &tr_id, &idk, &balance, &day, &month, &year)==6)
	{
		if( id == idk)
		{
			printf("\n\t   %d \t%d   %d   \t      %d   %d   %d\n",tr_id,idk, balance, day, month, year);
			
		}
		
	}
	fclose(fp1);
	printf("\n\n\n\n\n\n\nPress any key to claim!!!!!!");getch();
	system("cls");
	printf("\n\n------------------------------------------------------");
	printf("\n\t <>Fill the Following details<>");
	printf("\n\tEnter how many days you hospitalised?");
	scanf("%d",&hospital);fflush(stdin);
	printf("\n\tEnter how many days you stay in ICU?");
	printf("\n\tIf you are not stay in ICU just enter 0 if yes enter days: \t");
	scanf("%d",&icu);fflush(stdin);
	printf("\n\tEnter how many days you stay in room charges?");
	printf("\n\ttotal number of days in hospital for room charges: \t");
	scanf("%d",&ward);fflush(stdin);
	printf("\n\tThe cost of surgical fees \nif any if not please enter 0: \t");
	scanf("%d",&surgical);fflush(stdin);
	printf("\n\tThe cost of hospital total supplies and services fees only \n\tif any if not please enter 0: \t");
	scanf("%d",&supplies);fflush(stdin);
	printf("\n\tThe cost of other fees if any if not please enter 0: \t");
	scanf("%d",&other);fflush(stdin);
	while(fscanf(fp,"%d %d %d %s %d",&idk, &age, &choice,type,&amount)==5)
	{
		if(id == idk)
		{
			if(choice == 150)
			{
				total=icu*400+ward*150+surgical+supplies+other;
				printf("\n\tYour total fees ");
				
			}
			else if(choice == 120)
			{
				total=icu*250+ward*120+surgical+supplies+other;
				printf("\n\tYour total fees ");
			}
			else if(choice == 200)
			{
				total=icu*700+ward*200+surgical+supplies+other;
				printf("\n\tYour total fees ");	
			}
			fclose(fp);
			calcu(amount,total,id);
		}
	}
	fclose(fp);
}
void calcu(amount,total,id)
{
	printf("is %d\n",total);getch();
	if(amount>=total)
	{
		amount = amount - total;
		printf("\n\tthe amount after deduction of total cost is RM %d\n",amount); getch();
		updatefiles(id,amount);
		trans_file(id,total);
	}
	else
	{
		system("cls");
		printf("\n\tlow balance in your account \n!!!");
		printf("\n\tThanks for using!!!!!"); getch();return;
	}
}
void updatefiles(int id, int amoun)//for updating files to create transaction history and for claim processing
{
	FILE*fp,*fpg;
	int idk,age,amount,choice;
	char type[15];
	fpg = fopen("selectplanTMP.txt", "w");
	char oldname[] = "selectplanTMP.txt";
	char newname[] = "selectplan.txt";
	fp=fopen("selectplan.txt","r");
	if(fp==NULL)
    {
    	printf("\n\tFIle could not be opened!\n"); getch(); return ;
    }
	//21 40 200 annual 200000
	while(fscanf(fp,"%d %d %d %s %d",&idk, &age, &choice,type,&amount)==5)
	{
		if(id == idk)
		{
			fprintf(fpg,"%d %d %d %s %d\n",idk,age,choice,type,amoun);	
		}
		else
		{
			fprintf(fpg,"%d %d %d %s %d\n",idk, age, choice,type,amount);
		}
	}
	fclose(fp);
	fclose(fpg);
	getch();
	if(!remove(newname))
	{
		printf("\n----------------------------------------------");
	    printf("\n\tFile removed successfully!");
	    printf("\n--------------------------------------------");getch();
	}
	
	if(!rename(oldname, newname))
	{
		printf("\n--------------------------------------------");
		printf("\n\tFile renamed successfully!");
		printf("\n--------------------------------------------");
	}
	getch();
}
void trans_file(int id, int total)//to add date in claim history
{
	FILE *fp = fopen("transaction.txt", "a");
	time_t rawtime = time(NULL);
	struct tm *ptm = localtime(&rawtime);
    fprintf(fp, "%d %d %d %d %d %d\n", generatetransactionID(),id, total, ptm->tm_mday, ptm->tm_mon+1, ptm->tm_year+1900);
    fclose(fp);
	
}
int generatetransactionID()//to generate transaction history
{
    int idf;
    int  claim_amount;
    char uf[20];
    int day, month, year, tr_id;
	FILE *fp = fopen("transaction.txt", "r");
	int maxID=0;
	while(fscanf(fp, "%d %d %d %d %d %d", &tr_id, &idf,&claim_amount, &day, &month, &year)==6)
	{
		if( tr_id>maxID)
		{
			maxID = tr_id;
		}
	}
	fclose(fp);
	return (maxID+1);
}
void admin_menu_pass()//admin login process username and password are default by the system that is username is admin and password is nepal123
{
	char username[20]= "admin", password[20]= "nepal123", usernameg[20], passwordp[20];
	{
		system("cls");
		printf(" \n\t Enter username:"); scanf("%s",&usernameg); fflush(stdin);
		printf(" \n\t Enter password:"); gets(passwordp); fflush(stdin);
		if(strcmp(username,usernameg) ==0 )
		{
			if(strcmp(password,passwordp) == 0)
			{
				system("cls");
				printf("\n\n\n\t login sucessful.\n\n\n\n\n\n\n\n\n\n\n\tPress any key to continue!!!!:>\n\t"); getch();
				admin_menu();
			}
		else
		{
			printf("\n Incorrect passsword"); getch();
		}
		}
		else
		{
			printf("\n Incorrect username"); getch();
		}
	}
	getch();
}

void admin_menu()//after admin log in the main menu for admin panel
{
 do
	{
		int choice;
	    system("cls");
	    printf("\n\t____<-Welcome->____\n\t\tADMIN_PANEL*\n\n");
	    printf("\n\t<-View Customer list:->\t\t\t\t1");
	    printf("\n\t<-Search by Id:-> \t\t\t\t2");
	    printf("\n\t<-Health history-> \t\t\t\t3");
	    printf("\n\t<-Transaction history of all customer:->\t4");
	    printf("\n\t<-View customer by claim type->\t\t\t5");
	    printf("\n\t<-Logout:->\t\t\t\t\t6");
	    printf("\n\n\t<-Which option do you want to perform[1|2|3|4]->?\n");
	    scanf("\t\t%d", &choice);
	    switch(choice){
	       case 1: viewcustomerlist(); break;
	       case 2: customer_byid();break;
	       case 3: del_user();break;
	       case 4: account_info();break;
	       case 5: list_claim();break;
	       case 6: 
		   			 system("cls");
					 printf("\t<-Thanks for using!!!:):)->");
					 return; getch();
	      default: printf("\n\tInvalid choice. Enter [1Å]2]\n\n"); getch();
	    }
	}while(1);

}
void del_user()//to show the history of helath by id to the admin panel
{
	FILE*fp;
	char history[20];
	int id;
	fp=fopen("health.txt","r");
	if(fp==NULL){
		printf("\nFile not found 101");getch;return;
	}
	system("cls");
	printf("\n\tusers health history with their ID");
	printf("\n=========================================================================================================================\n\n");
	printf("\n\t<-The customer who have their health issues->");
	printf("\n\t|ID|\t|Health history|");
	while(fscanf(fp,"%d %s",&id, history)==2)
	{
		printf("\n\t|%d|\t |%s|",id,history);
	}
	fclose(fp);
	getch();
}
void viewcustomerlist()//to show custoemr list
{
	FILE *fpg,*fp;
	int id, idf,amount,age,choice;
	char fname[20],username[20], password[20],type[20];
	char phone[15];
	char city[20], role;
	fpg=fopen("customerlist.txt","r");
	if(fpg==NULL){
		printf("\nFile could not opened!please verify your information!!"); getch; return;
	}
	system("cls");
	printf("\n\t\t\t\t<-Welcome admin->\n\there is desired details\n");
	printf("\t|ID| |customer name| \t|Username| \t|Password| |Address|\t\t|Phone no.| |Role|");
	while(fscanf(fpg, "%d %s %s %s %s %s %c", &id, fname, username, password, city,phone, &role) == 7)
	{
		printf("\n\t|%d|    |%s|           |%s|      |%s|      |%s|       |%s|     |%c|",id, fname, username, password, city, phone, role);
	}
	fclose(fpg);
	moredetail(); getch(); return;
}
void moredetail()//to show the plan types that the customer choose
{
	int id, idf,amount,age,choice;
	char type[20];
	FILE*fp;
	fp=fopen("selectplan.txt","r");
	if(fp==NULL){
		printf("\nFile could not opened!please verify your information!!"); getch; return;
	}
	printf("\n=========================================================================================================================\n\n");
	printf("\n\t<-The customer who have selected plan->");
	printf("\n\t|ID| |Age| |Plan type| |Claim limit| |Balance|");
	while(fscanf(fp,"%d %d %d %s %d",&id, &age, &choice,type,&amount)==5)
	{
		printf("\n\t|%d|\t|%d| |%d||%s|\t|%d|",id, age, choice, type, amount);
	}
	printf("\n=========================================================================================================================\n\n");
	fclose(fp);
	getch();
}
void customer_byid()//to view customer by their id
{
	int id, idf,amount,age,choice;
	char fname[20],username[20], password[20],type[20];
	char phone[15];
	char city[20], role;

	FILE*fpg,*fp,*hp;
	system("cls");
	printf("\nEnter desired customer ID: ");scanf("%d",&idf);fflush(stdin);
	fpg=fopen("customerlist.txt","r");
	fp=fopen("selectplan.txt","r");
	hp=fopen("health.txt","r");
	if(fpg==NULL&fp==NULL){
		printf("\nFile could not opened!please verify your information!!"); getch; return;
	}
	while(fscanf(fpg, "%d %s %s %s %s %s %c", &id, fname, username, password, city,phone, &role) == 7)
	{
		if(id==idf)
		{
			while(fscanf(fp,"%d %d %d %s %d",&id, &age, &choice,type,&amount)==5)
			{
				if(id==idf)
				{
					printf("\t\t\t\t<-Welcome admin->\n\there is desired details\n");
					printf("\t|ID| |customer name| \t|Username| \t|Password| |Address|\t\t|Phone no.| |Role|");
					printf("\n\t|%d|    |%s|           |%s|      |%s|      |%s|       |%s|     |%c|",id, fname, username, password, city, phone, role);
					printf("\n=========================================================================================================================\n\n");
					printf("\n\t<-Selected plans details->");
					printf("\n\t|ID| |Age| |Plan type| |Claim limit| |Balance|");
					printf("\n\t|%d|\t|%d| |%d||%s|   |%d|",id, age, choice, type, amount);
					printf("\n=========================================================================================================================\n\n");
					getch();
					return;
				}
			}
		}
	}
	fclose(fpg);
	printf("Details could not \nfound thanks for visting!!!:):):)");
	getch();return;
}
void account_info()//to view th transation history of all customer
{
	FILE*fp;
	int idf,idk,amount,balance,age,choice,tr_id,day,month,year;
	fp=fopen("transaction.txt","r");
	printf("\n=========================================================================================================================\n\n");
	printf("\n\t\t\t<-Transaction History->");
	printf("\n=========================================================================================================================\n\n");
	printf("\n\t|tID| |ID| |Claimed amt| |Date| |Month| |Year|");
    while(fscanf(fp, "%d %d %d %d %d %d", &tr_id, &idk, &balance, &day, &month, &year)==6)
    {
    	printf("\n\t   %d \t%d   %d   \t      %d   %d   %d\n",tr_id,idk, balance, day, month, year);
	}
	printf("\n=========================================================================================================================\n\n");
	fclose(fp);
	getch();
}
void list_claim()//to view subscriber - main menu
{
	int ch;
	do{
		system("cls");
		printf("\nTo view");
		printf("\n\tAnnual lifetime Subscriber list \t1");
		printf("\n\tLifetime Subscriber List \t\t2");
		printf("\n\tGo back\t\t\t\t\t3");
		printf("\n----------------------------------------------------------------------------------");
		printf("\nWhich services do you want to choose?");
		scanf("%d",&ch);fflush(stdin);
		switch(ch)
		{
			case 1: annual(); break;
			case 2: lifetime(); break;
			case 3: system("cls");
					printf("Thanks for using:)");getch;return;
			default: printf("\n\tInvalid choice");getch();
		}
	}while(1);
}
void annual()//to show the details of annual subscribers
{
	system("cls");
	FILE*fp;
	int idk,age,amount,choice,sum=0;
	char type[15];
	fp=fopen("selectplan.txt","r");
	if(fp==NULL)
    {
    	printf("\n\tFIle could not be opened!\n"); getch(); return ;
    }
    printf("\n=========================================================================================================================\n\n");
	printf("\n\tThe list of annual claim type subscriber are:.");
	printf("\n\t|ID| |Age| |Plan type| |Claim limit| |Balance|");
	while(fscanf(fp,"%d %d %d %s %d",&idk, &age, &choice,type,&amount)==5)
	{
		if(strcmp(type,"annual")==0)
		{
			printf("\n\t  %d    %d \t%d \t%s \t\t%d",idk,age,choice,type,amount);
			sum=sum+amount;
		}
		
	}
	printf("\n=========================================================================================================================\n\n");
	fclose(fp);
	printf("\n\t%d is the grand total of annual subscriber amount",sum);
	printf("\n\n\t|Press any key to go back!!!|");
	getch();
}
void lifetime()//to show details of lifetime subscriber
{
	system("cls");
	FILE*fp;
	int idk,age,amount,choice,sum=0;
	char type[15];
	fp=fopen("selectplan.txt","r");
	if(fp==NULL)
    {
    	printf("\n\tFIle could not be opened!\n"); getch(); return ;
    }
    printf("\n=========================================================================================================================\n\n");
	printf("\n\tThe list of lifetime claim type subscriber are:.");
	printf("\n\t|ID| |Age| |Plan type| |Claim limit| |Balance|");
	while(fscanf(fp,"%d %d %d %s %d",&idk, &age, &choice,type,&amount)==5)
	{
		if(strcmp(type,"lifetime")==0)
		{
			printf("\n\t  %d   %d \t%d \t%s \t%d",idk,age,choice,type,amount);
			sum=sum+amount;
		}
	}
	printf("\n=========================================================================================================================\n\n");
	fclose(fp);
	printf("\n\t%d is the grand total of lifetime subscriber amount",sum);
	printf("\n\n\t|Press any key to go back!!!|");
	getch();
}
void forget()//to change the password in customer section
{
	FILE*fpg;
	char usern[20];
	int id,idf;
	char fname[20], username[20],password[20],npass[20],cpass[20];
    char city[20];
    char phone[15];
    char role,ch; 
    fpg=fopen("customerlist.txt","r");
	system("cls");
	printf("\tEnter the following details:.");
	printf("\n\tEnter your username: ");
	gets(usern);fflush(stdin);
	printf("\n\tEnter your id provided by admin: ");
	scanf("%d",&id);fflush(stdin);
	while(fscanf(fpg, "%d %s %s %s %s %s %c", &idf, fname, username, password, city, phone, &role) == 7)
	{
		if(usern==username||id==idf)
		{
			printf("\n\t|Username|\t%s\n\t|Password|\t%s",username,password);
			printf("\n\tDo you want to change password?[y-yes | n-no]");
			scanf("%c",&ch);fflush(stdin);
			if(ch=='y')
			   {
					printf("\n\tEnter new password: \n\t(Please remember your password):");
					gets(npass);fflush(stdin);
					printf("\n\tConfirm your password: ");
					gets(cpass);fflush(stdin);
					if(strcmp(npass,cpass)==0)
					{
						printf("password is about to change");
						fclose(fpg);
						change(cpass,id);
						return;
					}
					else
					{
						fclose(fpg);
						printf("data didnot match");forget();
					}
			   }
		}
	}
	fclose(fpg);
	return;
	printf("\n\tNo match found!!!!!");
	getch();
}
void change(char *cpass,int id)//to change the file status of password
{
	FILE*fpg,*fp;
	int idf;
	char fname[20],username[20],password[20],city[20],phone[20],role;
	fpg = fopen("customerlisttmp.txt", "a");
	char oldname[] = "customerlisttmp.txt";
	char newname[] = "customerlist.txt";
	fp=fopen("customerlist.txt","r");
	if(fp==NULL)
    {
    	printf("\n\tFIle could not be opened!\n"); getch(); return;
    }
    while(fscanf(fp, "%d %s %s %s %s %s %c", &idf, fname, username, password, city, phone, &role) == 7)
    {
    	if(id!=idf)
    	{
    		fprintf(fpg,"%d %s %s %s %s %s %c\n",idf, fname, username, password, city, phone, role);
		}
		else
		{
			fprintf(fpg,"%d %s %s %s %s %s %c\n",idf, fname, username, cpass, city, phone, role);
		} 
	}
	fclose(fp);
	fclose(fpg);
	getch();
	if(!remove(newname))
	{
		printf("\n----------------------------------------------");
	    printf("\n\tFile removed successfully!");
	    printf("\n--------------------------------------------");getch();
	}
	
	if(!rename(oldname, newname))
	{
		printf("\n--------------------------------------------");
		printf("\n\tFile renamed successfully!");
		printf("\n--------------------------------------------");
	}
	getch();
	
}
//ending..........................................................................
