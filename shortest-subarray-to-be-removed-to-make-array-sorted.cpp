/**
* https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        // Step 1: Find the longest non-decreasing prefix
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }

        // If the entire array is already non-decreasing
        if (left == n - 1) {
            return 0;
        }

        // Step 2: Find the longest non-decreasing suffix
        int right = n - 1;
        while (right - 1 >= 0 && arr[right - 1] <= arr[right]) {
            right--;
        }

        // Step 3: Initialize result to remove either prefix or suffix
        int result = min(n - left - 1, right);

        // Step 4: Merge prefix and suffix using two pointers
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};

#include <iostream>
#include <vector>
using namespace std;

int main() {
    Solution solution;
    vector<int> arr1 = {1, 2, 3, 10, 4, 2, 3, 5};
    vector<int> arr2 = {5, 4, 3, 2, 1};
    vector<int> arr3 = {1, 2, 3};

    cout << solution.findLengthOfShortestSubarray(arr1) << endl; // Output: 3
    cout << solution.findLengthOfShortestSubarray(arr2) << endl; // Output: 4
    cout << solution.findLengthOfShortestSubarray(arr3) << endl; // Output: 0

    return 0;
}

