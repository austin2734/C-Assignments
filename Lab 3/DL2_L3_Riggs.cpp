
/*
  Author: Austin Riggs;  Course: COSC 1337 Summer 2022 DL2;  Instructor: Thayer;
  Lab: 03;  Purpose: Math quiz program for younger students
*/

#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

template <typename T>
T kbd_entry(const string & prompt, T low, T hi) {
  T value{};
  while (true) {
    if (cout << prompt and cin >> value and value >= low and value <= hi) return value;
    cin.clear(); cin.ignore(INT_MAX, '\n'); cout << "  try again...\n";
  }
}

int main() {
	
	string welcome_message = "Welcome! How many many math problems would you like to solve? ";
	int math_problems = kbd_entry(welcome_message, 0, INT_MAX );
	
	unsigned seed = time(0); // seed number created from time
	srand(seed); // set rand with seed number
	
	int correct_count{}; // holds user score 
		
	for(int q{1}; q <= math_problems; q++) {
		
		
		cout << "Enter -1 to exit the quiz at anytime." << endl;
		cout << "question #" << q << " of " << math_problems << endl;
		
		int num_1,
			num_2,
			answer; // holds correct sum of num_1 and num_2
		
		while(true) { // loops until sum of 2 numbers less than or equal to 100 are generated
			
			num_1 = rand() % (101); // range formula: (rand() % (max - min + 1) + min 
		    num_2 = rand() % (101);
		    
		    if (num_1 + num_2 <= 100) {
		    	
		    	answer = num_1 + num_2;
				break;
			}
		}
		
		
		string question = to_string(num_1) + " + " + to_string(num_2) + " = ? "; 
		int guess = kbd_entry(question, -1, 100); // user input for math problem
		
		if (guess == -1) { // exit program
			
			"Good-bye for now!";
			break;
			
		}
		else if (answer == guess) {
			
			cout << "Correct!" << endl;
			correct_count++;
		}
		else  {
			
			cout << "Incorrect." << endl;	
		}	
		
	}
	
	double percentage{};
	
	if(correct_count) { // ensures no divide by zero error takes place
		
		percentage = (static_cast<double>(correct_count) / math_problems) * 100 ; // correctly answered percentage calculator
	}
	
	cout << "You answered " << correct_count << " out of " << math_problems << " problems correctly." << endl;
	cout << setprecision(3) << percentage << "% of the your answers were correct." << endl;
	cout << "Good-bye for now!";
	
	return 0;
}

/*
Tests of program operation: 

test 1 - 

Welcome! How many many math problems would you like to solve? 3
Enter -1 to exit the quiz at anytime.
question #1 of 3
9 + 58 = ? 67
Correct!
Enter -1 to exit the quiz at anytime.
question #2 of 3
16 + 47 = ? 63
Correct!
Enter -1 to exit the quiz at anytime.
question #3 of 3
22 + 37 = ? 59
Correct!
You answered 3 out of 3 problems correctly.
100% of the your answers were correct.
Good-bye for now!
--------------------------------
Process exited after 31.13 seconds with return value 0
Press any key to continue . . .


test 2 - 

Welcome! How many many math problems would you like to solve? 0
You answered 0 out of 0 problems correctly.
0% of the your answers were correct.
Good-bye for now!
--------------------------------
Process exited after 1.881 seconds with return value 0
Press any key to continue . . .


test 3 -

Welcome! How many many math problems would you like to solve? no
  try again...
Welcome! How many many math problems would you like to solve? 3
Enter -1 to exit the quiz at anytime.
question #1 of 3
20 + 24 = ? I hate math :(
  try again...
20 + 24 = ? 44
Correct!
Enter -1 to exit the quiz at anytime.
question #2 of 3
60 + 13 = ? 5
Incorrect.
Enter -1 to exit the quiz at anytime.
question #3 of 3
2 + 56 = ? 1
Incorrect.
You answered 1 out of 3 problems correctly.
33.3% of the your answers were correct.
Good-bye for now!
--------------------------------
Process exited after 27.1 seconds with return value 0
Press any key to continue . . .

*/