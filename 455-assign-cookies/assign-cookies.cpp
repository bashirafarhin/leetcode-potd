class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans=0;
        int n=g.size();
        int m=s.size();
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(g[i]>s[j]){
                j++;}
            else{
                j++;
                 i++;
                 ans++;}
        }
        return ans;
    }
};