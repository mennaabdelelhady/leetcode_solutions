class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> cnt(n + 1, 0);
        vector<long long> pow10(n + 1, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        vector<int> digits;
        digits.reserve(n);

        for (char c : s)
            if (c != '0')
                digits.push_back(c - '0');

        int k = digits.size();

        vector<long long> prefVal(k + 1, 0);
        vector<long long> prefSum(k + 1, 0);

        int idx = 0;
        for (int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i];
            if (s[i] != '0') {
                cnt[i + 1]++;
                prefVal[idx + 1] = (prefVal[idx] * 10 + (s[i] - '0')) % MOD;
                prefSum[idx + 1] = prefSum[idx] + (s[i] - '0');
                idx++;
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            int L = cnt[l];
            int R = cnt[r + 1];

            int len = R - L;

            long long sum = prefSum[R] - prefSum[L];

            long long x =
                (prefVal[R] - prefVal[L] * pow10[len]) % MOD;

            if (x < 0) x += MOD;

            ans.push_back((x * (sum % MOD)) % MOD);
        }

        return ans;
    }
};