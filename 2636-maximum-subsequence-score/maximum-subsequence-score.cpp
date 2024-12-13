class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        long long sum=0;
        long long ans=0;
        vector<pair<int,int>>arr;
        for(int i=0;i<nums1.size();i++){
            arr.push_back({nums2[i],nums1[i]});
        }
        sort(arr.begin(),arr.end(),greater<pair<int,int>>());
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<nums1.size();i++){
            pq.push(arr[i].second);
            sum+=(arr[i].second);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans=max(ans,sum*arr[i].first);
            }
        }
        return ans;
    }
};