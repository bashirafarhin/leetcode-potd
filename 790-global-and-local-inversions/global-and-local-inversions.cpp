class Solution {
public:
    long long merge(vector<int>&nums,int s,int m,int e){
        vector<int>temp(e-s+1,0);
        int l=s;
        int r=m+1;
        long long globalPairs=0;
        int k=0;
        while(l<=m && r<=e){
            if(nums[l]>nums[r]){
                globalPairs+=(m-l+1);
                temp[k]=nums[r];
                r++;
            } else {
                temp[k]=nums[l];
                l++;
            }
            k++;
        }
        
        while(l<=m){
            temp[k]=nums[l];
            k++;
            l++;
        }
        
        while(r<=e){
            temp[k]=nums[r];
            k++;
            r++;
        }

        for(int i=s;i<=e;i++){
            nums[i]=temp[i-s];
        }
        return globalPairs;
    }

    long long mergeSort(vector<int>&nums,int s,int e){
        if(s>=e){ return 0; }
        int m=(s+e)/2;
        long long inv=0;
        inv+=mergeSort(nums,s,m);
        inv+=mergeSort(nums,m+1,e);
        inv+=merge(nums,s,m,e);
        return inv;
    }
    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        long long local=0;

        for(int i=0;i<n-1;i++){
          if(nums[i]>nums[i+1]){
            local++;
          }
        }

        long long global=mergeSort(nums,0,n-1);
        return local==global;
    }
};