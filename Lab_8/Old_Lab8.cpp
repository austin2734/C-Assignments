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
using namespace std;

class Wordlet {
  private:
    int array_length{};
    int word_length{};
    int word_counter{1};
    int word_index{};
    double score{};
  public:
    Wordlet (int, int, int, int, double);
    int getArrayLength() const
      { return array_length; }
    int getWordLength() const
      { return word_length; }
    int getWordCounter() const
      { return word_counter;}
    int getWordIndex() const
      { return word_index;}
    void setArrayLength(int length)
	  { array_length = length;}
    void setWordLength(int w_length)
      { word_length = w_length;}
    void setWordCounter(int count)
      { word_counter = count;}
    void setWordIndex(int index)
	  { word_index = index;}
	double getScore() const
	  { return score; }
	void setScore( double num)
	  { score = num;}
	void playGame(const string []);
	void gamePrompt();
	void endGamePrompt();
    string getGuess(const string&, int);
    string lowerString(const string&);
    bool compareWords(const string&, const string&);
    void calcScore();
};


Wordlet::Wordlet(int a_length=0,int w_length=0,int w_counter=1,int w_index=0, double g_score=0.0) {
  array_length = a_length;
  word_length = w_length;
  word_counter = w_counter;
  word_index = w_index;
  score = g_score;
}

void Wordlet::gamePrompt() {
  cout << "Welcome to Austin's verison of Wordlet!" << endl << endl;
  cout << "Game Discription:" << endl;
  cout << "This game is similar to the game Wordle, where you will try to correctly guess a hidden word. " << endl
       << "For each attempt, you will be shown:" << endl
	   << "* If the position of the letter in your guessed word was correct." << endl
	   << "* If the a letter in your guessed word is in the hidden word." << endl
	   << "* If a letter in the guessed word is not in the hidden word." << endl
	   << "Good luck!" << endl << endl;
}

void Wordlet::playGame(const string word_list[]) {

    gamePrompt();

    while(word_index < array_length) {

    string current_word = word_list[word_index];
	cout << "Hint - " << current_word << endl << endl;
    cout << "Word #" << word_counter << endl;
    cout << "Enter s to skip to the next word or q to quit Wordlet" << endl;
    string guess = getGuess("Enter your 5 letter guess: ", word_length);

    if (guess == "q") break;
    else if (guess == "s") {
      cout << "\nSkipping to next word.\n\n";
      word_index++;
      word_counter++;
      continue;
	}
	else if (compareWords(current_word, guess)) {
	  cout << "Correct!\n" << endl;
      word_index++;
      word_counter++;
      continue;
	}
	else {
	  continue;
	}
  }
  calcScore();
  endGamePrompt();
}

string Wordlet::lowerString(const string &user_input) {
  string lowered;
  for (int i{}; i < user_input.size(); i++) {
    lowered += tolower(user_input[i]);
  }
  return lowered;
}

string Wordlet::getGuess(const string &prompt, int word_length) {
  string value;
  while(true) {
    cout << prompt;
    cin >> value;
    value = lowerString(value);
    if (value == "q" || value == "s") break;
    else if (value.size() == word_length) break;
    else {
      cin.clear(); cin.ignore(INT_MAX, '\n');
	  cout << "ERROR: Please enter " << word_length << " character word." << endl;
    }
  }
  return value;
}

bool Wordlet::compareWords(const string &word, const string &guess) {

  int match{},
      in_word{},
      not_in_word{};
  bool matched{};
  string symbol{}; // used for character map output to user
  enum Symbols{Correct='!', InWord='?', Incorrect='X'};

  for (int i{}; i < word.size(); i++) {
    if (word[i] == guess[i]) {
      match++;
      symbol += Correct;
    }
    else {
      int no_match{};
      for (int j{}; j < guess.size(); j++) {
        if(word[j] == guess[i] ) {
          in_word++;
          symbol += InWord;
          break;
	    }
	    else {
          no_match++;
	    }
      }
	if(no_match == word.size()) {
          not_in_word++;
          symbol += Incorrect;
	    }
   }
  }
    cout << "Number of correct letters in right position: " << match << endl << "Number of correct letters "
         << "in wrong position: "<< in_word << endl << "Number of letters not in word: " << not_in_word << endl
		 << "Character map: "<< symbol << endl << endl;

   if(match == word.size()){
     matched = true;
     score++;
   }

   return matched;
}

void Wordlet::calcScore() {

  double percent_correct{},
         one_hundred = 100.00;

  if(score != 0) {

    percent_correct = one_hundred * (score / array_length);
  }

  cout << "\nFinal Score: " << score << " out of " << array_length << " correct. " << endl
       << "Percentage Score: " << setprecision(2) << fixed << percent_correct << "%\n";
}

void Wordlet::endGamePrompt() {
  cout << "\nThanks for playing Austin's verison of Wordlet!\n";
}



int main() {

  Wordlet game1;

  string word_list[] = {"fuzzy", "apple", "dream", "earth","sleep", "brave", "drive"};
  game1.setArrayLength({sizeof(word_list) / sizeof(word_list[0])});
  game1.setWordLength(word_list[0].size());


 /* cout << "Welcome to Austin's verison of Wordlet!" << endl << endl;
  cout << "Game Discription:" << endl;
  cout << "This game is similar to the game Wordle, where you will try to correctly guess a hidden word. For each "
       << "attempt, you will be shown if the position of the letter in your guessed word was correct, if the a letter "
	   << "in your guessed word is in the hidden word, or if a letter in the guessed word is not in the hidden word."
	   << " Good luck!" << endl << endl;
*/
  game1.playGame(word_list);
/*while(game1.getWordIndex() < game1.getArrayLength()) {

	string current_word = word_list[word_index];
	cout << current_word << endl;
    cout << "Word #" << word_count << endl;
    cout << "Enter s to skip to the next word or q to quit Wordlet" << endl;
    string guess = getGuess("Enter your 5 letter guess: ", game1.getWordLength());


    if (guess == "q") break;
    else if (guess == "s" ) {
      cout << "\nSkipping to next word.\n\n";
      word_index++;
      word_count++;
      continue;
	}

	else if (compareWords(current_word, guess)) {
	  cout << "Correct!" << endl;
      word_index++;
      word_count++;
      continue;

	}
	else {
	  continue;
	}

  }
  */

  // << "\nThanks for playing Austin's verison of Wordlet!\n";
  return 0;
}




/*

string getGuess(const string &prompt, int word_length) {
  string value;
  while(true) {
    cout << prompt;
    cin >> value;
    value = lowerString(value);
    cout << "Value: " << value << " val size: " << value.size() << endl;
    if (value == "q" || value == "s") break;
    else if (value.size() == word_length) break;
    else {
      cin.clear(); cin.ignore(INT_MAX, '\n');
	  cout << "ERROR: Please enter " << word_length << " character word." << endl;
    }
  }
  return value;
}

string lowerString(const string &user_input) {
  string lowered;
  for (int i{}; i < user_input.size(); i++) {
    lowered += tolower(user_input[i]);

  }

  return lowered;
}
*/