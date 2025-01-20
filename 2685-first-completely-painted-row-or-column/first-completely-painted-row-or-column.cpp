class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>matAdd;
        int r=mat.size();
        int c=mat[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                matAdd[mat[i][j]]={i,j};
            }
        }
        vector<int>row(r,c);
        vector<int>col(c,r);
        for(int i=0;i<arr.size();i++){
            int x=matAdd[arr[i]].first;
            int y=matAdd[arr[i]].second;
            row[x]--;
            col[y]--;
            if(!row[x] || !col[y]){ return i; }
        }
        return -1;
    }
};