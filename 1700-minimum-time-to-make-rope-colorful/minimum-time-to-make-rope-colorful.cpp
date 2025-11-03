class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int sum = 0;

        for(int i = 1; i < colors.size(); i++) {
            int maxx = 0;

            while(i < colors.size() && colors[i] == colors[i - 1]) {
                sum += neededTime[i - 1];
                maxx = max(maxx, neededTime[i - 1]);
                i++;
            }
            sum += neededTime[i - 1];
            maxx = max(maxx, neededTime[i - 1]);

            if(maxx != 0) {
                sum -= maxx;
            }

        }

        return sum;

    }
};