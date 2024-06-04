class Solution {
public:
    bool isSafe(vector<vector<char>>&board,int r,int c){
        int n=board.size();
        //check above
        for(int i=r-1;i>=0;i--){
            if(board[i][c]=='Q'){ return false; }
        }
        //check above left diagonal
        int i=r-1;
        int j=c-1;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q'){ return false; }
            i--;
            j--;
        }
        //check above right diagonal
        i=r-1;
        j=c+1;
        while(i>=0 && j<n){
            if(board[i][j]=='Q'){ return false; }
            i--;
            j++;
        }
        return true;
    }

    void addInAns(vector<vector<char>>&board,vector<vector<string>>&ans){
        int n=board.size();
        vector<string> res;
        for(int i=0;i<n;i++){
            string row="";
            for(int j=0;j<n;j++){
                row+=board[i][j];
            }
            res.push_back(row);
        }
        ans.push_back(res);
        return ;
    }

    void solve(vector<vector<char>>&board,int r,int n,vector<vector<string>>&ans){
        if(r==n){
            addInAns(board,ans);
            return; }
        for(int c=0;c<n;c++){
            if(isSafe(board,r,c)){
                board[r][c]='Q';
                solve(board,r+1,n,ans);
                board[r][c]='.'; //backtrack
            }
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int n) {
       vector<vector<char>>board(n,vector<char>(n,'.'));
       vector<vector<string>>ans;
       solve(board,0,n,ans);
       return ans;
    }
};