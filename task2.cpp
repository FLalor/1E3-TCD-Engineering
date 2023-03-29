#include<iostream>
using namespace std;
int main()
{
  int n, i, a=0, b=1, c;

  //input
  cout << "How many fibs:";
  cin >> n;

  //display Fibonacci Series
  for (i=a; i<=n; i++)
  {
    cout << a << " ";
    c=a+b;
    a=b;
    b=c;
  }

  return 0;
}
