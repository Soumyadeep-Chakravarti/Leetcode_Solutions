class Solution {
public:
  int takeCharacters(string s, int k) {
    int n = s.length();

    // Step 1: Check if there are enough characters in the string.
    int countA = count(s.begin(), s.end(), 'a');
    int countB = count(s.begin(), s.end(), 'b');
    int countC = count(s.begin(), s.end(), 'c');

    // If any character doesn't appear k times or more, return -1
    if (countA < k || countB < k || countC < k) {
      return -1;
    }

    // Step 2: Sliding window to find the minimal subarray that contains at
    // least k of each character.
    unordered_map<char, int> freq;
    int left = 0;
    int result = INT_MAX;

    // Slide the window from the right
    for (int right = 0; right < n; ++right) {
      freq[s[right]]++;

      // Check if the current window satisfies the condition (at least k of 'a',
      // 'b', 'c')
      while (freq['a'] >= k && freq['b'] >= k && freq['c'] >= k) {
        // Update the result with the minimum window size
        result = min(result, right - left + 1);

        // Shrink the window from the left
        freq[s[left]]--;
        left++;
      }
    }

    return result;
  }
};
