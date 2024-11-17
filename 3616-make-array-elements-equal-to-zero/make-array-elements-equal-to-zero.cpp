class Solution {
public:
    int countValidPos(int pos, char last, vector<int>& nums){
        if(pos<0 || pos>=nums.size()){
            for(int n : nums){
                if(n){ return 0; }
            }
            return 1;
        }
        int validMove=0;
        if(!nums[pos]){
            validMove+=countValidPos(pos+last,last,nums);
        } else {
            nums[pos]--;
            validMove+=countValidPos(pos-1*last,-1*last,nums);
            nums[pos]++;
        }
        return validMove;
    }
    int countValidSelections(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(!nums[i]){
                ans+=countValidPos(i,-1,nums);
                ans+=countValidPos(i,1,nums);
            }
        }
        return ans;
    }
};