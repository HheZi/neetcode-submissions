class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (int l = 0, r = 1; r < prices.size(); r++) {

            if (prices[r] > prices[l]) {
                profit = max(prices[r] - prices[l], profit);
            } else if (prices[r] < prices[l]) {
                l = r;
            }
        }

        return profit;
    }
};
