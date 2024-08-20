class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int r=board.size();
        int c=board[0].size();
        vector<vector<int>>newBoard(r,vector<int>(3,0));
        vector<pair<int,pair<int,int>>>arr;
        for(int i=0;i<r;i++){
            vector<pair<int,int>>temp;
            for(int j=0;j<c;j++){ temp.push_back({board[i][j],j}); }
            sort(temp.begin(),temp.end(),greater<pair<int,int>>());
            for(int j=0;j<c;j++){
                if(j<3) newBoard[i][j]=temp[j].second;
                arr.push_back({board[i][j],{i,j}});
            }
        }
        sort(arr.begin(),arr.end(),greater<pair<int,pair<int,int>>>());
        int n=arr.size();
        long long res=-1e18;
        for(int r1=0;r1<r;r1++){
            for(int c1=0;c1<3;c1++){
                for(int r2=r1+1;r2<r;r2++){
                    for(int c2=0;c2<3;c2++){
                        int i=newBoard[r1][c1];
                        int j=newBoard[r2][c2];
                        if(i==j){ continue; }
                        for(int k=0;k<n;k++){
                            if(arr[k].second.first !=r1 && arr[k].second.first !=r2 && arr[k].second.second !=i && arr[k].second.second !=j){
                                long long sum=(long long)board[r1][i]+(long long)board[r2][j]+(long long)arr[k].first;
                                res=max(res,sum);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};