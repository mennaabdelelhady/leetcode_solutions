class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort both arrays
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        
        // Expand factories into individual slots
        // e.g. factory at pos=5 with limit=3 → three slots at pos=5
        vector<long long> slots;
        for (auto& f : factory) {
            for (int i = 0; i < f[1]; i++) {
                slots.push_back(f[0]);
            }
        }
        
        int n = robot.size();
        int m = slots.size();
        
        // dp[i] = min total distance to assign robots[i..n-1] to slots[i..m-1]
        // We process from right to left
        // dp has size (n+1) × (m+1), but we optimize to 1D
        
        // dp[j] = min cost using robots[i..n-1] starting from slot j
        vector<long long> dp(m + 1, 0);
        
        // Base: if no robots left (i == n), cost is 0 regardless of j
        // If robots remain but no slots, cost is infinity
        
        for (int i = n - 1; i >= 0; i--) {
            // We need a new dp array for this robot index
            vector<long long> ndp(m + 1, LLONG_MAX);
            // ndp[j] = min cost to assign robots[i..n-1] using slots[j..m-1]
            
            for (int j = m - 1; j >= i; j--) {
                // Option 1: skip slot j (don't assign robot i to slot j)
                if (ndp[j + 1] != LLONG_MAX) {
                    ndp[j] = ndp[j + 1];
                }
                // Option 2: assign robot i to slot j
                if (dp[j + 1] != LLONG_MAX) {
                    long long cost = abs(robot[i] - slots[j]) + dp[j + 1];
                    ndp[j] = min(ndp[j], cost);
                }
            }
            dp = ndp;
        }
        
        return dp[0];
    }
};