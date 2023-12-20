class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
     int n=arr.size();
     int ql=queries.size();
     vector<int> ans(ql,0);
     for(int i=1;i<n;i++){
       arr[i]=arr[i]^arr[i-1];
     }
     for (int i=0;i<ql;i++){
         int l=queries[i][0];
         int r=queries[i][1];
         ans[i]=arr[r];
         if(l !=0){ ans[i]=ans[i] ^ arr[l-1];}
     }
     return ans;
    }
};