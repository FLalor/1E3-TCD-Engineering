#include <iostream>
#include <string>

using namespace std;

string girls [10] = {"Grace", "Fiadh", "Emily", "Sophie", "Ava", "Amelia", "Ella", "Hannah", "Lucy", "Alex"};
    string boys [10] = {"Jack", "James", "Noah", "Daniel", "Conor", "Finn", "Liam", "Fionn", "Alex", "Charlie"};

int findRank(string name, string names[], int size) {
    for(int i=0; i<size; i++) {
        if(name == names[i]) {
            return i+1;
        }
    }
    return -1;
}

int main() {
    string name;
    while(true) {
        cout << "Enter a name to search for:";
        cin >> name;

        int girls_rank = findRank(name, girls, 10);
        int boys_rank = findRank(name, boys, 10);

        if(girls_rank == -1 && boys_rank == -1) {
            cout << name << " is not in the top 10 for girls or boys." << endl;
        } else {
            if(girls_rank != -1) {
                cout << name << " is ranked " << girls_rank << " in top girls name." << endl;
            }
            if(boys_rank != -1) {
                cout << name << " is ranked " << boys_rank << " in top boys name." << endl;
            }
        }

        string choice;
        cout << "Look up the rank of another name? Enter No to end:";
        cin >> choice;
        if(choice == "No") {
            break;
        }
    }

    return 0;
}