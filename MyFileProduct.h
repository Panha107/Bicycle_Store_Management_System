#ifndef _MYFILE_PRODUCT_H
#define _MYFILE_PRODUCT_H
/////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
#include "antheaderPlusPlus.h"
#include "antheaderInput.h"
#include "Time.h"
///.....................................................
using namespace std;

class ProductManagement{
	public:
		int code;
		int qty;
		char model[20];
		char from[15];
		char color[15];
		char size[10];
		double price;

	public:
		void Input();
		static void Header();
		void upDateRecord();
		void GetDataOneRecord();
		static void Line();
	public:
		int CodeAuto();
		void Insert();
		void ViewsAll();
		void SearchBycode();
		void DeleteByCode();
		void Update();
};
//           	#############################################################
ProductManagement bike;
fstream File1;
///////////////   ...................................
int ProductManagement::CodeAuto()
{
	ifstream Readcode;
	int code;
	Readcode.open("ProductManagementList.bin",ios::in| ios::binary);
	if(Readcode.fail())
	{
		code = 0;
	}
	if(Readcode.good())
	{
		Readcode.read((char*)&bike , sizeof(bike));
		while(Readcode.eof()!= true)
		{

			code = bike.code;
			Readcode.read((char*)&bike, sizeof(bike));
			
		}
	}
	Readcode.close();
	return code;
}
void ProductManagement::Insert()
{
	File1.open("ProductManagementList.bin", ios::out | ios::app | ios::binary);
	bike.code = CodeAuto();
	bike.Input();
	File1.write((char*)&bike, sizeof(bike));
	File1.close();	
}
void ProductManagement::ViewsAll()
{
	File1.open("ProductManagementList.bin", ios::in | ios::binary);
    // % not found file %
    if(File1.fail()) { gotoxy(30,15); foreColor(4);	cout << "File was not found!!!\2\2\2";}
    // % found file %
    if(File1.good())
    {
    
		ProductManagement::Header();

		    // $ first read 
			File1.read((char*)&bike, sizeof(bike));
			// condition
			while(File1.eof() != true)
			{
					bike. GetDataOneRecord();
					// $ next read 
			    File1.read((char*)&bike, sizeof(bike));
			}
			foreColor(2);
			cout<<"\n\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Press Any Key to back [Menu]>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;;
	}
	
	File1.close();		
}
void ProductManagement::SearchBycode()
{
	File1.open("ProductManagementList.bin", ios::in | ios::binary);
    if(File1.fail()) { gotoxy(30,15); foreColor(4);	cout << "File was not found.";}
    if(File1.good())
    {
    	int searchBycode;
    	bool isFound = false;
    	DrawRectangle(14,2,82,28,15);
    	HLine(14,6,82,15, 205);
    	gotoxy(40,4);
    	cout <<"SEARCH BICYCLE INFORMATION";
    	Current();
    	drawBoxSingleLine(32,16,40,1,7);
    	gotoxy(39,17);
    	cout << "Input CODE to search : "; cin>>searchBycode; fflush(stdin); cin.clear();
    	/*                         End Input                            */
		    // $ first read 
			File1.read((char*)&bike, sizeof(bike));
			// condition
			while(File1.eof() != true)
			{
								    
			    if(searchBycode == bike.code)
			    {
			    	cls();
			    	// -> Header
					ProductManagement::Header();
				    	// -> get data
						bike.GetDataOneRecord();
					
					isFound = true;
				}
						
				// $ next read 
			    File1.read((char*)&bike, sizeof(bike));
			}
			// Message searching no found
			if(isFound == false) 
			{
				foreColor(12);
				gotoxy(38,20);	cout << "Code you enter was not found." <<endl;
			}
		
	}// end if good
	
	File1.close();	
}
/*void DeleteAll()
{
	remove("ProductManagementList.bin");// should condiiton yes No
	
	cout << "All Records have been deleted." << endl;
}*/
void ProductManagement::DeleteByCode()
{
	ofstream backup;
	File1.open("ProductManagementList.bin", ios::in | ios::binary);
	backup.open("BackupFile.bin", ios::out | ios::binary);
	
    if(File1.fail()){ gotoxy(30,15); foreColor(4);	cout << "File was not found!!!\2\2\2";}
    // % found file %
    if(File1.good())
    {
    	int deleteBycode;
    	bool isFound = false;
    	DrawRectangle(14,2,82,28,15);
    	HLine(14,6,82,15, 205);
    	gotoxy(40,4);
    	cout <<"DELETE BICYCLE INFORMATION";
    	Current();
    	drawBoxSingleLine(32,16,40,1,7);
    	gotoxy(39,17);
    	cout << "Input CODE to delete : "; cin>>deleteBycode; fflush(stdin); cin.clear();
    	
    	/*                         End Input                            */
		    // $ first read 
			File1.read((char*)&bike, sizeof(bike));
			// condition
			while(File1.eof() != true)
			{	
			    // @                          Condition Delete             @
			    
			    if(deleteBycode == bike.code)
			    {
					// remove outside of loop
					isFound = true;
				}
				if(deleteBycode != bike.code)
				{
					// backup data
					backup.write((char*)&bike, sizeof(bike));
				}
						
				// $ next read 
			    File1.read((char*)&bike, sizeof(bike));
			}
			// Message Update not found
			if(isFound == false){	gotoxy(38,20);	foreColor(12);	cout << "Code you enter was not found." << endl;} 
			if(isFound == true){	gotoxy(38,20);	foreColor(10);	cout << "Deleted successfully.";} 
		     
	}// end if good
	// Remove & Rename file
	File1.close();
	backup.close();
	remove("ProductManagementList.bin");
	rename("BackupFile.bin", "ProductManagementList.bin");	
}
void ProductManagement::Update()
{
	File1.open("ProductManagementList.bin", ios::out | ios::in | ios::binary);

    // % not found file %
    if(File1.fail()) { gotoxy(30,15); foreColor(4);	cout << "File was not found.";}
    // % found file %
    if(File1.good())
    {
    	/*                         Start Input                            */
    	int updateBycode;
    	bool isFound = false;
    	DrawRectangle(14,2,82,26,15);
    	HLine(14,6,82,15, 205);
    	gotoxy(40,4);
    	cout <<"UPDATE BICYCLE INFORMATION";
    	Current();
    	drawBoxSingleLine(32,16,40,1,7);
    	gotoxy(39,17);
    	cout << "Input CODE to update : "; cin>>updateBycode; fflush(stdin); cin.clear();
    	
			File1.read((char*)&bike, sizeof(bike));
			// condition
			while(File1.eof() != true)
			{	
			    // @                          Condition Update             @
			    
			    if(updateBycode == bike.code)
			    {
			    	cls();
			    	Current();
			    	// step 1: Update on RAM, New Data
			    	bike.upDateRecord();
			    	File1.seekp((int)File1.tellg()-sizeof(bike));
			    	// step 2.2>. write New data on Ram to replace old in file by position update
					File1.write((char*)&bike, sizeof(bike));
					
					isFound = true;
				}
						
				// $ next read 
			    File1.read((char*)&bike, sizeof(bike));
			}
			// Message Update not found
			gotoxy(38,20);	foreColor(12);	if(isFound == false)	cout << "ID you wanna Update not found.";
			gotoxy(38,28);	foreColor(12);	if(isFound == true)  cout << "Updated successfully." << endl;
		     
	}// end if good
	
	File1.close();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

		void ProductManagement::Input()
		{
			DrawRectangle(14,2,82,28,15);
			HLine(14,6,82,15, 205);
			foreColor(125);
			gotoxy(44,4);
			cout <<"ADD BICYCLES INFORMATION";  
			foreColor(9);
			gotoxy(30,8);   cout <<"CODE         : "; 
			gotoxy(30,11);  cout <<"MODEL        : "; 
			gotoxy(30,14);  cout <<"FROM         : ";
			gotoxy(30,17);	cout <<"COLOR        : ";
			gotoxy(30,20);	cout <<"BIKE_SIZE    : ";
			gotoxy(30,23);	cout <<"QUANTITY     : ";
			gotoxy(30,26);	cout <<"PRICE($)     : ";
			drawBoxSingleLine(50,7,25,1,2);		
			drawBoxSingleLine(50,10,25,1,2);
			drawBoxSingleLine(50,13,25,1,2);
			drawBoxSingleLine(50,16,25,1,2);
			drawBoxSingleLine(50,19,25,1,2);
			drawBoxSingleLine(50,22,25,1,2);
			drawBoxSingleLine(50,25,25,1,2);
			gotoxy(62,8);	cout<<(code+=1);          	
			gotoxy(53,11);	inputLetter(model); 	fflush(stdin);
			gotoxy(53,14);	inputLetter(from); 		fflush(stdin);
			gotoxy(53,17);	inputLetter(color); 	fflush(stdin);
			gotoxy(53,20);	cin.getline(size,10);  	fflush(stdin);
			gotoxy(53,23);	cin>>qty;              	fflush(stdin); cin.clear();
			gotoxy(53,26);	cin>>price;            	fflush(stdin); cin.clear();
		}
		void ProductManagement::Header()
		{
			DrawRectangle(9,3,96,2,15);
			HLine(8,5,98,204, 205);
			HLine(8,7,98,204, 205);
			VLine(17,5,1,122, 179);
			VLine(40,5,1,122, 179);
			VLine(58,5,1,122, 179);
			VLine(74,5,1,122, 179);
			VLine(86,5,1,122, 179);
			VLine(97,5,1,122, 179);
		
			gotoxy(44,4);	cout <<"INFORMATION OF BICYCLE"<<endl;
			
				foreColor(241);
				gotoxy(8,6);	cout <<"  CODE  ";
				gotoxy(17,6);	cout <<"        MODEL         ";
				gotoxy(40,6);	cout <<"     FROM        ";
				gotoxy(58,6);	cout <<"     COLOR     ";
				gotoxy(74,6);	cout <<" BIKE_SIZE ";
				gotoxy(86,6);	cout <<" QUANTITY ";
				gotoxy(97,6);	cout <<"  PRICE  ";
				cout<<endl;
		}
		void ProductManagement::upDateRecord()
		{
			
			DrawRectangle(14,2,82,29,15);
			HLine(14,6,82,15, 205);
			foreColor(125);
			gotoxy(44,4);
			cout <<"UPDATE BICYCLES INFORMATION";  
			foreColor(9);
			gotoxy(30,8);   cout <<"CODE          : "; 
			gotoxy(30,11);  cout <<"New model     : "; 
			gotoxy(30,14);  cout <<"New from      : ";
			gotoxy(30,17);	cout <<"New color     : ";
			gotoxy(30,20);	cout <<"New bike_size : ";
			gotoxy(30,23);	cout <<"New quantity  : ";
			gotoxy(30,26);	cout <<"New price($)  : ";
			drawBoxSingleLine(50,7,25,1,2);		
			drawBoxSingleLine(50,10,25,1,2);
			drawBoxSingleLine(50,13,25,1,2);
			drawBoxSingleLine(50,16,25,1,2);
			drawBoxSingleLine(50,19,25,1,2);
			drawBoxSingleLine(50,22,25,1,2);
			drawBoxSingleLine(50,25,25,1,2);
			gotoxy(62,8);	cout<<code;          
			gotoxy(53,11);	inputLetter(model); fflush(stdin);
			gotoxy(53,14);	inputLetter(from); fflush(stdin);
			gotoxy(53,17);	inputLetter(color); fflush(stdin);
			gotoxy(53,20);	cin.getline(size,10);  fflush(stdin);
			gotoxy(53,23);	cin>>qty;              fflush(stdin); cin.clear();
			gotoxy(53,26);	cin>>price;            fflush(stdin); cin.clear();
		}
		void ProductManagement::GetDataOneRecord()
		{
			foreColor(7);
			cout <<"\n\t   "<<left<<setw(7)<<code<<setw(20)<<model<<"   "<<setw(18)<<from<<setw(17)<<color<<setw(12)<<size<<setw(10)<<qty<<setw(8)<<price;
			Line();
		}	
		void ProductManagement::Line()
		{
			cout<<"\n\t";
			for(int i=1; i<99; i++)
			{
				foreColor(10);
				cout<<char(196);
			}
		}

#endif