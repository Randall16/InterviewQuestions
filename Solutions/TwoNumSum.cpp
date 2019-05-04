/**
 * Write a funtction that given an array, and a integer value "sum" that
 * returns true there exists two values inside the array that can added together
 * to equal sum.
 * 
 * Example {67, 23, 5, 2, 99}, 25 returns true because 23 + 2 = 25
 * 
 * Example {67, 23, 5, 2, 99}, 555 returns false because no two values added
 * equal 555
 */

#include <iostream>
#include <unordered_set>
using namespace std;


// O(n) run time
bool twoNumSum(const int* arr, const unsigned int size, const int sum) {

    // declare hash set to store previous elements
    unordered_set<int> compliments;

    // loop through array
    for(unsigned int i = 0; i < size; i++) {

        // calculate the value that would make a sum with the current array slot
        int target = sum - arr[i];

        // perform O(1) search on set for our target value
        if(compliments.find(target) != compliments.end())
            return true; // if found we can stop and return true
        else
            compliments.insert(arr[i]); // else continue building up the set
    }

    // if make through the entire array then we know a sum does not exist
    return false;
}



// Sample driver of the function
int main() {

    int arr[] = {67, 23, 5, 2, 99};
    int size = sizeof(arr);
    int sum = 25;

    if(twoNumSum(arr, size, sum))
        cout << "A sum exists" << endl;
    else 
        cout << "A sum does NOT exists" << endl;

    return 0;
}