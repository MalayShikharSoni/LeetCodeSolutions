class Solution {
public:
    string multiply(string num1, string num2) {

        if(num1 == "0" || num2 == "0")
            return "0";

        int len1 = num1.size();
        int len2 = num2.size();

        vector<int> product(len1 + len2, 0);

        for(int i = len1 - 1; i >= 0; i--) {
            for(int j = len2 - 1; j >= 0; j--) {

                int n1 = num1[i] - '0';
                int n2 = num2[j] - '0';

                int mul = n1 * n2;

                int low = i + j + 1;
                int high = i + j;

                int sum = mul + product[low];

                product[low] = sum % 10;
                product[high] += sum / 10;
            }
        }

        string ans;

        for(int p : product) {
            if(ans.empty() && p == 0) continue;
            ans += to_string(p);
        }

        return ans;
    }
};