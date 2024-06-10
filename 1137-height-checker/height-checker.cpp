class Solution {
public:
    int heightChecker(vector<int>& heights) {
      int n=heights.size();
      vector<int>expected;
      for(int i=0;i<heights.size();i++){ expected.push_back(heights[i]); }
      sort(expected.begin(),expected.end());
      int ans=0;
      for(int i=0;i<n;i++){
        ans+= (expected[i]==heights[i]) ? 0 : 1 ;
      }
      return ans;
    }
};