class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<string> st;

        for(int i = 0; i < tokens.size(); i++) {

            if(tokens[i] == "+") {
                int x = stoi(st.top());
                st.pop();

                int y = stoi(st.top());
                st.pop();

                st.push(to_string(x + y));
                cout << st.top() << endl;
            }
            
            else if(tokens[i] == "-") {
                int x = stoi(st.top());
                st.pop();

                int y = stoi(st.top());
                st.pop();

                st.push(to_string(y - x));
                cout << st.top() << endl;

            }
            
            else if(tokens[i] == "*") {
                int x = stoi(st.top());
                st.pop();

                int y = stoi(st.top());
                st.pop();

                st.push(to_string(x * y));
                cout << st.top() << endl;

            }
            
            else if(tokens[i] == "/") {
                int x = stoi(st.top());
                st.pop();
                cout << "x " << x << endl;

                int y = stoi(st.top());
                st.pop();
                cout << "y " << y << endl;

                st.push(to_string(y / x));
                cout << "div" << st.top() << endl;

            }

            else {
                st.push(tokens[i]);
                cout << st.top() << endl;

            }

        }

        return stoi(st.top());

    }
};