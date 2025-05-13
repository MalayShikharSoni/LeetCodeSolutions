class Solution {
public:
    long long mod = 1000000007LL;

    int lengthAfterTransformations(string s, int t) {

        vector<long long> arr(26, 0);

        for (char c : s) {
            arr[c - 'a']++;
        }

        while (t > 0) {

            vector<long long> temp(26, 0);

            for (int i = 0; i < 25; i++) {
                temp[i + 1] = arr[i];
            }

            temp[0] = (temp[0] + arr[25]) % mod;
            temp[1] = (temp[1] + arr[25]) % mod;

            arr = temp;
            t--;
        }
        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            ans = (ans + arr[i]) % mod;
        }

        return ans;
    }
};