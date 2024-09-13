#include <iostream>
#include <vector>
using namespace std;

// Function to find the missing number
int findMissingNumber(const vector<int>& arr, int n) {
    // Calculate the sum of first n natural numbers
    int totalSum = (n * (n + 1)) / 2;

    // Calculate the sum of elements in the given array
    int actualSum = 0;
    for (int num : arr) {
        actualSum += num;
    }

    // The missing number is the difference between the expected sum and actual sum
    return totalSum - actualSum;
}

// Example usage
int main() {
    // Example array with one missing number
    vector<int> arr = {1, 2, 4, 5}; // Missing 3
    int n = 5; // Size of the array should be 5, including the missing element

    cout << "The missing number is: " << findMissingNumber(arr, n) << endl;

    return 0;
}
