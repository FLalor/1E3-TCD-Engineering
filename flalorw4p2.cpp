#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

int main () {
  //read weather station name
  std::string name;
  std::cin >> name;

  //eead all data

  std::string input;
  
  double min_value =  std::numeric_limits<double>::max();
  double max_value = -std::numeric_limits<double>::max();
  double sum = 0.0; //sum of all inputted data
  int data_count; //how many data points were taken in
  
  for (data_count = 0; ; ++data_count) {
    //read following value
    std::cin >> input;

    // Break if terminated by -999
    if (input == "-999")
      break;

    //collect value from input data
    const double value = std::stod(input);
    
    //read if new value is the current min/max
    if (value < min_value)
      min_value = value;

    if (value > max_value)
      max_value = value;

    //sum the values 
    sum += value;
  }
  
  //spit out results to user
  std::cout << std::fixed << std::setprecision(1);
  
  std::cout << name << ' ';

  //only output results if data was provided
  if (data_count > 0) {
    const double average = sum / data_count;

    std::cout << min_value << ' ' << max_value << ' ' << average;
  }
  else
    std::cout << "NO DATA";
  
  return 0;
}