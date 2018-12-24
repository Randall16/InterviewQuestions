/**
* PROBLEM -
* Write a function that checks if an equation has balanced parentheses.
* For example the equation 5 * (8 + 2) is valid whereas the equation
* (22 * 3) + 9) is NOT valid.
* Accept the input as a string and return a boolean.
*/

#include <iostream>
#include <stack>
using namespace std;

// Function Prototypes
bool isBalanced(const string& input);
bool isOpenParen(const char c);
bool isClosingParen(const char c);

// Start of main
int main() {

	// Declaring sample inputs
	string valid = "((88 - 27) + 9) * 2";
	string invalid = "(9 - 2) * ) 2 (";

	cout << isBalanced(valid) << endl;    // Prints 1 because it is true
	cout << isBalanced(invalid) << endl;  // Prints 0 because it is false

	return 0;
}

// Function definitions
bool isBalanced(const string& input) {
	// Using a stack that will only hold opening parentheses when we find a
	// closing parentheses we will pop the stack.
	stack<char> braces;

	for (int i = 0; i < input.length(); i++) {

		// Store the character we'll be looking at
		const char value = input[i];

		// Add to stack if it is an opening brace
		if ( isOpenParen(value) ) {
			braces.push(value);
		}
		else if ( isClosingParen(value) ) {

			// In order for this to be valid there must already be a 
			// paraenthesis on the stack.
			if ( braces.empty() ) {
				return false;
			}
			else {
				braces.pop();
			}
		}
	}

	// Finally, the stack must be empty in order to be a valid equation
	return braces.empty();
}

bool isOpenParen(const char c) {
	return (c == '(');
}

bool isClosingParen(const char c) {
	return (c == ')');
}
