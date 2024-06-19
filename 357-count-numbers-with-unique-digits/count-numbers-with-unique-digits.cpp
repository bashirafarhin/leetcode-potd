class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){ return 1; }
        int ans=0;
        int count=9;
        int num=9;
        for(int i=1;i<=n;i++){
            if(i==1){ ans+=10; }
            else{
                count*=num;
                num--;
                ans+=count;
            }
        }
        return ans;
    }
};