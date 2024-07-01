class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int size=*max_element(nums.begin(),nums.end())+n+1;
        vector<int>freq(size,0);
        for(int num : nums){ freq[num]++; }
        int moves=0;
        for(int i=0;i<size;i++){
            if(freq[i]>=2){
                int increment=freq[i]-1;
                moves+=increment;
                freq[i+1]+=increment;
            }
        }
        return moves;
    }
};