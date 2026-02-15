class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if(prices.size() <= 1) {
            return 0;
        }

        int n = prices.size();
        vector<int> buy(n);
        vector<int> sell(n);
        vector<int> rest(n);

        buy[0] = -1 * prices[0];
        sell[0] = 0;
        rest[0] = 0;

        for(int i = 1; i < prices.size(); i++) {

            buy[i] = max(buy[i - 1], rest[i - 1] - prices[i]);
            sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
            rest[i] = max(rest[i - 1], sell[i - 1]);

        }

        return max(sell[n - 1], rest[n - 1]);

    }
};