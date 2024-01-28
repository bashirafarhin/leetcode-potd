class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=indices.size();
        string ans="";
        for(int i=0;i<n;i++){ans +='a';}
        for(int i=0;i<n;i++){
            ans[indices[i]]=s[i];
        }
        return ans;

    }
};