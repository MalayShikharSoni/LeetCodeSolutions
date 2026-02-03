class MinStack {

private:
    vector<vector<int>> st;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minn = getMin();

        if(st.empty() || val < minn) {
            minn = val;
        }

        st.push_back({val, minn});
    }
    
    void pop() {
        return st.pop_back();
    }
    
    int top() {
        if(!st.empty()) {
            return st.back()[0];
        }
        
        return -1;
    }
    
    int getMin() {
        if(!st.empty()) {
            return st.back()[1];
        }

        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */