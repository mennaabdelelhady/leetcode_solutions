class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }
        
        int result = INT_MAX;
        
        for (auto& [val, indices] : positions) {
            if (indices.size() < 3) continue;
            
            // Sliding window of size 3
            for (int i = 0; i + 2 < indices.size(); i++) {
                int dist = 2 * (indices[i + 2] - indices[i]);
                result = min(result, dist);
            }
        }
        
        return result == INT_MAX ? -1 : result;
    }
};