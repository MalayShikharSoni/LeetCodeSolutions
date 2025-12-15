class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        
        vector<int> descents;
        long long ans = 0;

        int length = 1;
        for(int i = 0; i < prices.size() - 1; i++) {
            if(prices[i] - prices[i + 1] == 1) {
                length++;
            } else {
                descents.push_back(length);
                length = 1;
            }
        }

        descents.push_back(length);

        for(int d : descents) {
            ans += (long long) d * (long long)(d + 1) / 2;
        }

        return ans;

    }
};