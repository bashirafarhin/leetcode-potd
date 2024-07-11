class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;

        for(int i=0;i<k;i++){
          while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);
        }

        int n=nums.size();
        vector<int>ans;
        ans.push_back(nums[dq[0]]);

        for(int i=k;i<n;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }

            dq.push_back(i);

            if(dq[0]<=i-k){
                dq.pop_front();
            }

            ans.push_back(nums[dq[0]]);
        }
        return ans;
    }
};