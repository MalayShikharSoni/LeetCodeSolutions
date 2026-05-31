class Solution {
public:
    unordered_map<string, vector<string>> adj;
    unordered_map<string, string> emailToName;
    unordered_set<string> visited;

    void dfs(string email, vector<string>& emails) {

        visited.insert(email);
        emails.push_back(email);

        for(string neighbor : adj[email]) {

            if(!visited.count(neighbor)) {
                dfs(neighbor, emails);
            }

        }

    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        for(auto& account : accounts) {

            string name = account[0];

            for(int i = 1; i < account.size(); i++) {
                
                string currMail = account[i];
                emailToName[currMail] = name;

                if(i > 1) {

                    string firstMail = account[1];

                    adj[firstMail].push_back(currMail);
                    adj[currMail].push_back(firstMail);

                }

            }

        }

        vector<vector<string>> ans;

        for(auto& [email, name] : emailToName) {

            if(!visited.count(email)) {

                vector<string> emails;

                dfs(email, emails);

                sort(emails.begin(), emails.end());

                vector<string> merged;
                merged.push_back(name);

                for(auto& e : emails) {
                    merged.push_back(e);
                }

                ans.push_back(merged);                
            }

        }

        return ans;

    }
};