class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        // Step 1: Apply gravity (to the right)
        for (int i = 0; i < m; i++) {
            int empty = n - 1; // position where stone should fall

            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    empty = j - 1; // reset after obstacle
                } 
                else if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][empty]);
                    empty--;
                }
            }
        }

        // Step 2: Rotate 90° clockwise
        vector<vector<char>> res(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return res;
    }
};