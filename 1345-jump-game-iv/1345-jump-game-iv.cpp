class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 0;

        // value -> all indices having this value
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                int i = q.front();
                q.pop();

                // reached last index
                if (i == n - 1)
                    return steps;

                // i - 1
                if (i - 1 >= 0 && !vis[i - 1]) {
                    vis[i - 1] = true;
                    q.push(i - 1);
                }

                // i + 1
                if (i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = true;
                    q.push(i + 1);
                }

                // same value jumps
                for (int idx : mp[arr[i]]) {
                    if (!vis[idx]) {
                        vis[idx] = true;
                        q.push(idx);
                    }
                }

                // clear to avoid reprocessing same value again
                mp[arr[i]].clear();
            }

            steps++;
        }

        return -1;
    }
};