class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxC=0;
        int start=-1;
        int end=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){ 
                if(start==-1){ start=i; end=i; }
                else{ end++; }
                maxC=max(maxC, end-start+1);
             }
            else { start=-1;  }
        }
        return maxC;
    }
};