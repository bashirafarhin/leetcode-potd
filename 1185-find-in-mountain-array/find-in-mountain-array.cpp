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
    int peakIndex(MountainArray &mountainArr){
        int l=0;
        int h=mountainArr.length()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(mountainArr.get(m)<=mountainArr.get(m+1)){
                l=m+1;
            } else {
                h=m-1;
            }
        }
        return l;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        // Peak Index in a Mountain Array
        int ind=peakIndex(mountainArr);
        int l=0;
        int h=ind;
        int ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(mountainArr.get(m)==target){
                ans=m;
            }
            if(target<=mountainArr.get(m)){
                h=m-1;
            } else {
                l=m+1;
            }
        }
        if(ans !=-1){ return ans; }

        l=ind+1;
        h=mountainArr.length()-1;
        while(l<=h){
            int m=(l+h)/2;
            if(mountainArr.get(m)==target){
                return m;
            }
            if(target<=mountainArr.get(m)){
                l=m+1;
            } else {
                h=m-1;
            }
        }
        return ans;

    }
};