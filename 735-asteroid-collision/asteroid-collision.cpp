class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>st;
        for(int i=0;i<ast.size();i++){
            if(st.empty() || (st.back()>0 && ast[i]>0) || (st.back()<0 && ast[i]<0) || (st.back()<0)){
                st.push_back(ast[i]);
            } else if(abs(st.back())<abs(ast[i])){
                st.pop_back();
                i--;
            } else if(abs(st.back())==abs(ast[i])){
                st.pop_back();
            }
        }
        return st;
    }
};