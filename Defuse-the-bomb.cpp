/**
*https://leetcode.com/problems/defuse-the-bomb/
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);  // Initialize the result array with zeros

        if (k == 0) {
            return result;  // If k is 0, all numbers become 0
        }

        for (int i = 0; i < n; ++i) {
            int total = 0;
            if (k > 0) {  // Sum of the next k numbers
                for (int j = 1; j <= k; ++j) {
                    total += code[(i + j) % n];  // Use modulo for circular indexing
                }
            } else if (k < 0) {  // Sum of the previous |k| numbers
                for (int j = 1; j <= abs(k); ++j) {
                    total += code[(i - j + n) % n];  // Use modulo for circular indexing
                }
            }
            result[i] = total;
        }

        return result;
    }   
};