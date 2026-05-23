class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Compare current element with next element (circularly)
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        // Valid if there is at most one "drop"
        return count <= 1;
    }
};