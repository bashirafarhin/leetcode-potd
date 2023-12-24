class Solution {
public:
    int minOperations(string s) {
    int n=s.length();
    int evenPosZ=0;   //zero at even position
    int oddPosZ=0;   //zero at odd position
    int totalEvenPos= (n % 2)==0? n/2 : n/2+1;   //total even position
    int totalOddPos=n-totalEvenPos;   //total odd position
    for(int i=0;i<n;i++){
        if( (i & 1) && s[i]=='0'){oddPosZ++;}
        else if( !(i & 1) && s[i]=='0'){evenPosZ++;}
    }
    int ans1=totalEvenPos-evenPosZ+oddPosZ;   //010101.....
    int ans2=evenPosZ+totalOddPos-oddPosZ;   //101010.....
    return min(ans1,ans2);
    }
};