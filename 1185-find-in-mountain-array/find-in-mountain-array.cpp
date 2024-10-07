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
    int incArr(int l, int h, int& target, MountainArray& arr) {
        int ans = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (arr.get(m)==target) { return m; }
            if (arr.get(m) > target) {
                    h = m-1;
            } else {
                l = m+1;
            }
        }
        return -1;
    }

    int decArr(int l, int h, int& target, MountainArray& arr) {
        int ans = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            if (arr.get(m)==target) { return m; }
            if (arr.get(m) > target) {
                    l = m+1;
            } else {
                h = m-1;
            }
        }
        return ans;
    }

    int peakIndex(MountainArray& arr) {
        int l = 0;
        int h = arr.length() - 1;
        int ans = h;
        while (l <= h) {
            int m = (l + h) / 2;
            ans = m;
            if (arr.get(m - 1) < arr.get(m)) {
                if (arr.get(m) < arr.get(m + 1)) {
                    l = m;
                } else {
                    h = m;
                    break;
                }
            } else {
                h = m;
            }
        }
        return ans;
    }

    int findInMountainArray(int target, MountainArray& mountainArr) {
        int pi = peakIndex(mountainArr);
        int leftInd = incArr(0, pi, target, mountainArr);
        if (leftInd == -1) {
            return decArr(pi, mountainArr.length() - 1, target, mountainArr);
        }
        return leftInd;
    }
};