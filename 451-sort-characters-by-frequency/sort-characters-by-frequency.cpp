class Solution {
public:
    string frequencySort(string s) {
        map<char, int> mpp;
        for (char c : s) {
            mpp[c]++;
        }

        vector<pair<char, int>> vec(mpp.begin(), mpp.end());

        sort(vec.begin(), vec.end(),
             [](const auto& a, const auto& b) { return a.second > b.second; });

        string ans;
        for (const auto& x : vec) {
            ans += string(x.second, x.first);
        }

        return ans;
    }
};