class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();

        vector<int> lis(n,1); //lis length
        vector<int> preIndex(n,-1); //lis preIndex

        sort(nums.begin(),nums.end());
     
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if((nums[i]%nums[j])==0 && (lis[i]<lis[j]+1) ){
                    lis[i]=lis[j]+1;
                    preIndex[i]=j;
                }
            }
        }
        int maxlis=0;
        int ind=0;
        for(int i=0;i<n;i++){
            if(maxlis<lis[i]){
                maxlis=lis[i];
                ind=i;
            }
        }
        
        vector<int>res;
        while(ind !=-1){
            res.push_back(nums[ind]);
            ind=preIndex[ind];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};