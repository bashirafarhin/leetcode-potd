class Solution {
public:
    long long mergeSort(vector<int>&arr,int s,int e){
        if(s>=e){ return 0; }
        long long mid=(s+e)/2;
        long long cnt=0;
        cnt+=mergeSort(arr,s,mid);
        cnt+=mergeSort(arr,mid+1,e);
        cnt+=merge(arr,s,mid,e);
        return cnt;
    }
      
    long long merge(vector<int>&arr,int s,int mid,int e){
        int i=s, j=mid+1, k=0;
        long long cnt=0;
        int* temp=new int[e-s+1]{0};
        while(i<=mid && j<=e){
            if(arr[i]>arr[j]){
                cnt+=(mid-i+1);
                temp[k]=arr[j];
                j++;
            } else {
                temp[k]=arr[i];
                i++;
            }
            k++;
        }
        while(i<=mid){
            temp[k]=arr[i];
            k++;
            i++;
        }
        while(j<=e){
            temp[k]=arr[j];
            k++;
            j++;
        }
        for(int i=s;i<=e;i++){
            arr[i]=temp[i-s];
        }
        delete[] temp;
        return cnt;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();
        long long local=0;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){ local++; }
        }
        long long global=mergeSort(nums,0,n-1);
        return local==global;
    }
};