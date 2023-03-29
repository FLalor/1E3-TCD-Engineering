#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1415;

double circle_area (double diameter);
double ring_area (double circleD, double holeD);
double circumference(double diameter);

int main() {
  double outerD, innerD, distance;

  cout << "Enter outer and inner diameters:";
  cin >> outerD >> innerD;

  double outerR = outerD / 2.0;
  double innerR = innerD / 2.0;

  double area = ring_area(outerD, innerD);
  distance = circumference(outerR + innerR);

  cout << "Area:" << area << " Distance:" << distance << endl;

  return 0;
}

double circle_area (double diameter) {
  double radius = diameter / 2.0;
  return PI * pow(radius, 2);
}

double ring_area (double circleD, double holeD) {
  double outerA = circle_area(circleD);
  double innerA = circle_area(holeD);
  return outerA - innerA;
}

double circumference(double diameter) {
  return PI * diameter;
}
