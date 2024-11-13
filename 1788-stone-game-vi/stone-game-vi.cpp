class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        vector<vector<int>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({aliceValues[i]+bobValues[i],aliceValues[i],bobValues[i]});
        }
        sort(arr.begin(),arr.end(),greater<vector<int>>());
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(i & 1){
                b+=arr[i][2];
            } else {
                a+=arr[i][1];
            }
        }
        return a==b ? 0 : (a>b ? 1 : -1);
    }
};