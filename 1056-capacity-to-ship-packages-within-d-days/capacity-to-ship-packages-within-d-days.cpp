class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int maxx=weights[0];
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(weights[i]>maxx){
                maxx=weights[i];
            }
        }

        int low=maxx;
        int high=sum;
        int minn=sum;

        while(low<=high){
            int mid=(low+high)/2;

            if(check(mid,days,weights)){
                minn=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return minn;
    }

    int check(int capacity, int days, vector<int>weights){
        int n=weights.size();
        int c=capacity;
        int daycount=1;

        for(int i=0;i<n;i++){
            if(c>=weights[i]){
                c-=weights[i];
            }
            else{
                daycount++;
                c=capacity-weights[i];

            }
        }

        if(daycount<=days){
            return 1;
        }
        return 0;
    }
    
};