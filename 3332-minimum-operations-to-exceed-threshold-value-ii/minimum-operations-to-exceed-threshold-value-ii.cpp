class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<long long int, vector<long long int>, greater<long long int>> q;

        for(auto it: nums){
            q.push(it);
        }

        long long int count=0;

        while(q.top()<k){
            long long int first = q.top();
            q.pop();

            long long int second = q.top();
            q.pop();

            long long int num = 2*min(first, second) + max(first, second);
            q.push(num);
            count++;

        }

        return count;
    }
};