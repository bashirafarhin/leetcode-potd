class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.size() < str2.size()){
            return gcdOfStrings(str2,str1);
        }
        if(str2==""){ return str1; }
        int i=0;
        while(i<str2.size() && str1[i]==str2[i]){
            i++;
        }
        return i ? gcdOfStrings(str2, str1.substr(i)) : "";
    }
};