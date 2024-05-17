class Solution {
public:
// Time --->O(2*mn)--->O(mn)
    vector<int> solve(vector<vector<int>>& land,int r,int c,vector<vector<int>>& vis){
     int R=land.size();
     int C=land[0].size();

     int i=r;
     int j=c;
     for(i=r;i<R;i++){
        if(land[i][c]==0){ break; } 
        for(j=c;j<C;j++){
            if(land[i][j]==0){ break; }
            vis[i][j]=1;
        }
              
     }

     vector<int>ans={r,c,i-1,j-1};
     return ans;
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
       int R=land.size();
       int C=land[0].size();
       vector<vector<int>>vis(R,vector<int>(C,0));
       vector<vector<int>>ans;

       for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(land[i][j] && !vis[i][j]){
                //gotta go since find farmland
                ans.push_back(solve(land,i,j,vis));
            }
        }
       }
       return ans;
    }
};