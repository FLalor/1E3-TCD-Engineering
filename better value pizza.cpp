//5 points of 20 for this week
//Indicate which pizza is better value
//Complete this program so that the if statement provided will print "FIRST", "SECOND or "SAME" as appropriate.
//Reuse your previous ppsi code
#include <iostream>
using namespace std;

int main() {
 //declare variables ...
  const double PI = 3.1415;
  double A1, A2, d1, d2, p1, p2, ppsi1, ppsi2;

  //read in data
  cout << "Enter the diameter and price of the first pizza:";
  cin >> d1; 
  cin >> p1;
  //similarly for second pizza ...
  cout << "Enter the diameter and price of the second pizza:";
  cin >> d2; 
  cin >> p2;
  //compute ppsi1 and ppsi2...
  A1 = (PI*(d1/2.0*d1/2.0));

  A2 = (PI*(d2/2.0*d2/2.0));

  ppsi1 = p1/A1; 

  ppsi2 = p2/A2;

  

  //workout and print the answer
  if (ppsi1 < ppsi2) {
    cout << "FIRST";
  }
  else if (ppsi1 > ppsi2) {
    cout << "SECOND";
  } else if (ppsi1 == ppsi2) {
    cout << "SAME";
  }

  cout << endl;
  
  return 0;
}