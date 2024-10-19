/**
 * https://leetcode.com/problems/valid-palindrome/
 */


impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        // Convert the string into an iterator of characters
        let filtered: Vec<char> = s.chars()
            .filter(|c| c.is_alphanumeric())  // Keep only alphanumeric characters
            .map(|c| c.to_ascii_lowercase())  // Convert to lowercase
            .collect();

        // If filtered is empty or has only one character, it's a palindrome
        if filtered.is_empty() {
            return true;
        }

        // Use two-pointer technique to compare characters from both ends
        let mut left = 0;
        let mut right = filtered.len() - 1;

        while left < right {
            if filtered[left] != filtered[right] {
                return false;
            }
            left += 1;
            right -= 1;
        }

        // If all characters match, return true
        true
    }
}