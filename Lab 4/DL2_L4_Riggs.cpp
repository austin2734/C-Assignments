
/*
  Author: Austin Riggs;  Course: COSC 1337 Summer 2022 DL2;  Instructor: Thayer;
  Lab: 04;  Purpose: Food ordering program that totals price and calorie count of user menu choices
*/

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	
	enum Food{Burger = 'b', Fries = 'f', Milk_shake = 'm', Pancake = 'p', Order = 'o', Clear = 'c', Quit = 'q'};
	
	Food option{}; // "Food" type variable to hold user input converted from user_choice variable 
	char user_choice{}; // Holds user input from menu options
	
	int burger_count{}, // variables to hold various program counts or totals
	    fries_count{},
	    milk_shake_count{},
		pancake_count{},
		calorie_total{};
		
	double price_total = 0.00; // Holds price total
	
	bool ordering = true;
	bool quit_order = false; // flag used when user quits program 
	
	const double BURGER = 5.00, // Food costs
				 	 FRIES = 3.00,
	             MILK_SHAKE = 4.00,
				    PANCAKE = 4.00;
				 
	const int B_CALS = 540, // Food calorie counts
		  	  F_CALS = 490,
		      M_CALS = 820,
		      P_CALS = 410;
	
	cout << "Welcome to Austin's Burgers and Pancakes! What can I get for you today?" << endl;
	
	while(ordering) {
		cout << "Current order: " << "Burgers:" << burger_count << " Fries:" << fries_count << " Milkshakes:";  // user menu
		cout << milk_shake_count << " Pancakes:" << pancake_count << endl;
		cout << "Current order total: $" << setprecision(2) << fixed << price_total;
		cout << " Calories: " << calorie_total << endl;
		cout << "Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit "; 
		cin  >> user_choice;
		
		option = static_cast<Food>(tolower(user_choice)); // lowers character of user input and converts type from char to "Food"
		
		if (option == 'q') { // clears price total and quits program
		
			quit_order = true;
			break;
		}
		if (option == 'o') break;  // quits program keeping price_total amount
		
		switch(option) {
			
			case  Burger: 	cout << "Burger added to your order!" << endl;
						price_total += BURGER;
						calorie_total += B_CALS;
						burger_count++;
						break;
						
			case  Fries:   cout << "Fries added to your order!" << endl;
						price_total += FRIES;
						calorie_total += F_CALS;
						fries_count++;
						break;
			
			case  Milk_shake :	cout << "Milkshake added to your order!" << endl;
						price_total += MILK_SHAKE;
						calorie_total += M_CALS;
						milk_shake_count++;
						break;
						
			case Pancake :   cout << "Pancake added to your order!" << endl;
						price_total += PANCAKE;
						calorie_total += P_CALS;
						pancake_count++;
						break;
						
			case 'c':	cout << "Your order has been cleared!" << endl; // clears all program accumulators
						price_total = 0;
						calorie_total = 0;
						burger_count = 0;
						fries_count = 0;
						milk_shake_count = 0;
						pancake_count = 0;
						break;
						
			default: cout << "That is not a vaild option, please try again." << endl; // error message
					    	
		}
	}
	
	if (quit_order) {
		
		cout << "Your order has been succefully canceled. We hope to see you again soon!" << endl;
	}
	
	else {
		
		cout << "Your order total comes to $" << setprecision(2) << fixed << price_total << endl;
		cout << "Thank you for shopping at Austin's Burgers and Pancakes!" << endl;
	}
	
	
	return 0;
}

/*

Tests of program operation: 


test of order to completion - 

Welcome to Austin's Burgers and Pancakes! What can I get for you today?
Current order: Burgers:0 Fries:0 Milkshakes:0 Pancakes:0
Current order total: $0.00 Calories: 0
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit m
Milkshake added to your order!
Current order: Burgers:0 Fries:0 Milkshakes:1 Pancakes:0
Current order total: $4.00 Calories: 820
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit b
Burger added to your order!
Current order: Burgers:1 Fries:0 Milkshakes:1 Pancakes:0
Current order total: $9.00 Calories: 1360
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit b
Burger added to your order!
Current order: Burgers:2 Fries:0 Milkshakes:1 Pancakes:0
Current order total: $14.00 Calories: 1900
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit f
Fries added to your order!
Current order: Burgers:2 Fries:1 Milkshakes:1 Pancakes:0
Current order total: $17.00 Calories: 2390
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit p
Pancake added to your order!
Current order: Burgers:2 Fries:1 Milkshakes:1 Pancakes:1
Current order total: $21.00 Calories: 2800
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit o
Your order total comes to $21.00
Thank you for shopping at Austin's Burgers and Pancakes!

--------------------------------
Process exited after 33.75 seconds with return value 0
Press any key to continue . . .

test of clearing of order - 

Welcome to Austin's Burgers and Pancakes! What can I get for you today?
Current order: Burgers:0 Fries:0 Milkshakes:0 Pancakes:0
Current order total: $0.00 Calories: 0
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit b
Burger added to your order!
Current order: Burgers:1 Fries:0 Milkshakes:0 Pancakes:0
Current order total: $5.00 Calories: 540
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit f
Fries added to your order!
Current order: Burgers:1 Fries:1 Milkshakes:0 Pancakes:0
Current order total: $8.00 Calories: 1030
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit p
Pancake added to your order!
Current order: Burgers:1 Fries:1 Milkshakes:0 Pancakes:1
Current order total: $12.00 Calories: 1440
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit m
Milkshake added to your order!
Current order: Burgers:1 Fries:1 Milkshakes:1 Pancakes:1
Current order total: $16.00 Calories: 2260
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit c
Your order has been cleared!
Current order: Burgers:0 Fries:0 Milkshakes:0 Pancakes:0
Current order total: $0.00 Calories: 0
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit

test of invaild input and quitting program - 

Welcome to Austin's Burgers and Pancakes! What can I get for you today?
Current order: Burgers:0 Fries:0 Milkshakes:0 Pancakes:0
Current order total: $0.00 Calories: 0
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit b
Burger added to your order!
Current order: Burgers:1 Fries:0 Milkshakes:0 Pancakes:0
Current order total: $5.00 Calories: 540
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit f
Fries added to your order!
Current order: Burgers:1 Fries:1 Milkshakes:0 Pancakes:0
Current order total: $8.00 Calories: 1030
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit p
Pancake added to your order!
Current order: Burgers:1 Fries:1 Milkshakes:0 Pancakes:1
Current order total: $12.00 Calories: 1440
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit m
Milkshake added to your order!
Current order: Burgers:1 Fries:1 Milkshakes:1 Pancakes:1
Current order total: $16.00 Calories: 2260
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit c
Your order has been cleared!
Current order: Burgers:0 Fries:0 Milkshakes:0 Pancakes:0
Current order total: $0.00 Calories: 0
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit b
Burger added to your order!
Current order: Burgers:1 Fries:0 Milkshakes:0 Pancakes:0
Current order total: $5.00 Calories: 540
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit g
That is not a vaild option, please try again.
Current order: Burgers:1 Fries:0 Milkshakes:0 Pancakes:0
Current order total: $5.00 Calories: 540
Choices: b)urger f)ries m)ilkshake p)ancake o)rder c)lear q)uit q
Your order has been succefully canceled. We hope to see you again soon!

--------------------------------
Process exited after 102 seconds with return value 0
Press any key to continue . . .

*/

