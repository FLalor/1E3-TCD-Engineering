
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

int main () {
  // Read weather station name.
  std::string name;
  std::cin >> name;

  // Read all data.
  std::string input;
  double min_value =  std::numeric_limits<double>::max();
  double max_value = -std::numeric_limits<double>::max();
  double sum = 0.0; // Sum of all inputted data.
  int data_count; // How many data points were inputted.
  
  for (data_count = 0; ; ++data_count) {
    // Read next value.
    std::cin >> input;

    // Break if terminated by -999.
    if (input == "-999")
      break;

    // Get value from input data.
    const double value = std::stod(input);
    
    // Check if new value is the current min/max.
    if (value < min_value)
      min_value = value;

    if (value > max_value)
      max_value = value;

    // Add value to sum.
    sum += value;
  }
  
  // Output results to user.
  std::cout << std::fixed << std::setprecision(1);
  
  std::cout << name << ' ';

  // Only output results if data was provided.
  if (data_count > 0) {
    const double average = sum / data_count;

    std::cout << min_value << ' ' << max_value << ' ' << average;
  }
  else
    std::cout << "NO DATA";
  
  return 0;
}
