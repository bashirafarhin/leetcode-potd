class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans=0;
        int damage=INT_MAX;
        int count=0;
        for(int node : nums){
            if((node ^ k) >node){
                ans+=node^k;
                count++;
            } else {
                ans+=node;
            }
            damage=min(damage,abs(node-(node^k)));
        }
        if(count & 1){
            ans-=damage;
        }
        return ans;
    }
};