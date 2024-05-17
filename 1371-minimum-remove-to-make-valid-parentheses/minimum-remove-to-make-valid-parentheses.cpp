class Solution {
public:
    // we need to remove the indices from string which are in stack
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty() && s[st.top()]=='('){ st.pop(); }
                else{ st.push(i); }
            }
        }

        if(st.empty()){ return s; }
        
        string ans="";
        for(int i=n-1;i>=0;i--){
      
            if(!st.empty() && st.top()==i){ st.pop(); }
            else{ ans+=s[i]; }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};