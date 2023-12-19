class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int row=img.size();
    int col=img[0].size();
    vector<vector<int>> ans(row,vector<int>(col,0));
    int dx[]={-1,-1,0,1,1,1,0,-1};
    int dy[]={0,1,1,1,0,-1,-1,-1};
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
        int avg=img[i][j];
        int n=1;
        for(int k=0;k<8;k++){
        int newrow=i+dx[k];
        int newcol=j+dy[k];
        if(newrow>=0 && newrow<row && newcol>=0 && newcol<col){avg+=img[newrow][newcol];n++;}}
        ans[i][j]=avg/n;
        }
    }
    return ans;  
    }
};