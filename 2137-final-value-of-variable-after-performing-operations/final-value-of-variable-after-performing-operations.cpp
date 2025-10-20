class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int ans = 0;

        for(string op : operations) {
            if(op == "X++" || op == "++X") ans++;
            else ans--;
        }

        return ans;

    }
};