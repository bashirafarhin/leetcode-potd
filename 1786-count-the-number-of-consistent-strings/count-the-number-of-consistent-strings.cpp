class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
     unordered_set<char> st;
     for(auto ch : allowed){st.insert(ch);}
     int consistent_strings=0;
     for(auto word : words){
        bool flag=true;
         for(auto ch : word){
             if(st.find(ch)==st.end()){flag=false;}}
         if (flag){consistent_strings++;}
     }
     return consistent_strings;
    }
};