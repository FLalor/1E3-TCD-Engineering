#include <iostream>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void printNstars(int n) {
    for (int i = 0; i < n; i++) {
        cout << "*";
    }
    cout << endl;
}

int main() {
    const int MAX_PRIME = 50;
    const int SCALE_FACTOR = 2;

    // Draw scaled axis
    for (int i = 1; i <= MAX_PRIME; i++) {
        if (i % SCALE_FACTOR == 0) {
            cout << "+";
        } else {
            cout << "-";
        }
    }
    cout << "|" << endl;

    // Draw bars for prime numbers
  cout << "*\n";
    for (int i = 1; i <= MAX_PRIME; i++) {
        if (isPrime(i)) {
            printNstars(i);
        }
    }

    return 0;
}
