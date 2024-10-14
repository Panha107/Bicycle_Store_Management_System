#ifndef MENUBIKE_H
#define MENUBIKE_H
#include"antheaderPlusPlus.h"
using namespace std;


void MenuProdUct()
{
	DrawRectangle(14,2,82,25,15);
	HLine(14,6,82,15, 205);
	foreColor(253);
	gotoxy(44,4);
	cout << "INFORMATION OF BICYCLE" << endl;
	drawBoxSingleLine(25,9,25,1,11);
	gotoxy(29,10);
	cout << "[1].INSERT";
	drawBoxSingleLine(60,9,25,1,11);
	gotoxy(64,10);
	cout << "[2].VIEW ALL";
	drawBoxSingleLine(25,13,25,1,11);
	gotoxy(29,14);
	cout << "[3].SEARCH BY BARCODE";
	drawBoxSingleLine(60,13,25,1,11);
	gotoxy(64,14);
	cout << "[4].REMOVE";
	drawBoxSingleLine(25,17,25,1,11);
	gotoxy(29,18);
	cout << "[5].UPDATE";
	drawBoxSingleLine(60,17,25,1,10);
	gotoxy(64,18);
	cout << "[6].BACK";
}
void INforEmployee()
{
	DrawRectangle(14,2,82,25,15);
	HLine(14,6,82,15, 205);
	foreColor(99);
	gotoxy(44,4);
	cout << "INFORMATION OF EMPLOYEE";
	drawBoxSingleLine(25,9,25,1,13);
	gotoxy(29,10);
	cout << "[1].INSERT";
	drawBoxSingleLine(60,9,25,1,13);
	gotoxy(64,10);
	cout << "[2].VIEW ALL";
	drawBoxSingleLine(25,13,25,1,13);
	gotoxy(29,14);
	cout << "[3].SEARCH BY ID";
	drawBoxSingleLine(60,13,25,1,13);
	gotoxy(64,14);
	cout << "[4].REMOVE ";
	drawBoxSingleLine(25,17,25,1,13);
	gotoxy(29,18);
	cout << "[5].UPDATE";
	drawBoxSingleLine(60,17,25,1,10);
	gotoxy(64,18);
	cout << "[6].BACK";
}
void IN_forCustOmer()
{
	DrawRectangle(14,2,82,25,15);
	HLine(14,6,82,15, 205);
	foreColor(99);
	gotoxy(44,4);
	cout << "INFORMATION OF CUSTOMER";
	drawBoxSingleLine(25,9,25,1,12);
	gotoxy(29,10);
	cout << "[1].INSERT";
	drawBoxSingleLine(60,9,25,1,12);
	gotoxy(64,10);
	cout << "[2].VIEW ALL";
	drawBoxSingleLine(25,13,25,1,12);
	gotoxy(29,14);
	cout << "[3].SEARCH BY ID";
	drawBoxSingleLine(60,13,25,1,12);
	gotoxy(64,14);
	cout << "[4].REMOVE";
	drawBoxSingleLine(25,17,25,1,12);
	gotoxy(29,18);
	cout << "[5].UPDATE";
	drawBoxSingleLine(60,17,25,1,10);
	gotoxy(64,18);
	cout << "[6].BACK";
}
#endif