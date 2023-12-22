class Solution {

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
    int steps=0;
    while(s.size()>1){
        if(s.back()=='1'){s=addOne(s);}
        else{s.pop_back();}
        steps++;
    }
    return steps;
    }
};