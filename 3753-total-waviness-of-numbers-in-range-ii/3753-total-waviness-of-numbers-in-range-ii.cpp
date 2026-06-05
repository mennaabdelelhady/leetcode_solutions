class Solution {
public:
    struct Node {
        long long cnt;
        long long sum;
    };

    string s;
    Node memo[20][11][11][2];
    bool vis[20][11][11][2];

    Node dfs(int pos, int a, int b, bool started, bool tight) {
        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][a][b][started]) {
            return memo[pos][a][b][started];
        }

        int lim = tight ? s[pos] - '0' : 9;

        long long totalCnt = 0;
        long long totalSum = 0;

        for (int d = 0; d <= lim; d++) {
            bool ntight = tight && (d == lim);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 10, 10, false, ntight);
                totalCnt += nxt.cnt;
                totalSum += nxt.sum;
            } else {
                int na, nb;
                long long add = 0;

                if (!started) {
                    // first real digit
                    na = 10;
                    nb = d;
                } else if (a == 10) {
                    // second real digit
                    na = b;
                    nb = d;
                } else {
                    // b becomes an interior digit
                    if ((b > a && b > d) || (b < a && b < d))
                        add = 1;

                    na = b;
                    nb = d;
                }

                Node nxt = dfs(pos + 1, na, nb, true, ntight);

                totalCnt += nxt.cnt;
                totalSum += nxt.sum + nxt.cnt * add;
            }
        }

        Node res{totalCnt, totalSum};

        if (!tight) {
            vis[pos][a][b][started] = true;
            memo[pos][a][b][started] = res;
        }

        return res;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, false, true).sum;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};