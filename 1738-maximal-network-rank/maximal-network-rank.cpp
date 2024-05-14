class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>>graph(n,vector<int>(n,0));
        vector<int>arr(n,0);
        for(auto it : roads){
            graph[it[0]][it[1]]=1;
            graph[it[1]][it[0]]=1;
            arr[it[0]]++;
            arr[it[1]]++;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
              
                int curr=arr[i]+arr[j];
                curr-= ( graph[i][j]==1 ? 1 : 0 );
                ans=max(ans,curr);
            }
        }
        return ans;
    }
};