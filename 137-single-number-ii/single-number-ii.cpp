class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>arr(32,0);

        for(int i=0;i<nums.size();i++){
            int n=nums[i];
            for(int j=31;j>=0;j--){
                arr[j]+=(n&1);
                n>>=1;
            }
        }

        for(int i=0;i<32;i++){cout<<arr[i];}
        cout<<endl;

        int ans=0;
        for(int i=31;i>=0;i--){

            if(arr[i]%3 !=0) {ans|=(1<<(31-i));}
        }
        return ans;
    }
};