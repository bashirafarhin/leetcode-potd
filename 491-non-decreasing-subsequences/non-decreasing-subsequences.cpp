class Solution {
    void recur(vector<int>&nums,int i,set<vector<int>>&st,vector<int>&smallans){
     if(i==nums.size()){
         if(smallans.size()>1){st.insert(smallans);}
         return ;}
     int len=smallans.size();
     if(len==0 || smallans[len-1] <=nums[i]){
       smallans.push_back(nums[i]);
       recur(nums,i+1,st,smallans);
       smallans.pop_back();}
     recur(nums,i+1,st,smallans);
     return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
    set<vector<int>> st;
    vector<int>smallans;
    recur(nums,0,st,smallans);
    vector<vector<int>>ans;
    for(auto vec : st){ans.push_back(vec);}
    return ans;
    }
};