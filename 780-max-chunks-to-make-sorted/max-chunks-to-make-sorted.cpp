class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int diff=0, count=0;

        for(int i=0;i<arr.size();i++){
            diff+=arr[i]-i;
            if(diff==0){
                count++;
            }
        }
        return count;
    }
};