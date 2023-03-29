#include <iostream>

using namespace std;

int main() {
    int limit, a = 0, b = 1, c, count = 0;

    cout << "Fibs below what:";
    cin >> limit;

  //complete fib sequence
    while (a <= limit) {
        count++;
        if (a == 0) {
            cout << a << " ";
            a = b;
            continue;
        }
      //exit if greater than limit
        if (a => limit) {
            break;
        }
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }

    cout << endl << "That was " << count << " terms.";

    return 0;
}
