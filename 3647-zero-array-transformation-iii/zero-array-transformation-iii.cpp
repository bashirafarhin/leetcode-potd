class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        sort(q.begin(),q.end());
        priority_queue<int,vector<int>,greater<int>>chosen;
        priority_queue<int>candidates;
        int j=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            while(j<q.size() && q[j][0]==i){
                candidates.push(q[j][1]);
                j++;
            }
            nums[i]-=chosen.size();
            while(nums[i]>0 && !candidates.empty() && candidates.top()>=i){
                ans++;
                nums[i]--;
                chosen.push(candidates.top());
                candidates.pop();
            }
            if(nums[i]>0){ return -1; }
            while(!chosen.empty() && chosen.top()<=i){
                chosen.pop();
            }
        
        }
        return q.size()-ans;
    }
};