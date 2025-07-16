class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return countReversePairs(nums, 0, nums.size() - 1);
    }

private:
    int countReversePairs(vector<int>& nums, int left, int right) {
        if (left >= right)
            return 0;

        int mid = left + (right - left) / 2;

        int count = countReversePairs(nums, left, mid) +
                    countReversePairs(nums, mid + 1, right);

        int i = left;
        int j = mid + 1;
        int p = mid + 1;
        int k = 0;

        vector<int> merged(right - left + 1);

        while (i <= mid) {
            while (p <= right && (long long)nums[i] > 2LL * nums[p]) {
                p++;
            }
            count += p - (mid + 1);

            while (j <= right && nums[i] >= nums[j]) {
                merged[k++] = nums[j++];
            }

            merged[k++] = nums[i++];
        }

        while (j <= right) {
            merged[k++] = nums[j++];
        }

        for (int x = 0; x < merged.size(); ++x) {
            nums[left + x] = merged[x];
        }

        return count;
    }
};
