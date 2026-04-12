class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int a = 0;
        int n = nums.size();
        k = k % n;
        int arr[n];

        for (int i = n - k; i < n; i++) {
            arr[a] = nums[i];
            a++;
        }
        for (int i = 0; i < n - k; i++) {
            arr[a] = nums[i];
            a++;
        }
        for (int i = 0; i < n; i++) {
            nums[i] = arr[i];
        }
    }
};