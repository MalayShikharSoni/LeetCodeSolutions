class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        
        if(arr.size() <= 1) {
            return arr.size();
        }

        int status = 0;
        int maxLen = 1;
        int len = 1;

        for(int i = 1; i < arr.size(); i++) {

            if(status == 0) {

                if(arr[i - 1] > arr[i]) {
                    status = -1;
                    len += 1;
                    maxLen = max(maxLen, len);
                } else if(arr[i - 1] < arr[i]){
                    status = 1;
                    len += 1;
                    maxLen = max(maxLen, len);
                } else {
                    status = 0;
                    len = 1;
                }

            } else if(status == -1) {

                if(arr[i - 1] < arr[i]) {
                    status = 1;
                    len += 1;
                    maxLen = max(maxLen, len);
                } else if(arr[i - 1] > arr[i]) {
                    len = 2;
                    status = -1;
                } else {
                    len = 1;
                    status = 0;
                }

            } else if(status == 1) {

                if(arr[i - 1] > arr[i]) {
                    status = -1;
                    len += 1;
                    maxLen = max(maxLen, len);
                } else if(arr[i - 1] < arr[i]){
                    len = 2;
                    status = 1;
                } else {
                    len = 1;
                    status = 0;
                }

            }

        }

        return maxLen;

    }
};