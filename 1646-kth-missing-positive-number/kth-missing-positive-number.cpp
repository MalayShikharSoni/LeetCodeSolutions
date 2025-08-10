class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0;
        int count=0;
        int current=1;

        while(count!=k){
            if(i<n && arr[i]==current){
                i++;
            }
            else{
                count++;
                if(count==k){
                    return current;
                }
            }
            current++;
        }
        return -1;
    }
};