class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int>ans;
        while(i<n1 && j <n2){
            if(nums1[i]==nums2[j]){
                ans.push_back(nums1[i]);
                while(i<n1 && nums1[i]==ans.back()){ i++; }
                while(j<n2 && nums2[j]==ans.back()){ j++; }
            }
            else if(i<n1 && j<n2 && (nums1[i] <nums2[j]) ){ i++; }
            else { j++; }
        }
        return ans;
    }
};