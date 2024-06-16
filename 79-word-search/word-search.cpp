class Solution {
public:
    bool solve(vector<vector<char>>& board,int r,int c,int i, string word){
        if(i==word.size()){ return true; }
        if(r<0 || r==board.size() || c<00 || c==board[0].size() || board[r][c]=='.' || board[r][c] !=word[i]){ return false; }
        vector<pair<int,int>> direction={{-1,0}, {0,1}, {1,0}, {0,-1}};

        char original=board[r][c];
        board[r][c]='.';
        bool ans=false;
        for(auto it : direction){
            int newr=r+it.first;
            int newc=c+it.second;
            if(solve(board,newr,newc,i+1,word)){
                ans=true;
                break;
            }
        }

        board[r][c]=original;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
       int n=board.size();
       int m=board[0].size();
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(solve(board,i,j,0,word)){ return true; } 
        }
       }
       return false;
    }
};