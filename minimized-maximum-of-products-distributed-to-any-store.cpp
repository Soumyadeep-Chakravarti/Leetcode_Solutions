/**
*https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
*/

#include <vector>
#include <algorithm>
using namespace std;

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canDistribute(vector<int>& quantities, int n, int x) {
        int storesNeeded = 0;
        for (int qty : quantities) {
            storesNeeded += (qty + x - 1) / x; // Equivalent to ceil(qty / x)
            if (storesNeeded > n) return false;
        }
        return true;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = *max_element(quantities.begin(), quantities.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistribute(quantities, n, mid)) {
                result = mid; // Mid is valid, try smaller x
                right = mid - 1;
            } else {
                left = mid + 1; // Mid is invalid, try larger x
            }
        }

        return result;
    }
};


#include <iostream>
using namespace std;

int main() {
    Solution solution;
    vector<int> quantities1 = {11, 6};
    vector<int> quantities2 = {15, 10, 10};
    vector<int> quantities3 = {100000};

    cout << solution.minimizedMaximum(6, quantities1) << endl; // Output: 3
    cout << solution.minimizedMaximum(7, quantities2) << endl; // Output: 5
    cout << solution.minimizedMaximum(1, quantities3) << endl; // Output: 100000

    return 0;
}
