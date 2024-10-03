#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {-1};  // No elements in the array
    
    // Initialize two candidates and their respective counts
    int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0;
    
    // Step 1: Find potential candidates using Boyer-Moore Voting Algorithm
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }

    // Step 2: Verify if the candidates appear more than n/3 times
    count1 = 0;
    count2 = 0;
    for (int num : nums) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }

    vector<int> result;
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);
    
    return result.empty() ? vector<int>{-1} : result;
}

int main() {
    vector<int> nums = {3, 2, 3, 4, 2, 2, 3};  // Example input
    vector<int> result = majorityElement(nums);
    
    if (result.size() == 1 && result[0] == -1) {
        cout << "-1\n";
    } else {
        for (int num : result) {
            cout << num << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
