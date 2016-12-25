/** 
 * Michael Wilson
 * Random Learning of C++
 * Problems are from Chapter 2 of Data Abstractions & Problem Solving
 * in C++ by Frank M. Carrano and Timothy Henry */
#include <iostream>

/** Need this for the MAX function */
#include <algorithm>

using namespace std;

/* method signature */
int getValue(int, int, int);

int search(int, int, int);
int mystery(int);

int f(int);

/** Signature for fact so that it may be used */
int itrFact(int);

/** This is the second programming problem from chapter 2
 * This finds the maximum value in an unsorted array using the psuedocode from 2.4.3
 * @pre Array is valid, first & last are nonnegative, first <= last
 * @post None
 * @param x[] The array
 * @param first The first index to consider
 * @param last The last index to consider
 * @return The max value in the array */
int maxArray(int x[], int first, int last) {
	int mid = (first + last)/2;
	// implies that there is one element
	return first == last ? x[first] : max(maxArray(x, first, mid), maxArray(x, mid + 1, last));
}

/** Displays the octal representation of a number
 * @pre number is valid
 * @post None.
 * @param n The number to convert */
void displayOctal(int n) {
	if(n > 0) {
		if(n / 8 > 0)
			displayOctal(n / 8);
		cout << n % 8;
	} 	
}

/** Checks to see how many instances of a number exist in an array
 * @pre valid array and number
 * @post None.
 * @param x[] The array
 * @param n The current position
 * @param desiredValue the target value
 * @return The count of the number of occurrences desiredValue appears */
int getNumberEqual(const int x[], unsigned int n, signed int desiredValue) {
	/* Initialize the count */
	int count = 0;

	/* check to see if we have an invalid # of <E> in x[] to look at */
	if(n <= 0)
		return 0;
	else {
		/* found the desired value */
		if(x[n - 1] == desiredValue)
			count = 1;		
		/* Decreases the # by  1 so that we eventually reach the base case */
		return getNumberEqual(x, n - 1, desiredValue) + count;
	}
}

/** Method that returns the sum of the numbers from start to end
 * @pre valid array
 * @post None.
 * @param x[] The array
 * @param length The length of the array
 * @param n The current spot in the array we are looking */
int runningSum(const int x[], unsigned int length, unsigned int n) {
	return n < length ? runningSum(x, length, n + 1) + x[n] : 0;
}

/** Functions that writes numbers 1 to n
 * @pre number is nonnegative
 * @post None
 * @param current The current number to print
 * @param n The number to go up to */
void printNumbersTo(int n, int current) {
	if(current <= n) {
		cout << current << " ";
		printNumbersTo(n, current + 1);
	}
}

/** Returns the sum of squares
 * @pre None
 * @post None
 * @param current The current number we are looking at
 * @param n The number to go up to
 * @return The sum of the squares up to n */
int sumOfSquares(int current, int n) {
	return current <= n ? current * current + sumOfSquares(current + 1, n) : 0;
}

/******************************
 * THIS IS CODE FROM THE BOOK *
 ******************************/
/** This is just to check to see the understanding of passing by value and reference */
void recurse(int * x, int y) {
	if(y > 0) {
		x++;
		y--;
		cout << x << " " << y << endl;
		recurse(x, y);
		cout << x << " " << y << endl;
	}
}

/** Iterative solution for finding powers
 * Does N operations
 * @pre n >= 0
 * @post None
 * @param x The base
 * @param n The power
 * @return The result of the given base to a specified power */
int itrPower(int x, int n) {
	if(n == 0)
		return 1;
	int returnValue = x;
	for(int i = 0; i < n-1; i++) {
		returnValue *= x;
	}
	return returnValue;
}

/** first recursive solution for finding powers, doesn't account for negative
 * Does N operations
 * @pre n >= 0
 * @post None
 * @param x The base
 * @param n The power
 * @return The result of the given base to a specified power */
int rec1Power(int x, int n){
	return n == 0 ? 1 : x * rec1Power(x, n - 1);
}

/** second recursive solution for finding powers
 * Does logN operations
 * @pre n >= 0
 * @post None
 * @param x The base
 * @param n The power
 * @return The result of the given base to a specified power */
int rec2Power(int x, int n){
	if(n == 0) {
		return 1;
	} else if(n > 0 && n % 2 == 0) {
		return rec2Power(x, n / 2) * rec2Power(x, n / 2); 
	} else {
		return x * rec2Power(x, n / 2) * rec2Power(x, n / 2);
	}
}

/** Does nothing more than execute powerCalled functions */
void powerCall() {
	int base, power;
 	cout << "Please enter a base: ";
 	cin >> base;
 	cout << "Please enter a power: ";
 	cin >> power;
 	cout << base << "^" << power << " = " << itrPower(base, power) << endl;
 	cout << base << "^" << power << " = " << rec1Power(base, power) << endl;
 	cout << base << "^" << power << " = " << rec2Power(base, power) << endl;
}

/** Does nothing more than execute the first 15 problems */
void firstFifteen() {
	displayOctal(15);
	cout << endl;
	int x[] = {1, 2, 3};
	int length = sizeof(x)/sizeof(x[0]);
	cout << runningSum(x, length, 0) << endl;
	printNumbersTo(10, 1);
	int ans;
	cout << "Please enter a number: ";
	cin >> ans;
	cout << "Sum of squares up to " << ans << " is " << sumOfSquares(1, ans) << endl;
	cout << getValue(1, 7, 7) << endl;
 	cout << mystery(30) << endl; 	
 	cout << "The value of f(3) is " << f(3) << endl;
 	int a = 5;
 	recurse(&a, 3);
}

/** Function that calls the itrFactorial function */
void callFactorial() {
	int factorial;
	cout << "Please enter the number that you would like to find the factorial of: ";
	cin >> factorial;
 	cout << factorial << "! is " << itrFact(factorial);
}
 
int main() {
	// firstFifteen();
 	// powerCall();
 	//callFactorial();

	// create a random array 
	int x[] = {1, 2,35, 64, 25, 4,5 ,36, 3, 120, 432, 43, 42,43 ,41 ,430};
	int lastIndex = sizeof(x)/sizeof(x[0]) - 1;
	cout << "The maximum value in the given array is: " << maxArray(x, 0, lastIndex) << endl;
	return 0;
}

/** Iterative version of factorial 
 * @pre n >= 0
 * @post None
 * @param n The number to find the factorial of 
 * @return The factorial of n */
int itrFact(int n) {
	if(n == 0) 
		return 1;
	int prod = 1;
	for(int i = 1; i <= n; i++)
		prod *= i;
	return prod;
}

/******************************
 * THIS IS CODE FROM THE BOOK *
 ******************************/

/**
 * @pre None
 * @post None
 * @param a The first number
 * @param b The second number
 * @param n The target number
 * @return The number of times it takes to find two numbers which are less than the square 
 *         root of a number*/
int getValue(int a, int b, int n) {
	int returnValue = 0;
	
	// prints out the values that were passed in
	cout << "Enter: a = " << a << " b = " << b << endl;

	// finds the mid value
	int c = (a + b)/2;

	returnValue = c * c <= n ? c : getValue(a, c - 1, n);

	cout << "Leave a = " << a << " b = " << b << endl;
	return returnValue;
}

/******************************
 * THIS IS CODE FROM THE BOOK *
 ******************************/

/** Finds the greatest number that can be a square root of N
 * @pre None
 * @post None
 * @param first The starting point
 * @param last The max number in range
 * @param n The number to check the square root of 
 * @return The greatest number that can be a square root of n */
int search(int first, int last, int n) {
	int returnValue = 0;
	cout << "Enter: first = " << first << " last = " << last << endl;
	int mid = (first + last)/2;
	if((mid * mid <= n) && n < (mid + 1) * (mid + 1))
		returnValue = mid;
	else if(mid * mid > n)
		returnValue = search(first, mid - 1, n);
	else
		returnValue = search(mid + 1, last, n);
	cout << "Leave: first = " << first << " last = " << last << endl;
	return returnValue;
}

/******************************
 * THIS IS CODE FROM THE BOOK *
 ******************************/

/** Searches for a number that is the square root of n {rounded down}
 * @pre None
 * @post None
 * @param n The number to deal with
 * @return The greatest number that can be a square root of n */
int mystery(int n) {
	return search(1, n, n);
}


/******************************
 * THIS IS CODE FROM THE BOOK *
 ******************************/

/** NOTE CALL OF 3 BREAKS THIS FUNCTION
 * @pre n >= 0
 * @post None
 * @param n The number to check
 * @return */
int f(int n) {
	cout << "Function entered with n = " << n << endl;
	switch(n) {
		case 0: case 1: case 2:
			return n + 1;
		default: 
			return f(n - 2) * f(n - 4);
	}
}