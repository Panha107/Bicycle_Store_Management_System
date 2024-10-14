/*#include<iostream>
#include"antheaderPlusPlus.h"
#include "antheaderInput.h"
using namespace std;
int main()
{
	//drawRec(int x=10,int y=9,int w=10,int h=10,string s="Mello");
	//drawline(int x, int y, int w, int h, int a,int b);
	//drawline(29,5 ,31, 10,(3,3),0,9);
	//drawline(25,7 ,0, 0,0,0,9);
	//DrawRectangle(int x, int y, int w, int h, int c = 7);
	//DrawRectangle(32,6,25,1,(9,2,6));
	//DrawRectangle(32,9,25,1,(9,2,6));
	//DrawRectangle(25,7,((20),(10)),10,(9,2,6));
	//DrawRectangle(31,6,30,5,(9,2,6));
	//gotoxy(34,10);
	//cout<<"Enter : ";
	//drawRec(int x,int y,int w,int h,string s)
	//drawRec(1,1,25,1);
	//clrXY(int x, int y,int count)
	//clrXY(1, 1,2);
	//clrXY(2, 1,2);
	//drawBoxSingleLineWithBG(int x, int y, int w, int h, int color)
	drawBoxSingleLineWithBG(30, 10 , 35, 2, 4);
	//drawBoxSingleLine(int x, int y, int w, int h, int color = 7)
	//clrXY(1,0,2);
	drawBoxSingleLine(1, 0, 10, 1, 9);
	//drawBoxDoubleLineWithBG(int x, int y, int w, int h, int color)
	//drawBoxDoubleLineWithBG(1, 2,20,3,10);
	//HLine(int x, int y, int w, int color = 7, int line = 196)
	//HLine(1, 2, 30,  7, 196);
	//VLine(int x, int y, int h, int color = 7, int line = 179)
	//VLine(1, 2,9,7, 179);
	char* name;
	char* number;
	//cout << "Input letter : ";inputLetter(name);
	cout << "Input Number : ";inputNumber(number);
	//clearBox(int x, int y, int w, int h, int color = 7)
	clearBox(1,1,2,0, 1);
	getch(); return 0;
}*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include "antheaderPlusPlus.h"

using namespace std;
int y=7;

class BicycleInfor{
	public:
		int code;
		char model[20];
		char from[15];
		char color[15];
		char size[10];
		int qty;
		double price;

	public:
		void Input()
		{
			DrawRectangle(14,2,82,30,15);
			HLine(14,6,82,15, 205);
			foreColor(125);
			gotoxy(44,4);
			cout <<"ADD BICYCLES INFORMATION";  
			foreColor(9);
			gotoxy(30,8);   cout <<"Code         : "; 
			gotoxy(30,11);  cout <<"Model        : "; 
			gotoxy(30,14);  cout <<"From         : ";
			gotoxy(30,17);	cout <<"Color        : ";
			gotoxy(30,20);	cout <<"Bike_size    : ";
			gotoxy(30,23);	cout <<"Quantity     : ";
			gotoxy(30,26);	cout <<"Price($)     : ";
			drawBoxSingleLine(50,7,25,1,2);		
			drawBoxSingleLine(50,10,25,1,2);
			drawBoxSingleLine(50,13,25,1,2);
			drawBoxSingleLine(50,16,25,1,2);
			drawBoxSingleLine(50,19,25,1,2);
			drawBoxSingleLine(50,22,25,1,2);
			drawBoxSingleLine(50,25,25,1,2);
			gotoxy(62,8);	cin>>code;         fflush(stdin); cin.clear();
			gotoxy(53,11);	cin.getline(model,20); fflush(stdin);
			gotoxy(53,14);	cin.getline(from,20); fflush(stdin);
			gotoxy(53,17);	cin.getline(color,20); fflush(stdin);
			gotoxy(53,20);	cin.getline(size,10);  fflush(stdin);
			gotoxy(53,23);	cin>>qty;              fflush(stdin); cin.clear();
			gotoxy(53,26);	cin>>price;            fflush(stdin); cin.clear();
		}
	public:
		void upDateRecord()
		{
			
			DrawRectangle(14,2,82,30,15);
			HLine(14,6,82,15, 205);
			foreColor(125);
			gotoxy(44,4);
			cout <<"UPDATE BICYCLES INFORMATION";  
			foreColor(9);
			gotoxy(30,8);   cout <<"Code         : "; 
			gotoxy(30,11);  cout <<"Model        : "; 
			gotoxy(30,14);  cout <<"From         : ";
			gotoxy(30,17);	cout <<"Color        : ";
			gotoxy(30,20);	cout <<"Bike_size    : ";
			gotoxy(30,23);	cout <<"Quantity     : ";
			gotoxy(30,26);	cout <<"Price($)     : ";
			drawBoxSingleLine(50,7,25,1,2);		
			drawBoxSingleLine(50,10,25,1,2);
			drawBoxSingleLine(50,13,25,1,2);
			drawBoxSingleLine(50,16,25,1,2);
			drawBoxSingleLine(50,19,25,1,2);
			drawBoxSingleLine(50,22,25,1,2);
			drawBoxSingleLine(50,25,25,1,2);
			gotoxy(62,8);	cout<<code;          
			gotoxy(53,11);	cin.getline(model,20); fflush(stdin);
			gotoxy(53,14);	cin.getline(from,20); fflush(stdin);
			gotoxy(53,17);	cin.getline(color,20); fflush(stdin);
			gotoxy(53,20);	cin.getline(size,10);  fflush(stdin);
			gotoxy(53,23);	cin>>qty;              fflush(stdin); cin.clear();
			gotoxy(53,26);	cin>>price;            fflush(stdin); cin.clear();//cout<<"$";
		}
	public:
		static void Header()
		{
			
			DrawRectangle(9,3,96,2,15);
			HLine(8,5,98,3, 205);
			HLine(8,7,98,3, 205);
			VLine(17,5,1,122, 179);
			VLine(40,5,1,122, 179);
			VLine(58,5,1,122, 179);
			VLine(74,5,1,122, 179);
			VLine(86,5,1,122, 179);
			VLine(97,5,1,122, 179);
		
			gotoxy(44,4);	cout <<"INFORMATION OF BICYCLE"<<endl;
			
				foreColor(79);
				gotoxy(8,6);	cout <<"  CODE  ";
				gotoxy(17,6);	cout <<"        MODEL         ";
				gotoxy(40,6);	cout <<"     FROM        ";
				gotoxy(58,6);	cout <<"     COLOR     ";
				gotoxy(74,6);	cout <<" BIKE_SIZE ";
				gotoxy(86,6);	cout <<" QUANTITY ";
				gotoxy(97,6);	cout <<"  PRICE  ";
				cout<<endl;
			
		}
	public:
		void GetDataOneRecord()
		{
			cout << fixed << setprecision(2);
			foreColor(10);
			{	
				gotoxy(12,y);	cout <<code;
				gotoxy(20,y);	cout <<model; 
				gotoxy(39,y);	cout <<from;
				gotoxy(54,y);	cout <<color;
				gotoxy(69,y);	cout <<size;
				gotoxy(82,y);	cout <<qty;
				gotoxy(91,y);	cout <<price;
			}
			
		}
		//public:	    
			static void Aheader()
			{
				gotoxy(12,5);
				cout <<left<<setw(10)<<"Code"<<setw(15)<<"Model"<<setw(15)<<"From"<<setw(10)<<"Color"<<setw(10)<<"Size"<<setw(10)<<"Qty"<<setw(10)<<"Price"<<endl<<endl;
			}
			void line3()
			{
				cout<<"\n\t";
				for(int i=1; i<99; i++)
				{
					foreColor(10);
					cout<<char(196);
				}
			}
			void Display()
			{
				foreColor(7);
				cout <<"\n\t   "<<left<<setw(7)<<code<<setw(20)<<model<<"   "<<setw(18)<<from<<setw(17)<<color<<setw(12)<<size<<setw(10)<<qty<<setw(8)<<price;
				line3();
			}
};
BicycleInfor bk;
fstream File1;
void Insert()
{
	File1.open("ProductManagementList.bin", ios::out | ios::app | ios::binary);
	bk.Input();
	File1.write((char*)&bk, sizeof(bk));
	File1.close();	
}
void ViewsAll()
{
	File1.open("ProductManagementList.bin", ios::in | ios::binary);
    // % not found file %
    if(File1.fail()) cout << "File was not found!!!\2\2\2" << endl;
    // % found file %
    if(File1.good())
    {
    	// -> Header
		BicycleInfor::Header();
	//	BicycleInfor::Aheader();
		//h+=2;
		    // $ first read 
			File1.read((char*)&bk, sizeof(bk));
			// condition
			while(File1.eof() != true)
			{
				// -> get data
				//BicycleInfor::Header();
				//DrawRectangle(10,2,90,6,15);
				//gotoxy(12,7);
				
				//	bk. GetDataOneRecord();
					bk.Display();
					//h++;
					//y++;
				// $ next read 
			    File1.read((char*)&bk, sizeof(bk));
			}
		// -> Footer		
	//	ProductManagement::Footer();
	}
	
	File1.close();	
}
void DeleteAll()
{
	remove("ProductManagementList.bin");// should condiiton yes No
	
	cout << "\nAll Records have been deleted." << endl;
}

int main()
{
	//	cls();
	//system("color 9F");
	//cout<<setw(20)<<"Hello world";
	do{
		cls();
		//system("color 9F");
		ViewsAll(); 
		cout<<"\n\n\n\t\t\tEnter";
	}while(getch()==13);
	//	bk.upDateRecord();//::upDateRecord();
//	DeleteAll();

	getch(); return 0;
}