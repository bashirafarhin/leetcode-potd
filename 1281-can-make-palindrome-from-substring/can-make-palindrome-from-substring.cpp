class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    int n=queries.size();
    vector<bool> ans(n,true);
    int len=s.length();
    vector<vector<int>>prefix;
    vector<int> arr(26,0);
    for(int i=0;i<len;i++){
        arr[s[i]-'a']++;
        prefix.push_back(arr);
    }
    for(int i=0;i<n;i++){
        int l=queries[i][0];
        int r=queries[i][1];
        int k=queries[i][2];
        int cnt=0;
        for(int j=0;j<26;j++){
            int val=prefix[r][j];
            if(l !=0){val=val-prefix[l-1][j];}
            if(val & 1){cnt++;}
        }
        if(cnt > (2*k+1))  {ans[i]=false;}
    }
    return ans;
    }
};