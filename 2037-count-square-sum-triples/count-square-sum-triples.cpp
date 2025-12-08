class Solution {
public:
    int countTriples(int n) {

        int count = 0;
        
        for(int a = 1; a <= n - 1; a++) {
            
            for(int b = 1; b <= n - 1; b++) {

                int cSquare = a * a + b * b;
                int cSecond = (int)sqrt(cSquare);

                if(cSecond * cSecond == cSquare && cSecond <= n) {
                    cout << a << " " << b << " " << cSquare  << " " << cSecond <<  endl;
                    count++;
                }

            }

        }

        return count;

    }
};