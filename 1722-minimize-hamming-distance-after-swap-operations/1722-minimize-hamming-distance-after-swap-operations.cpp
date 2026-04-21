class Solution {
public:
    // Union-Find helpers
    vector<int> parent, rank_;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        // union by rank
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rank_.resize(n, 0);
        iota(parent.begin(), parent.end(), 0); // parent[i] = i
        
        // Step 1: Build union-find groups from allowed swaps
        for (auto& swap : allowedSwaps)
            unite(swap[0], swap[1]);
        
        // Step 2: Group source elements by their root
        // root -> {value -> count}
        unordered_map<int, unordered_map<int, int>> groups;
        for (int i = 0; i < n; i++)
            groups[find(i)][source[i]]++;
        
        // Step 3: For each index, check if target[i] can be matched
        // within the same component
        int hamming = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            auto& freq = groups[root];
            if (freq.count(target[i]) && freq[target[i]] > 0) {
                freq[target[i]]--; // consume this source element
                // matched! no contribution to hamming distance
            } else {
                hamming++; // can't match target[i] in this group
            }
        }
        
        return hamming;
    }
};