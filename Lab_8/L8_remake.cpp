
/*
  Programmer / author:	Austin Riggs
  Assignment:           Lab 8
  Topic:                Create game Wordlet where user guesses characters of hidden word
  File Name:            DL2_L8_Riggs.cpp
  Course/Section:       COSC 1337; Section DL2
  Due Date:             6/30/2022
  Instructor:           Thayer
*/
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
using namespace std;

class Wordlet {  // Holds indiviual words for Wordlet game
  private:
    string word;
  public:
    Wordlet(const string&, int);
    string getWord() const
    { return word;}
    void setWord(const string&, int);
};

 // contructor for Wordlet - defaults to "error" if word not provided,
 // SIZE defaults to 5, word can only be 5 characters in length or is set to "error"
Wordlet::Wordlet(const string &w="error", int SIZE=5) {
  if (w.size() == SIZE)
  { word = w; }
  else
  { word = "error";}
}

void Wordlet::setWord( const string &w, int SIZE) { // sets word in Wordlet object
  if(w.size() == SIZE) word = w;
}

void gamePrompt(); // outputs start of game message to user
string getGuess(const string&, int); // gets guess word of user, validates guess word
bool compareWords(const string&, const string&); // compares obj word and user guess word
string lowerString(const string&); // lowers user guess word to all lowercase characters
void calcScore(double, int); // calculates user score after playing game



int main() {

  const int WORD_LENGTH{5}; // max length a word can be in wordlet
  const int ARRAY_LENGTH{7}; // max length word_list array can be
  int array_index{}; // keeps track of current index in array
  int count{1}; // used to output to user which word they are in game
  vector<string> guesses; // holds user guesses
  double score{}; // keeps track of words user guessed correctly

  // creates and stores words in 7 Wordlet objects - ARRAY_LENGTH limits the array from being longer than 7
  // obj elements
  Wordlet word_list[ARRAY_LENGTH] =	{Wordlet("fuzzy", WORD_LENGTH),
                                     Wordlet("apple", WORD_LENGTH),
						             Wordlet("dream", WORD_LENGTH),
									 Wordlet("earth", WORD_LENGTH),
									 Wordlet("sleep", WORD_LENGTH),
									 Wordlet("brave", WORD_LENGTH),
									 Wordlet("drive", WORD_LENGTH)};


    gamePrompt(); // outputs game instructions to user

    while(array_index < ARRAY_LENGTH) { // will loop for length of array

    string current_word = word_list[array_index].getWord();
	cout << "Hint - " << current_word << endl << endl;
    cout << "Word #" << count << endl;
    cout << "Enter s to skip to the next word or q to quit Wordlet" << endl;

    // function call to getGuess to get guess word from user, WORD_LENGTH limits max guess length
    string guess = getGuess("Enter your 5 letter guess: ", WORD_LENGTH);

    if (guess == "q") break; // quits program if input is q
    else if (guess == "s") { // skips to next Wordlet object in array
      cout << "\nSkipping to next word.\n\n";
      array_index++; // array index incremented
      count++; // current word # incremented
      continue;
	}

    // holds all of user guesses
    guesses.push_back(guess);

	// call to compareWords function, obj word and user guess taken as arguements. returns true
	// if words match, else returns false
	if (compareWords(current_word, guess)) { // if true, skips to next obj word in array
	  cout << "Correct!\n" << endl;

	  score++; // score incremented
      array_index++;
      count++;
      continue; //
	}
	else { // else, program will not update any counters and will remain on current word
	  continue;
	}
  }

  // outputs all of user guesses during game
  if (score > 0) {
    cout << "Here are the words that you guessed or got correct:" << endl << endl;
  for (int i{}; i < guesses.size(); i++){
    cout << guesses[i] << endl;
  }
  }

  calcScore(score, ARRAY_LENGTH); // calcuates user final score

  cout << "\nThanks for playing Austin's verison of Wordlet!\n";

  return 0;

} // end of main


// begining message to game - NOTE: I know this could go in main but seems cleaner here
void gamePrompt() {
  cout << "Welcome to Austin's verison of Wordlet!" << endl << endl;
  cout << "Game Discription:" << endl;
  cout << "This game is similar to the game Wordle, where you will try to correctly guess a hidden word. " << endl
       << "For each attempt, you will be shown:" << endl
	   << "* If the position of the letter in your guessed word was correct." << endl
	   << "* If the a letter in your guessed word is in the hidden word." << endl
	   << "* If a letter in the guessed word is not in the hidden word." << endl
	   << "Good luck!" << endl << endl;
}


// function to get and validate user guess word
string getGuess(const string &prompt, int word_length) {
  string value;
  while(true) {
    cout << prompt;
    cin >> value;
    value = lowerString(value); // call to lowerString funciton, lowers user input
    if (value == "q" || value == "s") break; // break if user wishes to quit game or skip word
    else if (value.size() == word_length) break; // validates that guess word is correct length
    else {
      cin.clear(); cin.ignore(INT_MAX, '\n'); // clears cin
	  cout << "ERROR: Please enter " << word_length << " character word." << endl; // error message
    }
  }
  return value;
}
// function compares two words to find if guess word letters are in correct position relative to obj word,
// if any of the letters of the guess word are in the obj word, and if letters in guess word are not in obj word
bool compareWords(const string &word, const string &guess) {

  int match{}, // holds count of letters in correct position to obj word
      in_word{}, // holds count of letters that are in both words
      not_in_word{}; // hold count of letters that are not in obj word but in guess word
  bool matched{};
  string symbol{}; // used for character map output to user

  //  enum type used for character map / symbol output to visually show user which letters are correct, in word
  // or not in word.
  enum Symbols{Correct='!', InWord='?', Incorrect='X'};

  // checks to see if letters at [i] are the same
  for (int i{}; i < word.size(); i++) {
    if (word[i] == guess[i]) {
      match++;
      symbol += Correct; // '!' character added to symbol variable
    }
    else { // if letters at [i] do not match
      int no_match{}; // holds count of letters that do not match guess[i]
      for (int j{}; j < guess.size(); j++) {
        if(word[j] == guess[i] ) { // if letter match
          in_word++;
          symbol += InWord; // adds '?' to symbol variable
          break;
	    }
	    else {
          no_match++;
	    }
      }
	if(no_match == word.size()) { // if no_match = length of the word, guess letter not in obj word
          not_in_word++;
          symbol += Incorrect; // adds 'X' to symbol variable
	    }
   }
  }
    // outputs results of compare words and outputs symbol (Character Map) to user
    cout << "Number of correct letters in right position: " << match << endl << "Number of correct letters "
         << "in wrong position: "<< in_word << endl << "Number of letters not in word: " << not_in_word << endl
		 << "Character map: "<< symbol << endl << endl;

   if(match == word.size()){ // if match = length of word, guess word is correct
     matched = true;
   }
   return matched;
}

// iterates over string, lowers each character and returns new word
string lowerString(const string &user_input) {
  string lowered;
  for (int i{}; i < user_input.size(); i++) {
    lowered += tolower(user_input[i]);

  }

  return lowered;
}

// calculates final score to user
void calcScore(double score, int ARRAY_LENGTH) {

  double percent_correct{},
         one_hundred = 100.00; // used for percentage calculation

  if(score != 0) { // keeps divide by zero error from occuring

    percent_correct = one_hundred * (score / ARRAY_LENGTH);
  }

  cout << "\nFinal Score: " << score << " out of " << ARRAY_LENGTH << " correct. " << endl
       << "Percentage Score: " << setprecision(2) << fixed << percent_correct << "%\n";
}

// Test Output Below:
/*
#######################################################################################################################

Test 1 - normal operation

Welcome to Austin's verison of Wordlet!

Game Discription:
This game is similar to the game Wordle, where you will try to correctly guess a hidden word.
For each attempt, you will be shown:
* If the position of the letter in your guessed word was correct.
* If the a letter in your guessed word is in the hidden word.
* If a letter in the guessed word is not in the hidden word.
Good luck!

Hint - fuzzy

Word #1
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: bananas
ERROR: Please enter 5 character word.
Enter your 5 letter guess: w
ERROR: Please enter 5 character word.
Enter your 5 letter guess: 1234
ERROR: Please enter 5 character word.
Enter your 5 letter guess: qwert
Number of correct letters in right position: 0
Number of correct letters in wrong position: 0
Number of letters not in word: 5
Character map: XXXXX

Hint - fuzzy

Word #1
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: banks
Number of correct letters in right position: 0
Number of correct letters in wrong position: 0
Number of letters not in word: 5
Character map: XXXXX

Hint - fuzzy

Word #1
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: yuzzf
Number of correct letters in right position: 3
Number of correct letters in wrong position: 2
Number of letters not in word: 0
Character map: ?!!!?

Hint - fuzzy

Word #1
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: fubby
Number of correct letters in right position: 3
Number of correct letters in wrong position: 0
Number of letters not in word: 2
Character map: !!XX!

Hint - fuzzy

Word #1
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: fuzzy
Number of correct letters in right position: 5
Number of correct letters in wrong position: 0
Number of letters not in word: 0
Character map: !!!!!

Correct!

Hint - apple

Word #2
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: apple
Number of correct letters in right position: 5
Number of correct letters in wrong position: 0
Number of letters not in word: 0
Character map: !!!!!

Correct!

Hint - dream

Word #3
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: dream
Number of correct letters in right position: 5
Number of correct letters in wrong position: 0
Number of letters not in word: 0
Character map: !!!!!

Correct!

Hint - earth

Word #4
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: earth
Number of correct letters in right position: 5
Number of correct letters in wrong position: 0
Number of letters not in word: 0
Character map: !!!!!

Correct!

Hint - sleep

Word #5
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: s

Skipping to next word.

Hint - brave

Word #6
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: s

Skipping to next word.

Hint - drive

Word #7
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: s

Skipping to next word.

Here are the words that you guessed or got correct:

qwert
banks
yuzzf
fubby
fuzzy
apple
dream
earth

Final Score: 4 out of 7 correct.
Percentage Score: 57.14%

Thanks for playing Austin's verison of Wordlet!



#######################################################################################################################

Test 2 - Test of uppercase characters in guess words

Welcome to Austin's verison of Wordlet!

Game Discription:
This game is similar to the game Wordle, where you will try to correctly guess a hidden word.
For each attempt, you will be shown:
* If the position of the letter in your guessed word was correct.
* If the a letter in your guessed word is in the hidden word.
* If a letter in the guessed word is not in the hidden word.
Good luck!

Hint - fuzzy

Word #1
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: FUZZy
Number of correct letters in right position: 5
Number of correct letters in wrong position: 0
Number of letters not in word: 0
Character map: !!!!!

Correct!

Hint - apple

Word #2
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: APPLE
Number of correct letters in right position: 5
Number of correct letters in wrong position: 0
Number of letters not in word: 0
Character map: !!!!!

Correct!

Hint - dream

Word #3
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: dreaM
Number of correct letters in right position: 5
Number of correct letters in wrong position: 0
Number of letters not in word: 0
Character map: !!!!!

Correct!

#######################################################################################################################

Test 3 - quitting program without answering a question

Welcome to Austin's verison of Wordlet!

Game Discription:
This game is similar to the game Wordle, where you will try to correctly guess a hidden word.
For each attempt, you will be shown:
* If the position of the letter in your guessed word was correct.
* If the a letter in your guessed word is in the hidden word.
* If a letter in the guessed word is not in the hidden word.
Good luck!

Hint - fuzzy

Word #1
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: q

Final Score: 0 out of 7 correct.
Percentage Score: 0.00%

Thanks for playing Austin's verison of Wordlet!



########################################################################################################################

Test 4 - creating a Wordlet obj with default values or if input word is more than 5 characters in length

Welcome to Austin's verison of Wordlet!

Game Discription:
This game is similar to the game Wordle, where you will try to correctly guess a hidden word.
For each attempt, you will be shown:
* If the position of the letter in your guessed word was correct.
* If the a letter in your guessed word is in the hidden word.
* If a letter in the guessed word is not in the hidden word.
Good luck!

Hint - error

Word #1
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess: error
Number of correct letters in right position: 5
Number of correct letters in wrong position: 0
Number of letters not in word: 0
Character map: !!!!!

Correct!

Hint - apple

Word #2
Enter s to skip to the next word or q to quit Wordlet
Enter your 5 letter guess:


*/
