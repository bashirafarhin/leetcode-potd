class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> pre;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            pre.push_back(sum);
        }

        vector<int> ans;
        ans.push_back((pre[n-1]-pre[0])-(n-1)*pre[0]);

        for(int i=1;i<n;i++)
        {
            int curr=0;
            int prev=pre[i-1];
            curr+=(i)*nums[i]-prev;
            curr+=(pre[n-1]-pre[i])-(n-(i+1))*nums[i];
            ans.push_back(curr);
        }
        return ans;
    }
};