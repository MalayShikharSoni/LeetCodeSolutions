class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {

        int shift = 0;
        vector<long long> lengths;
        long long length = 1;

        for (int i = 0; i < operations.size(); i++) {
            length *= 2;
            lengths.push_back(length);

            if (length >= k) {
                break;
            }
        }

        for (int i = lengths.size() - 1; i >= 0; i--) {

            long long half = lengths[i] / 2;
            int o = operations[i];

            if (k > half) {
                k -= half;
                if (o == 1) {
                    shift++;
                }
            }
        }

        return (char)(((shift) % 26) + 'a');
    }
};