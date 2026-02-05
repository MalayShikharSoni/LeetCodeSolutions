class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int maxArea = 0;
        stack<int> st;
        int n = heights.size();

        for(int i = 0; i <= n; i++) {

            int currHeight;
            if(i == n) {
                currHeight = 0;
            } else {
                currHeight = heights[i];
            }
            
            while(!st.empty() && currHeight < heights[st.top()]) {

                int height = heights[st.top()];
                st.pop();

                int width;
                if(st.empty()) {
                    width = i;
                } else {
                    width = i - st.top() - 1;
                }

                maxArea = max(maxArea, width * height);

            }

            st.push(i);

        }

        return maxArea;

    }
};