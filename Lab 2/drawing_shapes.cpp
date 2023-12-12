/*
  Author:
  Course: COSC 1337 Semester:     Section:   ;  Instructor: Thayer
  Lab: 2  Purpose:  Draw 1 arrow and 2 letter shapes with variable height.
*/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
  cout<<"This program draws characters. Select character, then height(s)\n";
  const string PROMPT{"how many rows tall? (0 to quit): "};

  bool running{true};
  while (running) {
    cout << "\nOption: b)box /)/ \\)\\ q)quit? (q to quit): ";
    char option{}; cin>>option;

    if (option=='b') { // box
      while (true) {
        cout << "([box]) " << PROMPT;
        int rows=0;
        cin >> rows;
        if (rows<=0) break;
        for (int row{1}; row<=rows; ++row) { // for each row
          for (int col{1}; col<=rows; ++col) { // for each column
            cout << '*';
          }
          cout<<endl; // next row
        }
        cout<<endl;
      }
    }

    else if (option=='/') { // forward slash
      while (true) {
        cout << "(/) " << PROMPT;
        int rows=0;
        cin >> rows;
        if (rows<=0) break;
        for (int row{1}; row<=rows; ++row) {
          cout << string(rows-row, ' ') << "*\n";
        }
        cout<<endl;
      }
    }

    else if (option=='\\') { // back slash
      while (true) {
        cout << "(\\) " << PROMPT;
        int rows=0;
        cin >> rows;
        if (rows<=0) break;
        for (int row{1}; row<=rows; ++row) { // backslash
          cout << string(row-1, ' ') << "*\n";
        }
        cout<<endl;
      }
    }

    else if (option=='q') {
      break;
    }

    else {
      cout<<"Invalid option, try again.\n";
    }
  }

  cout<<"Goodbye\n";
  return 0;
}

/*

*/