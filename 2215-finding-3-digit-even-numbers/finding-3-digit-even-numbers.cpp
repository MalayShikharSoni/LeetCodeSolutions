class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        
        vector<int> freq(10, 0);

        for(int i=0;i<digits.size();i++){
            freq[digits[i]]++;
        }

        vector<int> ans;

        for(int i=1;i<=9;i++){
            if(freq[i]==0){
                continue;
            }
            freq[i]--;

            for(int j=0;j<=9;j++){
                if(freq[j]==0){
                    continue;
                }
                freq[j]--;

                for(int k=0;k<=8; k+=2){
                    if(freq[k]==0){
                        continue;
                    }
                    ans.push_back(i*100 + j*10 + k);
                }
                freq[j]++;
            }
            freq[i]++;
        }

        return ans;

    }
};