class Solution {
public:
    string decodeString(string s) {
        
        stack<int> kValues;
        stack<string> st;

        string ans = "";
        int k = 0;

        for(char c : s) {

            if(isdigit(c)) {

                k = k * 10 + (c - '0');

            } else if(c == '[') {

                st.push(ans);
                ans = "";

                kValues.push(k);
                k = 0;

            } else if(c == ']') {

                string prevStr = st.top();
                st.pop();
                int repeat = kValues.top();
                kValues.pop();

                string temp = "";
                for(int i = 0; i < repeat; i++) {
                    temp += ans; 
                }

                ans = prevStr + temp;

            } else {
                ans += c;
            }

        }

        return ans;

    }
};