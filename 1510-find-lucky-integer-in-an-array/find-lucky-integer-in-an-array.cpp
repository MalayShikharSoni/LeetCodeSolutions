class Solution {
public:
    int findLucky(vector<int>& arr) {
        
        map<int, int> freq;
        int ans = -1;
        
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }

        for(auto& f : freq){
            if(f.first == f.second){
                ans = f.first;
            }
        }
        
        return ans;

    }
};