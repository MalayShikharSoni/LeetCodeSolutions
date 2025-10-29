class Solution {
public:
    int smallestNumber(int n) {

        int num = 2;
        while (true) {
            if ((num - 1) >= n)
                return num - 1;
            num *= 2;
        }

        return -1;
    }
};