class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        
        vector<int> stack;

        for(int num : nums) {

            while(!stack.empty()) {
                int top = stack.back();
                int gc = gcd(top, num);

                if(gc == 1) {
                    break;
                }

                stack.pop_back();

                long long merged = (long long) top / gc * num;
                num = (int)merged;
            }

            stack.push_back(num);

        }

        return stack;

    }

    int gcd(int a, int b) {

        if(b == 0) return a;

        return gcd(b, a % b);

    }
};