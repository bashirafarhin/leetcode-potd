class Solution {
public:
    int minOperations(string s) {
        // if the string needs to be an alternating then it will either start from 0 or 1
        int startWithZero=0;
        int startWithOne=0;
        for(int i=0;i<s.length();i++){
            if(i & 1) {
                if(s[i]=='0')
                startWithZero++;

                 if(s[i]=='1')
                startWithOne++;
            }

            else {
                if(s[i]=='1')
                startWithZero++;

                 if(s[i]=='0')
                startWithOne++;
            }
        }
        return min(startWithZero, startWithOne);
    }
};