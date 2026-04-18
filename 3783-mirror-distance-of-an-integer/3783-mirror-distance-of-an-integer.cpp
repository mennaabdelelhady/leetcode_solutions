class Solution {
public:
    int mirrorDistance(int n) {
        int reversed = 0, temp = n;
        while (temp > 0) {
            reversed = reversed * 10 + temp % 10;
            temp /= 10;
        }
        return abs(n - reversed);
    }
};