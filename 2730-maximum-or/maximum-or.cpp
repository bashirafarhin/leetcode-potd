class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
     int n=nums.size();
     vector<long long> prefix(n,0);
     vector<long long> suffix(n,0);
     prefix[0]=nums[0];
     for(int i=1;i<n;i++){prefix[i]=prefix[i-1] | nums[i];}
     suffix[n-1]=nums[n-1];
     for(int i=n-2;i>=0;i--){suffix[i]=suffix[i+1] | nums[i];}
     long long ans=-1e9;
     for(int i=0;i<n;i++){
       long long number=nums[i];
       long long val=number<<k;
       if(i !=0){val=val | prefix[i-1];}
       if(i !=n-1){val=val | suffix[i+1];}
       ans=max(ans,val);
      }
     
     return ans;
    }
};