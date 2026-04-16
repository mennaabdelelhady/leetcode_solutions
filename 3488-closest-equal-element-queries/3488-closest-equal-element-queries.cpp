class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        // group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for (int q : queries) {
            int val = nums[q];
            auto &v = mp[val];
            
            if (v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // binary search
            auto it = lower_bound(v.begin(), v.end(), q);
            
            int res = INT_MAX;
            
            // check next
            if (it != v.end()) {
                int j = *it;
                if (j != q)
                    res = min(res, min(abs(j - q), n - abs(j - q)));
                
                // next element after it
                if (it + 1 != v.end()) {
                    j = *(it + 1);
                    res = min(res, min(abs(j - q), n - abs(j - q)));
                }
            }
            
            // check previous
            if (it != v.begin()) {
                int j = *(it - 1);
                res = min(res, min(abs(j - q), n - abs(j - q)));
            }
            
            // circular wrap (first & last)
            int j = v[0];
            if (j != q)
                res = min(res, min(abs(j - q), n - abs(j - q)));
            
            j = v.back();
            if (j != q)
                res = min(res, min(abs(j - q), n - abs(j - q)));
            
            ans.push_back(res);
        }
        
        return ans;
    }
};