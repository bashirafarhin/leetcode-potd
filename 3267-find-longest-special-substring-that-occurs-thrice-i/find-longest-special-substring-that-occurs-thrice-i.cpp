class Solution {
public:
    int maximumLength(string s) {
        
        unordered_map<string,int> mp;
        for (int i = 0; i < s.length(); i++) {
        string subStr;
        for (int j = i; j < s.length(); j++) {
            subStr += s[j];
            if(j !=i && (s[i] !=s[j]) ){break;}
            mp[subStr]++;
       }}
        int ans=-1;
        for(auto it : mp){
            if(it.second <3){continue;}
            string str=it.first;
            bool flag=true;
            int n=str.length();
            for(int i=0;i<n;i++){
                if(str[i] !=str[0]){flag=false;break;}
            }
            if(flag && ans<n){ans=n;}
        }
        return ans;
    }
};