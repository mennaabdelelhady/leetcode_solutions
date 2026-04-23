class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        
        // group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<long long> res(n, 0);
        
        for (auto &p : mp) {
            vector<int>& idx = p.second;
            int m = idx.size();
            
            vector<long long> prefix(m + 1, 0);
            
            // build prefix sum
            for (int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + idx[i];
            }
            
            for (int i = 0; i < m; i++) {
                long long left = (long long)i * idx[i] - prefix[i];
                long long right = (prefix[m] - prefix[i + 1]) - (long long)(m - i - 1) * idx[i];
                
                res[idx[i]] = left + right;
            }
        }
        
        return res;
    }
};