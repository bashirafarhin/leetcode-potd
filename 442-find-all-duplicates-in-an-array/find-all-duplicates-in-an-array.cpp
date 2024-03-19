class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        //brute force methods using sets and map
        int n=nums.size();
        vector<int>ans;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            int ind=nums[i]-1;
            if(visited[ind]){
                ans.push_back(nums[i]);
            } else {
                visited[ind]=true;
            }
        }
        return ans;
    }
};