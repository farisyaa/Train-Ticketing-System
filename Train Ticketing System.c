#include<stdio.h>
#include<stdlib.h>//contains header information for memory allocation and freeing functions
#include<string.h>//contains string processing functions

/*******************************************GLOBAL VARIABLES**********************************************************/
char name[50], type, preference;
int train_num, num_of_seats;

/*******************************************FUNCTION PROTOTYPE**********************************************************/
void reservation(void);						                                       	//main reservation function
void viewdetails(void);						                                    	//view details of all the trains								
void printticket(char name[], int, char, char, int, float);                       	//print ticket 
void specifictrain(int);				                                     		//print data related to specific train
float charge(int, int, char, char);		            		                    	//charges automatically 
void login();



/******************************************FUNCTION DECLARATION**********************************************************/

/*********************************************MENU OPTIONS*************************************************/

int main()
{
	system("cls"); 
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|        TRAIN TICKET BOOKING SYSTEM            |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|             BROUGHT TO YOU BY                 |\n");
	printf("\t\t|           NATASHAH AMIRAH 181792              |\n");
	printf("\t\t|           NUR IMAN KAMILA 182262              |\n");
	printf("\t\t|          NUR LIYANA AMEERA 182300             |\n");
	printf("\t\t|         NIK DEANNA ASHEERA  181817            |\n");
	printf("\t\t|         NUR FARISYA AQILAH  182300            |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
		
	    
	printf(" \n Press any key to continue:");
	
	getch();//hold a program execution	
    system("cls");//clear screen
	login();//function call for login as located inside main
	int menu_choice, choice_return;
	
	start:
	system("cls");
	
	printf("\n=================================\n");
	printf("    TRAIN BOOKING SYSTEM");
	printf("\n=================================");
	printf("\n1>> Book A Ticket Now ");
	printf("\n-------------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n-------------------------------");
	printf("\n3>> Exit");
	printf("\n-------------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	
	switch(menu_choice)
	{
		case 1:
			reservation();		
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
		case 3:
			return(0);
		default:
			printf("\nInvalid choice");
	}
	goto start;//go to where it started
	
	system("pause");
	return(0);
}

/*********************************************VIEWDETAILS()*************************************************/

void viewdetails(void)//there's not receive any data and return any
{
	system("cls");
	printf("------------------------------------------------------------------------------------------------------");	
	printf("\nTr.No\t()Name\t\t\tDestinations\t\t\tCharges(E/B)\t\tTime\n");
	printf("------------------------------------------------------------------------------------------------------");
	
	printf("\n1001\tHang Tuah Express\tKUALA LUMPUR To BUTTERWORTH\tRM 50/70\t\t9.00am");
	
	printf("\n1002\tHang Tuah Express\tBUTTERWORTH To KUALA LUMPUR\tRM 50/70\t\t12.00pm");
	
	printf("\n1003\tAbd Rahman Express\tIPOH  To JOHOR BAHRU	\tRM 70/90\t\t8.00am");
	
	printf("\n1004\tAbd Rahman Express\tJOHOR BAHRU To IPOH	\tRM 70/90\t\t11.00am");
	
	printf("\n1005\tTaming Sari Express\tMELAKA To KOTA BAHRU	\tRM 60/80\t\t7.00am");
		
	printf("\n1006\tTaming Sari Express\tKOTA BAHRU To MELAKA	\tRM 60/80\t\t9.30am");
		
    printf("\n1007\tPermata Express\t\tKUALA KEDAH To KUALA LUMPUR\tRM 60/80\t\t1.00pm");
	
    printf("\n1008\tPermata Express\t\tKUALA LUMPUR To KUALA KEDAH\tRM 60/80\t\t4.00pm");
   
    printf("\n1009\tDirgahayu Express\tKOTA KINABALU To KUCHING\tRM 100/120\t\t3.35pm");
   
    printf("\n1010\tDirgahayu Express\tKUCHING To KOTA KINABALU\tRM 100/120\t\t4.15pm");
}


/*********************************************RESERVATION()*************************************************/

void reservation(void)//not receiving any data and does not return any
{
	char confirm, type, preference;
	int i=0;//does not want trashvalue
	float charges;
	system("cls");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(name);
	
	printf("\nEnter Number of Seats:> ");
	scanf("%d",&num_of_seats);
	
	printf("\nEconomy or Business (E/B):> ");
	scanf(" %c",&type);
	
	printf("\nWindow or Aisle or Random (W/A/R):> ");
	scanf(" %c",&preference);
	
	printf("\n\n>>Press Enter To View Available Trains<< ");
	getch();
	system("cls");
	viewdetails();//calling for viewdetails function
	printf("\n\nEnter Train Number:> ");
	start1://go back start 1
	scanf("%d",&train_num);
	system ("cls");
	
/*********************************************SEATING CHART*************************************************/
	if(train_num>=1001 && train_num<=1010)
	{
		int business[10][1], economy[25][1], z=1;//row cols ,z for numbering of seats
		int m=0, n=0, g=0, h=0;

	
		printf ("\tSEATING CHART\n");
	
		printf ("\tBusiness Class seating: \n");
	
		for (g=0; g<10; g++)
		{ printf ("\t");
			for (h=0; h<1; h++)
			{
				printf ("[ %2d ]\t\t[ %2d ]\t\t[ %2d ]", z, z++, z++);
				z++;
			}
		 printf ("\n"); 
		}
	
		printf ("\n\n\tEconomy Class seating: \n"); 
	
		for (m=0; m<25; m++)
		{ printf ("\t"); 
			for (n=0; n<1; n++)
			{	
				printf ("[%3d][%3d][%3d]\t\t[%3d][%3d][%3d]", z, z++, z++, z++, z++, z++);
				z++;
			}
		 printf ("\n"); 
		}
	
		getch();
		system ("cls");
		
		charges = charge(train_num, num_of_seats, type, preference);
		printticket(name, num_of_seats, type, preference, train_num, charges);//function call for print ticket		
	}
	
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}

	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c", &confirm);
	
	if(confirm == 'y')//user enter y meaning yes
	{
		printf("=====================================================");
		printf("\n Reservation Done\n");
		printf("\n Please Print This Ticket at Home\n");
		printf("\n Please Pay at Our Counter\n");
		printf("=====================================================");
		printf("\nPress any key to go back to Main Menu");
	}
	else
	{
		if(confirm=='n')//user enter n meaning no 
		{
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	getch();//hold screen for a while
}

/*********************************************CHARGE()*************************************************/
//add on charges for business,seating at window/aisle
float charge(int train_num, int num_of_seats, char type, char preference)//non void with parameters meaning execpt data and give data
{
	float total=0;
	
	
//Kuala Lumpur - Butterworth
	if (train_num==1001 || train_num==1002)
	{
		total = 50 * num_of_seats;
		
		if (type=='B')
			total += (20 * num_of_seats);
			
		if (preference== 'W')
		total += (10 * num_of_seats);
	
		if (preference== 'A')
		total += (5 * num_of_seats);
		
	}

//Ipoh - Johor Bahru	
	else if (train_num==1003 || train_num==1004)
	{
		total = 70 * num_of_seats;
		
		if (type=='B')
			total += (20 * num_of_seats);	
			
		if (preference== 'W')
		total += (10 * num_of_seats);
	
		if (preference== 'A')
		total += (5 * num_of_seats);

	}

//Melaka - Kota Bahru	
	else if (train_num==1005 || train_num==1006)
	{
		total = 60 * num_of_seats;
		
		if (type=='B')
			total += (20 * num_of_seats);
			
		if (preference== 'W')
			total += (10 * num_of_seats);
	
		if (preference== 'A')
			total += (5 * num_of_seats);

	}

//Kuala Kedah - Kuala Lumpur
	else if (train_num==1007 || train_num==1008)
	{
		total = 60 * num_of_seats;
		
		if (type=='B')
			total += (20 * num_of_seats);
				
		if (preference== 'W')
			total += (10 * num_of_seats);
	
		if (preference== 'A')
			total += (5 * num_of_seats);

	}

//Kota Kinabalu - Kuching	
	else if (train_num==1009 || train_num==1010)
	{
		total = 100 * num_of_seats;
		
		if (type=='B')
			total += (20 * num_of_seats);
				
		if (preference== 'W')
			total += (10 * num_of_seats);
	
		if (preference== 'A')
			total += (5 * num_of_seats);

	}
	
	return total;//to take the value of the total 
}


/*********************************************PRINTTICKET()*************************************************/

void printticket(char name[], int num_of_seats, char type, char preference, int train_num, float charges)//does not except any data but return data
{
	system("cls");
	printf("-----------------------------------------------------\n");
	printf("\t\t\tTICKET\n");
	printf("-----------------------------------------------------\n\n");
	printf("Name:\t\t\t%s", name);
	printf("\nNumber of Seats:\t%d", num_of_seats);
	printf("\nClass:\t\t\t%c", type);
	printf("\nSeating Preference:\t%c", preference);
	printf("\nTrain Number:\t\t%d", train_num);
	specifictrain(train_num);//function call for specific train
	printf("\nCharges:\t\t%.2f", charges);
}

/*********************************************SPECIFICTRAIN()*************************************************/
//general information about the train(destination,time)
void specifictrain(int train_num)
{
	
	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tHang Tuah Express");
		printf("\nDestination:\t\tKuala Lumpur to Butterworth");
		printf("\nDeparture:\t\t9.00 am ");
	}
	if (train_num==1002)
	{
		printf("\nTrain:\t\t\tHang Tuah Express");
		printf("\nDestination:\t\tButterworth to Kuala Lumpur");
		printf("\nDeparture:\t\t12.00 pm");
	}
	if (train_num==1003)
	{
		printf("\nTrain:\t\t\tAbd Rahman Express");
		printf("\nDestination:\t\tIpoh to Johor Bahru");
		printf("\nDeparture:\t\t8.00 am");
	}
	if (train_num==1004)
	{
		printf("\nTrain:\t\t\tAbd Rahman Express");
		printf("\nDestination:\t\tJohor Bahru to Ipoh");
		printf("\nDeparture:\t\t11.00 am ");
	}
	if (train_num==1005)
	{
		printf("\nTrain:\t\t\tTaming Sari Express");
		printf("\nDestination:\t\tMelaka to Kota Bahru");
		printf("\nDeparture:\t\t7.00 am");
	}
	if (train_num==1006)
	{
		printf("\ntrain:\t\t\tTaming Sari Express");
		printf("\nDestination:\t\tKota Bahru to Melaka");
		printf("\nDeparture:\t\t9.30 am ");
	}
	if (train_num==1007)
	{
		printf("\ntrain:\t\t\tPermata Express");
		printf("\nDestination:\t\tKuala Kedah to Kuala Lumpur");
		printf("\nDeparture:\t\t1.00 pm ");
	}
	if (train_num==1008)
	{
		printf("\ntrain:\t\t\tPermata Express");
		printf("\n Destination:\t\tKuala Kedah to Kuala Lumpur");
		printf("\nDeparture:\t\t4.00 pm ");
	}
	if (train_num==1009)
	{
		printf("\ntrain:\t\t\tDirgahayu Express");
		printf("\nDestination:\t\tKota Kinabalu to Kuching");
		printf("\nDeparture:\t\t3.35 pm ");
	}
	if (train_num==1010)
	{
		printf("\ntrain:\t\t\tDirgahayu Express");
		printf("\nDestination:\t\tKuching to Kota Kinabalu");
		printf("\nDeparture:\t\t4.15 pm");
	}
}

/*********************************************LOGIN()*************************************************/

void login()//it stands on it's own and it does not disturb any data 
{
	int a=0,i=0;
    char uname[10],c=0; 
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	
    printf("\n  =======================  LOGIN FORM  =======================\n  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname); 
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword); 
		if(strcmp(uname,"user")==0 && strcmp(pword,"pass")==0)//comparing the username and password entered by the user
	{
	printf("  \n\n\n       WELCOME TO OUR SYSTEM !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\nPress any key to continue...");
	getch();//holds the screen
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		
		getch();//holds the screen
		system("cls");
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

