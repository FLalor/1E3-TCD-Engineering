
#include <iomanip>
#include <iostream>
#include <cassert>

int main() {
  const double interest_rate = 0.01; // Monthly interest rate.
  
  // Get loan amount from user.
  double loan_amount;
  std::cout << "Loan amount:";
  std::cin >> loan_amount;

  // Get the monthly repayment from user.
  double monthly_payment;
  std::cout << "Monthly payment:";
  std::cin >> monthly_payment;
  
  // Run load calculation for each month.
  double total_interest = 0.0;
  double loan_balance = loan_amount; // How much the user currently owes.
  int payment_count = 0;
  
  for (int month = 0; ; ++month) {
    // Calculate the interest for the current month and accumulate total interest.
    const double interest = loan_balance * interest_rate;
    total_interest += interest;

    // Add interest to loan balance.
    loan_balance += interest;

    /*
    std::cout << "Month "          << month          << '\n';
    std::cout << "interest: "      << interest       << '\n';
    std::cout << "total_interest:" << total_interest << '\n';
    std::cout << "loan_balance 1:" << loan_balance   << '\n';
    */
    
    // Check if this is the last payment.
    if (loan_balance <= monthly_payment) {
      // Exit loop as balance is zero.
      payment_count = month + 1;
      break;
    }

    // Subtract payment from loan.
    loan_balance -= monthly_payment;
    
    //std::cout << "loan_balance 2:" << loan_balance << "\n\n";
  }

  // Print results.
  std::cout << std::fixed << std::setprecision(2);
  
  std::cout << payment_count  << " months.\n"
            << total_interest << " euro total interest.\n"
            // The final payment is equal to the end balance of the loan.
            << loan_balance   << " euro final payment.\n";

  return 0;
}
