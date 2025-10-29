class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        double ans = -1;

        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> num3;
        int k = 0;
        int i = 0;
        int j = 0;
        bool flag = false;
        int mid = (len1 + len2) / 2;  // <---- stored as int

        if ((len1 + len2) % 2 == 0) {
            while (i < len1 && j < len2) {
                if (k == mid + 1) {
                    flag = true;
                    break;
                }
                if (num1[i] > num2[j]) {
                    num3.push_back(num2[j++]);
                    k++;
                } else {
                    num3.push_back(num1[i++]);
                    k++;
                }
            }
            if (!flag) {
                while (i < len1) {
                    if (k == mid + 1) {
                        flag = true;
                        break;
                    }
                    num3.push_back(num1[i++]);
                    k++;
                }
                while (j < len2) {
                    if (k == mid + 1) {
                        flag = true;
                        break;
                    }
                    num3.push_back(num2[j++]);
                    k++;
                }
            }
            ans = (num3[k - 1] + num3[k - 2]) / 2.0;

        } else {
            while (i < len1 && j < len2) {
                if (k == mid + 1) {
                    flag = true;
                    break;
                }
                if (num1[i] > num2[j]) {
                    num3.push_back(num2[j++]);
                    k++;
                } else {
                    num3.push_back(num1[i++]);
                    k++;
                }
            }
            if (!flag) {
                while (i < len1) {
                    if (k == mid + 1) {
                        flag = true;
                        break;
                    }
                    num3.push_back(num1[i++]);
                    k++;
                }
                while (j < len2) {
                    if (k == mid + 1) {
                        flag = true;
                        break;
                    }
                    num3.push_back(num2[j++]);
                    k++;
                }
            }

            ans = num3[k - 1];

        }
        return ans;
    }
};
