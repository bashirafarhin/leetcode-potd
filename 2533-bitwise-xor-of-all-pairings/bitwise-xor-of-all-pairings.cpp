class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        if(!(n1 & 1) && !(n2 & 1)){ return 0; }
        int ans=0;
        if(!((n1 & 1) && (n2 & 1))){
            if(n1 & 1){
                for(int n : nums2){ ans = ans ^ n; }
            } else {
                for(int n : nums1){ ans = ans ^ n; }
            }
            return ans;
        }
        if(nums1.size() & 1){
            for(int n : nums1){ ans = ans ^ n; }
        }
        if(nums2.size() & 1){
            for(int n : nums2){ ans = ans ^ n; }
        }
        return ans;
    }
};