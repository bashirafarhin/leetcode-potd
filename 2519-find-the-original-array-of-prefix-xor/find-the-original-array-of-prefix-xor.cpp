class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
     vector<int> ans;
     int n=pref.size();
     ans.push_back(pref[0]);
     for(int i=1;i<n;i++){
         int x=pref[i] xor pref[i-1];
         ans.push_back(x);
     }
     return ans;
    }
};