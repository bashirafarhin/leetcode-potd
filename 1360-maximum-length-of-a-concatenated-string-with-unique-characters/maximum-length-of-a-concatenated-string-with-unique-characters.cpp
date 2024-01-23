class Solution {
    int solve(int i,vector<string>& arr,string s){
        if(i==arr.size()){return s.size();}
        string combined=arr[i]+s;
        unordered_set<char> st(combined.begin(),combined.end());
        int take=0;
        if(st.size()==combined.size()){
           take=solve(i+1,arr,combined);
        }
        int nottake=solve(i+1,arr,s);
        return max(take,nottake);

    }
public:
    int maxLength(vector<string>& arr) {
        return solve(0,arr,"");
    }
};