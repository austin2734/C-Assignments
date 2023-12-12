/*
  Author:          Austin Riggs
  Assignment:      Lab 10
  Topic:           pointers, objects in memory: stack, heap; data structures
  Course/Section:  COSC 1337
  Due Date:        See syllabus or blackboard
  Instructor:      Thayer
  Purpose:
  Show understanding of objects in memory using: values, addresses, pointers, stack, heap;
  dynamic memory allocation using new, delete, delete []. Get introduction to linked data structures
  using a singly linked list.

  Use C++ to construct a memory layout as shown in a specified memory diagram.
  Use startup code with useful macros to display variables: names, values, addresses.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Helpful macros to make it easier to output name, address, and value of a variable
// You may use these, or write your own to do something similar
#define show_addr(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<<  (void*) &(var) <<endl;

#define show_addr_value(var, width) \
  cout<<"address of " <<setw(width)<<left<<#var<<" is: &"<< (void*) &(var)<<"  "     \
      <<"contents of "<<setw(width)<<left<<#var<<" is: "<<var<<endl;

#define show_name_addr_value(var) \
  cout<<"name: "<<#var<<"  address: &"<<  (void*) &(var) <<"  value: " << var << endl;

#define show_name_addr_value_sizeof(var) \
  cout<<"name: "<<#var<<"  address: &"<< (void*) &(var)<<"  value: " << var << "  sizeof: " << sizeof(var) << endl;

#define show_name_addr_value_deref(var) \
  cout<<"name: "<<#var<<"  address: &"<<  (void*) &(var)<<"  value: " << var \
      << "  *" << #var << ": " << *var << endl;

class Letter { // modify class Letter if desired to provide constructors, etc.
  public:
    Letter(char, string); // constructor
    char   ch{};       // character of the Letter
    string mnemonic; // memory aid for the Letter
    Letter *next;    // pointer to the next Letter in the list

    string to_string() const {
      return string{ch} + "=" + mnemonic;
    }
};

// constructor definition for Letter
Letter::Letter(char c=' ', string m=" ") {
 ch = c;
 mnemonic = m;
}


int main () {
  cout << "Output from Lab 10 memory diagram on pointers:\n\n";

  char        junk__c;
  bool        junk__b;
  short       junk__s;
  int         junk__i;
  float       junk__f;
  double      junk__d;
  long double junk_ld;
  show_name_addr_value_sizeof(junk__c);
  show_name_addr_value_sizeof(junk__b);
  show_name_addr_value_sizeof(junk__s);
  show_name_addr_value_sizeof(junk__i);
  show_name_addr_value_sizeof(junk__f);
  show_name_addr_value_sizeof(junk__d);
  show_name_addr_value_sizeof(junk_ld);

  cout << endl;

  float price = 0;
  float *p_price = &price;
  *p_price = 14.85;
  show_name_addr_value_sizeof(price);
  show_name_addr_value_sizeof(p_price);
  show_name_addr_value_deref(p_price);
  cout << "The contents of *p_price is: " << *p_price << endl << endl;

   // variables PI, PI_div_2, and pointer *p_PI
  double PI{};
  double PI_div_2{};
  double *p_PI = &PI;
  *p_PI = 3.141592;
  PI_div_2 = *p_PI / 2;
  show_addr_value(PI, 8);
  show_addr_value(PI_div_2, 8);
  show_addr_value(p_PI, 8);
  cout << "The contents of *p_PI is:    " << *p_PI << endl << endl;

  // variable ACCeID and pointer p_ACCeID
  int ACCeID{};
  int *p_ACCeID = &ACCeID;
  *p_ACCeID = 2074323;
  show_addr_value(ACCeID, 8);
  show_addr_value(p_ACCeID, 8);
  cout << "The contents of *p_ACCeID is: " << *p_ACCeID << endl << endl;

  // pointer p_amount
  int *p_amount = new int;
  *p_amount = 1918;
  show_addr_value(p_amount, 8);
  cout << "The contents of *p_amount is: " << (dec) << *p_amount << endl;
  delete p_amount;
  cout << "After delete, the contents of p_amount is: " << p_amount << endl;
  p_amount = nullptr;
  cout << "After reset to nullptr, the contents of p_amount is: " << p_amount << endl << endl;

  // pointer pArray1
  int *pArray1 = new int[3];
  pArray1[0] = 404;
  pArray1[1] = 505;
  pArray1[2] = 606;
  show_addr_value(pArray1,8);
  show_addr_value(pArray1[0],8);
  show_addr_value(pArray1[1],8);
  show_addr_value(pArray1[2],8);
  delete [] pArray1;
  cout << "After delete [], the contents of pArray is: " << pArray1 << endl;
  pArray1 = nullptr;
  cout << "After reset to nullptr, the contents of pArray1 is: " << pArray1 << endl << endl;

   // Array2 and pointer pArray2
  int Array2[2];
  int *pArray2 = Array2;
  pArray2[0] = 1001;
  pArray2[1] = 2002;
  show_addr_value(pArray2,8);
  show_addr_value(pArray2[0],8);
  show_addr_value(pArray2[1],8);
  cout << "No need to delete Array2, it is on the stack, not the heap" << endl << endl;

   // big_buffer pointer to array and buffer_end pointer
  double *big_buffer = new double[ACCeID];
  double *buffer_end = (big_buffer + (ACCeID - 1));
  show_addr_value(big_buffer, 8);
  show_addr_value(buffer_end, 8);
  delete [] big_buffer;
  cout << "After delete [], the contents of big_buffer is: " << big_buffer << endl;
  cout << "After delete, the contents of buffer_end is: " << buffer_end << endl;
  big_buffer = nullptr;
  cout << "After reset to nullptr, the contents of big_buffer is: " << big_buffer << endl;
  buffer_end = nullptr;
  cout << "After reset to nullptr, the contents of buffer_end is: " << buffer_end << endl << endl;

  // emptyList pointer
  Letter *emptyList{};
	show_addr_value(emptyList, 8);
  cout << endl;

  // zed object
  cout<<"static (uses: Letter zeta):\n";
  Letter zed{'Z', "zeta"};
  cout << zed.to_string() << endl;
  show_addr_value(zed.ch, 8);
  show_addr_value(zed.mnemonic, 8);
  show_addr_value(zed.next, 8);
  cout << endl;

  // p_initials pointer to Letter object A
  cout<<"dynamic (uses: p_initials, Letter(\"alpha\"), Letter(\"romeo\"):\n";
  Letter *p_initials = new Letter('A', "alpha");
  cout << p_initials -> to_string() << endl;
  show_addr_value(p_initials, 8);
  show_addr_value(p_initials -> ch, 8);
	show_addr_value(p_initials -> mnemonic, 8);
	show_addr_value(p_initials -> next, 8);
	cout << endl;

	// next pointer to Letter R
	p_initials -> next = new Letter('R', "romeo");
	cout << p_initials -> next -> to_string() << endl;
	show_addr_value(p_initials -> next -> ch, 8);
	show_addr_value(p_initials -> next -> mnemonic, 8);
  show_addr_value(p_initials -> next -> next, 8);
  cout << endl;

   // deletion of linked lists in memory dynamically allocated
  delete p_initials -> next;
  cout << "After delete, the contents of p_initials -> next is: " << p_initials -> next << endl;
  p_initials -> next = nullptr;
  cout << "After reset to nullptr, the contents of p_initials -> next is: " << p_initials -> next << endl;
  delete p_initials;
  cout << "After delete, the contents of p_initials is: " << p_initials << endl;
  p_initials = nullptr;
  cout << "After reset to nullptr, the contents of p_initials is: " << p_initials << endl;

  return 0;
} // end of main

/*
Program Output :


Output from Lab 10 memory diagram on pointers:

name: junk__c  address: &0x7bfd1f  value:    sizeof: 1
name: junk__b  address: &0x7bfd1e  value: 0  sizeof: 1
name: junk__s  address: &0x7bfd1c  value: 32764  sizeof: 2
name: junk__i  address: &0x7bfd18  value: -1889883514  sizeof: 4
name: junk__f  address: &0x7bfd14  value: 0  sizeof: 4
name: junk__d  address: &0x7bfd08  value: 1.32657e-315  sizeof: 8
name: junk_ld  address: &0x7bfcf0  value: -5.25649e-1521  sizeof: 16

name: price  address: &0x7bfcec  value: 14.85  sizeof: 4
name: p_price  address: &0x7bfce0  value: 0x7bfcec  sizeof: 8
name: p_price  address: &0x7bfce0  value: 0x7bfcec  *p_price: 14.85
The contents of *p_price is: 14.85

address of PI       is: &0x7bfcd8  contents of PI       is: 3.14159
address of PI_div_2 is: &0x7bfcd0  contents of PI_div_2 is: 1.5708
address of p_PI     is: &0x7bfcc8  contents of p_PI     is: 0x7bfcd8
The contents of *p_PI is:    3.14159

address of ACCeID   is: &0x7bfcc4  contents of ACCeID   is: 2074323
address of p_ACCeID is: &0x7bfcb8  contents of p_ACCeID is: 0x7bfcc4
The contents of *p_ACCeID is: 2074323

address of p_amount is: &0x7bfcb0  contents of p_amount is: 0xd61460
The contents of *p_amount is: 1918
After delete, the contents of p_amount is: 0xd61460
After reset to nullptr, the contents of p_amount is: 0

address of pArray1  is: &0x7bfca8  contents of pArray1  is: 0xd61460
address of pArray1[0] is: &0xd61460  contents of pArray1[0] is: 404
address of pArray1[1] is: &0xd61464  contents of pArray1[1] is: 505
address of pArray1[2] is: &0xd61468  contents of pArray1[2] is: 606
After delete [], the contents of pArray is: 0xd61460
After reset to nullptr, the contents of pArray1 is: 0

address of pArray2  is: &0x7bfc98  contents of pArray2  is: 0x7bfca0
address of pArray2[0] is: &0x7bfca0  contents of pArray2[0] is: 1001
address of pArray2[1] is: &0x7bfca4  contents of pArray2[1] is: 2002
No need to delete Array2, it is on the stack, not the heap

address of big_buffer is: &0x7bfc90  contents of big_buffer is: 0xd75040
address of buffer_end is: &0x7bfc88  contents of buffer_end is: 0x1d486d0
After delete [], the contents of big_buffer is: 0xd75040
After delete, the contents of buffer_end is: 0x1d486d0
After reset to nullptr, the contents of big_buffer is: 0
After reset to nullptr, the contents of buffer_end is: 0

address of emptyList is: &0x7bfc80  contents of emptyList is: 0

static (uses: Letter zeta):
Z=zeta
address of zed.ch   is: &0x7bfc50  contents of zed.ch   is: Z
address of zed.mnemonic is: &0x7bfc58  contents of zed.mnemonic is: zeta
address of zed.next is: &0x7bfc78  contents of zed.next is: 0x4b2bf0

dynamic (uses: p_initials, Letter("alpha"), Letter("romeo"):
A=alpha
address of p_initials is: &0x7bfc48  contents of p_initials is: 0xd61460
address of p_initials -> ch is: &0xd61460  contents of p_initials -> ch is: A
address of p_initials -> mnemonic is: &0xd61468  contents of p_initials -> mnemonic is: alpha
address of p_initials -> next is: &0xd61488  contents of p_initials -> next is: 0xd60150

R=romeo
address of p_initials -> next -> ch is: &0xd61a50  contents of p_initials -> next -> ch is: R
address of p_initials -> next -> mnemonic is: &0xd61a58  contents of p_initials -> next -> mnemonic is: romeo
address of p_initials -> next -> next is: &0xd61a78  contents of p_initials -> next -> next is: 0x5c6172694b5c7372

After delete, the contents of p_initials -> next is: 0xd61a50
After reset to nullptr, the contents of p_initials -> next is: 0
After delete, the contents of p_initials is: 0xd61460
After reset to nullptr, the contents of p_initials is: 0

--------------------------------
Process exited after 0.04547 seconds with return value 0
Press any key to continue . . .
*/