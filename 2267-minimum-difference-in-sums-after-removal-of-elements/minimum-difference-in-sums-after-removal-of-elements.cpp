class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int k = n / 3;

        vector<long long> minSumPrefix(n);
        vector<long long> maxSumSuffix(n);

        priority_queue<int> leftMaxHeap;
        priority_queue<int, vector<int>, greater<int>> rightMinHeap;

        long long currMinSum = 0;
        long long currMaxSum = 0;
        long long ans = LLONG_MAX;

        for (int i = 0; i < k; i++) {
            leftMaxHeap.push(nums[i]);
            currMinSum += nums[i];
        }

        minSumPrefix[k - 1] = currMinSum;

        for (int i = k; i < n - k; i++) {
            if (!leftMaxHeap.empty() && nums[i] < leftMaxHeap.top()) {

                currMinSum -= leftMaxHeap.top();
                leftMaxHeap.pop();
                leftMaxHeap.push(nums[i]);
                currMinSum += nums[i];
            }

            minSumPrefix[i] = currMinSum;
        }

        for (int i = n - 1; i >= n - k; i--) {
            rightMinHeap.push(nums[i]);
            currMaxSum += nums[i];
        }

        maxSumSuffix[n - k] = currMaxSum;

        for (int i = n - k - 1; i >= k; i--) {
            if (!rightMinHeap.empty() && nums[i] > rightMinHeap.top()) {
                currMaxSum -= rightMinHeap.top();
                rightMinHeap.pop();
                rightMinHeap.push(nums[i]);
                currMaxSum += nums[i];
            }

            maxSumSuffix[i] = currMaxSum;
        }

        for (int i = k - 1; i < n - k; i++) {
            ans = min(ans, minSumPrefix[i] - maxSumSuffix[i + 1]);
        }

        return ans;
    }
};