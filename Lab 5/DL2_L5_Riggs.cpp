#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;


int main() {
	
	ifstream temp_file("lohiF.txt");
	int low_temp{}, // holds monthly low temp
		high_temp{}, // holds monthly high temp
		temp_diff{}, // holds difference in high and low temps
		month_count = 1; // used to show month count in bar chart
		
	const int FREEZING = 32; // temp in F where water freezes
	
	if (temp_file) {
		
		string data_description{}; // holds data description string from lohiF.txt
		getline(temp_file, data_description); 
		
		cout << "Austin's bar chart:" << endl << endl; 	
		cout << data_description << endl << endl;
		
		while(!temp_file.eof()) {
			
			temp_file >> low_temp; 
			temp_file >> high_temp;
			temp_diff = high_temp - low_temp;
			
			cout << month_count << setw(low_temp - FREEZING) << "(" << low_temp << " F)";
			cout << string(temp_diff, '*') << "("  << high_temp << " F)" << endl;
			
			month_count++; 
		}
	}
	
	else {
			cout << "Error: Unable to locate text file.";	// exception handling when file is not found
		}
	
	return 0;	
}

/*

Program output -

Austin's bar chart:

Austin Average Monthly low high Temperatures (Fahrenheit) Years 2010 - 2019

1        (41 F)**********************(63 F)
2             (46 F)*********************(67 F)
3                    (53 F)**********************(75 F)
4                          (59 F)**********************(81 F)
5                                  (67 F)********************(87 F)
6                                         (74 F)********************(94 F)
7                                           (76 F)**********************(98 F)
8                                           (76 F)************************(100 F)
9                                       (72 F)*********************(93 F)
10                            (61 F)**********************(83 F)
11                 (50 F)**********************(72 F)
12           (44 F)********************(64 F)

--------------------------------
Process exited after 0.07966 seconds with return value 0
Press any key to continue . . .
*/