class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            ans+=s[i];
            if(st.empty() || st.top().first !=ans.back()){
                st.push({s[i],1});
            } else {
                st.top().second=st.top().second+1;
            }

            if(st.top().second==k){
                while(st.top().second !=0){
                    st.top().second--;
                    ans.pop_back();
                }
                st.pop();
            }
        }
        return ans;
    }
};