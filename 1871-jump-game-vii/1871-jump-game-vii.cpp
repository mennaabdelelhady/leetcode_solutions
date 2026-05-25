class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        vector<bool> dp(n, false);
        dp[0] = true;

        int reachable = 0;

        for (int i = 1; i < n; i++) {

            // add new index that can jump to i
            if (i - minJump >= 0 && dp[i - minJump])
                reachable++;

            // remove index that is too far
            if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1])
                reachable--;

            // current position reachable
            if (s[i] == '0' && reachable > 0)
                dp[i] = true;
        }

        return dp[n - 1];
    }
};