class Solution {
public:
    // string is invalid if at any point close > open

    bool checkValidString(string s) {
        int n=s.length();
        stack<pair<char,int>>st,sta; //stack of brackets and asterisks
 
        for(int i=0;i<n;i++){
            if(s[i]=='('){ st.push({s[i],i}); }
            else if(s[i]=='*'){ sta.push({s[i],i}); }
            else{
                if(!st.empty() && st.top().first=='('){st.pop(); }
                else if(!sta.empty()){ sta.pop(); }
                else{ return false; }
            }
        }

        while ( !st.empty() && !sta.empty() ){
            if(sta.top().second<st.top().second){ return false; }
            st.pop();
            sta.pop();
        }
        
        return st.empty() ;
    }
};