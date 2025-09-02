class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int count = (n + m) / 2;

        int i = 0;
        int j = 0;
        int prev = 0;
        int curr = 0;
        while (i<n && j<m) {
            prev=curr;
            if (nums1[i] >= nums2[j]) {
                curr=nums2[j];
                j++;
            } else {
                curr=nums1[i];
                i++;
            }
            count--;
            if (count < 0)
                break;
        }

        if(count>=0){
            while(count>=0 && i<n){
                prev=curr;
                curr=nums1[i];
                i++;
                count--;
            }

            while(count>=0 && j<m){
                prev=curr;
                curr=nums2[j];
                j++;
                count--;
            }
        }

        if((n+m)%2){
            return curr;
        }

        return (double)(prev+curr)/(double)2;
        
    }
};