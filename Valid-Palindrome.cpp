/**
*https://leetcode.com/problems/valid-palindrome/
*/


class Solution {
public:
    bool isPalindrome(string s) {
        // Initialize two pointers
        int left = 0;
        int right = s.size() - 1;
        
        // Loop until the pointers meet
        while (left < right) {
            // Move the left pointer to the next alphanumeric character
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Move the right pointer to the previous alphanumeric character
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters at the two pointers (convert to lowercase)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            // Move both pointers inward
            left++;
            right--;
        }
        
        // If all characters match, it's a palindrome
        return true;
    }
};
