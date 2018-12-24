/**
* The function below returns the first repeating character in a string. It does so in O(n) 
* complexity where n is the size of the string being passed in. Each time the function is 
* called an unordered_set will be created. As we cycle through the string one character at 
* a time we first search the set to see if that character already existst. If so we can 
* stop there and return that character if not, insert that character into the set and continue
* to the next itteration. This is an unordered_set meaning its backed by a hash table givings
* us constant O(1) lookup time when searching the set.
*/

#include <iostream>
#include <string>
#include <unordered_set>

// Function prototypes
char firstRepeatingChar(const std::string& input);

// Start of main function
int main()
{
	std::cout << firstRepeatingChar("hello") << std::endl;	// prints 'l'

	return 0;
}

// Function definitions
char firstRepeatingChar(const std::string & input)
{
	std::unordered_set<char> seenChars;

	for (int i = 0; i < input.size(); i++) {

		if (seenChars.find(input[i]) != seenChars.end()) {
			return input[i];
		}
		else {
			seenChars.insert(input[i]);
		}
	}

	return NULL;		// return null if not found
}
