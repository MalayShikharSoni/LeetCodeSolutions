class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> prefix(n+1,0);

        vector<char> vowels={'a','e','i','o','u'};

        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i];

            if(find(vowels.begin(), vowels.end(), words[i].front())!=vowels.end() && find(vowels.begin(), vowels.end(), words[i].back())!=vowels.end()){
                prefix[i+1]++;
            }
        }

        vector<int> ans;

        for(auto q : queries){
            ans.push_back(prefix[q[1]+1] - prefix[q[0]]);
        }

        return ans;
    }
};