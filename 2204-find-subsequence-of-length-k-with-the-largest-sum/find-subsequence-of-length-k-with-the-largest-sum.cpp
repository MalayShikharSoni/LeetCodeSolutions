class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        vector<pair<int,int>> numAndIndex;

        for(int i=0;i<nums.size();i++){
            numAndIndex.push_back({nums[i], i});
        }

        sort(numAndIndex.begin(), numAndIndex.end(), [](pair<int,int>& a, pair<int,int> b){
            return a.first > b.first;
        });

        vector<pair<int,int>> firstK(numAndIndex.begin(), numAndIndex.begin()+k);

        sort(firstK.begin(), firstK.end(), [](pair<int,int>& a, pair<int,int> b){
            return a.second < b.second;
        });

        vector<int> ans;

        for(auto x : firstK){
            ans.push_back(x.first);
        }

        return ans;

    }
};