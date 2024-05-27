//factorial me trailing zeroes only beacuse of 2 5 10
//that is only because of 2*5 that is find pair of (2,5)
//for every  2 , 5 should exist and for every 5, 2 should exist
//for every 5, 2 should exist--->this condition always remain true
//that is we need to find only number of 5

class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        while(n){
            n/=5;
            ans+=n;
        }
        return ans;
    }
};