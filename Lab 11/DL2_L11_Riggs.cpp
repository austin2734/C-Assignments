/*
  Author: Austin Riggs
  Section: DL2
  Course: COSC1337
  Topic: lab 11, calendar helper, startup code
  Note: This code provides a test bed for class Day. Testing class Day should be easy and complete.
  You do not have the startup code exactly as is, but it should provide easy options to test class Day.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

template<typename T> // useful for getting user's keyboard input without crash or hang
T kbd_input(const string &prompt="Enter: ", const string &errmsg="   Oops! Try again.\n\n") {
  while (true) {
    cout << prompt; T ans{};
    if (cin>>ans) return ans;
    else {
      cin.clear(); cin.ignore(INT_MAX, '\n'); cout<<errmsg;
    }
  }
}

// int_entry vaildates various int inputs from user in program
template <typename T>
T int_entry(const string & prompt, T low, T hi) {
  T value{};
  while (true) {
    if (cout << prompt and cin >> value and value >= low and value <= hi) return value;
    cin.clear(); cin.ignore(INT_MAX, '\n'); cout << "  try again...\n";
  }
}

// helper function that returns lower case, three letter verison of string passed to it
string three_letters(const string &w) {

  string fixed_month;

  for (int i{}; i < 3; i++) {
    char letter = tolower(w[i]);
    fixed_month += letter;
	}

  return fixed_month;
}

class Day {
  private:
    int day_of_year{}; // limit day_of_year to positive numbers

  public:
    // default constructor and constructor prototypes
    Day()
    { day_of_year = 1;} // default constructor
    Day(int); // int constructor prototype
    Day(const string&, int); // month and int constructor prototype

    // month:
    static const int daysInMonth[12];
    static const int daysInMonth_accum[12];
    static const string monthsOfYear[12];  // Later initialized to: {"january", "february", "march", ... "december"};
    enum Month_t {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

    // week
    static const string daysOfWeek[7];  // Initialized to: {"sunday", "monday", "tuesday", ... "saturday"};
    enum Weekday_t {SUN, MON, TUE, WED, THR, FRI, SAT}; // may be useful

    // day
    static const int BASE_YEAR=2022;
    static const Month_t BASE_MONTH=JAN;
    static const Weekday_t BASE_WEEKDAY=SAT; // January 1, 2022 was a Saturday
    static const int BASE_DAY=1;

  // Added member functions (definition and prototypes)
    int getDayCount() const // returns current day_of_year number
    { return day_of_year;}
    string to_cap(const string&); // reformats month and weekday strings to have uppercase first letter
    string string_date(int); // converts day_of_year to string date
    void change_day(int); // updates current day_of_year number
    Day operator++(); // overloaded prefix ++ declaration
    Day operator++(int); // overloaded postfix ++ declaration
    Day operator--(); // overloaded prefix -- declaration
    Day operator--(int); // overloaded postfix -- declaration
    friend ostream &operator<<(ostream &, Day); // EXTRA CREDIT - overloaded << operator declaration

};

// Use these as needed
const int Day::daysInMonth[12]       = {31, 28, 31, 30,  31,  30,  31,  31,  30,  31,  30,  31};
const int Day::daysInMonth_accum[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
const string Day::monthsOfYear[12] = {"jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec"};
// {"january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december"};
const string Day::daysOfWeek[7] = {"sun", "mon", "tue", "wed", "thr", "fri", "sat"};
// {"sunday", "monday", "tuesday", "wednesday", "thursday", "friday", "saturday"};

// constructor definition for int days input
Day::Day(int d) {
  // ensures that day_of_year is no less than 1
  if (d > 1) {
  day_of_year = d;
	}
	else {
	 day_of_year = 1;
	}
}

// constructor definition for string month and int days input
Day::Day (const string& month, int days) {
  int total_days{};
  // checks month string with values of monthsOfYear array
  for (int m{}; m < 12; m++) {
    if (month == monthsOfYear[m]) {
      // checks to see if given day of month is greater than month allows
      if (days <= daysInMonth[m] ) {
        total_days = daysInMonth_accum[m] + days;
      }
      // if day is greater than possible in given month, date set to last day of month
      else {
        // if day of month greater than the highest value for a given month,
        // day of month set to highest month value possible for that month (i.e - feb 31 == feb 28)
        total_days = daysInMonth[m] + daysInMonth_accum[m];
			}
      break;
    }
	}
	// ensures that days_of_year is no less than 1
	if (total_days > 0) {
    day_of_year = total_days;
  }
  else {
    day_of_year = 1;
	}
}

// overloaded prefix ++ operator definition
Day Day::operator++() {
  day_of_year++;
  return *this;
}

// overloaded postfix ++ operator definition
Day Day::operator++(int) {
  Day temp = *this;
  day_of_year++;
  return temp;
}

// overloaded prefix -- operator definition
Day Day::operator--() {
  if (day_of_year > 1) {
    day_of_year--;
	}
	return *this;
}

// overloaded postfix -- operator definition
Day Day::operator--(int) {
  Day temp = *this;
  if (day_of_year > 1) {
    day_of_year--;
	}
	return temp;
}

// overloaded << operator definition
ostream &operator<<(ostream &out, Day a) {

  out << a.string_date(a.getDayCount());
  return out;
}

// function converts day_of_year value to date and returns string of such date
string Day::string_date(int num=-1) {
  int c_year    = BASE_YEAR; // current year variable
  int c_month   = BASE_MONTH; // current month variable
  int c_weekday = BASE_WEEKDAY; // current weekday variable
  int c_day     = BASE_DAY; // current day variable
  int remainder{}; // variable used to make calcualtions of date conversion

  // ensures that num is not negative (if no arugment passed to string_date, remainder set to obj day_of_year number
  // as default value for num is -1)
  if (num < 1) {
    remainder = day_of_year;
	}
	else {
	  remainder = num;
	}

	// FRI (value of 5) added to remainder variable offset yearly start of Saturday so that int c_weekday can be used
  // to find correct weekday in daysOfWeek array
	c_weekday = (FRI + remainder) % 7;

  if (remainder > 365) {
    c_year += remainder / 365;

    remainder = remainder % 365;
  }
  // loops through values in daysInMonth array to find c_month and c_day values
  for (int m{}; m < 12; m++) {
    // if m == 11, month is december and must c_month must be set to m
    if (m == 11) {
      c_month = m;
      c_day = remainder - daysInMonth_accum[c_month];
		}
    if (remainder <= daysInMonth_accum[m] )  {
      // m subtracted by 1 as value at daysInMonth_accum[m] is greater than remainder
      c_month = m - 1;
      // c_day calculated from subtracting remainder (days less than year) from current month max day amount
      c_day = remainder - daysInMonth_accum[c_month];
      break;
		}
	}

  string weekday = to_cap(daysOfWeek[c_weekday]); // Capitalizes first letter of weekday from daysOfWeek array
  string month =  to_cap(monthsOfYear[c_month]); // Capitalizes first letter of month from monthsOfYear array

  return weekday + " " + month + " " + to_string(c_day) + ", " + to_string(c_year);
}


// Day function member that updates Day object day_of_year value
void Day::change_day(int num) {
  // checks if num is negative, and if so, checks to see if substracting value will make day_of_year less than 1
  if ( num < 0 && day_of_year > num) {
    day_of_year += num;
	}
	else if (num > 0){
	  day_of_year += num;
	}
}

// member function that returns string with capitalized first letter of string argument passed to it
string Day::to_cap(const string &word) {
  string cap_word;
  for (int i{}; i < word.length(); i++) {
    if (i == 0) {
     cap_word += toupper(word[i]);
		}
		else {
		  cap_word += word[i];
		}
	}
  return cap_word;
}

int main() {
  cout <<"Welcome to Austin's calendar helper!\n";
  Day day(2); // this is updated in the set day options, and is the 1st day displayed in the Display options.
  for (bool running=true; running; ) {
    cout<<"\nOptions: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: ";
    string option; char option_letter; cin>>option; option_letter=tolower(option[0]);
    switch (option_letter) {
      case 'd': {
          // value of day_of_year retrieved from getDayCount function
          int day_count = day.getDayCount();
          cout << "\nCurrent day's date: "<< day.string_date(day_count) << endl;
          break;
        }

      case 'w': {
          int dc = day.getDayCount();
          cout << "\nDays of week from day's current date: \n\n";
          for (int i{}; i < 7; i++) {
						cout << day.string_date(dc);
						if (i != 6) { // ensures last printed day does not have comma
              cout << ", \n";
						}
						else {
						  cout << endl;
						}
						dc++; // dc incremented by 1
					}
          break;
        }

      case 'm': {
          cout<<"m option - show a month of days starting at current day, TO BE IMPLEMENTED\n";
          int dc = day.getDayCount();
          cout << endl << "Next 30 days from day's current date: \n\n";
          for (int i{1}; i < 31; i++) {
						cout << day.string_date(dc);
						if (i != 30) { // ensures last printed date does not have trialing comma
              cout << ",  ";
						}
						if (i % 5 == 0) { // formats output into rows with 5 dates each
						  cout << endl;
						}
						dc++;
					}
					cout << endl << endl;
          break;
        }

      case 's': // set day, test constructors: Day(), Day(int) constructor
        {
          char option = tolower(kbd_input<char>("  set day d)efault m)month,day n)umber v)ary: "));
          if (option=='q') break;

          switch(option) {
            case 'd': { // d=default: use default for an instance of class Day
              Day default_day;
              cout << "\nNew day created!\n";
              // EXTRA CREDIT - use of overloaded << operator on object default_day to print date
              cout << "\nNew day's date: " << default_day << endl;
              break;
            }

            case 'm': {  // m=month day: ask user for month and day of month, use user's input to construct a Day
              string month;
              cout << "Please enter a 3 letter month abbreviation to create a new day: ";
              cin >> month;
              // three_letters returns shortened lowercase verison of user month input
              month = three_letters(month);
              int c_day = int_entry("Please enter a vaild day of that month: ", 1, 31);
              Day daySetByMonth(month,c_day);
              cout << "\nNew day created!\n";
              cout << "\nNew day's date: " << daySetByMonth << endl;
              break;
            }

            case 'n': { // n=number: ask user for number 1..365..etc., use user's input to construct a Day
              // day 731 would be the start of 2024, which is avoided as it is a leap year
              int c_day = int_entry("Please enter a number greater than 0 to create a new day: ", 1, INT_MAX);
              Day daySetByNumber(c_day);
              cout << "\nNew day created!\n";
							cout << "\nNew day's date: " << daySetByNumber.string_date() << endl;
              break;
            }

            case 'v': { // v=vary: ask user for amount (can negative, 0, positive), vary current day by that amount
              // limit holds greatest value that could be subtracted from current day_of_year
              int limit = -(day.getDayCount() - 1);
              int c_day =int_entry("Please enter a number value to change the current day by: ",limit,INT_MAX);
              day.change_day(c_day);
              cout << endl << "Date updated!" << endl;
              cout << endl << "Current Date: " << day.string_date() << endl;
              break;
            }

            default: // not a valid option
              cout<<"    set day Invalid option.\n"; break;// continue;
          }

          break;
        }

      case 't': {

          // tests of the overloaded prefix and postfix -- ++ operators
          const int RANGE=5;

          cout << "\nCurrent Day: " << day.string_date() << endl << endl;

          cout << "Overloaded prefix ++ operator test : " << endl;
          for (int i{}; i < RANGE; i++)cout << (++day).string_date() << endl;
          cout << endl;
        	cout << "Overloaded postfix ++ operator test : " << endl;
          for (int i{}; i < RANGE; i++) cout << day++.string_date() << endl;
          cout << endl;
          cout << "Overloaded prefix -- operator test : " << endl;
          for (int i{}; i < RANGE; i++) cout << (--day).string_date() << endl;
          cout << endl;
          cout << "Overloaded postfix -- operator test : " << endl;
          for (int i{}; i < RANGE; i++) cout << day--.string_date() << endl;
          cout << endl;
          cout << "\nBack to current day: " << day.string_date() << endl << endl;
          break;
        }

      case 'q':
        running=false;
        break;

      default:
        cout<<"  Invalid option, try again. q to quit.\n";
        break;
    }
  }
  cout<<"\nThanks for using Austin's calendar helper! Good-bye!";
}

/*

Test 1 - Tests of d)ay, w)eek, m)onth, t)esting, and q)uit menu options

Welcome to Austin's calendar helper!

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: b
  Invalid option, try again. q to quit.

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: flaksdfjl
  Invalid option, try again. q to quit.

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: d

Current day's date: Sat Jan 1, 2022

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: w

Days of week from day's current date:

Sat Jan 1, 2022,
Sun Jan 2, 2022,
Mon Jan 3, 2022,
Tue Jan 4, 2022,
Wed Jan 5, 2022,
Thr Jan 6, 2022,
Fri Jan 7, 2022

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: m
m option - show a month of days starting at current day, TO BE IMPLEMENTED

Next 30 days from day's current date:

Sat Jan 1, 2022,  Sun Jan 2, 2022,  Mon Jan 3, 2022,  Tue Jan 4, 2022,  Wed Jan 5, 2022,
Thr Jan 6, 2022,  Fri Jan 7, 2022,  Sat Jan 8, 2022,  Sun Jan 9, 2022,  Mon Jan 10, 2022,
Tue Jan 11, 2022,  Wed Jan 12, 2022,  Thr Jan 13, 2022,  Fri Jan 14, 2022,  Sat Jan 15, 2022,
Sun Jan 16, 2022,  Mon Jan 17, 2022,  Tue Jan 18, 2022,  Wed Jan 19, 2022,  Thr Jan 20, 2022,
Fri Jan 21, 2022,  Sat Jan 22, 2022,  Sun Jan 23, 2022,  Mon Jan 24, 2022,  Tue Jan 25, 2022,
Wed Jan 26, 2022,  Thr Jan 27, 2022,  Fri Jan 28, 2022,  Sat Jan 29, 2022,  Sun Jan 30, 2022



Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: t

Current Day: Sat Jan 1, 2022

Overloaded prefix ++ operator test :
Sun Jan 2, 2022
Mon Jan 3, 2022
Tue Jan 4, 2022
Wed Jan 5, 2022
Thr Jan 6, 2022

Overloaded postfix ++ operator test :
Thr Jan 6, 2022
Fri Jan 7, 2022
Sat Jan 8, 2022
Sun Jan 9, 2022
Mon Jan 10, 2022

Overloaded prefix -- operator test :
Mon Jan 10, 2022
Sun Jan 9, 2022
Sat Jan 8, 2022
Fri Jan 7, 2022
Thr Jan 6, 2022

Overloaded postfix -- operator test :
Thr Jan 6, 2022
Wed Jan 5, 2022
Tue Jan 4, 2022
Mon Jan 3, 2022
Sun Jan 2, 2022


Back to current day: Sat Jan 1, 2022


Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: q

Thanks for using Austin's calendar helper! Good-bye!
--------------------------------
Process exited after 29.44 seconds with return value 0
Press any key to continue . . .

#######################################################################################################################

Test 2 - Tests of set day options: d)efault, m)month/day, n)umber, v)ary options -

Welcome to Austin's calendar helper!

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: s
  set day d)efault m)month,day n)umber v)ary: d

New day created!

New day's date: Sat Jan 1, 2022

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: s
  set day d)efault m)month,day n)umber v)ary: m
Please enter a 3 letter month abbreviation to create a new day: JuNE
Please enter a vaild day of that month: 3

New day created!

New day's date: Fri Jun 3, 2022

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: s
  set day d)efault m)month,day n)umber v)ary: m
Please enter a 3 letter month abbreviation to create a new day: Feb
Please enter a vaild day of that month: 30

New day created!

New day's date: Mon Feb 28, 2022

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: s
  set day d)efault m)month,day n)umber v)ary: m
Please enter a 3 letter month abbreviation to create a new day: dssdlkfasdjgkladsgjdasklgj
Please enter a vaild day of that month: 20

New day created!

New day's date: Sat Jan 1, 2022

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: s
  set day d)efault m)month,day n)umber v)ary: n
Please enter a number greater than 0 to create a new day: 365

New day created!

New day's date: Sat Dec 31, 2022

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: s
  set day d)efault m)month,day n)umber v)ary: n
Please enter a number greater than 0 to create a new day: -100
  try again...
Please enter a number greater than 0 to create a new day: 0
  try again...
Please enter a number greater than 0 to create a new day: 400

New day created!

New day's date: Sat Feb 4, 2023

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: s
  set day d)efault m)month,day n)umber v)ary: v
Please enter a number value to change the current day by: -10
  try again...
Please enter a number value to change the current day by: -1
  try again...
Please enter a number value to change the current day by: 234

Date updated!

Current Date: Tue Aug 23, 2022

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: s
  set day d)efault m)month,day n)umber v)ary: v
Please enter a number value to change the current day by: -234

Date updated!

Current Date: Sat Jan 1, 2022

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: s
  set day d)efault m)month,day n)umber v)ary: v
Please enter a number value to change the current day by: dfslkjf
  try again...
Please enter a number value to change the current day by: 59

Date updated!

Current Date: Tue Mar 1, 2022

Options: Display d)ay w)eek m)onth; s)et-day t)esting q)uit: q

Thanks for using Austin's calendar helper! Good-bye!
--------------------------------
Process exited after 220.9 seconds with return value 0
Press any key to continue . . .


*/