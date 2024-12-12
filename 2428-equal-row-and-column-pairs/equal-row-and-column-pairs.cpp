class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        unordered_map<string,int>mp;

        for(int col=0;col<C;col++){
            string curr="";
            for(int row=0;row<R;row++){
                curr+=(to_string(grid[row][col]));
                curr+=" ";
            }
            curr.pop_back();
            mp[curr]++;
        }
        int ans=0;
        for(int row=0;row<R;row++){
            string curr="";
            for(int col=0;col<C;col++){
                curr+=(to_string(grid[row][col]));
                curr+=" ";
            }
            curr.pop_back();
            ans+=mp[curr];
        }
        return ans;
    }
};