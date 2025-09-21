class Solution {
public:
    long long int mergesort(vector<int>& nums, int l, int h) {
        if (l >= h) {
            return 0;
        }
        int m = (l + h) / 2;
        int ci = 0;
        ci += mergesort(nums, l, m);
        ci += mergesort(nums, m + 1, h);
        ci += merge(nums, l, m, h);
        return ci;
    }

    long long int merge(vector<int>& nums, int l, int m, int h) {
        int ci = 0;
        vector<int> temp(h - l + 1, 0);
        int i = l, j = m + 1, k = 0;
        while (i <= m && j <= h) {
            if (nums[i] <= nums[j]) {
                temp[k] = nums[i];
                i++;
            } else {
                temp[k] = nums[j];
                ci += (m - i +1);
                j++;
            }
            k++;
        }

        while (i <= m) {
            temp[k] = nums[i];
            i++;
            k++;
        }

        while (j <= h) {
            temp[k] = nums[j];
            j++;
            k++;
        }

        k = 0;
        for (int i = l; i <= h; i++) {
            nums[i] = temp[k++];
        }

        return ci;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n=nums.size();

        int l=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                l+=1;
            }
        }

        long long g=mergesort(nums,0,n-1);
        return l==g;
    }
};