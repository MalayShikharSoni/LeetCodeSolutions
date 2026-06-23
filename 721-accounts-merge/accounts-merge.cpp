class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x) {

        if (x == parent[x]) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    bool unionSet(int x, int y) {

        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        if (size[rootX] < size[rootY]) {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        } else {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }

        return true;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int emailCount = 0;

        unordered_map<string, string> emailToName;
        unordered_map<string, int> emailToId;

        for(auto& acc : accounts) {

            string name = acc[0];

            for(int i = 1; i < acc.size(); i++) {
                
                string email = acc[i];

                if(emailToId.find(email) == emailToId.end()) {
                    emailToId[email] = emailCount;
                    emailCount++;
                    emailToName[email] = name;
                }

            }

        }

        parent.resize(emailCount);
        size.resize(emailCount, 1);

        for(int i = 0; i < emailCount; i++) {
            parent[i] = i;
        }

        for(auto& acc : accounts) {

            int firstEmailId = emailToId[acc[1]];

            for(int i = 2; i < acc.size(); i++) {
                int nextEmailId = emailToId[acc[i]];
                unionSet(firstEmailId, nextEmailId);
            }

        }

        unordered_map<int, vector<string>> rootToEmails;

        for(auto& pair : emailToId) {

            string email = pair.first;
            int id = pair.second;

            int root = find(id);

            rootToEmails[root].push_back(email);

        }

        vector<vector<string>> merged;

        for(auto& pair : rootToEmails) {

            int root = pair.first;
            vector<string> emails = pair.second;

            sort(emails.begin(), emails.end());

            string name = emailToName[emails[0]];

            vector<string> account;
            account.push_back(name);
            account.insert(account.end(), emails.begin(), emails.end());
            merged.push_back(account);

        }

        return merged;

    }
};