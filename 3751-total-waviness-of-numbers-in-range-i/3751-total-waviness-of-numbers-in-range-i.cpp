class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;

        for (int x = num1; x <= num2; x++) {
            string s = to_string(x);
            int n = s.size();

            for (int i = 1; i < n - 1; i++) {
                if ((s[i] > s[i - 1] && s[i] > s[i + 1]) ||
                    (s[i] < s[i - 1] && s[i] < s[i + 1])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};