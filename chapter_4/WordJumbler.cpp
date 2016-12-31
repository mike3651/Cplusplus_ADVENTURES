#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	enum fields {WORD, HINT, NUM_FIELDS};
	const int NUM_WORDS = 5;
	// creates a dictionary
	const string WORDS[NUM_WORDS][NUM_FIELDS] = 
	{
		{"wall", "Do you feel you're banging your head against something?"},
		{"glasses", "These might help you see the answer"},
		{"labored", "Going slowly, is it?"},
		{"persistent", "Keep at it"},
		{"jumble", "It's what the game is about"}
	};

	// chooses a random word
	srand(static_cast<unsigned int>(time(0)));
	int choice = rand() % NUM_WORDS;
	string theWord = WORDS[choice][WORD];
	string theHint = WORDS[choice][HINT];

	// jumble up the word
	string jumble = theWord;
	int length = jumble.size();
	for(int i = 0; i < length; i++) {
		int index1 = rand() % length;
		int index2 = rand() % length;
		char temp = jumble[index1];
		jumble[index1] = jumble[index2];
		jumble[index2] = temp;
	}

	// welcomes the player
	cout << "Welcome to Word Jumble\n"<< endl;
	cout << "Unscrmble the letters to make a word."<< endl;
	cout << "Enter 'hint' for a hint"<< endl;
	cout << "Enter 'quit' to quit the game" << endl;
	cout << "The jumble is: "<< jumble;

	string guess;
	cout << "\n\nYour guess: ";
	cin >> guess;

	// gets the game loop going
	while((guess != theWord) && (guess != "quit")) {
		if(guess == "hint")
			cout << theHint;
		else
			cout << "Sorry that's not it";
		cout << "\n\nYour guess: ";
		cin >> guess;
	}

	if(guess == theWord)
		cout << "you win";
	else
		cout << "You lost );";
	cout << endl;
}