class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        auto reverseNum = [](int x) {
            int rev = 0;
            while (x > 0) {
                rev = rev * 10 + x % 10;
                x /= 10;
            }
            return rev;
        };
        
        // Map: reverse(nums[i]) -> LAST index i seen with that reverse
        // We only need the most recent index to minimize distance
        unordered_map<int, int> revToLastIndex;
        int ans = INT_MAX;
        
        for (int j = 0; j < (int)nums.size(); j++) {
            // Find most recent i where reverse(nums[i]) == nums[j]
            auto it = revToLastIndex.find(nums[j]);
            if (it != revToLastIndex.end()) {
                ans = min(ans, j - it->second);
            }
            
            // Update map: store most recent index for reverse(nums[j])
            int rev = reverseNum(nums[j]);
            auto it2 = revToLastIndex.find(rev);
            if (it2 == revToLastIndex.end() || it2->second < j) {
                revToLastIndex[rev] = j;
            }
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};