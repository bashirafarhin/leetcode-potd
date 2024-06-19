class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int majorityElement1=0;
        int majorityElement2=0;
        int count1=0;
        int count2=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(count1==0 && nums[i] !=majorityElement2){
                majorityElement1=nums[i];
                count1++;
            }
            else if(count2==0 && nums[i] !=majorityElement1){
                majorityElement2=nums[i];
                count2++;
            }
            else if(nums[i]==majorityElement1){ count1++; }
            else if(nums[i]==majorityElement2){ count2++; }
            else { count1-- ; count2--;}
        }

        //check if candidates finds are true
        count1=0;
        count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==majorityElement1){ count1++; }
            else if(nums[i]==majorityElement2){ count2++; }
        }

        vector<int> ans;
        if(count1>n/3){
            ans.push_back(majorityElement1);
        }
        if(count2>n/3){
            ans.push_back(majorityElement2);
        }
        return ans;
    }
};