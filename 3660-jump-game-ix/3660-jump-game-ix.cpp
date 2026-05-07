class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
      
        // Result array to store the final values
        vector<int> result(n);
      
        // Build prefix maximum array: prefixMax[i] = max(nums[0], nums[1], ..., nums[i])
        vector<int> prefixMax(n);
        prefixMax[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }
      
        // Initialize suffix minimum with a large value (approximately INT_MAX)
        int suffixMin = 1 << 30;
      
        // Traverse from right to left, building result array while tracking suffix minimum
        for (int i = n - 1; i >= 0; --i) {
            // If prefix max up to position i is greater than suffix min after position i,
            // copy the value from the next position (if valid), otherwise use prefix max
            if (prefixMax[i] > suffixMin) {
                // Copy from next position if within bounds
                result[i] = (i + 1 < n) ? result[i + 1] : prefixMax[i];
            } else {
                result[i] = prefixMax[i];
            }
          
            // Update suffix minimum: min(nums[i], nums[i+1], ..., nums[n-1])
            suffixMin = min(suffixMin, nums[i]);
        }
      
        return result;
    }
};