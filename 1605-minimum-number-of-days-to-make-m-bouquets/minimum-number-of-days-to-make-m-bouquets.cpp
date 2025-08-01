class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>bloomDay.size()){
            return -1;
        }

        int low=1;
        int high=1e9;

        while(low<high){
            int mid=(low+high)/2;

            if(canMake(bloomDay,m,k,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }
            
        }
        return low; 
    }

    int canMake(vector<int>& bloomDay, int m, int k, int day){
        int total=0;
        for(int i=0;i<bloomDay.size();i++){
            int count=0;
            while(i<bloomDay.size() && count<k && bloomDay[i]<=day){
                count++;
                i++;
            }

            if(count==k){
                total++;
                i--;
            }

            if(total>=m){
                return 1;
            }
        }
        return 0;
    }
};