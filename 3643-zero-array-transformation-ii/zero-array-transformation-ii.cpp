class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int i=0;
        int maxi=*max_element(nums.begin(),nums.end());
        if(maxi==0){ return 0; }
        vector<int>prefix(n+1,0);
        for(int k=0;k<queries.size();k++){
            int l=queries[k][0];
            int r=queries[k][1];
            int val=queries[k][2];
            if(l<=i && i<=r){
                prefix[i]+=val;
                prefix[r+1]-=val;
            } else if(l>i) {
                prefix[l]+=val;
                prefix[r+1]-=val;
            }
            
            while(i<n){
                if(nums[i]<=prefix[i]){          
                i++;
                prefix[i]+=prefix[i-1];
                } else {
                    break;
                }
            }
            if(i>=n){
                return k+1;
            }
        }
        return -1;
    }
};