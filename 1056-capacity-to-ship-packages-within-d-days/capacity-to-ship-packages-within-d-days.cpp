class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = INT_MIN;
        int high = 0;

        for(int w : weights) {
            low = max(low, w);
            high += w;
        }

        int ans = high;

        while(low < high) {

            int mid = low + (high - low) / 2;

            if(check(mid, weights, days)) {
                ans = mid;
                high = mid;
            } else {
                low = mid + 1;
            }

        }

        return ans;

    }

    bool check(int capacity, vector<int>& weights, int days) {

        int daycount = 1;
        int c = capacity;

        for(int i = 0; i < weights.size(); i++) {

            if(weights[i] <= c) {
                c -= weights[i];
            } else {
                c = capacity - weights[i];
                daycount++;
            }

        }

        return daycount <= days;

    }

};