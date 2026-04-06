class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insertPos = 0;
        
        // Move all non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[insertPos++] = nums[i];
            }
        }
        
        // Fill remaining positions with zeros
        while (insertPos < nums.size()) {
            nums[insertPos++] = 0;
        }
    }
};