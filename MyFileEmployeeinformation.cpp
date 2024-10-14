
#include <iostream>
#include <fstream>
#include <iomanip>
#include "antheaderPlusPlus.h"
int Barcodeauto();

class Employee{
	public:
		int id;
		char name[20];
		char gender[10];
		char telegram[20];
		char position[20];
		double salary;
	public:
		void Input()
		{
			int i,n;
			DrawRectangle(14,2,82,25,15);
			HLine(14,6,82,15, 205);
			foreColor(125);
			gotoxy(44,4);	cout <<"ADD STAFF INFORMATION";
			foreColor(9);
			gotoxy(30,8);	cout << "Staff's ID:  ";
			gotoxy(30,11);	cout << "Input Name:";
			gotoxy(30,14);	cout << "Input Sex:";
			gotoxy(30,17);	cout << "Input Telegrem:";
			gotoxy(30,20);	cout << "Input Position:";
			gotoxy(30,23);	cout <<	"Input Salary($): ";
			drawBoxSingleLine(50,7,25,1,2);		
			drawBoxSingleLine(50,10,25,1,2);
			drawBoxSingleLine(50,13,25,1,2);
			drawBoxSingleLine(50,16,25,1,2);
			drawBoxSingleLine(50,19,25,1,2);
			drawBoxSingleLine(50,22,25,1,2);
			gotoxy(61,8);	cout<<(id+=1);				
			gotoxy(53,11);	cin.getline(name,20);		fflush(stdin); 
			gotoxy(53,14);	cin.getline(gender,10);		fflush(stdin);
			gotoxy(53,17);	cin.getline(telegram,20);	fflush(stdin);
			gotoxy(53,20);	cin.getline(position,20);		fflush(stdin);
			gotoxy(53,23);	cin>>salary; 				fflush(stdin); cin.clear();
		}
		void upDateRecord()
		{
			DrawRectangle(14,2,82,25,15);
			HLine(14,6,82,15, 205);
			foreColor(125);
			gotoxy(44,4);	cout <<"UPDATE STAFF INFORMATION";
			foreColor(9);
			gotoxy(30,8);	cout << "Staff's ID:";
			gotoxy(30,11);	cout << "Input New Name:";
			gotoxy(30,14);	cout << "Input New Gender:";
			gotoxy(30,17);	cout << "Input New Telegrem:";
			gotoxy(30,20);	cout << "Input New Position:";
			gotoxy(30,23);	cout <<	"Input New Salary: ";
			drawBoxSingleLine(50,7,25,1,2);		
			drawBoxSingleLine(50,10,25,1,2);
			drawBoxSingleLine(50,13,25,1,2);
			drawBoxSingleLine(50,16,25,1,2);
			drawBoxSingleLine(50,19,25,1,2);
			drawBoxSingleLine(50,22,25,1,2);
			gotoxy(61,8);	cout<<id; 				
			gotoxy(53,11);	cin.getline(name,20);		fflush(stdin); 
			gotoxy(53,14);	cin.getline(gender,10);		fflush(stdin);
			gotoxy(53,17);	cin.getline(telegram,20);	fflush(stdin);
			gotoxy(53,20);	cin.getline(position,20);		fflush(stdin);
			gotoxy(53,23);	cin>>salary; 				fflush(stdin); cin.clear();
		}
		static void Header()
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
		void Dispaly()
		{
			foreColor(6);
			cout << "\n\t    " << left << setw(8) <<id<<setw(22)<< name<<"   "<<setw(9)<< gender<<setw(20)<<telegram<<" "<<setw(15)<< position<<"  $ "<<setw(10)<< salary;
		}
	public:
		static void footerline()
		{
			cout<<"\n\t  ";
				for(int i=1; i<94; i++)
				{
					foreColor(10);
					cout<<char(196);
				}
		}
};
Employee Staff;
fstream File2, File2h;
int Barcodeauto()
{
	ifstream readBarCode;
	int code;
	readBarCode.open("EmployeeIforManagementList.bin",ios::in| ios::binary);
	if(File2.fail())
	{
		code = 0;
	}
	if(readBarCode.good())
	{
		readBarCode.read((char*)&Staff , sizeof(Staff));
		while(readBarCode.eof()!= true)
		{

			code = Staff.id;
			readBarCode.read((char*)&Staff, sizeof(Staff));
			
		}
	}
	readBarCode.close();
	return code;
}
void Insert()
{
	File2h.open("EmployeeIforManagementList2.bin",ios::out | ios::app | ios::binary);
	File2.open("EmployeeIforManagementList.bin", ios::out | ios::app | ios::binary);
	Staff.id = Barcodeauto();
	Staff.Input();
	File2.write((char*)&Staff, sizeof(Staff));
	File2h.write((char*)&Staff, sizeof(Staff));
	File2.close();
	File2h.close();	
}
/*void InsertWithValidate()
{
	bool isFound = false;
	file.open("EmployeeIforManagementList.bin", ios::in | ios::binary);
	
	psValidate.inputWithBarcode();
	
    if(file.good())
    {
	    // $ first read 
		file.read((char*)&ps, sizeof(ps));
		// condition
		while(file.eof() != true)
		{	
		    if(psValidate.barcode ==  ps.barcode )
		    {
		    	cout << "Arealdy";
		    	
		    	isFound = true;
			}
			
			// $ next read 
		    file.read((char*)&ps, sizeof(ps));
		}
	
		file.close();
		
    }// end if good
    
    //-------------------------Create New File,  No Duplicate data--------------------
	// => No Exist in file
	if(isFound ==  false)
	{
		file.open("EmployeeIforManagementList.bin", ios::out | ios::app | ios::binary);
		psValidate.inputWithValide();
		
		file.write((char*)&psValidate, sizeof(psValidate));
		
		file.close();
	}
				
}*/
void viewsEmp()
{
	File2.open("EmployeeIforManagementList.bin", ios::in | ios::binary);
	if(File2.fail()) cout << "\nFile was not found..." << endl;
	// => Found
	if(File2.good())
	{	Employee::Header();
		File2.read((char*)&Staff, sizeof(Staff));
		// condition
		while(File2.eof() != true)
		{
			//b. Data
	        Staff.Dispaly();
			// -> next read
			File2.read((char*)&Staff, sizeof(Staff));
		}
		Employee::footerline();
		
	}// end if good
	File2.close();	
}
void viewsEmp2()
{
	File2h.open("EmployeeIforManagementList2.bin", ios::in | ios::binary);
	if(File2h.fail()) cout << "\nFile was not found..." << endl;
	// => Found
	if(File2h.good())
	{	Employee::Header();
		File2h.read((char*)&Staff, sizeof(Staff));
		// condition
		while(File2h.eof() != true)
		{
			//b. Data
	        Staff.Dispaly();
			// -> next read
			File2h.read((char*)&Staff, sizeof(Staff));
		}
		Employee::footerline();
		
	}// end if good
	File2h.close();	
}
void SearchBycode()
{
	File2.open("EmployeeIforManagementList.bin", ios::in | ios::binary);
    if(File2.fail()) cout << "File was not found." << endl;
    if(File2.good())
    {
    	int searchById;
    	bool isFound = false;
    	
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
					Employee::Header();
	
				    	// -> get data
						Staff.Dispaly();
					Employee::footerline();
					isFound = true;
				}
						
				// $ next read 
			    File2.read((char*)&Staff, sizeof(Staff));
			}
			// Message searching no found
			if(isFound == false) cout << "ID you enter was not found." <<endl;
		
	}// end if good
	
	File2.close();	
}
void DeleteByID()
{
	ofstream backup;
	File2.open("EmployeeIforManagementList.bin", ios::in | ios::binary);
	backup.open("BackupFile.bin", ios::out | ios::binary);
	
    if(File2.fail()) cout << "File was not found!!!\2\2\2" << endl;
    // % found file %
    if(File2.good())
    {
    	int deleteByid;
    	bool isFound = false;
    	
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
			if(isFound == false) cout << "ID you enter was not found" << endl;
			if(isFound == true)  cout << "Deleted successfully.";
		     
	}// end if good
	// Remove & Rename file
	File2.close();
	backup.close();
	remove("EmployeeIforManagementList.bin");
	rename("BackupFile.bin", "EmployeeIforManagementList.bin");	
}
void UpdateStaff()
{
	File2.open("EmployeeIforManagementList.bin", ios::out | ios::in | ios::binary);

    // % not found file %
    if(File2.fail()) cout << "File was not found." << endl;
    // % found file %
    if(File2.good())
    {
    	/*                         Start Input                            */
    	int updateByid;
    	bool isFound = false;
    	
    	cout << "Input CODE to update : "; cin>>updateByid; fflush(stdin); cin.clear();
    	cls();
			File2.read((char*)&Staff, sizeof(Staff));
			// condition
			while(File2.eof() != true)
			{	
			    // @                          Condition Update             @
			    
			    if(updateByid == Staff.id)
			    {
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
			if(isFound == false) cout << "Code you enter was not found." << endl;
			if(isFound == true)  cout << "Updated successfully." << endl;
		     
	}// end if good
	
	File2.close();
}
int main()
{
//	do{
	//	Insert();
	//	printf("hhjh");
	//}while(getch()==13);
	
	//Staff.Input();
	//Employee::Header();
	//Staff.Dispaly();
	press:
	cls();
	viewsEmp();
	getch();
	goto press;
	//viewsEmp2();
	//SearchBycode();
	//DeleteByID();
//	UpdateStaff();
//	Staff.upDateRecord();
//	Employee::Header();
	getch();
	
}