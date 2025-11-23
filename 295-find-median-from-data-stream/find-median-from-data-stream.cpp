class MedianFinder {
public:
    priority_queue<int> low;
    priority_queue<int, vector<int>, greater<int>> high;

    MedianFinder() {}

    void addNum(int num) {

        low.push(num);

        high.push(low.top());
        low.pop();

        if (low.size() < high.size()) {
            low.push(high.top());
            high.pop();
        }
    }

    double findMedian() {
        if (low.size() > high.size()) {
            return low.top();
        }

        return (low.top() + high.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */