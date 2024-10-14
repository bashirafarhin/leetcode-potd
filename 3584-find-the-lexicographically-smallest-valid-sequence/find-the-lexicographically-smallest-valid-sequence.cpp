class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        //precomputation
        int j=m-1;
        vector<int>preComp(m,-1);
        for(int i=n-1;i>=0 && j>=0;i--){
            if(word1[i]==word2[j]){
                preComp[j]=i;
                j--;
                cout<<i<<" ";
            }
        }
        vector<int>ans;
        int i=0;
        j=0;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                i++;
                j++;
            } else {
                //considering changing ith index;
                if(j+1<m && preComp[j+1]<=i){
                    i++;
                    continue;
                }
                ans.push_back(i);
                int p=i+1;
                int q=j+1;
                while(p<n && q<m){
                    if(word1[p]==word2[q]){
                        ans.push_back(p);
                        q++;
                    }
                    p++;
                }
                return ans;
            }
        }
        if(j==m){
            return ans;
        }
        return {};
    }
};