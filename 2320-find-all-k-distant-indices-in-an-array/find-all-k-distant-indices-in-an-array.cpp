class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> ans;
        int end = 0;

        for(int i =0;i<n;i++){
            if(nums[i]==key){

                int start = max(end, i-k);
                end = min(n-1, i+k);

                for(int j=start;j<=end;j++){
                    if(find(ans.begin(),ans.end(), j)==ans.end()){
                        ans.push_back(j);
                    }
                }

            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};