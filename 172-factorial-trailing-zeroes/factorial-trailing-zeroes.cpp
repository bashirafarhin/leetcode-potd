class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=5;i<=n;i+=5){
            int num=i;
            while(num % 5 ==0){
                ans++;
                num=num/5;
            }
        }
        return ans;
    }
};