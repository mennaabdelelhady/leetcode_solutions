class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> cnt(maxCost + 1, 0);

        for (int cost : costs) {
            cnt[cost]++;
        }

        int ans = 0;

        for (int price = 1; price <= maxCost; price++) {
            if (cnt[price] == 0) continue;

            int canBuy = min(cnt[price], coins / price);

            ans += canBuy;
            coins -= canBuy * price;

            if (coins < price) continue;
        }

        return ans;
    }
};