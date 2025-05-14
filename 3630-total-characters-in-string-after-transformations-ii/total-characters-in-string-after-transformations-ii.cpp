class Solution {
public:
    const int mod = 1e9 + 7;

    vector<vector<long long>> multiplyMatrices(const vector<vector<long long>> &A, const vector<vector<long long>> &B) {
        int rowsA = A.size(), colsA = A[0].size(), colsB = B[0].size();
        vector<vector<__int128_t>> temp(rowsA, vector<__int128_t>(colsB, 0));
        vector<vector<long long>> result(rowsA, vector<long long>(colsB, 0));

        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                for (int k = 0; k < colsA; k++) {
                    temp[i][j] += A[i][k] * B[k][j];
                }
                result[i][j] = temp[i][j] % mod;
            }
        }
        return result;
    }

    vector<vector<long long>> powerMatrix(vector<vector<long long>> matrix, long long exponent) {
        vector<vector<long long>> result(matrix.size(), vector<long long>(matrix.size(), 0));

        for (int i = 0; i < matrix.size(); i++) result[i][i] = 1;

        while (exponent > 0) {
            if (exponent % 2 == 1) result = multiplyMatrices(result, matrix);
            matrix = multiplyMatrices(matrix, matrix);
            exponent /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<long long>> transform(26, vector<long long>(26, 0));

        for (int i = 0; i < 26; i++) {
            for (int shift = 0; shift < nums[i]; shift++) {
                transform[i][(i + 1 + shift) % 26]++;
            }
        }

        transform = powerMatrix(transform, t);
        vector<vector<long long>> freq(1, vector<long long>(26, 0));
        for (char ch : s) {
            freq[0][ch - 'a']++;
        }

        freq = multiplyMatrices(freq, transform);
        int totallength = 0;
        for (int count : freq[0]) {
            totallength += count;
            if (totallength >= mod) totallength -= mod;
        }

        return totallength;
    }
};