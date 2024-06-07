class Solution {
public:
    string isRoot(vector<string>&dict,string str){
        int n=str.length();
        for(string word : dict){
            int m=word.length();
            int i=0,j=0;
            while(i<n && j<m && str[i]==word[j]){
                i++;
                j++;
            }
            if(j==m){ return word; }
        }
        return str;
    }

    string replaceWords(vector<string>& dict, string s) {
       string ans="";
       sort(dict.begin(),dict.end());
       int n=s.length();
       string curr="";
       for(int i=0;i<n;i++){
        curr+=s[i];
        if(s[i]==' ' || i==n-1){
            if(s[i]==' '){ curr.pop_back(); }
            ans+=isRoot(dict,curr);
            curr="";
            ans+=' ';
        }
       }
       ans.pop_back();
       return ans;
    }
};