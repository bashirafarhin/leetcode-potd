class Solution {
public:
    int findGCD(vector<int>& nums) {
     int Min=1e9;
     int Max=-1e9;
     int n=nums.size();
     for(int i=0;i<n;i++){
         if(Min>nums[i]){Min=nums[i];}
         if(nums[i]>Max){Max=nums[i];}
     }
    int a=Min;
    int b=Max;
    int div=1;
    for(int i=2;i<=Min;i++){
        if( (a % i)==0 && (b % i)==0 ){div=i;}
    }
    return div;
    }
};