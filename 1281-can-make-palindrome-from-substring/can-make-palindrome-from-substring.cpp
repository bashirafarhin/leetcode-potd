class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector<bool>ans;
        int n=s.length();
        vector<vector<int>>prefix; //prefix vector containing freq array
        vector<int>arr(26,0);
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
            prefix.push_back(arr);
        }
        for(auto q : queries){
            vector<int>freq(26,0);
            int l=q[0];
            int r=q[1];
            int k=q[2];
            int cnt=0;

            for(int i=0;i<26;i++){
                int freq=prefix[r][i];
                if(l !=0){ freq=freq-prefix[l-1][i]; }
                if(freq&1){ cnt++; }
            }

            if(cnt> (2*k+1)){ ans.push_back(false); }
            else{ ans.push_back(true); }
            
        }
        return ans; 
    }
};