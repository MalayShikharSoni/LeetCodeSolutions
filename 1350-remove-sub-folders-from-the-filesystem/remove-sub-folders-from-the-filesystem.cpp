class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        vector<string> ans;

        sort(folder.begin(), folder.end());

        for (auto& f : folder) {

            if (ans.empty()) {
                ans.push_back(f);
            } else {
                string latest = ans.back();

                if (f.find(latest) == 0 && f.size() > latest.size() &&
                    f[latest.size()] == '/') {
                    continue;
                } else {
                    ans.push_back(f);
                }
            }
        }

        return ans;
    }
};