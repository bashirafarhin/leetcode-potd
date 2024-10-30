class Solution {
public:
    void getBitsCount(long long num, vector<long long>&bitsCount){
        if(num==0){ //0
            return ;
        }
        if(num==1){ //0 1
            bitsCount[0]++;
            return ;
        }
        if(num==2){ //0 1 2
            bitsCount[0]++;
            bitsCount[1]++;
            return ;
        }
        long long bitLen=log2(num); //bit length to represent num
        long long nearPower=1LL<<bitLen; //power of 2 less than num
        bitsCount[ bitLen ]+=(num-nearPower+1);
        for(long long i=0;i<bitLen;i++){
            bitsCount[i]+=nearPower/2;
        }
        getBitsCount(num-nearPower, bitsCount);
    }

    long long calculateAccumulatedPrice(long long num, int x) {
        vector<long long>bitsCount(65,0);
        long long totalBits=0;
        getBitsCount(num, bitsCount);
        for(long long i=x-1;i<65;i+=x){
            totalBits+=bitsCount[i];
        }
        return totalBits;
    }

    long long findMaximumNumber(long long k, int x) {
        long long low = 1;
        long long high = 1e15;
        long long result = 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long accPrice = calculateAccumulatedPrice(mid, x);
            if (accPrice <= k) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};