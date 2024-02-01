class Solution {
public:
    bool checkIfPangram(string sentence) {
     int check=0;
     for(int i=0;i<sentence.length();i++){
         check = check | ( 1<< (sentence[i]-'a') );
     }
     return check==((1<<26) - 1) ? true : false ;
    }
};