#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define MAX 50

typedef struct login{
    char temp_name[100], temp_age[20], temp_email[20], temp_name1[50], temp_mobile[20], pass[13], name[20], temp_address[30], temp_landmark[30];
}
booking;

static int i=0;

struct web{
char name[30],pass[30];
}
w[99];

struct open{
    char pin[4];
}
set;


int n;
booking e;
void login();
int choice;
void signup();
void menu();
void user();
void administration();
void aboutus();
void Password();
void section();
void details();
void checker();

/**function that checks whether the database is located in the directory with the use of file handling**/
void checker()
{
        system ("cls");
        printf("Checking Database...\n");
        int wait;
        printf("In progress :");

            for(wait=0;wait<=10000;wait++){
                printf("\rIn progress : %d",wait/100);
            }
                printf("\n\n");

		FILE *fp;
		fp = fopen("E:\\record.txt","r");

            while( fread(&e, sizeof(e), 1, fp) == 1 ){
                    Sleep(1500);
            }
                if (fp==NULL)
                {
                    printf ("NO SYSTEM DETECTED! \n");
                    Sleep(1500);
                    checker();
                }
                    printf("\nSYSTEM DETECTED!\n");

		system ("pause");
		administration();
		fclose(fp);
}

/**function for the main menu and interface of the program**/
void section()
{
    system("cls");
    int choice;
    system ("COLOR CE");
    printf("*******************************************************************************************************************\n");
	printf("                                                 |: FOOD 2 GO :|\n");
	printf("*******************************************************************************************************************\n\n\n");
	printf(" [1] USER SECTION  \n\n [2] ADMINISTRATION SECTION \n\n [3] Exit \n\n\n   Enter Your Choice--->");
	scanf("%d",&choice);

                if(choice==1)
                {
                    user();
                }
                else if(choice==2)
                {
                    checker();
                    administration();
                }
                else if(choice==3)
                {
                system("cls");

        printf("\n\n\n");
        printf("*********************************************************************\n");
		printf("                        |:THANK YOU SO MUCH:|                           \n");
		printf("*********************************************************************\n\n");
		printf("*******************************************************************\n");
		printf("               |:Feeling HUNGRY ? Order now at FOOD 2 GO:|         \n");
		printf("*******************************************************************\n\n");
    exit(0);
}
}

/**function for the user section of the program**/
/**contains the option to Sign Up, Log In and entering the Mainmenu**/
void user()
{
    system("cls");
    printf("****************************************************************************************************************\n");
    printf("                                           |: WELCOME TO THE USER SECTION :|                                      \n");
    printf("****************************************************************************************************************\n\n");
    printf("[1]SIGNUP\n\n[2]LOGIN\n\n[3]MAINMENU\n\n");
    printf("Enter your choice---> ");
    scanf("%d", &choice);//uses switch case to prompt your choice

                switch (choice){

                    case 1:
                        {
                            signup();
                        }
                        break;

                    case 2:
                        {
                            login();
                        }
                         break;

                    case 3:
                        {
                            section();
                        }
                         break;

                    default:
                        {
                            printf("\nPlease Enter the ");
                            printf("valid choice\n");
                        }
                         break;

                        {
                            system("cls");
                            section();
                        }
    }
    }

/**Function for the Admin Section containing the commands of viewing records, orders, informations**/
void administration()
{
	Password();
	system("cls");
	printf("****************************************************************************************************************\n");
    printf("                                             |:WELCOME TO THE ADMIN SECTION:|                                     \n");
    printf("****************************************************************************************************************\n\n");
	printf("            [1] View Records\n\n            [2] Previous Orders\n\n            [3] Information \n\n            [4] Back To Main Menu \n\n        Enter Your Choice --->");

	int n;
	scanf("%d",&n);
    printf("\n\n");

	int wait;
	printf("In progress :");

        for(wait=0;wait<=10000;wait++){
            printf("\rIn progress : %d",wait/100);
        }
            printf("\n\n");

    if(n==1)    /**Choose the options through the use of if/else statement**/
        {
            {
                system ("cls");
                printf("*******************************************************************************************************************\n");
                printf("                                                   |User Details|\n");
                printf("*******************************************************************************************************************\n\n\n");

        FILE *view;
        char viw;
        view = fopen("E:\\record.txt","rt");

            while((viw=fgetc(view))!=EOF)
            {
                printf("%c",viw);
            }
                system ("pause");
                administration();
                fclose(view);
            }
        }
    else if(n==2)
		{
                system ("cls");
                FILE *view;
                char viw;
                view = fopen("E:\\order.txt","rb");

            while((viw=fgetc(view))!=EOF)
            {
                printf("%c",viw);
            }
                system ("pause");
                administration();
                fclose(view);
        }
    else if(n==3)
        {
                aboutus();
        }
    else if(n==4)
        {
            system("cls");
            section();
        }
    else
        {
            printf("Wrong Input !! PLease Re-enter The Correct Option");

            if(getch())
            administration();
        }
}

/**Contains the names of the people behind the project**/
void aboutus()
{
	system("cls");
	printf("PEOPLE BEHIND THIS PROJECT :\n\n   -->Christian Figuron as Business Analyst\n\n   -->Erica Mae Sarsoza as Business Analyst\n\n   -->Karl Nelson Calupaz as User Experience A.K.A Main Programmer\n\n   -->John Arthur Carandang as User Experience A.K.A Assistant Programmer\n\n   -->Krystel Mae Jabonete as User Interface\n\n   -->Ramonchito Archie Reynancia as User Interface\n\n   -->Kristian Eusebio as Technical Support\n\n   -->Ronne Reyes as Technical Support\n\n                    ****************************THANK YOU****************************");
	printf("\n\n");
	printf("    Press Any Key To Go Back.");

	if(getch())
	administration();
}

/**This function contains the password for administration section**/
void Password()
{
	system("cls");
	char str[10], c = ' ';
    char pin[] = "1234";

    int i = 0;
    printf("Enter the ADMIN PIN [4 pins]: ");

        while (i <= 9){
            str[i] = getch();
            c = str[i];

            if(c == 13)
                {
                    break;
                }
            else
                {
                    printf("*");
                }
                    i++;
                }
                    str[i] = '\0';
                    i = 0;

        if(strcmp(str,pin)!=0)
            {
                printf("\nWrong Pin\n");
                getch();
                Password();
            }
}

/**function for the sign up option in the user section of the program**/
void signup()
{
    int i,p=0;
    char c,checker[30]; int z=0;

    FILE *fp;
    fp=fopen("E:\\record.txt","ab");
    system("cls");
    printf("****************************************************************************************************************\n");
    printf("                                                 Sign up Now!!!                                   \n");
    printf("****************************************************************************************************************\n\n");
    printf("NOTE!!!\n\n");
    printf("*Space is not allowed\n\n");

    /**these are the informations needed to be filled out by the user**/
    printf("First Name: ");scanf("%s",&e.temp_name);
    printf("Last Name: ");scanf("%s",&e.temp_name1);
    printf("Age: ");scanf("%s",&e.temp_age);
    printf("Email: ");scanf("%s", &e.temp_email);
    printf("Mobile (Enter 11 Digits): ");scanf("%s",&e.temp_mobile);
    printf("City: ");scanf("%s",&e.temp_address);
	printf("Landmark: ");scanf("%s",&e.temp_landmark);
	printf("\n*Create your Username and Password.");
	printf("\n*Do not press backspace.\n");

    /**the checker will check whether the username is new or not**/
        for(i=0;i<100;i++){
            printf("Username: ");
            scanf("%s",checker);

        while(!feof(fp))
            {
                fread(&w[i],sizeof(w[i]),1,fp);
            if(strcmp(checker,w[i].name)==0)
            {
                printf("\nUSERNAME ALREDY EXISTS!");
                signup();
            }
            else
            {
                strcpy(w[i].name,checker);
            }
            break;
            }
                printf("Password: ");

        while((c=getch())!=13)
            {
                w[i].pass[z++]=c;
                printf("%c",'*');
            }

        /**Function to print the category in .txt**/
        fwrite(&w[i],sizeof(w[i]),1,fp);
        fprintf(fp,"\nFirst Name:%s\n",e.temp_name);
        fprintf(fp,"Last Name:%s\n",e.temp_name1);
        fprintf(fp,"Age:%s\n",e.temp_age);
        fprintf(fp,"Email:%s\n",e.temp_email);;
        fprintf(fp,"Mobile No.:%s\n",e.temp_mobile);
        fprintf(fp,"City:%s\n",e.temp_address);
        fprintf(fp,"Landmark:%s\n",e.temp_landmark);
        fprintf(fp,"\n");

        fclose(fp);
        printf("\n\nPress ENTER if you agree with Username and Password");

        if((c=getch())==13){

            printf("\n\nYou are successfully registered!");
            printf("\n\nLog in your account?\n\n");
            printf("> PRESS 1 FOR YES\n\n> PRESS 2 FOR NO\n\n");
            scanf("%d",&n);

        /**after the sign up it will directly go to the log in section**/
            switch(n){

                case 1:
                    login();
                    break;

                case 2: //* Signing up complete//

                    printf("\nTHANK YOU FOR SIGNING UP \n");
                    system ("pause");
                    user();
                    break;
                }
                }
                break;
                }
                getch();
                system("pause");

        // Printing the Output in .txt
        fwrite(&e, sizeof(e),1,fp);
        fprintf(fp,"\n\nFirst Name:%s\n",e.temp_name);
        fprintf(fp,"Last Name:%s\n",e.temp_name1);
        fprintf(fp,"Age:%s\n",e.temp_age);
        fprintf(fp,"Email:%s\n",e.temp_email);
        fprintf(fp,"Mobile No.:%s\n\n",e.temp_mobile);
        fprintf(fp,"Address:%s\n",e.temp_address);
        fprintf(fp,"Landmark:%s\n",e.temp_landmark);
        fprintf(fp,"\n");

        fclose(fp);

        int wait;
        printf("In progress :"); //* Progress section//

            for(wait=0;wait<=10000;wait++){
                printf("\rIn progress : %d",wait/100);
            }
            system("cls");
            login();
}

/**this contains the log in section, after logging in it will directly go to menu**/
void login(){
      system("cls");
      FILE *fp;
      char c,name[30],pass[30]; int z=0;
      int checku,checkp;
      fp=fopen("E:\\record.txt","rb");
        printf("****************************************************************************************************************\n");
        printf("                                             |WELCOME TO LOG IN ZONE|                                  \n");
        printf("****************************************************************************************************************\n\n");

      for(i=0;i<1000;i++)
        {
            printf("\n ENTER USERNAME: ");
            scanf("%s",name);
            printf(" ENTER PASSWORD: ");

            while((c=getch())!=13)
            {
                pass[z++]=c;
                printf("%c",'*');
            }
            pass[z]='\0';

            while(!feof(fp))
            {
                fread(&w[i],sizeof(w[i]),1,fp);
                checku=strcmp(name,w[i].name);
                checkp=strcmp(pass,w[i].pass);

                if(checku==0&&checkp==0)
                {
                    printf("\n\n                                     ---------------------------------------\n");
                    printf("                                      - YOU HAVE LOGGED IN SUCCESSFULLY!! -\n");
                    printf("                                     ---------------------------------------\n");
                    break;
                    menu();
                }
                else if(checku==0&&checkp!=0)
                {
                    printf("\n\n\nWRONG PASSWORD!! Not %s??",name);
                    printf("\n\n(Press 'Y' to re-login)");
                    if(getch()=='y'||getch()=='Y')
                    login();
                }
                else if(checku!=0)
                {
                    printf("\n\n\nYou are not a Registered User\nPress ENTER to Log in again");
                    if(getch()==13)
                    login();
                }
                }
                break;
        }
        getch();
        menu();
}

/**the main program contains all the variables declared and used in the food ordering section of the program**/
int main()
{
    static int totalCost;
    int i,j,choice,c=1,a[50],cost[33];

        for(i=0;i<33;i++)
            a[i]=0;

    char str[100];
    char items[33][100]={" 8-pc. Chicken","5-pc. Chicken","Chicken McDo w/ Fries","Fries","Burger McDo","McChicken","Double Cheeseburger","Hot Fudge Sundae","McFloat","Coke",
                        "Sprite","8-pc. Chickenjoy","6-pc. Chickenjoy","Chickenjoy w/ Fries","Burger Steak","Jolly Spaghetti","Yum Burger", "Double Bacon Cheesy",
                        "Peach Mango Pie","Chocolate Sundae Twirl","Coke","Sprite","Pearl Milk Tea","Panda Milk Tea","White Pearl Milk Tea","Taro Milk Tea",
                        "Orange Mountain Tea","Lemon Black Tea","Passion Fruit Tea Burst","Grapefruit and Orange Tea","Ceylon Black Tea","Jasmin Green Tea","Wintermelon Mountain Tea",
                        };
                        system("cls");
                        section();
}

/**the menu section contains the three food chains namely McDonald's, Jollibee and CoCo**/
/**in every switch case under the food chains name, there are also switch cases of menu**/
void menu()
{
    static int totalCost;
    int i,j,choice,c=1,a[50],cost[33];

        for(i=0;i<33;i++)
            a[i]=0;

    char str[100];
    char items[33][100]={" 8-pc. Chicken","5-pc. Chicken","Chicken McDo w/ Fries","Fries","Burger McDo","McChicken","Double Cheeseburger","Hot Fudge Sundae","McFloat","Coke","Sprite",
                        "8-pc. Chickenjoy","6-pc. Chickenjoy","Chickenjoy w/ Fries","Burger Steak","Jolly Spaghetti","Yum Burger","Double Bacon Cheesy","Peach Mango Pie",
                        "Chocolate Sundae Twirl","Coke","Sprite","Pearl Milk Tea","Panda Milk Tea","White Pearl Milk Tea","Taro Milk Tea","Orange Mountain Tea","Lemon Black Tea",
                        "Passion Fruit Tea Burst","Grapefruit and Orange Tea","Ceylon Black Tea","Jasmin Green Tea","Wintermelon Mountain Tea",};

        do
            {
                if(c==1)
                    {
                        system ("cls");
                        printf("****************************************************************************************************************\n");
                        printf("                                              |: WELCOME TO FOOD 2 GO :|                                      \n");
                        printf("****************************************************************************************************************\n\n");

                        printf("Enter the number of your choice:\n\n[1]- McDonald's\n\n[2]- Jollibee\n\n[3]- CoCo\n\nPress any other number to Mainmenu:\n"); //Prompt Your Order Choice
                        scanf("%d",&choice); // get your choice order.

                switch(choice){
                    case 1:
                      {
                        system ("cls");
                        int McDOChoice;
                        printf("****************************************************************************************************************\n");
                        printf("                                              |: McDonalds Menu :|                                      \n");
                        printf("****************************************************************************************************************\n\n");

                        printf("Enter the number of your choice:\n1 - 8-pc. Chicken - Php.280.00\n2 - 5-pc. Chicken - Php.200.00\n3 - Chicken McDo w/ Fries - Php.135.00\n4 - Fries - Php.35.00 \n5 - Burger McDo - Php.50.00\n6 - McChicken - Php.60.00\n7 - Double Cheeseburger - Php.90.00\n8 - Hot Fudge Sundae - Php.30.00\n9 - McFloat - Php.30.00\n10 - Coke - Php.25.00\n11 - Sprite - Php.25.00 \nPress any other number to exit:\n");
                        scanf("%d",&McDOChoice);

                        cost[0]=280.00;
                        cost[1]=200.00;
                        cost[2]=135.00;
                        cost[3]=35.00;
                        cost[4]=50.00;
                        cost[5]=60.00;
                        cost[6]=90.00;
                        cost[7]=30.00;
                        cost[8]=30.00;
                        cost[9]=25.00;
                        cost[10]=25.00;

                switch(McDOChoice)
                    {
                        case 1:
                            {
                                int num;
                                printf("You chose 8-pc. Chicken - Php.280.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[0]++;
                                        totalCost+=280.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 2:
                            {
                                int num;
                                printf("You chose  5-pc. Chicken - Php.200.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[1]++;
                                        totalCost+=200.00;
                                    }
                                    printf("Your Cost in Cart is %d\n",totalCost);
                            }
                            break;
                        case 3:
                            {
                                int num;
                                printf("You chose Chicken McDo w/ Fries - Php.135.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[2]++;
                                        totalCost+=135.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 4:
                            {
                                int num;
                                printf("You chose Fries - Php.35.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[3]++;
                                        totalCost+=35.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 5:
                            {
                                int num;
                                printf("You chose Burger McDo - Php.35.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[4]++;
                                        totalCost+=35.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 6:
                            {
                                int num;
                                printf("You chose McChicken - Php.60.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[5]++;
                                        totalCost+=60.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 7:
                            {
                                int num;
                                printf("You chose Double Cheeseburger - Php.90.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[6]++;
                                        totalCost+=90.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 8:
                            {
                                int num;
                                printf("You chose Hot Fudge Sundae - Php.30.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[7]++;
                                        totalCost+=30.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 9:
                            {
                                int num;
                                printf("You chose McFloat - Php.30.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[8]++;
                                        totalCost+=30.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 10:
                            {
                                int num;
                                printf("You chose Coke - Php.25.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[9]++;
                                        totalCost+=25.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 11:
                            {
                                int num;
                                printf("You chose Sprite - Php.25.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[10]++;
                                        totalCost+=25.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        default:
                            {
                                printf("Exit from McDo\n"); //Exit
                            }
                            break;
}
break;
}

                    case 2:
                      {
                        system ("cls");
                        int JollibeeChoice;
                        printf("****************************************************************************************************************\n");
                        printf("                                              |: Jollibee Menu  :|                                      \n");
                        printf("****************************************************************************************************************\n\n");

                        printf("Enter the number of your choice:\n1 - 8-pc. Chickenjoy - Php. 250.00 \n2 - 6-pc. Chickenjoy - Php. 200.00 \n3 - Chickenjoy w/ Fries - Php. 185.00 \n4 - Burger Steak - Php.95.00 \n5 - Jolly Spaghetti - Php.50.00\n6 - YumBurger - Php.50.00\n7 - Double Bacon Cheesy - Php.99.00\n8 - Peach Mango Pie - Php.35.00\n9 - Chocolate Sundae Twirl - Php.29.00\n10 - Coke - Php.25.00\n11 - Sprite - Php.25.00 \nPress any other number to exit:\n");
                        scanf("%d",&JollibeeChoice); // get your order

                        cost[11]=250.00;
                        cost[12]=200.00;
                        cost[13]=185.00;
                        cost[14]=95.00;
                        cost[15]=50.00;
                        cost[16]=50.00;
                        cost[17]=99.00;
                        cost[18]=35.00;
                        cost[19]=29.00;
                        cost[20]=25.00;
                        cost[21]=25.00;

                switch(JollibeeChoice)
                    {
                        case 1:
                            {
                                int num;
                                printf("You chose 8-pc. Chickenjoy - Php. 250.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[11]++;
                                        totalCost+=250.00;
                                    }
                                    printf("Your Cost in Cart is %d\n",totalCost);
                            }
                            break;
                        case 2:
                            {
                                int num;
                                printf("You chose 6-pc. Chickenjoy - Php. 200.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[12]++;
                                        totalCost+=200.00;
                                    }
                                    printf("Your Cost in Cart is %d\n",totalCost);
                            }
                            break;
                        case 3:
                            {
                                int num;
                                printf("You chose Chickenjoy w/ Fries - Php. 185.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                {
                                    a[13]++;
                                    totalCost+=185.00;
                                }
                                printf("Your Cost in Cart is %d\n",totalCost);
                            }
                            break;
                        case 4:
                            {
                                int num;
                                printf("You chose Burger Steak - Php.95.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                {
                                    a[14]++;
                                    totalCost+=95.00;
                                }
                                printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 5:
                            {
                                int num;
                                printf("You chose Jolly Spaghetti - Php.50.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[15]++;
                                        totalCost+=50.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 6:
                            {
                                int num;
                                printf("You chose Yum Burger - Php.50.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[16]++;
                                        totalCost+=50.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 7:
                            {
                                int num;
                                printf("You chose Double Bacon Cheesy - Php.99.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[17]++;
                                        totalCost+=99.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 8:
                            {
                                int num;
                                printf("You chose Peach Mango Pie - Php.35.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[18]++;
                                        totalCost+=35.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 9:
                            {
                                int num;
                                printf("You chose Chocolate Sundae Twirl - Php.29.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[19]++;
                                        totalCost+=29.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 10:
                            {
                                int num;
                                printf("You chose Coke - Php.25.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[20]++;
                                        totalCost+=25.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 11:
                            {
                                int num;
                                printf("You chose Sprite - Php.25.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[21]++;
                                        totalCost+=25.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        default:
                            {
                                printf("Exit from Jollibee Category\n"); //Exit From Jollibee
                            }
                            break;
}
break;
}

                    case 3:
                      {
                        system ("cls");
                        int CocoChoice;
                        printf("****************************************************************************************************************\n");
                        printf("                                              |: Coco Menu  :|                                      \n");
                        printf("****************************************************************************************************************\n\n");
                        printf("Enter the number of your choice:\n1 - Pearl Milk Tea - Php.99.00 \n2 - Panda Milk Tea - Php.105.00 \n3 - White Pearl Milk Tea - Php.105.00 \n4 - Taro Milk Tea - Php.99.00 \n5 - Orange Mountain Tea - Php.99.00\n6 - Lemon Black Tea - Php.120.00\n7 - Passion Fruit Tea Burst - Php.155.00\n8 - Grapefruit and Orange Tea - Php.155.00 \n9 - Ceylon Black Tea - Php.180.00\n10 - Jasmin Green Tea - Php.110.00\n11 - Wintermelon Mountain Tea - Php.99.00 \nPress any other number to exit:\n");
                        scanf("%d",&CocoChoice); // Get your Order

                        cost[22]=99.00;
                        cost[23]=105.00;
                        cost[24]=105.00;
                        cost[25]=99.00;
                        cost[26]=99.00;
                        cost[27]=120.00;
                        cost[28]=120.00;
                        cost[29]=155.00;
                        cost[30]=180.00;
                        cost[31]=110.00;
                        cost[32]=99.00;

                switch(CocoChoice)
                    {
                        case 1:
                            {
                                int num;
                                printf("You chose Pearl Milk Tea - Php. 99.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[22]++;
                                        totalCost+=99.00;
                                    }
                                    printf("Your Cost in Cart is %d\n",totalCost);
                            }
                            break;
                        case 2:
                            {
                                int num;
                                printf("You chose Panda Milk Tea - Php. 105.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[23]++;
                                        totalCost+=105.00;
                                    }
                                    printf("Your Cost in Cart is %d\n",totalCost);
                            }
                            break;
                        case 3:
                            {
                                int num;
                                printf("You chose White Pearl Milk Tea - Php. 105.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[24]++;
                                        totalCost+=105.00;
                                    }
                                    printf("Your Cost in Cart is %d\n",totalCost);
                            }
                            break;
                        case 4:
                            {
                                int num;
                                printf("You chose Taro Milk Tea - Php.99.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[25]++;
                                        totalCost+=99.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 5:
                            {
                                int num;
                                printf("You chose Orange Mountain Tea - Php.99.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[26]++;
                                        totalCost+=99.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 6:
                            {
                                int num;
                                printf("You chose Lemon Black Tea - Php.120.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                {
                                    a[27]++;
                                    totalCost+=120.00;
                                }
                                printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 7:
                            {
                                int num;
                                printf("You chose Passion Fruit Tea Burst - Php.155.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                {
                                    a[28]++;
                                    totalCost+=155.00;
                                }
                                printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 8:
                            {
                                int num;
                                printf("You chose Grape Fruit and Orange Tea - Php.155.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[29]++;
                                        totalCost+=155.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 9:
                            {
                                int num;
                                printf("You chose Ceylon Black Tea - Php.180.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[30]++;
                                        totalCost+=180.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 10:
                            {
                                int num;
                                printf("You chose Jasmin Green Tea - Php.110.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[31]++;
                                        totalCost+=110.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        case 11:
                            {
                                int num;
                                printf("You chose Wintermelon Mountain Tea - Php.99.00.Are you sure you want to buy? \nIf 'Yes' Enter 1 else any number:\n");
                                scanf("%d",&num);

                                if(num==1)
                                    {
                                        a[32]++;
                                        totalCost+=99.00;
                                    }
                                    printf("Your Cost in Cart is Php.%d\n",totalCost);
                            }
                            break;
                        default:
                            {
                                printf("Exit from Coco Category\n"); //Exit from Coco
                            }
                            break;
}
break;
}
        default:
        section();
        break;
}

    printf("\n\n");
    printf("*******************************************************************************************************************\n");
	printf("                                                 |: CART 2 GO :|\n");
	printf("*******************************************************************************************************************\n\n\n");

    for(i=0;i<33;i++)
        {
            if(a[i]!=0)
                {
                    printf("\n ID: %d\n Items: %s\n Quantity: %d\n Cost: Php %d.00\n",i,items[i],a[i],(cost[i]*a[i]));
                    FILE *fp;
                    fp= fopen("E:\\order.txt","a");
                    fprintf(fp,"\n ID: %d\n Items: %s\n Quantity: %d\n Cost: Php %d.00\n",i,items[i],a[i],(cost[i]*a[i]));
                    fclose(fp); //close the file
                }
        }
        printf("\nIf you wish to buy anything more Enter the number of your choice:\nEnter 1 to Add Item\nEnter 2 to Delete Items\nEnter 3 to Change Quantity \nPress any other number to exit:\n");
        scanf("%d",&c);
 }

    if(c==2)
        {
            int id;
            printf("Enter ID to delete item:\n"); // Prompt for deletion
            scanf("%d",&id); // The ID will be deleted

            if(id<=33&&id>=0)
                {
                    totalCost=totalCost-(cost[id]*a[id]);
                    a[id]=0;
                }
            else
                {
                    printf("Enter Valid id\n"); // If you pin wrong ID no. that can't be deleted
                }
                system ("cls");
                printf("Revised Items: \n\n"); // the item will revise

            for(i=0;i<33;i++)
                {
                    if(a[i]!=0)
                        {
                            printf("\n ID: %d\n Items: %s\n Quantity: %d\n Cost: Php %d.00\n",i,items[i],a[i],(cost[i]*a[i]));
                        }
                }
                printf("--------------------------------------------------------");
                printf("\n\t\tTotal Cost is Php %d\n",totalCost);
                printf("--------------------------------------------------------");
                printf("\nIf you wish to buy anything more Enter the number of your choice:\nEnter 1 to Add Item\nEnter 2 to Delete Items\nEnter 3 to Change Quantity \nPress any other number to checkout:\n");
                scanf("%d",&c);
}

    if(c==3)
        {
            int id,quantity;
            printf("Enter id to Change quantity of an item:\n"); // changing quantity of order
            scanf("%d",&id);
            printf("Enter quantity to be changed of an item:\n");
            scanf("%d",&quantity);

            if(id<=33&&id>=0)
                {
                if(quantity>=0 && a[id]>=0)
                    {
                    if(quantity<a[id])
                            {
                                int dec=a[id]*quantity;
                                a[id]=quantity;
                                totalCost=totalCost-(cost[id]*dec);
                            }
                            if(quantity>a[id])
                                {
                                    int inc=quantity-a[id];
                                    a[id]=quantity;
                                    totalCost=totalCost+(cost[id]*inc);
                                }
                                if(quantity==a[id])
                                    {
                                        a[id]=quantity;
                                        totalCost=totalCost+0;
                                    }
                    }
                    else
                        {
                            printf("Item has no Quantity.Please Try again\n"); // they don't have item quantity
                        }
                }
                else
                    {
                        printf("Enter Valid ID Number:\n"); //they will ask you to pin your valid ID Number
                    }
                    system ("cls");
                    printf("Revised Items: \n\n");

                    for(i=0;i<33;i++)
                        {
                            if(a[i]!=0)
                                {
                                    printf("\n ID: %d\n Items: %s\n Quantity: %d\n Cost: Php %d.00\n",i,items[i],a[i],(cost[i]*a[i]));
                                }
                        }
                        printf("--------------------------------------------------------");
                        printf("\n\t\tTotal Cost is Php %d\n",totalCost);
                        printf("--------------------------------------------------------");
                        printf("\nIf you wish to buy anything more Enter the number of your choice:\nEnter 1 to Add Item\nEnter 2 to Delete Items\nEnter 3 to Change Quantity \nPress any other number to exit:\n");
                        scanf("%d",&c);
        }
    }
        while(c==1 || c==2 ||c==3);
            printf("\n");
            printf("\n\t\t\tRECEIPT\n");
            printf("--------------------------------------------------------");
            printf("\n\t\tYour Final Cost is Php %d\n",totalCost);
            printf("--------------------------------------------------------");
            printf("\n\tThanks for Choosing Us and Visit us again!\n",str);

            Sleep(2000);
            details();
} // end of ordering

/**this section contains the details of the customer after ordering **/
void details()
{
    system("cls");
	char name1[20];
	char name2[20];
	long long int phone;
	char address[40];
	char landmark[30];

	printf("\n--->Please Give Your Contact Details: \n");
	printf("First Name : ");
	scanf("%s",name1);
	printf("Last Name : ");
	scanf("%s",name2);
	printf("Phone : ");
	scanf("%lld",&phone);
	printf("City : ");
	scanf("%s",address);
	printf("Landmark : ");
	scanf("%s",landmark);

	printf("\n\n");
	printf("--->Delivery Details:\n");

	FILE *cust;
	cust = fopen("E:\\order.txt","a");
	fprintf(cust," Order Placed By : %s %s\n",name1,name2);
	fclose(cust);

        printf("    -->First Name : %s\n    -->Last Name : %s\n    -->Phone : %lld \n    -->City : %s \n    -->Landmark : %s \n",name1,name2,phone,address,landmark);
        printf("\n\n\n");
        printf("             *********************************************************************************************\n");
        printf("                                       Your Order Will Be At Your Door In 30 minutes.\n");
        printf("                                                 .....HAPPY ORDERING.....\n");
        printf("             *********************************************************************************************\n");
        {
            exit(0);
        }
}
