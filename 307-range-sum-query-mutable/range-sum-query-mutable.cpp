class NumArray {
public:

    vector<int> arr;
    vector<int> tree;
    int n;

    void build(int node, int start, int end) {

        if(start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end - start) / 2;

        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);

        tree[node] = tree[2 * node] + tree[2 * node + 1];

    }

    void updateTree(int node, int start, int end, int index, int value) {

        if(start == end) {
            arr[index] = value;
            tree[node] = value;
            return; 
        }

        int mid = start + (end - start) / 2;

        if(index <= mid) {
            updateTree(2 * node, start, mid, index, value);
        } else {
            updateTree(2 * node + 1, mid + 1, end, index, value);
        }

        tree[node] = tree[2 * node] + tree[2 * node + 1];

    }

    int query(int node, int start, int end, int left, int right) {

        if(right < start || left > end) {
            return 0;
        }

        if(left <= start && end <= right) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;

        int leftSum = query(2 * node, start, mid, left, right);
        int rightSum = query(2 * node + 1, mid + 1, end, left, right);

        return leftSum + rightSum;

    }

    NumArray(vector<int>& nums) {
        
        arr = nums;
        n = arr.size();
        
        tree.resize(4 * n);
        build(1, 0, n - 1);

    }
    
    void update(int index, int val) {
        
        updateTree(1, 0, n - 1, index, val);

    }
    
    int sumRange(int left, int right) {
        
        return query(1, 0, n - 1, left, right);

    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */