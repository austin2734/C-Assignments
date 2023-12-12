/*
  Programmer / author:	Austin Riggs
  Assignment:           Lab 7
  Topic:                Implement and test class Object
  File Name:            DL2_L7_Riggs.cpp
  Course/Section:       COSC 1337; Section DL2
  Due Date:             6/28/2022
  Instructor:           Thayer
*/

#include <iostream>
#include <iomanip>
using namespace std;


// Do not allow infinite looping, bad data when getting values from the user!
template <typename T>
T kbd_entry(const string &prompt, T low, T hi) {
  T value{};
  while (true) {
    if (cout << prompt and cin >> value and value >= low and value <= hi) return value;
    cin.clear(); cin.ignore(INT_MAX, '\n'); cout << "  try again...\n";
  }
}

// class Climber creates an object of fuctions and attributes regarding an individual rock climber
class Climber{

// Climber class data members (private)
  private:
  	// holds first and last name of rock climber
    string first_name, last_name;
    // holds number of routes attempted to be climbed, number of routes finished, and years of experience rock climbing
    int routes_attempted{}, routes_finished{}, years_of_exp{};
    // hold highest route grade completed by individual climber
    double highest_grade{};

  public:
     // Climber class function member prototypes and function member inline definitions
    Climber(const string&, const string&, int, int, int, double);
    void setFirstName(const string &fn)
      { first_name = fn; }
    void setLastName(const string &ln)
      { last_name = ln; }
    void setRoutesAttempted(int);
    void setRoutesFinished(int);
    void setYearsOfExp(int);
    void setHighestGrade(double);
    string getFirstName() const
	  { return first_name; }
    string getLastName() const
      { return last_name; }
    int getRoutesAttempted() const
      { return routes_attempted; }
    int getRoutesFinished() const
      { return routes_finished; }
    int getYearsOfExp() const
      { return years_of_exp; }
    double getHighestGrade() const
      { return highest_grade; }
    // constants used for verfication of vaild inputs
    const int MIN_ROUTES = 0, MAX_ROUTES = 5000, MIN_YEARS = 0, MAX_YEARS = 100;
    const double LOW_GRADE = 5.0, HIGH_GRADE = 5.15;
};

// Climber class constructor, default values included if values are not provided
Climber::Climber(const string &fn="N/A", const string &ln="N/A", int ra=0, int rf=0, int y=0,double hg=0.0) {

	first_name = fn;

	last_name = ln;

	if(ra >= MIN_ROUTES && ra <= MAX_ROUTES) routes_attempted = ra;

	if(rf >= MIN_ROUTES && rf <= MAX_ROUTES) routes_finished = rf;

	if(y >= MIN_YEARS && y <= MAX_YEARS) years_of_exp = y;

	if(hg >= LOW_GRADE && hg <= HIGH_GRADE) highest_grade = hg;

}

// Climber class function definitions

void Climber::setRoutesAttempted(int ra) {
	if (ra >= MIN_ROUTES && ra <= MAX_ROUTES) routes_attempted = ra;
}

void Climber::setRoutesFinished(int rf) {
	if(rf >= MIN_ROUTES && rf <= MAX_ROUTES) routes_finished = rf;
}
void Climber::setYearsOfExp(int y) {
	if(y >= MIN_YEARS && y <= MAX_YEARS) years_of_exp = y;
}
void Climber::setHighestGrade(double hg) {
	if(hg >= LOW_GRADE && hg <= HIGH_GRADE ) highest_grade = hg;
}


int main() {

  const int MIN_INVENTORY{1}; // min array length
  const int MAX_INVENTORY{5}; // max array length
  cout << "This program will create up to " << MAX_INVENTORY
       << " rock climber objects and display them to the user.\n";

  int num_objs = kbd_entry("How many rock climber objects would you like to create?"
                           " Please enter a number between 1 - 5: ", MIN_INVENTORY, MAX_INVENTORY);
  Climber climbers[num_objs]; // creates array with number Climber objects user wants to make

  for (int i = 0; i < num_objs; i++) { // will loop for number of objects user wishes to make
    string first_name;
	string last_name;
    int routes_attempted{}, routes_finished{}, years_of_exp{};
    double highest_grade{};

    cout << "Climber Number #" << i+1 << " Information: " << endl;

	cout << "Please enter the first name of the climber: ";
	cin >> first_name;
	climbers[i].setFirstName(first_name);

    cout << "Please enter the last name of the climber: ";
    cin >> last_name;
	climbers[i].setLastName(last_name);

	routes_attempted = kbd_entry("Please enter the number of attempted routes by the climber "
	                             "(must be between 0 - 5000): ", climbers[i].MIN_ROUTES, climbers[i].MAX_ROUTES);
	climbers[i].setRoutesAttempted(routes_attempted);

	routes_finished = kbd_entry("Please enter the number of finished routes by the climber "
	                            "(must be between 0 - 5000): ", climbers[i].MIN_ROUTES, climbers[i].MAX_ROUTES);
	climbers[i].setRoutesFinished(routes_finished);

	years_of_exp = kbd_entry("Please enter the number years the climber has been climbing "
	                         "(must be between 0 - 100): ", climbers[i].MIN_YEARS, climbers[i].MAX_YEARS);
	climbers[i].setYearsOfExp(years_of_exp);

	// if routes_finished is less that 1, then it is not possible to have completed a route.
	// message bypassed and hightest_grade left at default value
	if (climbers[i].getRoutesFinished() > 0) {
	highest_grade = kbd_entry("Please enter the highest route grade the climber has completed "
	                          "(must be between 5.0 - 5.15): ", climbers[i].LOW_GRADE, climbers[i].HIGH_GRADE);
		climbers[i].setHighestGrade(highest_grade);
    }

    // prints climber attributes to user
	cout << "\nClimber #" << i+1 << " details:\n" << "Climber first name: " << climbers[i].getFirstName() << endl
	     << "Climber last name: " << climbers[i].getLastName() << endl << "Number of routes attempted: "
	     << climbers[i].getRoutesAttempted() << endl << "Number of routes finished: " << climbers[i].getRoutesFinished()
	     << endl << "Years of experience climbing: " << climbers[i].getYearsOfExp() << endl
	     << "Highest climbing grade climbed: " << setprecision(2) << fixed
	     << climbers[i].getHighestGrade() << endl << endl;


  }


  cout << "\nThis ends the class Object program. Goodbye.\n";

  return 0;
}   // end of main


// Test output below:
/*

test # 1 - test of error checking of inputs

This program will create up to 5 rock climber objects and display them to the user.
How many rock climber objects would you like to create? Please enter a number between 1 - 5: 6
  try again...
How many rock climber objects would you like to create? Please enter a number between 1 - 5: -1
  try again...
How many rock climber objects would you like to create? Please enter a number between 1 - 5: 0
  try again...
How many rock climber objects would you like to create? Please enter a number between 1 - 5: 1
Climber Number #1 Information:
Please enter the first name of the climber: Austin
Please enter the last name of the climber: Riggs
Please enter the number of attempted routes by the climber (must be between 0 - 5000): bananas
  try again...
Please enter the number of attempted routes by the climber (must be between 0 - 5000): -10
  try again...
Please enter the number of attempted routes by the climber (must be between 0 - 5000): 7000
  try again...
Please enter the number of attempted routes by the climber (must be between 0 - 5000): 40
Please enter the number of finished routes by the climber (must be between 0 - 5000): apples
  try again...
Please enter the number of finished routes by the climber (must be between 0 - 5000): 100000
  try again...
Please enter the number of finished routes by the climber (must be between 0 - 5000): 20
Please enter the number years the climber has been climbing (must be between 0 - 100): 21
Please enter the highest route grade the climber has completed (must be between 5.0 - 5.15): 4.5
  try again...
Please enter the highest route grade the climber has completed (must be between 5.0 - 5.15): 5.16
  try again...
Please enter the highest route grade the climber has completed (must be between 5.0 - 5.15): 5.12

Climber #1 details:
Climber first name: Austin
Climber last name: Riggs
Number of routes attempted: 40
Number of routes finished: 20
Years of experience climbing: 21
Highest climbing grade climbed: 5.12


This ends the class Object program. Goodbye.

test #2 - skip highest grade climbed prompt

This program will create up to 5 rock climber objects and display them to the user.
How many rock climber objects would you like to create? Please enter a number between 1 - 5: 1
Climber Number #1 Information:
Please enter the first name of the climber: Steve
Please enter the last name of the climber: Jobs
Please enter the number of attempted routes by the climber (must be between 0 - 5000): 0
Please enter the number of finished routes by the climber (must be between 0 - 5000): 0
Please enter the number years the climber has been climbing (must be between 0 - 100): 0

Climber #1 details:
Climber first name: Steve
Climber last name: Jobs
Number of routes attempted: 0
Number of routes finished: 0
Years of experience climbing: 0
Highest climbing grade climbed: 0.00


This ends the class Object program. Goodbye.


test #3 - test of multipe objects

This program will create up to 5 rock climber objects and display them to the user.
How many rock climber objects would you like to create? Please enter a number between 1 - 5: 2
Climber Number #1 Information:
Please enter the first name of the climber: Austin
Please enter the last name of the climber: Riggs
Please enter the number of attempted routes by the climber (must be between 0 - 5000): 40
Please enter the number of finished routes by the climber (must be between 0 - 5000): 20
Please enter the number years the climber has been climbing (must be between 0 - 100): 2
Please enter the highest route grade the climber has completed (must be between 5.0 - 5.15): 5.11

Climber #1 details:
Climber first name: Austin
Climber last name: Riggs
Number of routes attempted: 40
Number of routes finished: 20
Years of experience climbing: 2
Highest climbing grade climbed: 5.11

Climber Number #2 Information:
Please enter the first name of the climber: Brian
Please enter the last name of the climber: Smith
Please enter the number of attempted routes by the climber (must be between 0 - 5000): 100
Please enter the number of finished routes by the climber (must be between 0 - 5000): 60
Please enter the number years the climber has been climbing (must be between 0 - 100): 6
Please enter the highest route grade the climber has completed (must be between 5.0 - 5.15): 5.13

Climber #2 details:
Climber first name: Brian
Climber last name: Smith
Number of routes attempted: 100
Number of routes finished: 60
Years of experience climbing: 6
Highest climbing grade climbed: 5.13


This ends the class Object program. Goodbye.

*/