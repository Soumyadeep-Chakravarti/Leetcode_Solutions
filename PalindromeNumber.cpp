/**
* https://leetcode.com/problems/palindrome-number/
*/

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers that end with 0 (but aren't 0) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        
        int rev_num = 0; 
        while (x > rev_num) { 
            rev_num = rev_num * 10 + x % 10; 
            x = x / 10; 
        }
        
        // For odd-length numbers, rev_num/10 removes the middle digit
        return x == rev_num || x == rev_num / 10;
    }
};
