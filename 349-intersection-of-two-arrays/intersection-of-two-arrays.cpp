class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int>st;
      unordered_set<int>st_2;
      for(int n : nums1){ st.insert(n); }
      for(int n : nums2){
          if(st.find(n) !=st.end()){ st_2.insert(n); }
      }
      vector<int>ans(st_2.begin(),st_2.end());
      return ans;
    }
};