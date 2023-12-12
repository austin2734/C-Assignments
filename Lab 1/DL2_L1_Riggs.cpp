/*
  Author: Austin Riggs;  Course: COSC 1337 Summer 2022 DL2;  Instructor: Thayer;
  Lab: 01  Purpose: Assits with restaurant calculations
*/

# include <iostream>
# include <string>
# include <iomanip>
using namespace std;


int main() {
	
	// program will contiue to loop until use inputs character q
	
	while (true) {
		
	  char option=' ';
		
	  cout << "Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: ";
	  cin >> option;
	  cout << endl;
	  
	   // lowers user input to lowercase character
	  
	  option = tolower(option);
	  
	  // returns ordering advice to user
	  
	  if (option=='a') {
	  	
	    cout << "You can't go wrong with ordering tacos, I personally love them.\n";
	    cout << endl;
	  }
	  
	  // BMI calcuator
	  
	  else if (option=='b') {
	  	
	    int height{},
	    	weight{};
	    double bmi{};
	    
	    cout << "Please enter your height in inches: \n";
	    cin >> height;
	    
	    cout << "Please enter your weight in pounds: \n";
	    cin >> weight;
	    
	    bmi =  (static_cast<double>(weight) / (height * height) * 703);
	    
	    cout << "Your BMI is: " << bmi << endl;
	    cout << endl;
	    
	    
	  }
	  
	  // calorie counter 
	  
	  else if (option=='c') {
	  	
	    // num set to value of 1.0 to intialize while loop
	    
		float num = 1.0,
			  sum{};
	
		while(num != 0) {
			
			cout << "Enter number of calories consumed: ";
			cin >> num;
			
			sum += num;
		}
		
		cout << "Your total number of calories consumed is: " << sum << endl;
		cout << endl;
	    
	  }
	  
	  // program calucates bill total given food cost and tip percentage
	  
	  else if (option=='d') {
	  	
	    double food_cost{},
	    	   tip_percent{},
	    	   total{};
	    const double TAX_RATE = 0.0825;
	    
	    cout << "What was the total cost of the food ordered? ";
	    cin  >> food_cost;
	    
	    cout << "What percentage do you wish to tip? (enter intger number only) ";
	    cin  >> tip_percent;
	    
	    // tip will be applied to cost of food with tax
	    
	    total = (food_cost * (1 + TAX_RATE)) * (1 + (tip_percent / 100 ));
	    
	    // setprecision(2) rounds total to 2 decimal values
	    
	    cout << "The total amount due is: " << fixed << setprecision(2) << "$" << total << endl;
	    cout << endl;
	    
	    
	  }
	  
	  // escape out of while loop
	  
	  else if (option=='q')
	    break; 
	  else {
	  
	    // invalid option entered, display an error message
	    
	    cout << "Invalid option, please try again." << endl;
	    cout << endl;
      }
    
    
   }

return 0;

}

/*
Test of program running output: 

Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: a

You can't go wrong with ordering tacos, I personally love them.

Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: b

Please enter your height in inches:
70
Please enter your weight in pounds:
185
Your BMI is: 26.5418

Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: c

Enter number of calories consumed: 1000
Enter number of calories consumed: 500
Enter number of calories consumed: 250
Enter number of calories consumed: 250
Enter number of calories consumed: 0
Your total number of calories consumed is: 2000

Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: d

What was the total cost of the food ordered? 24.33
What percentage do you wish to tip? (enter intger number only) 20
The total amount due is: $31.60

Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: g

Invalid option, please try again.

Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: h

Invalid option, please try again.

Options (enter one letter): a)dvice b)mi c)alories d)ue q)uit: Q


--------------------------------
Process exited after 49.54 seconds with return value 0
Press any key to continue . . .
*/