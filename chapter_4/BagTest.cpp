/******************************************************************* 
 ** NOT MY CODE, FOLLOWED ALONG AND USED THIS CODE FOR SELF STUDY **
 ** CODE IS FROM FRANK M. CARRANO AND TIMOTHY HENRY'S DATA 		  **
 ** ABSTRACTION AND PROBLEM SOLVING WITH C++					  ** 	
 *******************************************************************/

#include "BagInterface.h"
#include "LinkedBag.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void displayBag(BagInterface<string>* bagPtr) {
	cout << "The bag contains " << bagPtr->getCurrentSize()
		 << " items:" << endl;
	vector<string> bagItems;
	bagItems = bagPtr->toVector();

	int numberOfEntries = bagItems.size();
	for(int i = 0; i < numberOfEntries; i++) 
	{
		cout << bagItems[i] << " ";
	}
	cout << endl << endl;	
}

void bagTest(BagInterface<string>* bagPtr) {
	cout << "isEmpty: returns " << bagPtr->isEmpty()
		 << "; should be 1 (true)" << endl;
	string items[] = {"one", "two", "three", "four", "five", "one"};
	cout << "Adding 6 items to the bag: " << endl;
	for(int i = 0; i < 6; i++)
		bagPtr->add(items[i]);
	displayBag(bagPtr);

	cout << "isEmpty: returns " << bagPtr->isEmpty() 
		 << "; should be 0 (false)" << endl;
	cout << "getCurrentSize returns : " << bagPtr->getCurrentSize()
		 << "; should be 6" << endl;
	cout << "Try to add another entry: add(\"extra\") returns "
	 	 << bagPtr->add("extra") << endl; 
}

int main() {
	BagInterface<string>* bagPtr = nullptr;
	char userChoice;
	cout << "Enter 'A' to test the array-based implementaiton\n"
		 << " or 'L' to test the link-based implementation: ";
	cin >> userChoice;
	bagPtr = new LinkedBag<string>();
	cout << "Testing the link-based Bag:" << endl;

	cout << "The intial bag is empty. " << endl;
	bagTest(bagPtr);
	delete bagPtr;
	bagPtr = nullptr;
	cout << "All done!" << endl;
	return 0; 
}