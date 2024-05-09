class Solution {
public:
    int maxDepth(string s) {
        int open=0;
        int ans=0;
        for(char c : s){
            if(c=='('){ open++; }
            else if(c==')'){ open--; }
            ans=max(ans,open);
        }
        return ans;
    }
};