class Solution {
public:
    string decodeString(string s) {
      string ans="";
      for(int i=0;i<s.size();){
        if('1'<=s[i] && s[i]<='9'){
            string num="";
            for(;'0'<=s[i] && s[i]<='9';i++){ num+=s[i]; }
            int open=1;
            int close=0;
            string newS="";
            i++;
            while(open !=close){
                if(s[i]=='['){ open++; }
                else if(s[i]==']')
                { close++;}
                newS+=s[i];
                i++;
            }
            newS.pop_back();
            string decoded=decodeString(newS);
            for(int freq=1;freq<=stoi(num);freq++){
                ans+=decoded;
            }
        } else {
            ans+=s[i];
            i++;
        }
      }
      return ans;
    }
};