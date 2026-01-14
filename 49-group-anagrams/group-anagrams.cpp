class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> groups;

        for(string str : strs) {

            string key = str;
            sort(key.begin(), key.end());
            groups[key].push_back(str);

        }

        for(auto& group : groups) {
            ans.push_back(group.second);
        }

        return ans;

    }
};