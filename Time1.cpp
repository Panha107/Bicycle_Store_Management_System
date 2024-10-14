#include <stdio.h>
#include <time.h>
#include "antheaderPlusPlus.h"
	
void Date()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	foreColor(79);
	printf("Date : %02d-%02d-%d",tm.tm_mon + 1, tm.tm_mday, tm.tm_year + 1900);
}
void Time()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	foreColor(244);
	printf("Time : %02d:%02d:%02d",tm.tm_hour, tm.tm_min, tm.tm_sec);
}
int main()
{
	gotoxy(19,3);
	{
		Date();
	gotoxy(19,4);
		Time();
	}
	
}