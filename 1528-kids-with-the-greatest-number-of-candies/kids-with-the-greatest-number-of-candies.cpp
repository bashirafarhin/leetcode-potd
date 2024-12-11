class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies=*max_element(candies.begin(),candies.end());
        int n=candies.size();
        vector<bool>ans(n,true);
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies<maxCandies){
                ans[i]=false;
            }
        }
        return ans;
    }
};