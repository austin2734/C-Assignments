/*
  Author: Austin Riggs;  Course: COSC 1337 Summer 2022 DL2;  Instructor: Thayer;
  Lab: 02;  Purpose: Program draws various characters as chosen by user input.
*/

#include <iostream>
#include <string>
using namespace std;

// exception handler kbd_entry

template <typename T>
T kbd_entry(const string & prompt, T low, T hi) {
  T value{};
  while (true) {
    if (cout << prompt and cin >> value and value >= low and value <= hi) return value;
    cin.clear(); cin.ignore(INT_MAX, '\n'); cout << "  try again...\n";
  }
}

int main() {
	
	bool running = true;	
	
	while(running) {
			
		char option = ' ';
		int height{};
		string height_prompt = "Enter a whole number for the height of the character (or 0 to quit): ";
		
		cout << "Input one of the letter options to have a character drawn (or q to quit): a) v b) 'A' c) 'R' q)uit: ";
		cin >> option;
		
		option = tolower(option); // lower's user input to lowercase character
		
		if (option == 'a') { //  this option creates a down arrow shape
			
			while(running)	{
				
				height = kbd_entry(height_prompt,-INT_MAX, INT_MAX); // uses kbd_entry to check if input is int
				
				if (height == 0) break; 
				
				cout << endl;
				
				for (int row{1}; row <= height; row++) {
					
					if (row == height) {
						cout << string(row - 1, ' ') << '*' << string(row -1, ' ') << endl; // creates bottom point of down arrow	
					}
					else {
						cout << string(row - 1, ' ') << '*' << string((height - row -1) * 2 + 1, ' '); 
						cout << '*' << string(row - 1, ' ') << endl;  // creates body of down arrow
				    }
		       }
		       
		       cout << endl;
		   }
		
	   }   
	   else if (option == 'b') { // this option creates an 'A' character
	       		
       		while(running) {
			   	
       			height = kbd_entry(height_prompt,-INT_MAX, INT_MAX); // uses kbd_entry to check if input is int
       			
       			if (height == 0) break;
       			
       			int mid_point = 1 + (height / 2); // finds midpoint to draw horizontal line in 'A' character
       			
       			cout << endl;
       			
       			for (int row{1}; row <= height; row++) {
       				
       				if (row == 1) {
       					
       					cout << string( height - row, ' ') << "* *" << string( height - row, ' ') << endl; // creates top of 'A' character
					   
					}
					
					else if (row == mid_point) {
						
						cout << string(height - mid_point, ' ') << string((mid_point * 2) + 1, '*') << string(height - mid_point, ' ') << endl; // middle line of 'A'
					}
					
					else {
						
						cout << string(height - row, ' ')<< "*" << string( row * 2 - 1, ' ') << "*" << string(height - row, ' ') << endl; // creates body of 'A'
					}
						
						
				}
				
				cout << endl;
			}
		}
		else if (option == 'c') { // draws a 'R' character
			
			while(running) {
				
				height = kbd_entry(height_prompt,-INT_MAX, INT_MAX); // uses kbd_entry to check if input is int
       			
       			if (height == 0) break;
       			
       			if (height == 1) { // was added in to account for a std::length error when lenght is less than 1
       			
       				cout << "This character needs have a height greater than 1 to draw, try again." << endl; 
                    continue;
				   }
       			
       			int mid_point = 1 + (height / 2); // calculates character midpoint
       			
       			cout << endl;
				
				for (int row{1}; row <= height; row++) {
					
					
					if (row == 1 || row == mid_point) {
						
						cout << "  " << string(height - 2, '*') << endl; // creates top shape of 'R' character 
					}
					
					else if (row < mid_point) {
						
						cout << "  " << '*' << string(height - 3 , ' ') << '*' << endl; // creates top shape of 'R' character
					}
					
					else {
						
						cout << "  " << '*' << string((row - mid_point) * 2, ' ') << '*' << endl; // creates bottom shape of 'R' character
					}
					
				}
				
				cout << endl;	
			}	
			
		}	
		else if (option == 'q') { // // exit message and break
		
			cout << "goodbye for now!"; 
			break;
	    }
	   
	   else { // invaild user input handling
	   	 
	   	  cout << "Invaid input....please try again." << endl;
	   }

   }
   
   return 0;
}

/*
Input one of the letter options to have a character drawn (or q to quit): a) v b) 'A' c) 'R' q)uit: a
Enter a whole number for the height of the character (or 0 to quit): 1

*

Enter a whole number for the height of the character (or 0 to quit): 5

*       *
 *     *
  *   *
   * *
    *

Enter a whole number for the height of the character (or 0 to quit): 10

*                 *
 *               *
  *             *
   *           *
    *         *
     *       *
      *     *
       *   *
        * *
         *

Enter a whole number for the height of the character (or 0 to quit): d
  try again...
Enter a whole number for the height of the character (or 0 to quit): 0
Input one of the letter options to have a character drawn (or q to quit): a) v b) 'A' c) 'R' q)uit: b
Enter a whole number for the height of the character (or 0 to quit): 1

* *

Enter a whole number for the height of the character (or 0 to quit): 5

    * *
   *   *
  *******
 *       *
*         *

Enter a whole number for the height of the character (or 0 to quit): 10

         * *
        *   *
       *     *
      *       *
     *         *
    *************
   *             *
  *               *
 *                 *
*                   *

Enter a whole number for the height of the character (or 0 to quit): h
  try again...
Enter a whole number for the height of the character (or 0 to quit): 0
Input one of the letter options to have a character drawn (or q to quit): a) v b) 'A' c) 'R' q)uit: c
Enter a whole number for the height of the character (or 0 to quit): 1
This character needs have a height greater than 1 to draw, try again.
Enter a whole number for the height of the character (or 0 to quit): 5

  ***
  *  *
  ***
  *  *
  *    *

Enter a whole number for the height of the character (or 0 to quit): 10

  ********
  *       *
  *       *
  *       *
  *       *
  ********
  *  *
  *    *
  *      *
  *        *

Enter a whole number for the height of the character (or 0 to quit): h
  try again...
Enter a whole number for the height of the character (or 0 to quit): 0
Input one of the letter options to have a character drawn (or q to quit): a) v b) 'A' c) 'R' q)uit: 2
Invaid input....please try again.
Input one of the letter options to have a character drawn (or q to quit): a) v b) 'A' c) 'R' q)uit: q
goodbye for now!
--------------------------------
Process exited after 46.07 seconds with return value 0
Press any key to continue . . .
*/