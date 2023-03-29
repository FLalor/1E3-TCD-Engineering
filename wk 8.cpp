#include <iostream>
using namespace std;

int month_length (int m, int y);
int year_length (int y);
bool leap_year (int year);
int daynumber (int day, int month, int year);

void dayMthYr (int daynum, int& day, int& month, int& year);

//declare calc_date ...
int calc_date (int daynum, char sign, int amount, char time_frame);


int main ()
{
   int number, day, month, year, d,m,y;
   int choice;

   //testing dayMthYr
   cout << "Enter 1 to test date conversion; enter 2 to calculate a new date:";
   cin >> choice;
   if (choice == 1) {
    cout << "Enter d, m, y: ";
    cin >> d >> m >> y;
    //convert to daynumber
    number = daynumber (d,m,y);
   cout << "That is daynumber " << number << endl;

    //convert back by calling your dayMthYr function giving it number and three 
    //variables, day, month and year, into which it puts the answers  ...
     dayMthYr (number, day, month, year);
  

     
    //dayMthYr has given values to the call-by-reference parameters day, month and year
    //print them out
    cout << number << " is " << day;
    cout << "/" << month << "/" << year << endl;
   }
   else {//choice is not 1
    //test calc_date
    cout << "Enter a date to be modified: ";
    cin >> d >> m >> y;
    char s,p;
    int v;   
    cout << "Enter the sign, value, and period (d/w/y) of the modification: ";
    cin >> s >> v >> p;

    //turn the date into a daynumber and call your calc_date function ...
     number = daynumber (d,m,y);
     number = calc_date (number, s, v, p);


    //convert the answer back to a date using dayMthYr ...
     dayMthYr (number, day, month, year);


   
    cout << endl << "New Date is " << day;
    cout << "/" << month << "/" << year << endl;
}
    return 0;
}

int calc_date (int daynum, char sign, int amount, char time_frame)
{
  int day, month, year;
  if (sign == '+')
  {
    if (time_frame == 'd')
    {
      amount = amount * 1;
      daynum = daynum + amount;
    }

    else if (time_frame == 'w')
    {
      amount = amount *7;
        daynum = daynum + amount;
    }
    else {
      dayMthYr(daynum, day, month, year);
      year = year + amount;
      daynum = daynumber(day, month, year);
    }
  }

  else {
    if(time_frame =='d'){
      amount = amount*1;
      daynum = daynum - amount;
    }

    else if (time_frame == 'w'){
      amount = amount*7;
      daynum = daynum - amount;
    }

    else {
      dayMthYr(daynum, day, month, year);
      year = year - amount;
    }
     
  }
 return daynum;
}


void dayMthYr (int daynum, int& day, int& month, int& year)
//converts daynum to date format and puts the answers into the call-by-refeence parameters, day, month and year
{
  year = 1900;
  month = 1; 
  while (daynum >= year_length(year)){
    daynum = daynum - year_length(year);
    year = year + 1;
  }
  while (daynum >= month_length(month, year)){
    daynum = daynum - month_length(month, year);
    month = month +1;
  }

  if(daynum == 0){
    day = 31;
    month = month -1;
  }
  else {
    day = daynum;
  }
}


//converts a date to a daynumber
int daynumber (int day, int month, int year)
{
    int y, m, daynumber;
    //accumelate days in all years before the given one
    daynumber = 0;
    for (y = 1900; y < year; y++)
    {
        daynumber = daynumber + year_length (y);
    }

    //in the given year, accumulate days in all months before the given month
    for (m = 1; m < month; m++)
    {
        daynumber = daynumber + month_length(m, year);
    }

    //accumulate all the days in the given month, including the given day
    daynumber = daynumber + day;

    return daynumber;
}

//gives back the number of days in the given month of the given year
int month_length (int m, int y)
{
    if (m==2) 
        if (leap_year(y))
	      return 29;
        else
		  return 28;
      
    else if (m==9 || m==4 || m==6 || m==11)  //i.e. September, April, June, or November
        return 30;
    
    else
        return 31;
}

int year_length (int y)
{
    if (leap_year (y)) 
        return 366;

    else
        return 365;
}

bool leap_year (int year)
{
    //returns true if year is a leap year
    
    if (year % 4 == 0) //all others are definitely not leap
        if (year < 1583)
            return true;
   
        else //after 1583
            if ((year % 100 == 0) && (year % 400 != 0))   //e.g. 1900
                return false;
            else //e.g. 1904 or 2000
                return true;

        else //not divisible by 4
            return false;
}
