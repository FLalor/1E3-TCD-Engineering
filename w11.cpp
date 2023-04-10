#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string SENTINEL = "X0000";

const double REG_FIXED_FEE = 10.00;
const int REG_FREE_MINS = 50;
const double REG_FEE_PER_MIN = 0.20;
const double P_FIXED_FEE = 25.00;
const int P_FREE_PEAK_MINS = 75;
const double P_PEAK_FEE_PER_MIN = 0.10;
const int P_FREE_OFF_MINS = 100;
const double P_OFF_FEE_PER_MIN = 0.05;

void read(char& code, int& mins1, int& mins2, double& bal, string& name) {
    cin >> name >> bal >> code;
    if (code == 'R') {
        cin >> mins1;
    } else {
        cin >> mins1 >> mins2;
    }
}

double reg_charge(int mins) {
    double total = REG_FIXED_FEE;
    if (mins > REG_FREE_MINS) {
        total += (mins - REG_FREE_MINS) * REG_FEE_PER_MIN;
    }
    return total;
}

double prem_charge(int peak_mins, int off_mins) {
    double total = P_FIXED_FEE;
    if (peak_mins > P_FREE_PEAK_MINS) {
        total += (peak_mins - P_FREE_PEAK_MINS) * P_PEAK_FEE_PER_MIN;
    }
    if (off_mins > P_FREE_OFF_MINS) {
        total += (off_mins - P_FREE_OFF_MINS) * P_OFF_FEE_PER_MIN;
    }
    return total;
}

void print_bill(string acc, string name, char code, double charge, double bal) {
    cout << setw(8) << acc << setw(15) << name << setw(11) << ((code == 'R') ? "Regular" : "Premium") << setw(10) << fixed << showpoint << setprecision(2) << charge << setw(10) << bal << endl;
}

int main() {
    string acc, name;
    char code;
    int mins1, mins2;
    double bal, tot;

    cout << setw(8) << "Account" << setw(15) << "Name" << setw(11) << "Act. Type" << setw(10) << "Charge" << setw(10) << "Balance" << endl;

    cin >> acc;
    while (acc != SENTINEL) {
        read(code, mins1, mins2, bal, name);
        if (code == 'R') {
            tot = reg_charge(mins1);
        } else {
            tot = prem_charge(mins1, mins2);
        }
        bal += tot;
        print_bill(acc, name, code, tot, bal);
        cin >> acc;
    }

    return 0;
}