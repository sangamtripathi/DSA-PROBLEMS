class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if (prices.empty())
        {
            return {};
        }
        int n = prices.size();

        int buy{prices[0]};
        int profit{};
        int max_profit{};

        for (int i{1}; i < n; ++i)
        {
            if (buy >= prices[i])
            {
                buy = prices[i];
            }
            else
            {
                profit = prices[i] - buy;
                max_profit = max(max_profit, profit);
            }
        }
        return max_profit;
    }
};