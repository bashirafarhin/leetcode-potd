class Solution {
public:
/*
find contribution of each element
eg contribution of 1
 in left subarray {3} {}
 in right subarray {1} {12} {124}
 total subarray in which 1 is minimum is 6



 build left and right subarray which are having contribution of each element on left and right parts
 3 1 2 4
  left [ 1 2 1 1]
  right [1 3 2 1]

  build these subarrays using stack
*/
    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        stack<pair<int,int>>sleft;
        vector<int>left(n,1);

        for(int i=0;i<n;i++){
            int cnt=1;
            while(!sleft.empty() && sleft.top().first>nums[i]){
                cnt+=sleft.top().second;
                sleft.pop();
            }
            sleft.push({nums[i],cnt});
            left[i]=sleft.top().second;
        }

        stack<pair<int,int>>sright;
        vector<int>right(n,1);

        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!sright.empty() && sright.top().first>=nums[i]){
                cnt+=sright.top().second;
                sright.pop();
            }
            sright.push({nums[i],cnt});
            right[i]=sright.top().second;
        }

        long mod=1e9+7;
        long ans=0;
        for(int i=0;i<n;i++){
            ans=( ans+ left[i]*right[i]*(long)nums[i] )%mod;
        }
        return (int)ans;
    }
};