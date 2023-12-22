class Solution {
    bool isnumber1(string s){
        int n=s.length();
        if(s[n-1]=='0'){return false;}
        for(int i=n-2;i>=0;i--){
         if(s[i]=='1'){return false;}
        }
        return true;
    }
    string addOne(string s){
        int carry=1;
        int n=s.length();
        string dup;
        for(int i=n-1;i>=0;i--){
          if(s[i]=='1' && carry==1){dup+='0';}
          else if(s[i]=='0' && carry==0){dup+='0';}
          else{dup+='1'; carry=0;}
        }
        if(carry==1){dup+='1';}
        reverse(dup.begin(),dup.end());
        return dup;
    }
 
public:
    int numSteps(string s) {
     if (s == "1") {return 0;}
    int steps=0;
    while(!isnumber1(s)){
        if(s.back()=='1'){s=addOne(s);}
        else{s.pop_back();}
        steps++;
    }
    return steps;
    }
};