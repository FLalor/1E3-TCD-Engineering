#include <iomanip>
#include <iostream>
#include <cassert>

int main() {
  const double interest_rate = 0.01; //monthly interest
  
  //loan amount from user
  double loan_amount;
  std::cout << "Loan amount:";
  std::cin >> loan_amount;

  //monthly repayment from user
  double monthly_payment;
  std::cout << "Monthly payment:";
  std::cin >> monthly_payment;

  
  double total_interest = 0.0;
  double loan_balance = loan_amount; //how much the user currently owes
  int payment_count = 0;
  
  for (int month = 0; ; ++month) {
    const double interest = loan_balance * interest_rate;
    total_interest += interest; //caluclates interest on loan per month and combines it to find total

    loan_balance += interest;

  
    
    //check for last payment
    if (loan_balance <= monthly_payment) {
      //exit loop as balance is zero
      payment_count = month + 1;
      break;
    }
    
    //update balance
    loan_balance -= monthly_payment;
  }

  std::cout << std::fixed << std::setprecision(2);
  
  std::cout << payment_count  << " months.\n"
            << total_interest << " euro total interest.\n"
            //the final payment is equal to the remaining balance of the loan
            << loan_balance   << " euro final payment.\n";

  return 0;
}