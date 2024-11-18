/**
 * https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k
 */

class Solution {
public:
  int shortestSubarray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n + 1, 0);

    // Compute prefix sums
    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }

    // Initialize a deque and the result variable
    deque<int> dq;
    int minLength = INT_MAX;

    // Iterate through the prefix sum array
    for (int j = 0; j <= n; ++j) {
      // Check if the current prefix sum satisfies the condition with the front
      // element of the deque
      while (!dq.empty() && prefix[j] - prefix[dq.front()] >= k) {
        minLength = min(minLength, j - dq.front());
        dq.pop_front();
      }

      // Maintain a monotonic deque by removing elements from the back
      while (!dq.empty() && prefix[j] <= prefix[dq.back()]) {
        dq.pop_back();
      }

      // Add the current index to the deque
      dq.push_back(j);
    }

    // Return the result
    return minLength == INT_MAX ? -1 : minLength;
  }
};
