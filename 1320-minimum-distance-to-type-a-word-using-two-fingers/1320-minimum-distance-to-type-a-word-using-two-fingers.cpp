class Solution {
public:
    int minimumDistance(string word) {
        // dist[a][b] = Manhattan distance between letters a and b
        auto dist = [](int a, int b) -> int {
            if (a == 26) return 0; // finger not placed yet, free move
            return abs(a / 6 - b / 6) + abs(a % 6 - b % 6);
        };
        
        int n = word.size();
        // dp[j] = min cost when one finger is on current char, other finger is on j
        // j = 26 means finger hasn't been placed yet
        vector<int> dp(27, INT_MAX);
        dp[26] = 0; // initially, other finger not placed
        
        for (int i = 0; i < n - 1; i++) {
            int cur = word[i] - 'A';
            int nxt = word[i + 1] - 'A';
            vector<int> ndp(27, INT_MAX);
            
            for (int other = 0; other <= 26; other++) {
                if (dp[other] == INT_MAX) continue;
                int cost = dp[other];
                
                // Option 1: finger on 'cur' moves to 'nxt', other stays
                int c1 = cost + dist(cur, nxt);
                if (c1 < ndp[other]) ndp[other] = c1;
                
                // Option 2: other finger moves to 'nxt', cur finger stays
                int c2 = cost + dist(other, nxt);
                if (c2 < ndp[cur]) ndp[cur] = c2;
            }
            
            dp = ndp;
        }
        
        // Answer is minimum over all possible positions of the other finger
        return *min_element(dp.begin(), dp.end());
    }
};