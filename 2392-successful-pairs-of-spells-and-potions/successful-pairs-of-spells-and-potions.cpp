class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        int m=potions.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int start=0;
            int end=m-1;
            int lowerBound=-1;
            while(start<=end){
                int mid=start+(end-start)/2;
                if((long long)potions[mid]*spells[i]>=success){
                    lowerBound=mid;
                    end=mid-1;
                } else {
                    start=mid+1;
                }
            }
            ans[i]=m-start;
        }
        return ans;
    }
};