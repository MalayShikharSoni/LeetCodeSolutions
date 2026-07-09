        class Solution {
        public:
            vector<long long> tree;
            vector<bool> lazy;

            void build(int node, int start, int end, vector<int>& arr) {

                if(start == end) {
                    tree[node] = arr[start];
                    return;
                }

                int mid = start + (end - start) / 2;

                build(2 * node, start, mid, arr);
                build(2 * node + 1, mid + 1, end, arr);

                tree[node] = tree[2 * node] + tree[2 * node + 1];

            }

            void applyFlip(int node, int start, int end) {

                tree[node] = (end - start + 1) - tree[node];
                lazy[node] = !lazy[node];

            }

            void push(int node, int start, int end) {
                
                if(!lazy[node]) {
                    return;
                }
                
                if(start != end) {

                    int mid = start + (end - start) / 2;

                    applyFlip(2 * node, start, mid);
                    applyFlip(2 * node + 1, mid + 1, end);
                
                }

                lazy[node] = false;

            }

            void update(int node, int start, int end, int left, int right) {

                if(end < left || right < start) {
                    return;
                }

                if(left <= start && end <= right) {
                    applyFlip(node, start, end);
                    return;
                }

                push(node, start, end);

                int mid = start + (end - start) / 2;

                update(2 * node, start, mid, left, right);
                update(2 * node + 1, mid + 1, end, left, right);

                tree[node] = tree[2 * node] + tree[2 * node + 1];

            }
        
            vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {

                int n = nums1.size();
                tree.resize(4 * n, 0);
                lazy.resize(4 * n, false);

                build(1, 0, n - 1, nums1);

                long long sum = 0;
                for(int num : nums2) {
                    sum += num;
                }

                vector<long long> ans;

                for(auto& query : queries) {

                    if(query[0] == 1) {

                        update(1, 0, n - 1, query[1], query[2]);

                    } else if(query[0] == 2) {

                        int p = query[1];
                        long long ones = tree[1];

                        sum += p * ones;

                    } else {

                        ans.push_back(sum);

                    }

                }

                return ans;

            }
        };