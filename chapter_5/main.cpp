// Michael Wilson
// This program checks to see if a given string is a valid identifier in c++

#include <iostream>
#include "ctype.h"

using namespace std;

bool isId(string);

int main() {
	string response;
	bool validResponse, finished = false;	
	while(!finished) {
		validResponse = false;
		cout << "Please enter what you believe is a valid C++ identifier: ";
		cin >> response;
		if(isId(response))
			cout << "valid C++ identifier\n\n";
		else
			cout << "invalid identifier\n\n";		
		while(!validResponse) {
			cout << "Enter another identifier?\n'y' for yes & 'n' for no: ";			
			cin >> response;
			cout << "\n\n";
			if(response == "y")
				validResponse = true;
			else if(response == "n")
				validResponse = false;
			else 
				cout << "I couldn't quite get that ):\nPlease try again\n\n";				
		}
	}	
 	return 0;
}


/** Code gathered from the psuedocode of defining languages (Chapter 5)
 * @pre String is of type string
 * @post None.
 * @param theString The string to validate
 * @return true if string is valid, false otherwise */
bool isId(string theString) {
	if(theString.length() == 1) {
		return isalpha(theString[0]) != 0  ? true : false;
	} else if(isalpha(theString[theString.length() - 1]) 
			|| isdigit(theString[theString.length() - 1])) 
		return isId(theString.substr(0, theString.length() - 2));
	else 
		return false;
}