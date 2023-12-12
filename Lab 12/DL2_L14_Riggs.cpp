/*
  Author:         Austin Riggs
  Assignment:     Lab 14
  Course/Section: COSC 1337 Section S (change S to your section number)
  Due Date:       See syllabus or blackboard
  Instructor:     Thayer
  Purpose: Practice recursion by re-implementing looping functions as recursive functions

  For each looping function, provide the code for the equivalent recursive function.
  See Blackboard, Lab 14 for complete instructions.

  IMPORTANT: Your recursive functions should NOT use any static local variables
  or global variables! The "state" of the function must be completely self-contained.
  A recursive functions may be called simultaneously by several programs at the same
  time. This occurs when a recursive function is in a library, such as qsort().
  If calls are not independent, the recursive function is limited to a single process.

  Search on "modify" to find places to insert your code or modify existing code.
*/

#include <iostream>
#include <iomanip>
#include <algorithm> // for min, max
#include <string.h> // used for substring function in string recursion
using namespace std;

void show_1_to_n_loop(int n) { // looping, PROVIDED, DO NOT CHANGE
  for (int i=1; i<=n; ++i) cout<<i<<" ";
}

void show_1_to_n_recurse(int n) { // recursive
  if (n > 0) {
    show_1_to_n_recurse(n - 1);
    // prints n greater than 0 to user on way back to first call
    cout << n << " ";

	}
}

void show_n_to_1_loop(int n) { // looping, PROVIDED, DO NOT CHANGE
  for (int i=n; i>=1; --i) cout<<i<<" ";
}

void show_n_to_1_recurse(int n) { // recursive
  if (n > 0) {
    // current value of n greater than 0 printed to user
    cout << n << " ";
    // show_n_to_1_recurse passed n - 1
    show_n_to_1_recurse(n - 1);
	}
}

string reverse_loop(string forward) { // looping, PROVIDED, DO NOT CHANGE
  string backwards;
  int size=forward.size();
  for (int i=0; i<size; ++i) {
    backwards+=forward[size-1-i];
  }
  return backwards;
}

string reverse_recurse(string forward) { // recursive
  string reversed;
  int index{};
  if (forward.size() > 0) {
    // reversed assigned last letter of foward
    reversed = forward[forward.size() -1];
    // foward substr cuts last letter off forward and passed to reverse_recurse
		reversed += reverse_recurse(forward.substr(0, forward.size() - 1));
	}
  return reversed;

}

int add2_fx(int a, int b) { // functional (for illustration only), PROVIDED, DO NOT CHANGE
  return a+b;
}

int add2_loop(int a, int b) { // looping, PROVIDED, DO NOT CHANGE
  int sum=a;
  if (b>0)
    for (int i=0; i<b; ++i) ++sum;
  else // b<=0
    for (int i=b; i<0; ++i) --sum;
  return sum;
}

int add2_recurse(int a, int b) { // recursive

  int sum = a;
  if (b > 0) {
    sum = add2_recurse( ++sum, --b);
	}
	else if (b < 0) {
	  sum = add2_recurse( --sum, ++b);
	}
  return sum;
}

int mult2_fx(int a, int b) { // functional (for illustration only), PROVIDED, DO NOT CHANGE
  return a*b;
}

int mult2_loop(int a, int b) { // looping, PROVIDED, DO NOT CHANGE
  int product=0;
  if (b>0)
    for (int i=0; i<b; ++i) product+=a;
  else // b<=0
    for (int i=b; i<0; ++i) product-=a;
  return product;
}

int mult2_recurse(int a, int b) { // recursive

  int product = 0;
  if (b > 0) {
    product = mult2_recurse(a, --b);
    product += a;
	}
	else if (b < 0) {
	  product = mult2_recurse(a, ++b);
    product -= a;
	}
  return product; // modify / replace this with your return value;  is 0 until new code added.
}

int search_loop(int array[], int size, int target) { // looping, PROVIDED, DO NOT CHANGE
  for (int i=0; i<size; ++i)
    if (array[i]==target) {return i;}
  return -1;
}

int search_recurse(int array[], int size, int target) { // recursive

  if (size == -1 ) {
    return -1;
	}
  else if (target == array[size - 1]) {
    return size - 1 ;
	}
  return size = search_recurse(array, size - 1, target);
}

enum control_flow_t {functional, looping, recursive};
void show_test(int n, string s, control_flow_t control_flow) {
  // utility function to format test output
  // n: test number; s: "description"; control_flow: functional, looping or recursive
  static const string fx="functional", sl="looping", sr="recursive";
  int max_len=max(fx.size(), max(sl.size(), sr.size()));
  string msg;
  switch (control_flow) {
    case functional: msg=fx;     break;
    case looping:    msg=sl;     break;
    case recursive:  msg=sr;     break;
    default:         msg="??";   break;
  }
  char iorr=msg[0];
  msg=" ("+msg+"): ";
  cout<<"\n"<<n<<iorr<<") "<<s<<setw(max_len+5)<<left<<msg;
}

void infinite_recursion() {
  // try at your own risk! Error message can be interesting.
  infinite_recursion();
}

// This code may be helpful when developing your recursive functions.
void recurse(int times_to_call) {
  // a generalized recursion outline; has 5 locations to do work...
  cout << "recurse head... " << "("<<times_to_call<<") " <<endl; // ALWAYS
  if (times_to_call>1) { // decision to recursive call
    cout << "recurse before call... " << "("<<times_to_call<<") " <<endl;
    recurse(times_to_call-1); // work (problem simplification) can be done inside the parameter list!
    cout << "recurse after call... " << "("<<times_to_call<<") " <<endl;
  } else {
    cout << "recurse else option... " << "("<<times_to_call<<") " <<endl;
  }
  cout << "recurse ...tail " << "("<<times_to_call<<") " <<endl; // ALWAYS
}

int main () {
  const string FIRSTNAME{"Austin"}; // modify / change this to your first name
  const string LASTNAME{"Riggs"};   // modify / change this to your last name

  // ----- DO NOT CHANGE ANY CODE BELOW in main(). CODE BELOW CALLS FUNCTIONS ABOVE FOR TESTING -----

  cout<<"start...\n";

  show_test(1, "show_1_to_n", looping);    show_1_to_n_loop(13);
  show_test(1, "show_1_to_n", looping);    show_1_to_n_loop(-7);    // handle unexpected values
  show_test(1, "show_1_to_n", recursive);  show_1_to_n_recurse(13);
  show_test(1, "show_1_to_n", recursive);  show_1_to_n_recurse(-7); // avoid runaway recursion
  cout<<endl;

  show_test(2, "show_n_to_1", looping);    show_n_to_1_loop(17);
  show_test(2, "show_n_to_1", looping);    show_n_to_1_loop(-3);    // handle unexpected values
  show_test(2, "show_n_to_1", recursive);  show_n_to_1_recurse(17);
  show_test(2, "show_n_to_1", recursive);  show_n_to_1_recurse(-3); // avoid runaway recursion
  cout<<endl;

  show_test(3, "reverse", looping);    cout<<reverse_loop("mom & dad live stressed");
  show_test(3, "reverse", looping);    cout<<reverse_loop(FIRSTNAME);
  show_test(3, "reverse", looping);    cout<<reverse_loop(LASTNAME);
  show_test(3, "reverse", recursive);  cout<<reverse_recurse("mom & dad live stressed");
  show_test(3, "reverse", recursive);  cout<<reverse_recurse(FIRSTNAME);
  show_test(3, "reverse", recursive);  cout<<reverse_recurse(LASTNAME);
  cout<<endl;

  show_test(4, "add2", functional);
  cout<<add2_fx( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_fx(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_fx(20, -9); cout<<" ";  // correct:  11
  cout<<add2_fx(-7, -5); cout<<" ";  // correct: -12
  show_test(4, "add2", looping);
  cout<<add2_loop( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_loop(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_loop(20, -9); cout<<" ";  // correct:  11
  cout<<add2_loop(-7, -5); cout<<" ";  // correct: -12
  show_test(4, "add2", recursive);
  cout<<add2_recurse( 4,  5); cout<<" ";  // correct:   9
  cout<<add2_recurse(-5, 15); cout<<" ";  // correct:  10
  cout<<add2_recurse(20, -9); cout<<" ";  // correct:  11
  cout<<add2_recurse(-7, -5); cout<<" ";  // correct: -12
  cout<<endl;

  show_test(5, "mult2", functional);
  cout<<mult2_fx( 2,   5); cout<<" ";  // correct:  10
  cout<<mult2_fx(-4,   5); cout<<" ";  // correct: -20
  cout<<mult2_fx( 3, -10); cout<<" ";  // correct: -30
  cout<<mult2_fx(-10, -4); cout<<" ";  // correct:  40
  show_test(5, "mult2", looping);
  cout<<mult2_loop( 2,   5); cout<<" ";  // correct:  10
  cout<<mult2_loop(-4,   5); cout<<" ";  // correct: -20
  cout<<mult2_loop( 3, -10); cout<<" ";  // correct: -30
  cout<<mult2_loop(-10, -4); cout<<" ";  // correct:  40
  show_test(5, "mult2", recursive);
  cout<<mult2_recurse( 2,   5); cout<<" ";  // correct:  10
  cout<<mult2_recurse(-4,   5); cout<<" ";  // correct: -20
  cout<<mult2_recurse( 3, -10); cout<<" ";  // correct: -30
  cout<<mult2_recurse(-10, -4); cout<<" ";  // correct:  40
  cout<<endl;

  int primes[] {2, 3, 5, 7, 11, 13, 17, 19, 23, 29}; // some numbers to search for
  int size_primes=sizeof(primes)/sizeof(primes[0]);  // get #elements in array

  show_test(6, "search", looping);
  cout<<search_loop(primes, size_primes, 2)<<", ";
  cout<<search_loop(primes, size_primes, 13)<<", ";
  cout<<search_loop(primes, size_primes, 10)<<", ";
  cout<<search_loop(primes, size_primes, 29);
  show_test(6, "search", recursive);
  cout<<search_recurse(primes, size_primes, 2)<<", ";
  cout<<search_recurse(primes, size_primes, 13)<<", ";
  cout<<search_recurse(primes, size_primes, 10)<<", ";
  cout<<search_recurse(primes, size_primes, 29)<<endl;

  // infinite_recursion();  // uncomment to experience infinite recursion (crash, error message)

  cout<<"\n...end\n";

  return 0;
} // end of main

// When complete, there will be test output for each of the 6 steps in pairs:
// looping and recursive. Your output should match.
/*
Output of program:

start...

1l) show_1_to_n (looping):    1 2 3 4 5 6 7 8 9 10 11 12 13
1l) show_1_to_n (looping):
1r) show_1_to_n (recursive):  1 2 3 4 5 6 7 8 9 10 11 12 13
1r) show_1_to_n (recursive):

2l) show_n_to_1 (looping):    17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
2l) show_n_to_1 (looping):
2r) show_n_to_1 (recursive):  17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
2r) show_n_to_1 (recursive):

3l) reverse (looping):    desserts evil dad & mom
3l) reverse (looping):    nitsuA
3l) reverse (looping):    sggiR
3r) reverse (recursive):  desserts evil dad & mom
3r) reverse (recursive):  nitsuA
3r) reverse (recursive):  sggiR

4f) add2 (functional): 9 10 11 -12
4l) add2 (looping):    9 10 11 -12
4r) add2 (recursive):  9 10 11 -12

5f) mult2 (functional): 10 -20 -30 40
5l) mult2 (looping):    10 -20 -30 40
5r) mult2 (recursive):  10 -20 -30 40

6l) search (looping):    0, 5, -1, 9
6r) search (recursive):  0, 5, -1, 9

...end

--------------------------------
Process exited after 0.0478 seconds with return value 0
Press any key to continue . . .


*/