class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        int moves=0;
        while(right<n-1){
            int maxRangeInd=-1;
            for(int i=left;i<=right;i++){
                if(i+nums[i]>maxRangeInd){
                    maxRangeInd=i+nums[i];
                }
            }
            left=right+1;
            right=maxRangeInd;
            moves++;
        }
        return moves;
    }
};