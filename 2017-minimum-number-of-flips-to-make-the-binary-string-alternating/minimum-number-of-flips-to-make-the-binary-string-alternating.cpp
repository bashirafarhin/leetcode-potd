class Solution {
public:
    int minFlips(string s) {
        int n=s.length();
        string news=s+s;
        int newLen=news.length();
        string altStartWith0="";
        string altStartWith1="";
        for(int i=0;i<newLen;i++){
            if(i & 1){
                altStartWith0+='1';
                altStartWith1+='0';
            } else {
                altStartWith0+='0';
                altStartWith1+='1';
            }
        }
        int diff1=0,diff2=0,count=n;
        for(int i=0;i<newLen;i++){
            diff1+=altStartWith0[i] !=news[i] ? 1 : 0;
            diff2+=altStartWith1[i] !=news[i] ? 1 : 0;
            if(i==n-1){
                count=min(count,min(diff1,diff2));
            } else if(i>=n){
                diff1-=altStartWith0[i-n] !=news[i-n] ? 1 : 0;
                diff2-=altStartWith1[i-n] !=news[i-n] ? 1 : 0;
                count=min(count,min(diff1,diff2));
            }
        }
        return count;
    }
};