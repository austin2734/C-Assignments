#include<iostream>
#include<cmath>
using namespace std; 

// double data type range check function prototype
double double_entry(const string &prompt, double low, double hi, const string &error = "Error. Please try again.");
// character distance function prototypes
char input(const string &prompt, const string &error);
int dist(int(char1), int(char2));
void display(char char1, char char2, const string &msg);
// number difference function prototypes
double input(double min_num, double max_num, const string &prompt, const string &error);
void display(double num1, double num2, const string &msg = "The difference between numbers ");
double dist(double num1, double num2);
// point distance function prototypes
void input (double &xVal, double &yVal, const string &point_prompt, int min_num = -100, int max_num = 100);
void display(double x1, double y1, double x2, double y2, const string &msg);
double dist(double x1, double y1, double x2, double y2);


int main() {
	
	const string E_MSG = "That is not a vaild input, please try again.";
	
	char choice{};
		   
	cout << "Welcome! This program will calculate the distance between two ";
	cout << "letters, numbers, or points." << endl << endl;
	
	
	do {  // loops until q is entered by user
		
		cout << "Please select one of the following options: l)etters n)umbers p)oints q)uit ";
		cin >> choice;
		choice = tolower(choice);
		
		switch(choice) {
			
			case 'l': { // letter distance finder
					   const string CHAR_PROMPT = "Please enter a single alphabetical character: ",
					   				CHAR_MSG = "The distance between letters ";
					   char char_1 = input(CHAR_PROMPT, E_MSG);
					   char char_2 = input(CHAR_PROMPT, E_MSG);
					   display(char_1, char_2, CHAR_MSG);
					   break;
			}	
			case 'n': { // number difference finder
					   const int MIN_NUM = -100;
					   const int MAX_NUM = 100;
					   const string NUM_PROMPT = "Please enter a number between -100 and 100: ";
					   // const string NUM_MSG = "The difference between numbers ";
					   double num_1 = input(MIN_NUM, MAX_NUM, NUM_PROMPT, E_MSG);
					   double num_2 = input(MIN_NUM, MAX_NUM, NUM_PROMPT, E_MSG);
					   display(num_1, num_2); // const string NUM_MSG commented out so default message is used
					   break; 
					
			}
			case 'p': { // point distance finder
				       const string POINT_PROMPT1 = "Please enter a value for the first ", // for x1 and y1
				       				POINT_PROMPT2 = "Please enter a value for the second ", // for x2 and y2
				      				POINT_MSG = "The distant in a straight line between points ";
				       double x1{},
				       		  y1{},
				       		  x2{},
				       		  y2{};
				       	input(x1, y1, POINT_PROMPT1); // min and max numbers not included, will use default vals
				       	input(x2, y2, POINT_PROMPT2); // min and max numbers not included, will use default vals
				       	display(x1, y1, x2, y2, POINT_MSG);
				       	break;
			}

			case 'q': {
				break;
			}
			default: {
				cout << "Invaild option. Please try again." << endl; // error handling
				break;
			}
		   			   					 
		}
		
	} while(choice != 'q');
	
	cout << "Good-bye!" << endl;
  	return 0;
}

// int min_num and int max_num default to -100 and 100 as declared in function prototype 
void input (double &xVal, double &yVal, const string &point_prompt, int min_num, int max_num) { // input func for points
	
	const string ERROR = "Please enter a number between -100 and 100",
	      x_prompt = point_prompt + "X: ", // adds x char to point_prompt message 
		  y_prompt = point_prompt + "Y: "; // adds y char to point_prompt message
		  
	xVal = double_entry(x_prompt, min_num, max_num, ERROR);
	yVal = double_entry(y_prompt, min_num, max_num, ERROR);
	
}

double input(double min_num, double max_num, const string &prompt, const string &error) { // input func for nums
	
	double user_num = double_entry(prompt, min_num, max_num, error);
	return user_num;
}

char input(const string &prompt, const string &error) { // input func for letters
	
	char user_char{};
	bool running  = true;
	
	while(running) { // loops until alphabetical char is entered by user.
		
		cout << prompt;
		cin >> user_char;
		user_char = tolower(user_char);
		
		if (isalpha(user_char)){
			running = false;	
		}
		
		else {
			cout << error << endl;
		}
	}
	
	return user_char;
}

void display(double x1, double y1, double x2, double y2, const string &msg) { // display for points
	
	int static displayCount_points{};
	double distance = dist(x1, y1, x2, y2);
	cout << msg << "(" << x1 << "," << y1 << ")" << " and ";
	cout << "(" << x2 << "," << y2 << ")" << " is: " << distance << endl;
	cout << "Function count: " << ++displayCount_points << endl;
}

void display(double num1, double num2, const string &msg){ // display for numbers
	
	int static displayCount_nums{};
	double distance = dist(num1, num2);
	cout << msg << num1 << " and " << num2 << " is: " << distance << endl;
	cout << "Function count: " << ++displayCount_nums << endl;	
}

void display(char char1, char char2, const string &msg) { // display for characters
	
	int static displayCount_chars{};
	int distance = dist(char1, char2);
	cout << msg << char1 << " and " << char2 << " is: " << distance << endl;
	cout << "Function count: " << ++displayCount_chars << endl;
}
double dist(double x1, double y1, double x2, double y2) { // calculates distance between two points
	
	return abs(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
	
}

double dist(double num1, double num2) { // calculates difference between two numbers
	
	return abs(num1 - num2);
}

int dist(int(char1), int(char2)) { // calculates distance between two letters in alphabet
	
	return abs(char1 - char2);	
}

// Edited version of kbd_entry from template to function, works with the double data type. 
double double_entry(const string &prompt, double low, double hi, const string &error) {
	double value{};
  	while (true) {
    	if (cout << prompt and cin >> value and value >= low and value <= hi) return value;
    	cin.clear(); cin.ignore(INT_MAX, '\n'); cout << error << endl;
  }
}

/*
Tests of program output: 

distance between letters -

Welcome! This program will calculate the distance between two letters, numbers, or points.

Please select one of the following options: l)etters n)umbers p)oints q)uit h
Invaild option. Please try again.
Please select one of the following options: l)etters n)umbers p)oints q)uit l
Please enter a single alphabetical character: 2
That is not a vaild input, please try again.
Please enter a single alphabetical character: a
Please enter a single alphabetical character: z
The distance between letters a and z is: 25
Function count: 1
Please select one of the following options: l)etters n)umbers p)oints q)uit l
Please enter a single alphabetical character: A
Please enter a single alphabetical character: a
The distance between letters a and a is: 0
Function count: 2 


difference between numbers - 

Please select one of the following options: l)etters n)umbers p)oints q)uit n
Please enter a number between -100 and 100: 300
That is not a vaild input, please try again.
Please enter a number between -100 and 100: -101
That is not a vaild input, please try again.
Please enter a number between -100 and 100: 100
Please enter a number between -100 and 100: -100
The difference between numbers 100 and -100 is: 200
Function count: 1
Please select one of the following options: l)etters n)umbers p)oints q)uit n
Please enter a number between -100 and 100: 10.5
Please enter a number between -100 and 100: -10.5
The difference between numbers 10.5 and -10.5 is: 21
Function count: 2

distance in straight line between two points - 

Welcome! This program will calculate the distance between two letters, numbers, or points.

Please select one of the following options: l)etters n)umbers p)oints q)uit p
Please enter a value for the first X: apples
Please enter a number between -100 and 100
Please enter a value for the first X: 0
Please enter a value for the first Y: 3
Please enter a vaule for the second X: 4
Please enter a vaule for the second Y: 0
The distant in a straight line between points (0,3) and (4,0) is: 5
Function count: 1
Please select one of the following options: l)etters n)umbers p)oints q)uit p
Please enter a value for the first X: 0
Please enter a value for the first Y: 0
Please enter a vaule for the second X: 0
Please enter a vaule for the second Y: 0
The distant in a straight line between points (0,0) and (0,0) is: 0
Function count: 2
Please select one of the following options: l)etters n)umbers p)oints q)uit p
Please enter a value for the first X: 0.5
Please enter a value for the first Y: 3.5
Please enter a vaule for the second X: 4.5
Please enter a vaule for the second Y: 0.5
The distant in a straight line between points (0.5,3.5) and (4.5,0.5) is: 5
Function count: 3
Please select one of the following options: l)etters n)umbers p)oints q)uit q
Invaild option. Please try again.
Good-bye!


*/