class Solution {
public:
    string simplifyPath(string path) {

        vector<string> st;
        int i = 0;

        while(i < path.size()) {

            while(i < path.size() && path[i] == '/') {
                i++;
            }   

            string temp = "";
            while(i < path.size() && path[i] != '/') {
                temp += path[i];
                i++;
            }

            if(temp == "." || temp == "") {
              
                continue;
            
            } else if(temp == "..") {
                
                if(!st.empty()) {
                    st.pop_back();
                }

            } else {
                st.push_back(temp);
            }

            i++;

        }

        string ans = "";

        for(string s : st) {
            ans += "/" + s;
        }

        return ans.empty() ? "/" : ans;
        
    }
};