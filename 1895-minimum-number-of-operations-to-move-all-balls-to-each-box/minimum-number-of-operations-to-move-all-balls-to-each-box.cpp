class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> left(n,0), right(n,0);
        vector<int> ans(n,0);
        int x = (boxes[0]=='1' ? 1 : 0);

        for(int i=1;i<n;i++){
            left[i] = left[i-1] + x;
            x += (boxes[i]=='1' ? 1 : 0);

        }

        x=(boxes[n-1]=='1' ? 1 : 0);

        for(int i=n-2;i>=0;i--){
            right[i]=right[i+1]+x;
            x+=(boxes[i]=='1' ? 1 : 0);
        }

        for(int i=0;i<n;i++){
            ans[i]=left[i]+right[i];
        }

        return ans;

    }
};