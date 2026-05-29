class Solution {
public:
    int mySqrt(int x) {
        
        if(x == 0 || x == 1) {
            return x;
        }

        int left = 0;
        int right = x;

        while(left <= right) {

            int mid = left + (right - left) / 2;
            long long square = (long long)mid * mid;
            if(square > x) {
                right = mid - 1;
            } else if(square == x) {
                return mid;
            } else {
                left = mid + 1;
            }
            
        }

        return right;

    }
};