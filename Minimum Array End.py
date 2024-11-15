class Solution:
    def minEnd(self, n: int, x: int) -> int:
        # Calculate the candidate last element
        last_element = x | (n - 1)
        
        # Ensure the last element is greater than x
        if last_element <= x:
            last_element = x + 1
        
        return last_element