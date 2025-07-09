class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        int n = startTime.size();
        vector<int> gap(n+1);

        gap[0] = startTime[0];
        for(int i=1;i<n;i++){
            gap[i] = startTime[i] - endTime[i-1];
        }
        gap[n] = eventTime - endTime[n-1];

        int i=0;
        int j=k;
        int sum = 0;
        int maxx = sum;

        for(int e = i; e<=n && e<=j; e++){
            sum+=gap[e];
        }
        maxx = max(maxx, sum);

        while(j<n){
            sum -= gap[i];
            i++;
            j++;
            sum += gap[j];
            maxx = max(maxx, sum);
        }

        return maxx;

    }
};