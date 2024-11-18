class Solution {
public:
    int sumOfDigits(long long n){
        int sum=0;
        while(n){
            sum+=n%10;
            n=n/10;
        }
        return sum;
    }
    long long makeIntegerBeautiful(long long n, int target) {
        long long moves=0;
        long long ten=1;
        while(sumOfDigits(n)>target){
            moves+=(10-n%10)*ten;
            n=(n/10 + 1);
            ten*=10;
        }
        return moves;
    }
};