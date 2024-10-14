/*#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main()
{
  int sec_prev=0;
  while(1)
  {
    int seconds, minutes, hours;
    string str;
  
    //storing total seconds
    time_t total_seconds=time(0);
  
    //getting values of seconds, minutes and hours
    struct tm* ct=localtime(&total_seconds);
  
    seconds=ct->tm_sec;
    minutes=ct->tm_min;
    hours=ct->tm_hour;
    
    //converting it into 12 hour format
    if(hours>=12)
      str="PM";
    else
      str="AM";
    hours=hours>12?hours-12:hours;  
    
    
    //printing the result
    if(seconds==sec_prev+1 || (sec_prev==59 && seconds==0))
    {
      system("CLS");
      cout<< (hours<10?"0":"") << hours <<":" << (minutes<10?"0":"") << minutes << ":" << (seconds<10?"0":"") << seconds << " " << str <<endl;
    }
    
    sec_prev=seconds;
  }
  return 0;
}*/
/*#include<stdio.h>
#include<dos.h>
int main()
{
   struct date d;

   getdate(&d);

   printf("Current system date is %d/%d/%d\n",d.da_day,d.da_mon,d.da_year);

   return 0;
}*/
/*#include<stdio.h>
#include<conio.h>
#include<dos.h>
main()
{
   struct date d;

   printf("Enter the new date ( day, month and year ) as integers ");
   scanf("%d%d%d",&d.da_day,&d.da_mon,&d.da_year);

   setdate(&d);

   printf("Current system date is %d/%d/%d\n",d.da_day,d.da_mon,d.da_year);

   getch();
   return 0;
}*/
