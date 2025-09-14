class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int n1, n2, c1=0, c2=0;
        for(int i=0;i<n;i++){
            if(n1==nums[i]){
                c1++;
            }
            else if(n2==nums[i]){
                c2++;
            }
            else if(c1==0){
                n1=nums[i];
                c1=1;
            }
            else if(c2==0){
                n2=nums[i];
                c2=1;
            } else {
                c1--; c2--;
            }
        }
        vector<int>ans;
        int f1=0;
        int f2=0;        
        for(int i=0;i<n;i++){
            if(n1==nums[i]){ f1++; }
            else if(n2==nums[i]){ f2++; }
        }
        if(f1 > n/3) ans.push_back(n1);
        if(f2 > n/3) ans.push_back(n2);
        return ans;
    }
};