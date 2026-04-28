class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        
        // Flatten grid
        for (auto &row : grid) {
            for (int val : row) {
                nums.push_back(val);
            }
        }
        
        // Check feasibility
        int rem = nums[0] % x;
        for (int val : nums) {
            if (val % x != rem) return -1;
        }
        
        // Sort
        sort(nums.begin(), nums.end());
        
        // Take median
        int median = nums[nums.size() / 2];
        
        // Count operations
        int ops = 0;
        for (int val : nums) {
            ops += abs(val - median) / x;
        }
        
        return ops;
    }
};