class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    
    bool dfs(vector<vector<char>>& grid, int r, int c, int pr, int pc) {
        visited[r][c] = true;
        
        vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        
        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;
            
            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;
            
            if (grid[nr][nc] != grid[r][c])
                continue;
            
            // If not visited → continue DFS
            if (!visited[nr][nc]) {
                if (dfs(grid, nr, nc, r, c))
                    return true;
            }
            // If visited and not parent → cycle found
            else if (!(nr == pr && nc == pc)) {
                return true;
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1))
                        return true;
                }
            }
        }
        
        return false;
    }
};