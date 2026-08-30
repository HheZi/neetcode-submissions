class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, min_buy = prices[0]; 

        for (int price : prices) {
            profit = max(profit, price - min_buy);
            min_buy = min(min_buy, price);
        }

        return profit;
    }
};
