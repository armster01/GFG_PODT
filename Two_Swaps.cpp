#include <bits/stdc++.h>
using namespace std;

// Function to check if the array can be sorted with exactly two swaps
bool canBeSortedWithTwoSwaps(vector<int>& arr) {
    int n = arr.size();
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    // Track mismatched indices
    vector<int> mismatchedIndices;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != sortedArr[i]) {
            mismatchedIndices.push_back(i);
        }
    }

    // If the array is already sorted
    if (mismatchedIndices.empty()) {
        return true;
    }

    // If the number of mismatched elements is odd, sorting with exactly two swaps is impossible
    if (mismatchedIndices.size() % 2 != 0) {
        return false;
    }

    // Try all possible swaps among mismatched elements
    for (int i = 0; i < mismatchedIndices.size(); ++i) {
        for (int j = i + 1; j < mismatchedIndices.size(); ++j) {
            vector<int> temp = arr;
            swap(temp[mismatchedIndices[i]], temp[mismatchedIndices[j]]);
            if (temp == sortedArr) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};  // Example array

    bool result = canBeSortedWithTwoSwaps(arr);

    if (result) {
        cout << "Yes, the array can be sorted with exactly two swaps.\n";
    } else {
        cout << "No, the array cannot be sorted with exactly two swaps.\n";
    }

    return 0;
}
