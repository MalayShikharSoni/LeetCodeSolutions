/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeak(MountainArray& mountainArr) {

        int low = 0;
        int high = mountainArr.length() - 1;

        while(low < high) {
            
            int mid = low + (high - low) / 2;
            
            if(mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }

        return low;

    }

    int searchLeft(MountainArray& mountainArr, int target, int low, int high) {

        while(low <= high) {

            int mid = low + (high - low) / 2;
            int midVal = mountainArr.get(mid);

            if(midVal == target) {
                return mid;
            } else if(midVal < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }


        }

        return -1;
    }

    int searchRight(MountainArray& mountainArr, int target, int low, int high) {

        while(low <= high) {

            int mid = low + (high - low) / 2;
            int midVal = mountainArr.get(mid);

            if(midVal == target) {
                return mid;
            } else if(midVal > target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }


        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int peak = findPeak(mountainArr);

        int left = searchLeft(mountainArr, target, 0, peak);
        if(left != -1) {
            return left;
        }

        return searchRight(mountainArr, target, peak + 1, mountainArr.length() - 1);

    }
};