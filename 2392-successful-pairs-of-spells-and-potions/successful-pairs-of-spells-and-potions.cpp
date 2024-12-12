class Solution {
public:
    int helper(int n, vector<int>&portions, long long success){
        int l=0;
        int h=portions.size()-1;
        int ans=portions.size();
        while(l<=h){
            int m=(h+(l-h)/2);
            long long strength=(long long)portions[m]*n;
            if(strength>=success){
                ans=m;
                h=m-1;
            } else {
                l=m+1;
            }
        }
        return portions.size()-ans;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& portions, long long success) {
        sort(portions.begin(),portions.end());
        vector<int>ans;
        for(int n : spells){
            ans.push_back(helper(n,portions,success));
        }
        return ans;
    }
};