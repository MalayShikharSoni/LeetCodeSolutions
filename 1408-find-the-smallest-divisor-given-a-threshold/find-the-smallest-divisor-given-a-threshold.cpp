class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int low=1;
        int n=nums.size();
        int high=nums[n-1];

        while(low<high){
            int mid=(low+high)/2;
            if(isDiv(nums,threshold,mid)){
                high=mid;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }

    int isDiv(vector<int>& nums, int threshold, int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i]/mid;
            if(nums[i]%mid!=0){
                sum++;
            }
        }
        if(sum<=threshold){
            return 1;
        }
        return 0;
    }
};