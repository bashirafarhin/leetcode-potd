class Solution {
public:
    static bool mycomp(vector<int> a,vector<int> b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
       sort(pairs.begin(),pairs.end(),mycomp);
       int n=pairs.size();
       int l=1;
       int c=pairs[0][1];
       for(int i=1;i<n;i++){
           if(c<pairs[i][0])
           {c=pairs[i][1];
            l++;}
       }
       return l;
    }
};