class Solution {
public:
    int beautySum(string s) {

        int beautysum = 0;
        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++) {

            mp.clear();

            for (int j = i; j < s.size(); j++) {

                char& ch = s[j];
                mp[ch]++;
                int maxi = INT_MIN;
                int mini = INT_MAX;

                for (auto each : mp) {
                    maxi = max(maxi, each.second);
                    mini = min(mini, each.second);
                }

                beautysum += (maxi - mini);
            }
        }
        
        return beautysum;
        
    }
};