class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int maxx = 0;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++) {
            maxx = max(maxx, weights[i]);
            sum += weights[i];
        }

        int low = maxx;
        int high = sum;
        int minn = sum;

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(check(mid, weights, days)) {
                minn = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }

        return minn;

    }

    bool check(int capacity, vector<int>& weights, int days) {

        int c = capacity;
        int dayCount = 1;

        for(int i = 0; i < weights.size(); i++) {

            if(c >= weights[i]) {
                c -= weights[i];
            } else {
                dayCount++;
                c = capacity - weights[i];
            }

        }

        if(dayCount <= days) {
            return true;
        }

        return false;

    }

};