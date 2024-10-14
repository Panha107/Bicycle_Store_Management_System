#ifndef _MYFILEEMPLOYEE_INFORMATION_H
#define _MYFILEEMPLOYEE_INFORMATION_H
//////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <iomanip>
#include "antheaderPlusPlus.h"
#include "antheaderInput.h"

#include "Time.h"

/////////////////////////////////////////////////////////////
class EmployeeInfor
{
	public:
		int id;
		char name[20];
		char gender[10];
		char telegram[20];
		char position[20];
		double salary;
	public:
		void Input();
		void upDateRecord();
		static void Header();
		void Dispaly();
		static void footerline();
	public:
		int IdAuto();
		void Insert();
		void views();
		void SearchByID();
		void DeleteByID();
		void Update();
};
/////////////////>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
EmployeeInfor Staff;
fstream File2;
//<<<<<<<<<<<<<<<<<<<<<<<<<.>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int EmployeeInfor::IdAuto()
{
	ifstream readBarCode;
	int id;
	readBarCode.open("EmployeeIforManagementList.bin",ios::in| ios::binary);
	if(File2.fail())
	{
		id = 0;
	}
	if(readBarCode.good())
	{
		readBarCode.read((char*)&Staff , sizeof(Staff));
		while(readBarCode.eof()!= true)
		{

			id = Staff.id;
			readBarCode.read((char*)&Staff, sizeof(Staff));
			
		}
	}
	readBarCode.close();
	return id;
}
void EmployeeInfor::Insert()
{
	File2.open("EmployeeIforManagementList.bin", ios::out | ios::app | ios::binary);
	Staff.id = IdAuto();
	Staff.Input();
	File2.write((char*)&Staff, sizeof(Staff));
	File2.close();	
}
void EmployeeInfor::views()
{
	File2.open("EmployeeIforManagementList.bin", ios::in | ios::binary);
	if(File2.fail()) {gotoxy(30,15); foreColor(4);	cout << "File was not found...";}
	// => Found
	if(File2.good())
	{
		EmployeeInfor::Header();
		File2.read((char*)&Staff, sizeof(Staff));
		// condition
		while(File2.eof() != true)
		{
			//b. Data
	        Staff.Dispaly();
			// -> next read
			File2.read((char*)&Staff, sizeof(Staff));
		}
		EmployeeInfor::footerline();
		foreColor(2);
			cout<<"\n\n\t  <<<<<<<<<<<<<<<<<<<<<<<<<<\3\3\2\2###Press Any Key to back [Menu]###\2\2\3\3>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;;
		
	}// end if good
	File2.close();	
}
void EmployeeInfor::SearchByID()
{
	File2.open("EmployeeIforManagementList.bin", ios::in | ios::binary);
    if(File2.fail())  {gotoxy(30,15); foreColor(4);	cout << "File was not found.";}
    if(File2.good())
    {
    	int searchById;
    	bool isFound = false;
    	DrawRectangle(14,2,82,28,15);
    	HLine(14,6,82,15, 205);
    	gotoxy(40,4);
    	cout <<"SEARCH STAFF INFORMATION";
    	Current();
    	drawBoxSingleLine(32,16,40,1,7);
    	gotoxy(39,17);
    	cout << "Input ID to search : "; cin>>searchById; fflush(stdin); cin.clear();
    	
    	/*                         End Input                            */
		    // $ first read 
			File2.read((char*)&Staff, sizeof(Staff));
			// condition
			while(File2.eof() != true)
			{				    
			    if(searchById == Staff.id)
			    {
			    	// -> Header
					cls();
					EmployeeInfor::Header();
				    	// -> get data
						Staff.Dispaly();		
					EmployeeInfor::footerline();
					
					isFound = true;
				}
						
				// $ next read 
			    File2.read((char*)&Staff, sizeof(Staff));
			}
			// Message searching no found
			if(isFound == false) 
			{
				gotoxy(38,20);	foreColor(12);	cout << "ID you enter was not found." ;
			}
		
	}// end if good
	
	File2.close();	
}
void EmployeeInfor::DeleteByID()
{
	ofstream backup;
	File2.open("EmployeeIforManagementList.bin", ios::in | ios::binary);
	backup.open("BackupFile.bin", ios::out | ios::binary);
	
    if(File2.fail())  {gotoxy(30,15); foreColor(4);	cout << "File was not found!!!\2\2\2";}
    // % found file %
    if(File2.good())
    {
    	int deleteByid;
    	bool isFound = false;
    	DrawRectangle(14,2,82,28,15);
    	HLine(14,6,82,15, 205);
    	gotoxy(40,4);
    	cout <<"DELETE STAFF INFORMATION";
    	Current();
    	drawBoxSingleLine(32,16,40,1,7);
    	gotoxy(39,17);
    	cout << "Input CODE to delete : "; cin>>deleteByid; fflush(stdin); cin.clear();
    	
    	/*                         End Input                            */
		    // $ first read 
			File2.read((char*)&Staff, sizeof(Staff));
			// condition
			while(File2.eof() != true)
			{	
			    // @                          Condition Delete             @
			    
			    if(deleteByid == Staff.id)
			    {
					// remove outside of loop
					isFound = true;
				}
				if(deleteByid != Staff.id)
				{
					// backup data
					backup.write((char*)&Staff, sizeof(Staff));
				}
						
				// $ next read 
			    File2.read((char*)&Staff, sizeof(Staff));
			}
			// Message Update not found
			if(isFound == false) {gotoxy(38,20);	foreColor(12);	cout << "ID you enter was not found.";}
			if(isFound == true)  {gotoxy(38,20);	foreColor(12);	cout << "Deleted successfully.";}
		     
	}// end if good
	// Remove & Rename file
	File2.close();
	backup.close();
	remove("EmployeeIforManagementList.bin");
	rename("BackupFile.bin", "EmployeeIforManagementList.bin");	
}
void EmployeeInfor::Update()
{
	File2.open("EmployeeIforManagementList.bin", ios::out | ios::in | ios::binary);

    // % not found file %
    if(File2.fail())  {gotoxy(30,15); foreColor(4);	cout << "File was not found.";}
    // % found file %
    if(File2.good())
    {
    	/*                         Start Input                            */
   		int updateByid;
    	bool isFound = false;
    	DrawRectangle(14,2,82,26,6);
    	HLine(14,6,82,15, 205);
    	gotoxy(40,4); foreColor(7);
    	cout <<"UPDATE STAFF INFORMATION";
    	Current();
    	drawBoxSingleLine(32,16,40,1,7);
    	gotoxy(39,17);
    	cout << "Input CODE to update : "; cin>>updateByid; fflush(stdin); cin.clear();
			File2.read((char*)&Staff, sizeof(Staff));
			// condition
			while(File2.eof() != true)
			{	
			    // @                          Condition Update             @
			    
			    if(updateByid == Staff.id)
			    {
			    	cls();
			    	Current();
			    	// step 1: Update on RAM, New Data
			    	Staff.upDateRecord();
			    	File2.seekp((int)File2.tellg()-sizeof(Staff));
			    	// step 2.2>. write New data on Ram to replace old in file by position update
					File2.write((char*)&Staff, sizeof(Staff));
					
					isFound = true;
				}
						
				// $ next read 
			    File2.read((char*)&Staff, sizeof(Staff));
			}
			// Message Update not found
			if(isFound == false){ 	gotoxy(38,20);	foreColor(12);	cout << "Code you enter was not found.";}
			if(isFound == true)	{	gotoxy(38,25);	foreColor(10);	  cout << "Updated successfully.";}
		     
	}// end if good
	
	File2.close();
}
////////////////////////////////////////class infor////////////////////////////

		void EmployeeInfor::Input()
		{
			DrawRectangle(14,2,82,25,15);
			HLine(14,6,82,15, 205);
			foreColor(125);
			gotoxy(44,4);	cout <<"ADD STAFF INFORMATION";
			foreColor(9);
			gotoxy(30,8);	cout << "Staff's ID:";
			gotoxy(30,11);	cout << "Input Name:";
			gotoxy(30,14);	cout << "Input Sex:";
			gotoxy(30,17);	cout << "Input Telegrem:";
			gotoxy(30,20);	cout << "Input Position:";
			gotoxy(30,23);	cout <<	"Input Salary: ";
			drawBoxSingleLine(50,7,25,1,2);		
			drawBoxSingleLine(50,10,25,1,2);
			drawBoxSingleLine(50,13,25,1,2);
			drawBoxSingleLine(50,16,25,1,2);
			drawBoxSingleLine(50,19,25,1,2);
			drawBoxSingleLine(50,22,25,1,2);
			gotoxy(61,8);	cout<<(id+=101); 					
			gotoxy(53,11);	inputLetter(name);			fflush(stdin); 
			gotoxy(53,14);	inputLetter(gender);		fflush(stdin);
			gotoxy(53,17);	cin.getline(telegram,20);	fflush(stdin);
			gotoxy(53,20);	inputLetter(position);		fflush(stdin);
			gotoxy(53,23);	cin>>salary; 				fflush(stdin); cin.clear();
		}
		void EmployeeInfor::upDateRecord()
		{
			DrawRectangle(14,2,82,27,15);
			HLine(14,6,82,15, 205);
			foreColor(125);
			gotoxy(44,4);	cout <<"UPDATE STAFF INFORMATION";
			foreColor(9);
			gotoxy(30,8);	cout << "Staff's ID:";
			gotoxy(30,11);	cout << "Input New Name:";
			gotoxy(30,14);	cout << "Input New Sex:";
			gotoxy(30,17);	cout << "Input New Telegrem:";
			gotoxy(30,20);	cout << "Input New Position:";
			gotoxy(30,23);	cout <<	"Input New Salary($): ";
			drawBoxSingleLine(50,7,25,1,2);		
			drawBoxSingleLine(50,10,25,1,2);
			drawBoxSingleLine(50,13,25,1,2);
			drawBoxSingleLine(50,16,25,1,2);
			drawBoxSingleLine(50,19,25,1,2);
			drawBoxSingleLine(50,22,25,1,2);
			gotoxy(61,8);	cout<<id; 					fflush(stdin); cin.clear();
			gotoxy(53,11);	inputLetter(name);			fflush(stdin); 
			gotoxy(53,14);	inputLetter(gender);		fflush(stdin);
			gotoxy(53,17);	cin.getline(telegram,20);		fflush(stdin);
			gotoxy(53,20);	inputLetter(position);		fflush(stdin);
			gotoxy(53,23);	cin>>salary; 				fflush(stdin); cin.clear();
		}
		void EmployeeInfor::Header()
		{
			DrawRectangle(11,2,91,1,15);
			HLine(10,4,93,25, 205);
			HLine(10,6,93,25, 205);
			VLine(19,4,1,244, 179);
			VLine(44,4,1,244, 179);
			VLine(53,4,1,244, 179);
			VLine(74,4,1,244, 179);
			VLine(89,4,1,244, 179);
			gotoxy(44,3);	cout <<"STAFF INFORMATION";
			foreColor(103);
			gotoxy(10,5);	cout << "   ID   ";
			gotoxy(19,5);	cout << "          Name          ";
			gotoxy(44,5);	cout << " Gender ";
			gotoxy(53,5);	cout << "      Telegram      ";
			gotoxy(74,5);	cout << "   Position   ";
			gotoxy(89,5);	cout << "  Salary($)   ";
			cout<<endl;
		}
		void EmployeeInfor::Dispaly()
		{
			foreColor(6);
			cout << "\n\t    " << left << setw(8) <<id<<setw(22)<< name<<"   "<<setw(9)<< gender<<setw(20)<<telegram<<" "<<setw(15)<< position<<"  $ "<<setw(10)<< salary;
		}
		void EmployeeInfor::footerline()
		{
			cout<<"\n\t  ";
				for(int i=1; i<94; i++)
				{
					foreColor(10);
					cout<<char(196);
				}
		}


#endif