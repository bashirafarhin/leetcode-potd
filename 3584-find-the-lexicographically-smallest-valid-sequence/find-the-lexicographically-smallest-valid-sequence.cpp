class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int l1=word1.size();
        int l2=word2.size();
        vector<int>next(l2,-1);
        int j=l2-1;
        for(int i=l1-1;i>=0 && j>=0;i--){
            if(word1[i]==word2[j]){
                next[j]=i;
                j--;
            }
        }
        vector<int>result;
        int k=1;
        j=0;
        for(int i=0;i<l1 && j<l2;i++){
            if(word1[i]==word2[j]){
                result.push_back(i);
                j++;
            } else {
                //change
                if(k>0){
                bool isNextFind=true;
                for(int k=j+1;k<l2;k++){
                    if(next[k]<=i){
                        isNextFind=false;
                        break;
                    }
                }
                if(isNextFind){
                    cout<<"in"<<endl;
                    result.push_back(i);
                    j++;
                    k--;
                }
                
                }
            }
        }
        if(j==l2){
            return result;
        }
        return {};
    }
};