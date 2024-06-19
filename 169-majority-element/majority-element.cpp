class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=0;
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count==0){
                candidate=nums[i];
                count++;
            } else if( candidate==nums[i] ){
                count++;
            } else if( candidate !=nums[i] ){
                count--;
            }
        }

        //check if majority element actually exist or not
        count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==candidate){ count++; }
        }

        return count>(n/2) ? candidate : -1;
    }
};