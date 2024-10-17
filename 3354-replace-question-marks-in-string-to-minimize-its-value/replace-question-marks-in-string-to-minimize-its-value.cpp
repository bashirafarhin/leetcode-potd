class Solution {
public:
    string minimizeStringValue(string s) {
        unordered_map<char,int>mp;
        set<pair<int,char>>st;
        for(char ch='a'; ch<='z'; ch++){
            st.insert({0,ch});
            mp[ch]=0;
        }

        for(char ch : s){
            if(ch !='?'){
                st.erase(st.find({mp[ch],ch}));
                mp[ch]++;
                st.insert({mp[ch],ch});
            }
        }
        // for(auto it : st){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        string missing="";
        for(char ch : s){
            if(ch=='?'){
                int freq=st.begin()->first;
                char c=st.begin()->second;
                st.erase(st.begin());
                missing+=c;
                st.insert({freq+1,c});
            }
        }
        sort(missing.begin(),missing.end());
        string ans="";
        int i=0;
        for(char ch : s){
            if(ch=='?'){
                ans+=missing[i];
                i++;
            } else {
                ans+=ch;
            }
        }
        return ans;
    }
};