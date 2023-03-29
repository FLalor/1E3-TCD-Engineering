#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// declare a read function that reads size chars into array a ...
void read(char answer[]);
int score(char solution[], char answers[]);

//declare a score function that takes two arrays of chars, correct answers and student answers, and their size, and returns the score ...



int main ()
{
    const int MCQsize = 20;
    int studentID;
    int grade;
    char solution[20], answers[20];
    
    //read the model/correct answers ...
    read(solution);
    
    //read the first student id
    cin >> studentID;
    while(studentID >0){
      read(answers);
      cout << studentID << " " << score(solution, answers) << endl;
        cin >> studentID;
    }
  
    
    //read, score and report each student's answers ...
        
  
    return 0;
}

void read(char answer[]){
	for(int i = 0; i < 20; i++){
		cin >> answer[i];
	}
}

int score(char solution[], char answers[]){
	int score=0;
	
	for(int i = 0; i < 20; i++){
		if(solution[i] == answers[i]){
			score = score + 2;
		}
		else if(answers[i] != 'x'){ 
			score = score -1;
		}
	}
	return score;
}	