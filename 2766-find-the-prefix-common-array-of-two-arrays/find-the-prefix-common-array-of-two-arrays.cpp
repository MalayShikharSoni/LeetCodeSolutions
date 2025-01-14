class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int n = A.size();
        vector<int> freq(n+1,0);
        int temp=0;
        for(int i=0;i<n;i++){
            if(++freq[A[i]]==2){
                temp++;
            }
            if(++freq[B[i]]==2){
                temp++;
            }

            ans.push_back(temp);
        } 

        return ans;
    }
};