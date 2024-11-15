class Solution {
public:
    long long minEnd(int n, int x) {
        // Start with the first element as x
        std::vector<long long> nums;
        nums.push_back(x);
        
        // Generate the remaining elements in increasing order
        for (int i = 1; i < n; ++i) {
            // Find the next number to keep increasing while maintaining AND constraint
            long long next_num = nums.back() + 1;
            while ((next_num & x) != x) {
                next_num++;
            }
            nums.push_back(next_num);
        }
        
        // Return the last element of the constructed array
        return nums.back();
    }
};
