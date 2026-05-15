class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            // Minimum is in the right part
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
            // Minimum is at mid or in the left part
            else {
                r = mid;
            }
        }

        return nums[l];
    }
};