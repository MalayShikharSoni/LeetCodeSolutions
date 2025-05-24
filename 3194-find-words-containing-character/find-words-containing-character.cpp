class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for(int i=0;i<words.size();i++){

            bool flag = false;
            for(char c : words[i]){
                if(c==x){
                    flag = true;
                    break;
                }
            }

            if(flag==true){
                ans.push_back(i);
            }
        }

        return ans;
    }
};