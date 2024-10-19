def twoSum(nums, target):
    # Dictionary to store the number and its index
    num_map = {}
    
    # Iterate through the list of numbers
    for i, num in enumerate(nums):
        complement = target - num
        
        # Check if the complement is in the dictionary
        if complement in num_map:
            # If it exists, return the indices
            return [num_map[complement], i]
        
        # If not, store the current number and its index in the dictionary
        num_map[num] = i