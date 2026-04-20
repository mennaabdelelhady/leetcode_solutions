class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int result = 0;
        
        // Check from the right: find furthest house from index 0 with different color
        for (int j = n - 1; j > 0; j--) {
            if (colors[j] != colors[0]) {
                result = max(result, j);
                break;
            }
        }
        
        // Check from the left: find furthest house from index n-1 with different color
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != colors[n - 1]) {
                result = max(result, (n - 1) - i);
                break;
            }
        }
        
        return result;
    }
};