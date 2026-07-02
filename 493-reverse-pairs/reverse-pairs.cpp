class Solution {
public:
    vector<long long> values;
    vector<int> tree;
    
    void update(int node, int start, int end, int index) {

        if(start == end) {
            tree[node]++;
            return;
        }

        int mid = start + (end - start) / 2;

        if(index <= mid) {
            update(2 * node, start, mid, index);
        } else {
            update(2 * node + 1, mid + 1, end, index);
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


    int reversePairs(vector<int>& nums) {

        for(int num : nums) {
            values.push_back((long long)num);
            values.push_back(2LL * (long long)num);
        }

        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());



        int m = values.size();
        tree.resize(4 * m, 0);

        int ans = 0;

        for(int i = nums.size() - 1; i >= 0; i--) {

            int rankNum = lower_bound(values.begin(), values.end(), (long long)nums[i]) - values.begin() + 1;
            ans += query(1, 1, m, 1, rankNum - 1);

            int rankDouble = lower_bound(values.begin(), values.end(), 2LL * (long long)nums[i]) - values.begin() + 1;
            update(1, 1, m, rankDouble);

        }

        return ans;

    }
};