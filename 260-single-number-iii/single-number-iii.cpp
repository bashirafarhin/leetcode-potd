class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
     int n=nums.size();
     int result=0;
     for(int i=0;i<n;i++){
      result=result^nums[i];
     }
    //  int set_bit_no = result & ~(result - 1);
     int pos=0;
     for(int i=0; i<32; i++)
        {if((result&(1<<i))!=0)
            {pos = i;
             break;}
        }
     int x=0,y=0;
     for(int i=0;i<n;i++){
       if(nums[i] & (1<<pos)) {
         x=x^nums[i];}
       else{
         y=y^nums[i];}
     }
     if(x>y)
     { return {y,x};}
     else
     { return {x,y};}   
    }
};