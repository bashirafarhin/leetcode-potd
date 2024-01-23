class Solution {
    int solve(int i,vector<string>& arr,string& s){

        unordered_set<char> st(s.begin(),s.end());
        if(st.size() !=s.size()){return -INT_MAX;} //if characters are not unique

        if(i==arr.size()){return 0;}

        for(char c : arr[i]) { s+=c; }
        int take=arr[i].size()+solve(i+1,arr,s);
        
        for(char c : arr[i]) { s.pop_back(); } //backtrack
        int nottake=solve(i+1,arr,s);

        return max(take,nottake);

    }
public:
    int maxLength(vector<string>& arr) {
        string s="";
        return solve(0,arr,s);
    }
};