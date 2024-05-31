class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        for(int i=0;i<n;i++){
            result^=nums[i];
        }

        //since the 2 numbers are different , there bits are different
        //find the 1st position where bits are different
        //separate the array in two parts on basis of different bit at that position

        int pos=0;
        for(int i=0;i<32;i++){
            if(result & 1){
                pos=i;
                break;
            }
            result>>=1;
        }

        int x=0,y=0;
        for(int i=0;i<n;i++){
            if( nums[i] & (1<<pos) ){ x^=nums[i]; }
            else { y^=nums[i]; }
        }
        return {x,y};
    }
};