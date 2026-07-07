class Solution {
public:
    vector<int> tree;
    void build(int node, int start, int end, vector<int>& arr) {

        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;

        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    
    }

    void update(int node, int start, int end, int idx) {
    
        if (start == end) {
            tree[node]++;
            return;
        }

        int mid = (start + end) / 2;

        if (idx <= mid)
            update(2 * node, start, mid, idx);
        else
            update(2 * node + 1, mid + 1, end, idx);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    
    }

    int query(int node, int start, int end, int l, int r) {
    
        if (r < start || end < l)
            return 0;      

        if (l <= start && end <= r)
            return tree[node]; 

        int mid = (start + end) / 2;

        int left = query(2 * node, start, mid, l, r);
        int right = query(2 * node + 1, mid + 1, end, l, r);

        return left + right;
    
    }
    
    int binarySearch(int val, vector<int>& arr) {
        
        int left = 0;
        int right = arr.size() - 1;

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(arr[mid] == val) {
                return mid;
            } else if(arr[mid] < val) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

        }
            
        return -1;

    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        vector<int> ans(nums.size());
        vector<int> arr = nums;

        sort(arr.begin(), arr.end());

        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        int m = arr.size();
        tree.resize(4 * m, 0);
        vector<int> freq(m, 0);
        
        build(1, 0, m - 1, freq);

        for(int i = nums.size() - 1; i >= 0; i--) {

            int sortedIndex = binarySearch(nums[i], arr);

            if(sortedIndex == 0) {
                ans[i] = 0;
            } else {
                ans[i] = query(1, 0, m - 1, 0, sortedIndex - 1);
            }

            update(1, 0, m - 1, sortedIndex);

        }

        return ans;

    }
};