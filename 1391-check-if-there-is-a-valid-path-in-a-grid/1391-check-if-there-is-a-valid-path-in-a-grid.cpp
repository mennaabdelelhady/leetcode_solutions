class Solution {
public:
    vector<vector<int>> mp = {
        {},
        {0,1},
        {2,3},
        {1,2},
        {0,2},
        {1,3},
        {0,3}
    };

    vector<pair<int,int>> dirs = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    bool canConnect(int fromDir, int toType) {
        if(fromDir == 0) fromDir = 1;
        else if(fromDir == 1) fromDir = 0;
        else if(fromDir == 2) fromDir = 3;
        else fromDir = 2;

        for(int d : mp[toType]) {
            if(d == fromDir) return true;
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            if(x == m-1 && y == n-1) return true;

            int type = grid[x][y];

            for(int d : mp[type]) {
                int nx = x + dirs[d].first;
                int ny = y + dirs[d].second;

                if(nx < 0 || ny < 0 || nx >= m || ny >= n || vis[nx][ny])
                    continue;

                if(canConnect(d, grid[nx][ny])) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};