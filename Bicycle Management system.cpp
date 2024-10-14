//////                      Main Program
#include <iostream>
#include "antheaderInput.h"
#include "MenuBike.h"
#include "MyFileProduct.h"
#include "Time.h"
#include "MyFileEmployeeinformation.h"
#include "MyFileCustomerinformation.h"
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void Login();
void MainMeNu();
int main()
{
	SetConsoleTitle("BICYCLE MANAGEMENT SYSTEM");
	//Login();
	//cout<<"\n\t size of ProductManagement = "<<sizeof(ProductManagement)<<" byte";
	MainMeNu();
//	getch();
	return 0;
}
void Login()
{
	while(true)
	{
		char username[25];
		char password[25];
		cls();
		DrawRectangle(20,6,60,15,14);
		DrawRectangle(17,7,2,13,14);
		DrawRectangle(35,4,30,1,12);
		gotoxy(38,5);
		cout << "WELCOME TO BICYCLE STORE";
		foreColor(5);
		gotoxy(28,9);	cout << "username  :";
		gotoxy(28,14);	cout << "password  :";
		drawBoxSingleLine(41,8,30,1,9);
		drawBoxSingleLine(41,13,30,1,9);
		HLine(28,10,8,2, 196);
		HLine(28,15,8,2, 196);
		foreColor(7);
		gotoxy(43,9);	cin>>username;  			fflush(stdin);
		gotoxy(43,14);	hidePassword(password);  	fflush(stdin);
		if(!strcmp(username, "Admin") && !strcmp(password, "1234") )
		{
			gotoxy(35,17);
			cout << "LOGIN SUCCEED..."; delay(600);
			cls();
			MainMeNu();
		}
		else if(strcmp(username, "Admin") != 0 && strcmp(password, "1234") != 0)
		{
		/*	gotoxy(34,17);
			cout << "Invalid Username & Password!!";
			gotoxy(43,9);
			cout << "Incorrect Username";
			gotoxy(43,14); 
			cout << "Incorrect Password";*/
		}
		else if(strcmp(username, "Admin") != 0 )
		{
			gotoxy(43,9);
			cout << "Incorrect Username...!";
		}
		else if(strcmp(password, "1234") != 0)
		{
			gotoxy(43,14); 
			cout << "Incorrect Password...!";
		}
		delay(900);
	}
}
void MainMeNu()
{
	int opt,op1;
	do{
		cls();
		Current();
	DrawRectangle(14,2,82,25,15);
	HLine(14,6,82,15, 205);
	foreColor(90); gotoxy(39,4);
	cout << "BICYCLE STORE MANAGEMENT SYSTEM";
	drawBoxSingleLine(40,8,30,1,9);
	gotoxy(47,9);
	cout << "[1].PRODUCT";
	drawBoxSingleLine(40,11,30,1,9);
	gotoxy(47,12);
	cout << "[2].EMPLOYEE";
	drawBoxSingleLine(40,14,30,1,9);
	gotoxy(47,15);
	cout << "[3].CUSTOMER";
	drawBoxSingleLine(40,17,30,1,10);
	gotoxy(47,18);
	cout << "[4].Exit program";
	drawBoxSingleLine(40,23,34,1,9);
	gotoxy(46,24);
	cout <<"Select Option[1-4]: "; cin>>opt; fflush(stdin); cin.clear(); 
	switch(opt)
	{
		case 1:
		{
			int ch;
			char op1;
			do{
			cls();
			gotoxy(1,1);
			Current();
			foreColor(9);
			MenuProdUct();
			drawBoxSingleLine(40,23,30,1,9);
			gotoxy(46,24);
			cout <<"Select Option[1-6]: "; cin>>ch; fflush(stdin); cin.clear(); 
			switch(ch)
			{
				case 1:
				{
					do{
						cls();
						Current();
						bike.Insert();
						drawBoxSingleLine(28,28,20,1,5);
						gotoxy(30,29);cout<<"[ANY KEY] back";
						drawBoxSingleLine(55,28,20,1,5);
						gotoxy(57,29);cout<<"[ENTER] Add more";
					}while(getch()==13);
					
					break;
				}
				case 2:
				{
					cls();
					bike.ViewsAll();
					getch();
					break;
				}
				case 3:
				{
					do{
						cls();
						bike.SearchBycode();
						drawBoxSingleLine(28,28,20,1,5);
						gotoxy(30,29);cout<<"[ANY KEY] back";
						drawBoxSingleLine(55,28,24,1,5);
						gotoxy(57,29);cout<<"[ENTER] Search again";
					}while(getch()==13);
					break;
				}
				case 4:
				{
					do{
						cls();
						bike.DeleteByCode();
						drawBoxSingleLine(28,28,20,1,5);
						gotoxy(30,29);cout<<"[ANY KEY] back";
						drawBoxSingleLine(55,28,24,1,5);
						gotoxy(57,29);cout<<"[ENTER] Delete again";
					}while(getch()==13);
										
					break;
				}
				case 5:
				{
					do{
						cls();
						bike.Update();
						drawBoxSingleLine(28,29,20,1,5);
						gotoxy(30,30);cout<<"[ANY KEY] back";
						drawBoxSingleLine(55,29,24,1,5);
						gotoxy(57,30);cout<<"[ENTER] Update other";
					}while(getch()==13);
					break;
				}
			}
			}while(ch!=6);
		}
		break;
		case 2:
		{
			int sh;
		do
		{
			cls();
			Current();
			INforEmployee();
			drawBoxSingleLine(40,23,30,1,9);
			gotoxy(46,24);
			cout <<"Select Option[1-6]: "; cin>>sh; fflush(stdin); cin.clear(); 
			switch(sh)
			{
				case 1:
				{
					do{
						cls();
						Current();
						Staff.Insert();
						drawBoxSingleLine(28,25,20,1,5);
						gotoxy(30,26);cout<<"[ANY KEY] back";
						drawBoxSingleLine(55,25,20,1,5);
						gotoxy(57,26);cout<<"[ENTER] Add more";
					}while(getch()==13);
					break;
				}
				case 2:
				{
					cls();
					Staff.views();
					getch();
					break;
				}
				case 3:
				{
					do{
						cls();
						Staff.SearchByID();
						drawBoxSingleLine(28,28,20,1,5);
						gotoxy(30,29);cout<<"[ANY KEY] back";
						drawBoxSingleLine(55,28,24,1,5);
						gotoxy(57,29);cout<<"[ENTER] Search again";
					}while(getch()==13);
					break;
				}
				case 4:
				{
					do{
						cls();
						Staff.DeleteByID();drawBoxSingleLine(28,28,20,1,5);
						gotoxy(30,29);cout<<"[ANY KEY] back";
						drawBoxSingleLine(55,28,24,1,5);
						gotoxy(57,29);cout<<"[ENTER] Delete again";
					}while(getch()==13);
					break;
				}
				case 5:
				{
					do{
						cls();
						Staff.Update();
						drawBoxSingleLine(28,27,20,1,5);
						gotoxy(30,28);cout<<"[ANY KEY] back";
						drawBoxSingleLine(55,27,24,1,5);
						gotoxy(57,28);cout<<"[ENTER] Update other";
					}while(getch()==13);
					break;
				}
			}
		}while(sh!=6);
			break;
		}	
		case 3:
		{
			int Gh;
		while(Gh!=6)
		{
			cls();
			Current();
			IN_forCustOmer();
			drawBoxSingleLine(40,23,30,1,9);
			gotoxy(46,24);
			cout <<"Select Option[1-6]: "; cin>>Gh; fflush(stdin); cin.clear(); 
			switch(Gh)
			{
				case 1:
				{
					do{
						cls();
						Current();
						ctm.Insert();
						drawBoxSingleLine(28,25,20,1,5);
						gotoxy(30,26);cout<<"[ANY KEY] back";
						drawBoxSingleLine(55,25,20,1,5);
						gotoxy(57,26);cout<<"[ENTER] Add more";
					}while(getch()==13);
					break;
				}
				case 2:
				{
					cls();
					ctm.ViewsAll();
					getch();
					break;
				}
				case 3:
				{
					do{
						cls();
						ctm.Search();
						drawBoxSingleLine(28,28,20,1,5);
						gotoxy(30,29);cout<<"[ANY KEY] back";
						drawBoxSingleLine(55,28,24,1,5);
						gotoxy(57,29);cout<<"[ENTER] Search again";
					}while(getch()==13);
					break;
				}
				case 4:
				{
					cls();
					ctm.Delete();
					break;
				}
				case 5:
				{
					cls();
					ctm.Update();
					break;
					
				}
			}
		}
			break;
			case 4:
			{
				cls();
				foreColor(244); gotoxy(41,6);
				//for(int l=1 ; l<27; l++)
				{
					cout <<"See You Next Time.......!!! "<<endl;
					delay(300);
				}
				exit(0);
			}	
			
		}
	}
	
 	}while(opt!=4);
}












