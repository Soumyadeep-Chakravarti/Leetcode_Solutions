"""https://leetcode.com/problems/valid-parentheses/"""

class Solution:
    def isValid(self, s: str) -> bool:
        compare_dict  = {')': '(', '}': '{', ']': '['}
        stack = []

        for char in s:
            if char in compare_dict:
                top_element = stack.pop() if stack else '#'
            
                if compare_dict[char] != top_element:
                    return False
            
            else:

                stack.append(char)
            
        return not stack