/**
* PROBLEM -
* Write a short program that prints each number from 1 to 100 on a new line.
* For each multiple of 3, print "Fizz" instead of the number.
* For each multiple of 5, print "Buzz" instead of the number.
* For numbers which are multiples of both 3 and 5, print "FizzBuzz" instead of the number.
*/

#include <iostream>
using namespace std;

// Function Prototypes
void fizzBuzz(const int cycles);

// Start of main
int main() {

	fizzBuzz(100);

	return 0;
}

// Function Definitions
void fizzBuzz(const int cycles) {

	for(int i = 1; i <= cycles; i++) {

		// Using modulo operator '%' to see if remainder is 0
		bool multipleOfThree = (i % 3 == 0);
		bool multipleOfFive = (i % 5 == 0);

		// chain of if statements to determine what is printed
		if (multipleOfFive && multipleOfThree)
			cout << "FizzBuzz";
		else if (multipleOfThree)
			cout << "Fizz";
		else if (multipleOfFive)
			cout << "Buzz";
		else
			cout << i;

		// Print new line each itteration
		cout << endl;
	}
}
