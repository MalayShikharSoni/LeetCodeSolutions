class FreqStack {
public:
    FreqStack() {
        
    }

    int maxFreq = 0;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> freqStack;
    
    void push(int val) {
        
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        freqStack[freq[val]].push(val);

    }
    
    int pop() {
        
        int top = freqStack[maxFreq].top();
        freqStack[maxFreq].pop();
        freq[top]--;
        if(freqStack[maxFreq].empty()) {
            maxFreq--;
        }

        return top;

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */