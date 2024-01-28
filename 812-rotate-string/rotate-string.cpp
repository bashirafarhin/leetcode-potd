class Solution {
public:
    bool rotateString(string s, string goal) {
     int n=s.length();
     int m=goal.length();
     if(n==m){
         s=s+s;
         if(s.find(goal) != string::npos){return true;}
     }
     return false;
    }
};