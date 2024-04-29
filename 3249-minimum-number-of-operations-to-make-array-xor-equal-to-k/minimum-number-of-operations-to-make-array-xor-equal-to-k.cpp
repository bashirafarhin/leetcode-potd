class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        int x=nums[0]; //find xor of array
        for(int i=1;i<n;i++){
            x=x^nums[i];
        }
        int operations=0;
        while(k !=0 || x !=0){
            int a=k & 1; //taking the Oth bit of k
            int b=x & 1;  //taking the Oth bit of x
            if(a !=b){ //if different bits
              operations++;}
            k=k>>1;
            x=x>>1;
        }
        return operations;
    }
};