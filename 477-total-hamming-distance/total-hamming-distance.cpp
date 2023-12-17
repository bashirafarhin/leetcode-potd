class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
     int hammingdistance=0;
     int n=nums.size();
     for(int i=0;i<32;i++){
      int count0=0;
      int count1=0;
      for(int j=0;j<n;j++){
        if(nums[j] & 1){count1++;}
        else{count0++;}
        nums[j]>>=1;
       }
       hammingdistance+= (count0*count1);
     }
     return  hammingdistance;
    }
};