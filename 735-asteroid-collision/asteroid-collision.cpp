class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int>ans;
        for(int i=0;i<ast.size();){
            if(ans.empty() || (ans.back()>0 && ast[i]>0) || (ans.back()<0 && ast[i]<0) || (ans.back()<0 && ast[i]>0)){
                ans.push_back(ast[i]);
                i++;
            } else if(abs(ans.back())==abs(ast[i])){
                ans.pop_back();
                i++;
            } else if(abs(ans.back())<abs(ast[i])){
                ans.pop_back();
            } else{
                i++;
            }
        }
        return ans;
    }
};