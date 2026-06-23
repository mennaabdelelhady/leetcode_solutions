class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1e9 + 7;
        int m = r - l + 1;

        vector<long long> dp0(m, 1), dp1(m, 1);
        vector<long long> new_dp0(m), new_dp1(m);

        for (int step = 0; step < n - 1; step++) {
            // suffix sum of dp1: suf[j] = dp1[j] + dp1[j+1] + ... + dp1[m-1]
            // new_dp0[j] = suf[j+1]  (suffix starting at j+1), 0 if j+1 == m
            long long running = 0;
            for (int j = m - 1; j >= 0; j--) {
                // running currently holds suffix sum starting at j+1
                new_dp0[j] = running % MOD;
                running = (running + dp1[j]) % MOD;
            }

            // prefix sum of dp0: pre[j] = dp0[0] + ... + dp0[j-1]
            // new_dp1[j] = pre[j]
            running = 0;
            for (int j = 0; j < m; j++) {
                new_dp1[j] = running % MOD;
                running = (running + dp0[j]) % MOD;
            }

            // swap instead of reallocating
            swap(dp0, new_dp0);
            swap(dp1, new_dp1);
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) ans = (ans + dp0[i]) % MOD;
        for (int i = 0; i < m; i++) ans = (ans + dp1[i]) % MOD;
        return (int)(ans % MOD);
    }
};