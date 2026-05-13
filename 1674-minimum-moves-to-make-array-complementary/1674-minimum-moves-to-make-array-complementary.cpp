class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        
        vector<int> diff(2 * limit + 2, 0);

        for (int i = 0; i < n / 2; i++) {
            int a = nums[i];
            int b = nums[n - 1 - i];

            int low = min(a, b) + 1;
            int high = max(a, b) + limit;
            int sum = a + b;

            // Default = 2 moves
            diff[2] += 2;

            // Range needing only 1 move
            diff[low] -= 1;
            diff[high + 1] += 1;

            // Exact sum needing 0 moves
            diff[sum] -= 1;
            diff[sum + 1] += 1;
        }

        int ans = INT_MAX;
        int cur = 0;

        for (int s = 2; s <= 2 * limit; s++) {
            cur += diff[s];
            ans = min(ans, cur);
        }

        return ans;
    }
};