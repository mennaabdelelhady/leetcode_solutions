class Solution {
public:
    static constexpr long long MOD = 1'000'000'007;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<pair<int,int>> q;
        vector<int> vis(n + 1, 0);

        q.push({1, 0}); // node, depth
        vis[1] = 1;

        int maxDepth = 0;

        while (!q.empty()) {
            auto [u, d] = q.front();
            q.pop();

            maxDepth = max(maxDepth, d);

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({v, d + 1});
                }
            }
        }

        return (int)modPow(2, maxDepth - 1);
    }
};