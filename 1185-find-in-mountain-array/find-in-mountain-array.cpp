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
    int findInLeft(int target, MountainArray &mountainArr,int low, int high){
         //left part is sorted in increasing order
         while(low<=high){
             int mid=low+(high-low)/2;
             int val =mountainArr.get(mid);
             if(val==target) return mid;
             else if( val>target) high =mid-1;
             else low=mid+1;
         }
         return -1;
    }
    int findInRight(int target, MountainArray &mountainArr,int low, int high){
      //right part is sorted in decreasing order
         while(low<=high){
             int mid=low+(high-low)/2;
             int val =mountainArr.get(mid);
             if(val==target) return mid;
             else if(val<target) high =mid-1;
             else low=mid+1;
         }
         return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        //finding peak index first 
        int n=mountainArr.length();
        int peakIndex;
        int low=0, high =n-1;
         while(low<=high){
            int mid=low+(high-low)/2;
            int val =mountainArr.get(mid);
            if(mid==0||val<mountainArr.get(mid+1))
            low=mid+1;
            else if(mid==n-1|| mountainArr.get(mid-1)>val) high=mid-1;
            else 
             {  
                 peakIndex=mid;
                 break;
             }
        }
        if(target==mountainArr.get(peakIndex)) return peakIndex;
        //now finding target in left of the array from 0 to peakIndex-1
        int leftInd= findInLeft(target,mountainArr,0,peakIndex-1);
        //now finding target in right of the array from peakIndex+1 to n-1
        int rightInd= findInRight(target,mountainArr,peakIndex+1,n-1);
        
        if(leftInd!=-1) return leftInd;
        return rightInd!=-1 ? rightInd: -1;
    }

};