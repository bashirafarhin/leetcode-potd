class Solution {
public:
    bool checkIfPangram(string sentence) {
     unordered_set<char> st;
     for(int i=0; i<sentence.length(); i++){
         st.insert(sentence[i]);
     }
     for(int i=0;i<26;i++){
         if(st.find('a'+i)==st.end()){ return false; }
     }
     return true;     
    }
};