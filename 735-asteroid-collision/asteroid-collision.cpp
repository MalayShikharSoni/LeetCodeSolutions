class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;

        for(int ast : asteroids) {

            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && ast < 0) {

                if(st.top() < -ast) {
                  
                    st.pop();
                
                } else if(st.top() == -ast) {

                    st.pop();
                    destroyed = true;
                    break;

                } else {

                    destroyed = true;
                    break;

                }

            }

            if(!destroyed) {
                st.push(ast);
            }

        }

        int size = st.size();
        if(size == 0) return {};

        vector<int> ans(size);
        for(int i = size - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;

    }
};