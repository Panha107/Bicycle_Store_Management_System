#include <iostream>
#include <conio.h>
#include "antheaderPlusPlus.h"
#include <fstream>
#include <string.h>
void Login();
void Register();
int main()
{
	Register();
	Login();
//	cout << "INVOICE";
//	cout << "Invoice No. : ";
//	cout << "Date : ";
//	cout << "Name : ";
	getch();	return 0;
}
void Login()
{
	int count;
	char user, pass, u, p;
	cls();
	cout << "username : "; cin>>user;
	cout << "pssword  : "; cin>>pass;
	ifstream input("Data.bin", ios::in | ios::binary);
	while(input>>u>>p)
	{
		if(u==user && p==pass)
		{
			count =1;
			cls();
		}
	}
	input.close();
	if(count ==1)
	{
		cout << "Login Success";
	}
	else
	{
		cout << "Login Error";
	}
}
void Register()
{
	char regu, repass;
	cls();
	cout << "username : "; cin>>regu;
	cout << "password : "; cin>>repass;
	ofstream reg("Data.bin", ios::out | ios::app | ios::binary);
	reg<<regu<<" "<<repass<<endl;
	cls();
	cout <<"Register successful";
	reg.close();
	
}