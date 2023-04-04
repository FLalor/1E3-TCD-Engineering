#include <iostream>
#include <cmath>
using namespace std;

int readToSentinel(double values[], int size);
double mean(double values[], int size);
double variance(double values[], int size);
double s_deviation(double values[], int size);
int zero_crossing(double values[], int size);

int main(){
	double values[100];
	int size = readToSentinel(values, 100);
	
	cout << "Count:" << size << endl;
  cout << "Mean:" << mean(values, size) << endl;
	cout << "Variance:" << variance(values, size) << endl;
	cout << "Std. Dev.:" << s_deviation(values, size) << endl;
	cout << "Zero Xs:" << zero_crossing(values, size) << endl;
	
	return 0;	
}

int readToSentinel(double values[], int size){
	int i;
	for(i = 0; i < size; i++){
		cin >> values[i];
		//cout << i << " " << values[i] << endl;
		 
		if(values[i] == 9999){
			values[i] = 0;
			return i; 
		}
	}
	return i;
}
	
double mean(double values[], int size){
	double total = 0;
	
	for(int i = 0; i < size; i++){
		total = total + values[i];
	}
	return total/size;
}

double variance(double values[], int size){
	double m = mean(values, size);
	double x;
	double total = 0;
	
	for(int i = 0; i < size; i++){
		x = values[i] - m;
		total = total + x*x;
	}
	return total/(size-1);
}
		
		
double s_deviation(double values[], int size){
	return sqrt(variance(values, size));
}
int zero_crossing(double values[], int size){
	int count = 0;
	for(int i = 1; i < size; i++){
		if(values[i]*values[i-1] < 0){
			count++;
		}
	}
	return count;
}