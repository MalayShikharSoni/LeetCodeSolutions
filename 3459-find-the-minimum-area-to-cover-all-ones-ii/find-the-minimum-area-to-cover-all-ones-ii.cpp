class Solution {
public:
    int minimumSum(vector<vector<int>>& A) {
        long long res = LLONG_MAX;
        vector<vector<int>> original = A;

        for (int rot = 0; rot < 4; rot++) {
            int n = A.size(), m = A[0].size();

            for (int i = 1; i < n; i++) {
                int a1 = minimumArea(vector<vector<int>>(A.begin(), A.begin() + i));

                for (int j = 1; j < m; j++) {
                    if (j == 0 || j == m) continue;

                    vector<vector<int>> part2(n - i, vector<int>(j));
                    vector<vector<int>> part3(n - i, vector<int>(m - j));

                    for (int r = 0; r < n - i; r++) {
                        copy(A[i + r].begin(), A[i + r].begin() + j, part2[r].begin());
                        copy(A[i + r].begin() + j, A[i + r].end(), part3[r].begin());
                    }

                    int a2 = minimumArea(part2);
                    int a3 = minimumArea(part3);
                    res = min(res, (long long)a1 + a2 + a3);
                }

                for (int i2 = i + 1; i2 < n; i2++) {
                    vector<vector<int>> part2(A.begin() + i, A.begin() + i2);
                    vector<vector<int>> part3(A.begin() + i2, A.end());
                    int a2 = minimumArea(part2);
                    int a3 = minimumArea(part3);
                    res = min(res, (long long)a1 + a2 + a3);
                }
            }

            A = rotate(original, rot + 1);
        }

        return (int)res;
    }

private:
    int minimumArea(const vector<vector<int>>& A) {
        if (A.empty() || A[0].empty()) return 0;
        int n = A.size(), m = A[0].size();
        int left = INT_MAX, top = INT_MAX, right = -1, bottom = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i][j] == 1) {
                    left = min(left, j);
                    top = min(top, i);
                    right = max(right, j);
                    bottom = max(bottom, i);
                }
            }
        }
        if (right == -1) return 0;
        return (right - left + 1) * (bottom - top + 1);
    }

    vector<vector<int>> rotate(const vector<vector<int>>& A, int times) {
        vector<vector<int>> res = A;
        for (int t = 0; t < times; t++) {
            int n = res.size(), m = res[0].size();
            vector<vector<int>> rotated(m, vector<int>(n));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    rotated[j][n - 1 - i] = res[i][j];
                }
            }
            res = rotated;
        }
        return res;
    }
};
