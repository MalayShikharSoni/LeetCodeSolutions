class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int maxx = INT_MIN;

        int left = 0;
        int right = height.size() - 1;

        while(left < right) {

            int currArea = (right - left) * min(height[left], height[right]);
            maxx = max(maxx, currArea);


            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }

        }

        return maxx;

    }
};