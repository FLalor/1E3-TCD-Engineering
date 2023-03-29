//LENS Allows me 10 Extra Minutes.

#include <iostream>
#include <string>

using namespace std;

//Saffir-Simp Category Determinatiion Func.
  int StormCat(int windSpeed)
  {
    if (windSpeed >= 250) {
        return 5;
    } else if (windSpeed >= 210) {
        return 4;
    }
    else if (windSpeed >= 178) {
        return 3;
    }
    else if (windSpeed >= 154) {
        return 2;
    }
    else if (windSpeed >= 119) {
        return 1;
    }
    else {
        return 0;  // not a hurricane
    }
  }

int main() {
  int n;
  cin >> n;

  //Loop for each year
  for (int year = 1; year <= n; year++){
    int max_windSpeed =-1;
    string max_windSpeedName;
    string strongestName = "NONE";
    int strongestCat = 0;

    //Input & Read Data

    int windSpeed;
    string Name;
    cin >> Name;

    while (Name != "XXX"){
      cin >> windSpeed;
      if (windSpeed >= 154) { //outputs cat 3 or stronger
        int category = StormCat (windSpeed);
                cout << year << endl;
                cout << Name << " Category " << category << endl;
                if (windSpeed > max_windSpeed) {
                    max_windSpeed = windSpeed;
                    max_windSpeedName = Name;
                }
        if (category > strongestCat){
          strongestCat = category;
                    strongestName = Name;
        }
    }
      cin >> Name;
    }

    // output strongest storm for this year
        if (strongestName != "NONE") {
            cout << "Strongest storm: " << strongestName << endl;
          
          cout << " ------------------" << endl;
        } else {
            cout << "Strongest storm: NONE" << endl;
          cout <<"------------------" << endl;
        }

        // output storms with wind speed between 154 and 250 km/h
        if (max_windSpeed != -1) {
            cout << max_windSpeedName << " " << max_windSpeed << endl;
            cin >> Name;
            while (Name != "XXX") {
                cin >> windSpeed;
                if (windSpeed >= 154 && windSpeed < 250) {
                    cout << Name << " " << windSpeed << endl;
                }
                cin >> Name;
            }
        }
        cout << "------------------" << endl;
    }
    }
