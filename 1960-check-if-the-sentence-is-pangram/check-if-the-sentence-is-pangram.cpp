class Solution {
public:
    bool checkIfPangram(string sentence) {
     sort(sentence.begin(),sentence.end());
     int n=sentence.length();
     int i=0;
     int alphabet=0;
     while(i<n){
        char curr=char ('a' + alphabet );
        if(sentence[i]==curr){
           while(i<n && sentence[i]==curr ){ i++; }
           alphabet++;
         }
         else {  return false; }
     }
     return alphabet==26 ? true : false;
    }
};