class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        
        // Group indices by value
        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]].push_back(i);
        }
        
        int minDist = INT_MAX;
        
        for (auto& [val, idx] : indices) {
            if (idx.size() < 3) continue;
            
            // Slide window of size 3 over sorted indices
            for (int i = 0; i + 2 < idx.size(); i++) {
                int dist = 2 * (idx[i + 2] - idx[i]);
                minDist = min(minDist, dist);
            }
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
};