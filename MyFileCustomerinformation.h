
#include <iostream>
#include <fstream>
#include <iomanip>
#include "antheaderPlusPlus.h"
#include "antheaderInput.h"
#include "Time.h"
class Customer{
	public:
		int idcus;
		char name[15];
		char username[20];
		char password[10];
		char address[20];
		char gender[10];
		char telegram[20];
	public:
		void InputResister()
		{
			DrawRectangle(14,2,82,25,15);
			HLine(14,6,82,15, 205);
			foreColor(125);
			gotoxy(46,4);	cout <<"CUSTOMER REGISTER";
			foreColor(9);
			gotoxy(30,8);	cout << "Full Name:";
			gotoxy(30,11);	cout << "Username :";
			gotoxy(30,14);	cout << "Password :";
			gotoxy(30,17);	cout << "Gender   :";
			gotoxy(30,20);	cout << "Address  :";
			gotoxy(30,23);	cout << "Telegram :";
			drawBoxSingleLine(50,7,25,1,11);		
			drawBoxSingleLine(50,10,25,1,11);
			drawBoxSingleLine(50,13,25,1,11);
			drawBoxSingleLine(50,16,25,1,11);
			drawBoxSingleLine(50,19,25,1,11);
			drawBoxSingleLine(50,22,25,1,11);
			foreColor(5);
			gotoxy(53,8);	cin.getline(name,20);		fflush(stdin);
			gotoxy(53,11);	cin.getline(username,20);	fflush(stdin);
			gotoxy(53,14);	hidePassword(password);		fflush(stdin);
			gotoxy(53,17);	cin.getline(gender,10);		fflush(stdin);
			gotoxy(53,20);	cin.getline(address,20);	fflush(stdin);
			gotoxy(53,23);	cin.getline(telegram,20);	fflush(stdin);
		}
		void UpdateResister()	
		{
			DrawRectangle(14,2,82,25,15);
			HLine(14,6,82,15, 205);
			foreColor(244);
			gotoxy(46,4);	cout <<"MODIFY CUSTOMER";
			foreColor(9);
			gotoxy(30,8);	cout << "Full Name:";
			gotoxy(30,11);	cout << "Username :";
			gotoxy(30,14);	cout << "Password :";
			gotoxy(30,17);	cout << "Gender   :";
			gotoxy(30,20);	cout << "Address  :";
			gotoxy(30,23);	cout << "Telegram :";
			drawBoxSingleLine(50,7,25,1,11);		
			drawBoxSingleLine(50,10,25,1,11);
			drawBoxSingleLine(50,13,25,1,11);
			drawBoxSingleLine(50,16,25,1,11);
			drawBoxSingleLine(50,19,25,1,11);
			drawBoxSingleLine(50,22,25,1,11);
			foreColor(5);
			gotoxy(53,8);	cin.getline(name,15);		fflush(stdin);
			gotoxy(53,11);	cin.getline(username,20);	fflush(stdin);
			gotoxy(53,14);	hidePassword(password);		fflush(stdin);
			gotoxy(53,17);	cin.getline(gender,10);		fflush(stdin);
			gotoxy(53,20);	cin.getline(address,20);	fflush(stdin);
			gotoxy(53,23);	cin.getline(telegram,20);	fflush(stdin);
		}
	public:
		static void Header()
		{
			
			DrawRectangle(40,0,35,1,1);
			HLine(5,4,105,92, 80900);
			HLine(5,6,105,92, 80900);
			VLine(12,4,1,236, 179);
			VLine(30,4,1,236, 179);
			VLine(49,4,1,236, 179);
			VLine(62,4,1,236, 179);
			VLine(73,4,1,236, 179);
			VLine(93,4,1,236, 179);
			gotoxy(48,1);	foreColor(7);	cout <<"CUSTOMER INFORMATION";
			foreColor(175);
			gotoxy(5,5);	cout << " Num  ";
			gotoxy(12,5);	cout << "    Full_Name    ";
			gotoxy(30,5);	cout << "     Username     ";
			gotoxy(49,5);	cout << "  Password  ";
			gotoxy(62,5);	cout << "  Gender  ";
			gotoxy(73,5);	cout << "      Address      ";
			gotoxy(93,5);	cout << "     Telegram    ";
			cout<<endl;
		}
		void Display()
		{
			foreColor(7);
			cout <<"\n      "<<left<<setw(6)<<idcus<<" "<<setw(15)<<name<<"   "<<setw(16)<<username<<"   "<<setw(10)<<password<<"   "<<setw(10)<<gender<<" "<<setw(20)<<address<<" "<<setw(18)<<telegram;
		}
		static void footerline()
		{
			cout<<"\n     ";
			for(int i=1; i<106; i++)
			{
				foreColor(2);
				cout<<char(196);
			}
		}
		void Login();
		void Register();
		int IDAuto();
		void Insert();
		void ViewsAll();
		void Search();
		void Delete();
		void Update();
};
Customer ctm;
fstream File3;
////////////////////////////////////////////////////////////////////////////////////////////
int Customer::IDAuto()
{
	ifstream ReadID;
	int cid;
	ReadID.open("CustomerManagementList.bin",ios::in| ios::binary);
	if(ReadID.fail())
	{
		cid = 0;
	}
	if(ReadID.good())
	{
		ReadID.read((char*)&ctm , sizeof(ctm));
		while(ReadID.eof()!= true)
		{

			cid = ctm.idcus;
			ReadID.read((char*)&ctm, sizeof(ctm));
			
		}
	}
	ReadID.close();
	return cid;
}
void Customer::Login()
{
	
}
void Customer::Register()
{
	
}
void Customer::Insert()
{
	File3.open("CustomerManagementList.bin", ios::out | ios::app | ios::binary);
	//ctm.idcus = ctm.IDAuto();
	ctm.InputResister();
	File3.write((char*)&ctm, sizeof(ctm));
	File3.close();	
}
void Customer::ViewsAll()
{
	File3.open("CustomerManagementList.bin", ios::in | ios::binary);
    // % not found file %
    if(File3.fail()) { gotoxy(30,15); foreColor(4);	cout << "File was not found!!!\2\2\2";}
    // % found file %
    if(File3.good())
    {
    
		Customer::Header();

		    // $ first read 
			File3.read((char*)&ctm, sizeof(ctm));
			// condition
			while(File3.eof() != true)
			{
					ctm.Display();
					ctm.idcus = ctm.IDAuto();
					idcus+=1;
					// $ next read 
			    File3.read((char*)&ctm, sizeof(ctm));
			}
			Customer::footerline();
			foreColor(2);
			cout<<"\n\n\t<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<Press Any Key to back [Menu]>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;;
	}
	
	File3.close();		
}
void Customer::Search()
{
	File3.open("CustomerManagementList.bin", ios::in | ios::binary);
    if(File3.fail()) { gotoxy(30,15); foreColor(4);	cout << "File was not found.";}
    if(File3.good())
    {
    	int searchID;
    	bool isFound = false;
    	DrawRectangle(14,2,82,28,15);
    	HLine(14,6,82,15, 205);
    	gotoxy(40,4);
    	cout <<"SEARCH CUSTOMER INFORMATION";
    	Current();
    	drawBoxSingleLine(32,16,40,1,7);
    	gotoxy(39,17);
    	cout << "Input ID to search : "; cin>>searchID; fflush(stdin); cin.clear();
    	/*                         End Input                            */
		    // $ first read 
			File3.read((char*)&ctm, sizeof(ctm));
			// condition
			while(File3.eof() != true)
			{
								    
			    if(searchID == ctm.idcus)
			    {
			    	cls();
			    	// -> Header
					Customer::Header();
				    	// -> get data
						ctm.Display();
					
					Customer::footerline();
					isFound = true;
				}
						
				// $ next read 
			    File3.read((char*)&ctm, sizeof(ctm));
			}
			// Message searching no found
			if(isFound == false) 
			{
				foreColor(12);
				gotoxy(38,20);	cout << "ID you enter was not found." <<endl;
			}
		
	}// end if good
	
	File3.close();	
}
void Customer::Delete()
{
	ofstream backup;
	File3.open("CustomerManagementList.bin", ios::in | ios::binary);
	backup.open("BackupFile.bin", ios::out | ios::binary);
	
    if(File3.fail())  {gotoxy(30,15); foreColor(4);	cout << "File was not found!!!\2\2\2";}
    // % found file %
    if(File3.good())
    {
    	int deleteID;
    	bool isFound = false;
    	DrawRectangle(14,2,82,28,15);
    	HLine(14,6,82,15, 205);
    	gotoxy(40,4);
    	cout <<"DELETE CUSTOMER INFORMATION";
    	Current();
    	drawBoxSingleLine(32,16,40,1,7);
    	gotoxy(39,17);
    	cout << "Input ID to delete : "; cin>>deleteID; fflush(stdin); cin.clear();
    	
    	/*                         End Input                            */
		    // $ first read 
			File3.read((char*)&ctm, sizeof(ctm));
			// condition
			while(File3.eof() != true)
			{	
			    // @                          Condition Delete             @
			    
			    if(deleteID == ctm.idcus)
			    {
					// remove outside of loop
					isFound = true;
				}
				if(deleteID != ctm.idcus)
				{
					// backup data
					backup.write((char*)&ctm, sizeof(ctm));
				}
						
				// $ next read 
			    File3.read((char*)&ctm, sizeof(ctm));
			}
			// Message Update not found
			if(isFound == false) {gotoxy(38,20);	foreColor(12);	cout << "ID you enter was not found.";}
			if(isFound == true)  {gotoxy(38,20);	foreColor(12);	cout << "Deleted successfully.";}
		     
	}// end if good
	// Remove & Rename file
	File3.close();
	backup.close();
	remove("CustomerManagementList.bin");
	rename("BackupFile.bin", "CustomerManagementList.bin");	
}
void Customer::Update()
{
	File3.open("CustomerManagementList.bin", ios::out | ios::in | ios::binary);

    // % not found file %
    if(File3.fail())  {gotoxy(30,15); foreColor(4);	cout << "File was not found.";}
    // % found file %
    if(File3.good())
    {
    	/*                         Start Input                            */
   		int updateID;
    	bool isFound = false;
    	DrawRectangle(14,2,82,26,6);
    	HLine(14,6,82,15, 205);
    	gotoxy(40,4); foreColor(7);
    	cout <<"UPDATE CUSTOMER INFORMATION";
    	Current();
    	drawBoxSingleLine(32,16,40,1,7);
    	gotoxy(39,17);
    	cout << "Input ID to update : "; cin>>updateID; fflush(stdin); cin.clear();
			File3.read((char*)&ctm, sizeof(ctm));
			// condition
			while(File3.eof() != true)
			{	
			    // @                          Condition Update             @
			    
			    if(updateID == ctm.idcus)
			    {
			    	cls();
			    	//Current();
			    	// step 1: Update on RAM, New Data
			    	ctm.UpdateResister();
			    	File3.seekp((int)File3.tellg()-sizeof(ctm));
			    	// step 2.2>. write New data on Ram to replace old in file by position update
					File3.write((char*)&ctm, sizeof(ctm));
					
					isFound = true;
				}
						
				// $ next read 
			    File3.read((char*)&ctm, sizeof(ctm));
			}
			// Message Update not found
			if(isFound == false){ 	gotoxy(38,20);	foreColor(12);	cout << "ID you enter was not found.";}
			if(isFound == true)	{	gotoxy(38,25);	foreColor(10);	  cout << "Updated successfully.";}
		     
	}// end if good
	
	File3.close();
}