#include <iostream>
#include <vector>
using namespace std;

// Function to find the missing and repeating numbers
pair<int, int> findMissingAndRepeating(vector<int>& arr) {
    int n = arr.size();
    int sum = (n * (n + 1)) / 2; // Sum of first n natural numbers
    int squareSum = (n * (n + 1) * (2 * n + 1)) / 6; // Sum of squares of first n natural numbers

    int actualSum = 0;
    int actualSquareSum = 0;

    // Calculate actual sum and actual sum of squares
    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
        actualSquareSum += arr[i] * arr[i];
    }

    // Missing number (A) and repeating number (B)
    int missingAndRepeatingSum = sum - actualSum; // A - B
    int missingAndRepeatingSquareSum = squareSum - actualSquareSum; // A^2 - B^2

    // A + B = (A - B) + 2B => A + B = missingAndRepeatingSum + 2B
    // A - B = missingAndRepeatingSum
    // A + B = (missingAndRepeatingSquareSum) / (missingAndRepeatingSum)

    int A_plus_B = (missingAndRepeatingSquareSum / missingAndRepeatingSum);
    int B = (A_plus_B - missingAndRepeatingSum) / 2;
    int A = A_plus_B - B;

    return {A, B}; // Return the missing and repeating numbers
}

int main() {
    // Example input
    vector<int> arr = {3, 1, 3, 4, 2};

    // Find the missing and repeating numbers
    pair<int, int> result = findMissingAndRepeating(arr);

    // Output the result
    cout << "Missing Number: " << result.first << endl;
    cout << "Repeating Number: " << result.second << endl;

    return 0;
}
