class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n=nums.size();

      unordered_set<int>st(nums.begin(),nums.end());
      vector<int>arr;
      for(int n : st){
        arr.push_back(n);
      }
      sort(arr.begin(),arr.end());
      n=arr.size();

      int ans=0;
      int j=0;
      for(int i=1;i<n;i++){
        while(i<n && arr[i-1]==arr[i]-1){
            i++;
        }
        ans=max(ans,i-j);
        j=i;
      }
      ans=max(ans,n-j);
      return ans;  
    }
};