/**
* Week 3 - Finding Net Pay
*
* Task 2 - Formatted output
*
* Copy the body of your solution to task 1 in here. Then arrange to
* (1) read a multipart name from the rest of the line of input e.g. given input "35 15 0 Michael McConnell" the name is "Michael McConnell".
* (2) format output, using fixed, showpoint, setprecision, setw, left, right, etc. to produce output exactly like this, 30 characters per line:
Name         Michael McConnell
Hours                    35.00
Hourly rate              15.00
Gross wage              525.00
Tax @ 20%               105.00
PRSI @ 2.5%              13.12
------------------------------
Net pay                 406.88
*
*/

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
//Use these constants in your calculations.
  //These allow easy changes to rates, etc. when there is a change in policy, etc.
  const double BASIC_HOURS = 35;//hours above this is overtime
    const double OTIME_MULT = 1.5;//the multiplier for overtime hours
    const double TAX_RATE = 0.20;//all pay is taxed at 20%
    const double PRSI_RATE = 0.025;//PRSI is 2.5% of gross pay

    //Declare all the variables as doubles ...
  double hours, hourly_rate, tax_credit, gross_pay, tax, prsi, net_pay;
  string name;
  char fillchar = ' ';
    

    //Read in the values
    //All inputs entered on one line, one prompt only
    cout << "Enter hours, hourly rate, tax credit, name:";

  cin >> hours;
  cin >> hourly_rate;
  cin >> tax_credit;
  getline(cin, name);
              // etc...


    //Calculate the gross pay
    //To pass test 3, adjust the following to arrange for gross_pay to include overtime pay...

  if(hours>35)
  {
    gross_pay = (35*hourly_rate)+(hours - BASIC_HOURS)*(hourly_rate*OTIME_MULT);
  }
  else
  {
    gross_pay = hours * hourly_rate;
  }

  
    //Calculate the deductions based on the gross pay
    //calculate tax ...

  tax = gross_pay*TAX_RATE;


    //apply the tax credit (to pass tests 4 & 5) ...

    if(tax < tax_credit)
    { tax = 0;}
    else {tax = tax - tax_credit;}

  //calculate PRSI ...

  prsi = gross_pay*PRSI_RATE;



    //calculate net_pay after deductions ...
net_pay = gross_pay - tax - prsi;

std::cout << std::fixed;
    std::cout << std::setprecision(2);
    
  std::cout << setfill(fillchar) <<endl; // fillchar has been set to '-' above
    std::cout << setw (4) << left << "Name" << setw (26) << right << name << endl;
  std::cout << setw (4) << left << "Hours" << setw (25) << right << hours << endl;
    std::cout << setw (4) << left << "Hourly rate" << setw (19) << right << hourly_rate << endl;
  std::cout << setw (4) << left << "Gross wage" << setw (20) << right << gross_pay << endl;
  std::cout << setw (4) << left << "Tax @ 20%" << setw (21) << right  << tax << endl;
  std::cout << setw (4) << left << "PRSI @ 2.5%" << setw (19) << right << prsi << endl;
    std::cout << "------------------------------" << endl;
    std::cout << setw (4) << left << "Net pay" << setw (23) << right << net_pay << endl;

    return 0;
}
