class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int>mp1;
        int n=nums.size();
        int i=0;
        int s1=0;
        int start=0;
        while(i<n){
            mp1[nums[i]]++;
            while(mp1.size()>k){
                s1+=(n-1-i+1);
                mp1[nums[start]]--;
                if(mp1[nums[start]]==0){
                    mp1.erase(nums[start]);
                }
                start++;
            }
            i++;
        }

        unordered_map<int,int>mp2;
        i=0;
        int s2=0;
        start=0;
        while(i<n){
            mp2[nums[i]]++;
            while(mp2.size()==k){
                mp2[nums[start]]--;
                if(mp2[nums[start]]==0){
                    mp2.erase(nums[start]);
                }
                start++;
            }
            s2+=(i-start+1);
            i++;
            
        }

        int t=n*(n+1)/2;
        cout<<s1<<" "<<s2;
        return t-s1-s2;
    }
};