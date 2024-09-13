#include <iostream>
#include <vector>

using namespace std;

// Function to calculate factorial
long long factorial(int n) {
    long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    // Input: Array A and its length N
    vector<int> A = {5, 7, 10};
    int N = A.size();
    
    // Output: Factorial for each element in the array
    for (int i = 0; i < N; i++) {
        cout << factorial(A[i]) << endl;
    }

    return 0;
}
