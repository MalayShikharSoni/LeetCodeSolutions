class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>mp;

        for(string word : words){
            mp[word]++;

        }

        int count = 0;
        bool alreadyPalindrome = false;

        for(auto& [word, freq] : mp){
            string str = word;
            reverse(str.begin(), str.end());

            if(word == str){
                count += (freq/2) * 4;

                if(freq%2){
                    alreadyPalindrome = true;
                }
            } else if(word<str && mp.count(str)){
                count += min(freq, mp[str]) * 4;
            }
        }

        int ans = count + alreadyPalindrome * 2;
        return ans;
    }
};