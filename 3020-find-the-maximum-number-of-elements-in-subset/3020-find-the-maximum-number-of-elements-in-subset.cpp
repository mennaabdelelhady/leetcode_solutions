class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = 1;

        // Handle 1 separately
        if (cnt.count(1)) {
            ans = max(ans, cnt[1] % 2 ? cnt[1] : cnt[1] - 1);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (cnt.count(cur)) {
                if (cnt[cur] >= 2) {
                    len += 2;
                    if (cur > 31622) break; // next square exceeds 1e9
                    cur *= cur;
                } else {
                    len += 1;
                    break;
                }
            }

            if (len % 2 == 0) len--; // top must appear once
            ans = max(ans, len);
        }

        return ans;
    }
};