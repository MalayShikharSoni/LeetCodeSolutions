class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int weekStart = 1; 

        while (n > 0) {
            if (n >= 7) {
                ans += (7 * (2 * weekStart + 6)) / 2;
                weekStart++;
                n -= 7;
            } else {
                for (int i = 0; i < n; i++) {
                    ans += weekStart + i;
                }
                break;
            }
        }

        return ans;
    }
};
