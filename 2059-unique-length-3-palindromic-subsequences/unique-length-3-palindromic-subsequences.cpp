class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        unordered_map<char, pair<int,int>> mp;

        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]].first=i;
            }
            mp[s[i]].second=i;
        }

        for(auto& [c,p] : mp){
            int left=p.first;
            int right=p.second;

            if(right-left<=1) continue;

            unordered_set<char> sett;
            for(int i=left+1;i<right;i++){
                sett.insert(s[i]);
            }

            ans+=sett.size();
        }

        return ans;
    }
};