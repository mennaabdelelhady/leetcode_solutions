class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            long long cur = len[i];

            if (s[i] >= 'a' && s[i] <= 'z') {
                len[i + 1] = cur + 1;
            } 
            else if (s[i] == '*') {
                len[i + 1] = max(0LL, cur - 1);
            } 
            else if (s[i] == '#') {
                len[i + 1] = cur * 2;
            } 
            else { // '%'
                len[i + 1] = cur;
            }
        }

        if (k >= len[n]) return '.';

        for (int i = n - 1; i >= 0; i--) {
            long long prevLen = len[i];
            long long curLen  = len[i + 1];

            char op = s[i];

            if (op >= 'a' && op <= 'z') {
                if (k == prevLen) return op; // appended character
            }
            else if (op == '#') {
                if (k >= prevLen) k -= prevLen;
            }
            else if (op == '%') {
                k = prevLen - 1 - k;
            }
            // '*' leaves all surviving indices unchanged when tracing back
        }

        return '.';
    }
};