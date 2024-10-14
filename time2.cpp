/*#include <iostream>
#include <ctime>

using namespace std;

int main() {
   // current date/time based on current system
   time_t now = time(0);
   
   // convert now to string form
   char* dt = ctime(&now);

   //cout << "The local date and time is: " << dt << endl;

	 cout << "Today : " << dt << endl;
   // convert now to tm struct for UTC
   tm *gmtm = gmtime(&now);
   dt = asctime(gmtm);
   //cout << "The UTC date and time is:"<< dt << endl;
}*/
/*#include <iostream>
#include <ctime>

using namespace std;

int main() {
   // current date/time based on current system
   time_t now = time(0);

   cout << "Number of sec since January 1,1970 is:: " << now << endl;

   tm *ltm = localtime(&now);

   // print various components of tm structure.
   cout << "Year:" << 1900 + ltm->tm_year<<endl;
   cout << "Month: "<< 1 + ltm->tm_mon<< endl;
   cout << "Day: "<< ltm->tm_mday << endl;
   cout << "Time: "<< 5+ltm->tm_hour << ":";
   cout << 30+ltm->tm_min << ":";
   cout << ltm->tm_sec << endl;
}*/
/* C++ Date and Time - Example Program of C++ Date and Time
 * This program prints today's date on the output screen */

/*#include<iostream>
#include<conio.h>
#include<ctime>
using namespace std;
int main()
{

   time_t now = time(0);
   tm *ltm = localtime(&now);
   cout<<"Today : ";
   cout<<ltm->tm_mday<<"."<<1+ltm->tm_mon<<".";
   cout<<1900+ltm->tm_year<<"\n";

   getch();
}*/
/* C++ Date and Time - Example of C++ Date and Time
 * This program prints current date on the output
 * output screen in C++ */

#include<iostream>
#include<conio.h>
#include<ctime>
using namespace std;
int  main()
{

   time_t now = time(0);
   tm *ltm = localtime(&now);
   cout<<"time is ";
   cout<<ltm->tm_hour<<":";
   cout<<ltm->tm_min<<":";
   cout<<ltm->tm_sec<<"\n";

   getch();
}
/* C++ Date and Time - Example of C++ Date and Time
 * This program demonstrates the working of date
 * and time in C++ program */

/*#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;
int main()
{
   int choice, ans;

   time_t now = time(0);
   tm *ltm = localtime(&now);

   do
   {
      cout<<"1. Time\n";
      cout<<"2. Date\n";
      cout<<"3. Month\n";
      cout<<"4. Year\n";
      cout<<"5. All\n";
      cout<<"6. Exit\n";
      cout<<"\nEnter your choice (1-6) ";
      cin>>choice;
      switch(choice)
      {
         case 1:
             cout<<"The current time is ";
             cout<<ltm->tm_hour<<":";
             cout<<ltm->tm_min<<":";
             cout<<ltm->tm_sec<<"\n";
             break;
         case 2:
            cout<<"Today's date is ";
            cout<<ltm->tm_mday<<"\n";
            break;
         case 3:
            cout<<"It's ";
            cout<<1+ltm->tm_mon<<"th month\n";
            break;
         case 4:
            cout<<"This is ";
            cout<<1900+ltm->tm_year<<"\n";
            break;
         case 5:
            cout<<"Time: "<<1+ltm->tm_hour<<":";
            cout<<1+ltm->tm_min<<":";
            cout<<1+ltm->tm_sec<<"\n";
            cout<<"Date: "<<ltm->tm_mday<<"\n";
            cout<<"Month: "<<1+ltm->tm_mon<<"\n";
            cout<<"Year: "<<1900+ltm->tm_year<<"\n";
            break;
         case 6:
            exit(1);
         default:
            cout<<"Wrong choice..!!..Press a key to exit..\n";
            getch();
            exit(2);
      }
      cout<<"\nWant to check more ? (y/n).. ";
      cin>>ans;
      cout<<"\n";
   }while(ans=='y' || ans=='Y');

   getch();
}*/
/*#include <stdio.h>
#include <time.h>

int main()
{
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}*/
/*#include <stdio.h>
#include "antHeaderPlusPlus.h"
struct Borrow{
	int r_id;
	char name[20];
	int b_id;
	int qty;
	char date[12];
	char status[15];
};
Borrow BR;
void Header2()
	{
		drawBoxSingleLine(10,3,80,1,10);
		gotoxy(11,4); foreColor(3);
		printf("%3s%20s%8s%15s%15s%15s\n","R_ID","Name","B_ID","Quantity","Date","Statue");
	}
	void GetDataReader2()
	{
		printf("\n\t    %3d%20s%8s%15s%15s%15s\n",BR.r_id,BR.name,BR.b_id,BR.qty,BR.date,BR.status);
		//line2();
	}
	void line3()
	{
		printf("\t ");
		for(int i=1; i<83; i++)
		{
			printf("-");
		}
	}
int main()
{
	Header2();
	GetDataReader2();
	line3();
}*/
/*
#include <stdio.h>
#include <string.h>
#include "antHeaderPlusPlus.h"
#include "Grapic_RUPP.h"
struct Reader{
	int id;
	char rnane[15];
	char sex[7];
	char address[19];
	char phone[18];
	char date[12];
	char username[8];
	char password[8];
};
	char username1[8];
	char password1[8];
Reader Rd;
FILE *fp1, *temp1;
void Header2();
void GetDataReader2();
int main()
{
	Header2();
	GetDataReader2();
	
}*/
	/*char Gk;
	do{
		cls();
	printf("\n\t\t\t\tReader");
	printf("\n\t\t\t\t [1].Login\n ");
	printf("\n\t\t\t\t [2].Register\n");
	printf("\n\t\t\t\t [3].Back\n");
	printf("\n\t\t\t\t select option[1-3]  : ");
	Gk=getch(); cls();
	switch(Gk)
	{

		case '1':
		{
			cls();
			printf("\n\t\t\t\t login");
			printf("\n\t\t\t Enter Username : "); gets(username1);
			printf("\n\t\t\t Enter Password : "); gets(password1);
			
			if(!strcmp(Rd.username,username1)&&!strcmp(Rd.password,password1))
			{
				printf("OK"); getch();
			}
			if(strcmp(username1,Rd.username)!=0 && strcmp(password1,Rd.password)!=0)
			{
				printf("Error username password"); getch();
			}
		}
		break;
		case '2':
		{
			cls();
		}break;
		
	}
}while(Gk!='3');
//getch();
	return 0;
}*/
/*
	void Input2()
	{
		printf("\n\t\t\t + Input R_ID       : "); scanf("%d",&Rd.id); 	fflush(stdin);
		printf("\n\t\t\t + Input Username   : "); gets(Rd.username);
		printf("\n\t\t\t + Input Password   : "); gets(Rd.password);
		printf("\n\t\t\t + Input R_Name     : "); gets(Rd.rnane); 		fflush(stdin);
		printf("\n\t\t\t + Input R_Sex      : "); scanf("%s",&Rd.sex); 	fflush(stdin);
		printf("\n\t\t\t + Input R_Address  : "); gets(Rd.address); 		fflush(stdin);
		printf("\n\t\t\t + Input R_Telegram : "); gets(Rd.phone); 		fflush(stdin);	
	}
	void Header2()
	{
		drawBoxSingleLine(4,3,102,1,10);
		gotoxy(5,4); foreColor(3);
		printf("%3s%10s%10s%17s%8s%20s%18s%13s\n","R_ID","USERNAME","PASSWORD","R_Name","R_Sex","R_Address","R_Telegram","Date");
	}
	void GetDataReader2()
	{
		printf("\n      %3d%10s%10s%17s%8s%20s%18s%13s\n",Rd.id,Rd.username,Rd.password,Rd.rnane,Rd.sex,Rd.address,Rd.phone,Rd.date);
		//line2();
	}
	void InputReaderInformation()
	{
		char Date[12];
		time_t t= time(NULL);
		struct tm tm = *localtime(&t);
		sprintf(Date,"%02d/%02d/%d", tm.tm_mday,tm.tm_mon+1,tm.tm_year+1900);
		strcpy(Rd.date,Date);
		
		fp1=fopen("ReaderInformation.bin","ab");
			Input2();
			fwrite(&Rd,sizeof(Reader),1,fp1);
			fclose(fp1);			
	}*/