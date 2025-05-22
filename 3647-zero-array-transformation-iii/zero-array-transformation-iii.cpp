class Solution {
public:
// method 1
// trying all the combinations using recursion

// method 2
// for nums[i]=n you have to pick n queries which will include index i so that it can becomes 0
// so will be picking those which will make others 0 also on the right side that is who have highest
// ending point
    int maxRemoval(vector<int>& nums, vector<vector<int>>& q) {
        sort(q.begin(),q.end());
        int ans=0;
        int j=0;
        priority_queue<int,vector<int>,greater<int>>chosen; // min-heap
        priority_queue<int>candidates; // max-heap
        for(int i=0;i<nums.size();i++){
                nums[i]-=chosen.size();
                while(j<q.size() && q[j][0]==i){
                    candidates.push(q[j][1]);
                    j++;
                }
                while(nums[i]>0 && !candidates.empty() && candidates.top()>=i){
                    ans++;
                    nums[i]--;
                    chosen.push(candidates.top());
                    candidates.pop();
                }
                if(nums[i]>0){ return -1; }
                while(!chosen.empty() && chosen.top()==i){
                    chosen.pop();
                }
            
        }
        return q.size()-ans;
    }
};