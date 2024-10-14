
#include <iostream>
#include "antheaderPlusPlus.h"
using namespace std;

void LoadingShort()
{
	foreColor(3);	
    for(int i=0; i<6; i++)
	{
		cout << (char)220;
		delay(60);
	}
}	
void LoadingLong()
{  
	foreColor(2);
    for(int i=0; i<30; i++)
    {
    	cout << (char)177;
    }
    
		cout << "\r";
		
	for(int i=0;i<30;i++)
	{
    	cout << (char)219;
    	Sleep(60);
    }
    system("cls");
}
int main()
{
	LoadingLong();
	LoadingShort();
	getch(); return 0;	
}