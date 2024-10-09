class Solution {
public:
    vector<int> helper(int i, int j, string& exp){
        if(j-i+1<=2){
            if(j-i+1==1){
                return {exp[i]-48};
            }
            return {(exp[i]-48)*10+(exp[i+1]-48)};
        }
        vector<int>ans;
        for(int k=i+1;k<j;k++){
            if(exp[k]=='+' || exp[k]=='-' || exp[k]=='*'){
                vector<int>left=helper(i,k-1,exp);
                vector<int>right=helper(k+1,j,exp);
                for(int n1 : left){
                    for(int n2 : right){
                        if(exp[k]=='+'){
                            ans.push_back(n1+n2);
                        } else if(exp[k]=='-'){
                            ans.push_back(n1-n2);
                        } else {
                            ans.push_back(n1*n2);
                        }
                    }
                }
            }
        }
        return ans;
    }
    vector<int> diffWaysToCompute(string expression) {
       int n=expression.length();
       return helper(0, n-1,expression); 
    }
};