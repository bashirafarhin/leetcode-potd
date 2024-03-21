class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int n=nums.size();
       sort(nums.begin(),nums.end());
       int find=1;
       for(int i=0;i<n;i++){
        if(nums[i]>0){
            if(find==nums[i]){
                 
                 while(i<n && nums[i]==find){ i++; }
                 i--;
                 find++; }

            else{ return find; }
        }
     }
     return find;
    }
};