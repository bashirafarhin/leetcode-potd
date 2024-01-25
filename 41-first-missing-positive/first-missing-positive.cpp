class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=0){ 
                swap(nums[i],nums[j]);
                j++;}
        }
        
        for(int n : nums){cout<<n<<" ";}
        cout<<endl;

        for(int i=0;i<j;i++){nums[i]=1;}

        for(int n : nums){cout<<n<<" ";}
        cout<<endl;

        for(int i=j;i<n;i++){
            if(nums[i]>n){continue;}
            int ind=abs(nums[i])-1;
            if(nums[ind]>0){
                nums[ind]=-1*nums[ind];
            }

        }

        for(int n : nums){cout<<n<<" ";}
        cout<<endl;

        for(int i=0;i<n;i++){
            if(nums[i]>0){return i+1;}
        }
        return n+1;
    }
};