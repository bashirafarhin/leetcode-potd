class Solution {
public:
    int singleNumber(vector<int>& nums) {
     int N=nums.size();
     vector<int> count(32,0);
     int ans=0;
     for(int pos=0;pos<32;pos++){
         int sum_bits_at_ith_pos=0;
         for(int i=0;i<N;i++){
             if(  (nums[i]>>pos) & 1 ){sum_bits_at_ith_pos++;}
         }
        if ( (sum_bits_at_ith_pos  % 3) !=0){ans+=1<<pos;}
     }
     return ans;
    }
};