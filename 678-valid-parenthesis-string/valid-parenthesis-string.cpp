class Solution {
public:
    // string is invalid if at any point close > open
    //we can see that we are only including open brackets in stacks

    bool checkValidString(string s) {
        int n=s.length();
        stack<int>st,sta; //stack of brackets and asterisks
 
        for(int i=0;i<n;i++){
            if(s[i]=='('){ st.push(i); }
            else if(s[i]=='*'){ sta.push(i); }
            else{
                if(!st.empty()){st.pop(); }
                else if(!sta.empty()){ sta.pop(); }
                else{ return false; }
            }
        }

        while ( !st.empty() && !sta.empty() ){
            if(sta.top()<st.top()){ return false; }
            st.pop();
            sta.pop();
        }
        
        return st.empty() ;
    }
};