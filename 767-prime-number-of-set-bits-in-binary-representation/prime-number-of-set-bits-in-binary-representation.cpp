class Solution {
public:
    int countPrimeSetBits(int left, int right) {
    int ans=0;
    for(int i=left;i<=right;i++){
        int num=i;
        int count=0;
        while(num){
            if(num & 1){count++;}
            num>>=1;}
        //check if count is prime or not
        bool flag=true;
        for(int j=2;j<=sqrt(count);j++){
            if(count%j==0){flag=false;break;}}
        if(count !=1 && flag){ans++;}
    }
    return ans;    
    }
};