class Solution {
public:
    bool perfectSquare(int n) {

        if (n == 1)
            return true;
        if (n == 4) 
            return true;
        int left = 1;

        int right = n / 2;

        while (left < right) {

            int mid = left + (right - left) / 2;
            if (mid * mid == n)
                return true;

            else if (mid * mid >= n) {
                right = mid;
            }

            else {
                left = mid + 1;
            }
        }

        return false;
    }

    int countTriples(int n) {

        int count = 0;

        for(int a = 1; a <= n - 1; a++) {

            for(int b = 1; b <= n - 1; b++) {

                int cSquare = a * a + b * b;
                // int cSecond = (int)sqrt(cSquare);

                // if(cSecond * cSecond == cSquare && cSecond <= n) {
                //     cout << a << " " << b << " " << cSquare  << " " <<
                // cSecond <<  endl;
                //     count++;
                // }

                if(perfectSquare(cSquare) && (sqrt(cSquare)) <= n){
                    cout << a << " " << b << " "  << cSquare <<  endl;
                    count++;
                }

            }

        }

        return count;

        // for (int i = 1; i < n * n; i++) {
        //     if (perfectSquare(i)) {
        //         cout << i << endl;
        //     }
        // }
        // return 0;
    }
};