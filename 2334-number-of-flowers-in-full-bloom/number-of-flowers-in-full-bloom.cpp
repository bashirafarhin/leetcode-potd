class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n=people.size();
        int m=flowers.size();
        vector<int>startTime(m,0);
        vector<int>endTime(m,0);
        for(int i=0;i<m;i++){
            startTime[i]=flowers[i][0];
            endTime[i]=flowers[i][1];
        }
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());

        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            int numOfBloomFlowers=upper_bound(startTime.begin(),startTime.end(),people[i])-startTime.begin();
            int numOfDiedFlowers=lower_bound(endTime.begin(),endTime.end(),people[i])-endTime.begin();
            ans[i]=numOfBloomFlowers-numOfDiedFlowers;
        }
        return ans;
    }
};