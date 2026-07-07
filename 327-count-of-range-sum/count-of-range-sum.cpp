class Solution {
public:
    vector<long long> tree;

    void update(int node, int start, int end, int idx) {

        if(start == end) {
            tree[node]++;
            return;
        }

        int mid = start + (end - start) / 2;

        if(idx <= mid) {
            update(2 * node, start, mid, idx);
        } else {
            update(2 * node + 1, mid + 1, end, idx);
        }

        tree[node] = tree[2 * node] + tree[2 * node + 1];

    }

    long long query(int node, int start, int end, int left, int right) {

        if(left > end || right < start) {
            return 0;
        }

        if(left <= start && right >= end) {
            return tree[node];
        }

        int mid = start + (end - start) / 2;

        int leftSum = query(2 * node, start, mid, left, right);
        int rightSum = query(2 * node + 1, mid + 1, end, left, right);

        return leftSum + rightSum;

    }

    int lowerBound(long long val, vector<long long>& arr) {

        int left = 0;
        int right = arr.size() - 1;
        int ans = arr.size();

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(arr[mid] >= val) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }        

        return ans;

    }

    int upperBound(long long val, vector<long long>& arr) {

        int left = 0;
        int right = arr.size() - 1;
        int ans = arr.size();

        while(left <= right) {

            int mid = left + (right - left) / 2;

            if(arr[mid] > val) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }

        return ans - 1;

    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {

        vector<long long> prefix;
        prefix.push_back(0);

        long long sum = 0;

        for(int num : nums) {
            sum += num;
            prefix.push_back(sum);
        }

        vector<long long> arr = prefix;

        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());

        int m = arr.size();
        tree.resize(4 * m, 0);

        long long ans = 0;

        for(long long pre : prefix) {

            long long leftVal = pre - upper;  
            long long rightVal = pre - lower;

            int leftIndex = lowerBound(leftVal, arr);
            int rightIndex = upperBound(rightVal, arr);

            if(leftIndex <= rightIndex) {
                ans += query(1, 0, m - 1, leftIndex, rightIndex);
            }

            int idx = lowerBound(pre, arr);
            update(1, 0, m - 1, idx);

        }

        return (int)ans;

    }
};