#include <iostream>
#include <string>
using namespace std; 


int main() {
	
	int input{};
	
	cout << "Please enter an integer: ";
	cin >> input;
	
	for (int row{1}; row <= input; row++) {
		cout << "*";
	}
	cout << endl << endl;
	
	
	for (int row{1}; row <= input; row++) {
		cout << "*\n";
	}
	
	cout << endl << endl;
	
	for (int row{1}; row <= input; row++){ 
	
		cout << string(row-1, ' ') << "*\n";
    }
    
    cout << endl << endl;
    
    for (int row{1}; row <= input; row++){
    	
    	cout << string( input - row, ' ') << "*\n"; 
	}
	
	cout << endl << endl;
	
	for (int row{1}; row <= input; row++){
		
		for (int col{1}; col <= input; col++) {
			
			cout << "*";
		}
		
		cout << endl;
	}
	
	cout << endl <<endl;
	
	for (int row{1}; row <= input; row++) {
		
		cout << string(row, '*') << endl;
	}
	
	cout << endl << endl;
	
	
	for (int row{1}; row <= input; row++) {
		
		cout << string(row * 2 - 1, '*' ) << endl;
	}
	
	cout << endl << endl;
	
	for (int row{1}; row <= input; row++) {
		
		cout << string( input - row, ' ') << string(row, '*') << endl;
	}
	
	cout << endl << endl;
	
	for (int row{1}; row <= input; row++) {
		
	
		
		if (row <= 1 + (input / 2)) {
			
			cout << string(row * 2 - 1, '*') << endl;
		}
		
		else {
			
		 	cout << string( ((input - row) * 2) + 1, '*') << endl;
		}
		
	}
	
	cout << endl << endl;
	
	
	for (int row{1}; row <= input; row++) {
		
		cout << string(input - row, ' ') << string(row * 2 - 1 , '*') << string(input - row, ' ') << endl;
	}
	
	cout << endl << endl;
	
	
	for (int row{1}; row <= input; row++) {	
	
		if (row == input) {
			
			cout << string(row - 1, ' ') << '*' << string(row - 1, ' ') << endl;
			break;
		}
		
		cout << string(row -1, ' ') << '*' << string((input - row - 1) * 2 + 1, ' ') << '*' << string(row-1, ' ') << endl; 
		
		
	}
	
	cout << endl << endl;
	
	
	for (int row{1}; row <= input; row++) {	
	
		if (row == ( 1 + (input / 2))) {
			
			cout << string(row - 1, ' ') << '*' << string(row - 1, ' ') << endl;
			continue;
		}
		
		if (row > (input / 2)) {
			
			cout << string(input - row, ' ') << '*' << string( (row * 2) - input -2,  ' ') << '*' << string(input - row, ' ') << endl;
			continue;
		}
		
		
		cout << string(row - 1, ' ') << string(1,'*') << string(input - (row * 2), ' ')<< string(1,'*') << string(row - 1, ' ') << endl; 
	

    }
	
	
}

 