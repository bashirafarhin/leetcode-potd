class Solution {
    int gcd(int a ,int b){
        if(a==0){return b;}
        if(b==0){return a;}
        if(a>b){return gcd(a-b,b);}
        return gcd(a,b-a);
    }
public:
    int findGCD(vector<int>& nums) {
     int Min=1e9;
     int Max=-1e9;
     int n=nums.size();
     for(int i=0;i<n;i++){
         if(Min>nums[i]){Min=nums[i];}
         if(nums[i]>Max){Max=nums[i];}
     }
     return gcd(Min,Max);
    }
};