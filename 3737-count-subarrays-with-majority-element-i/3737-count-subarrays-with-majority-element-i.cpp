class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += (nums[j] == target ? 1 : -1);

                if (sum > 0)
                    ans++;
            }
        }

        return ans;
    }
};