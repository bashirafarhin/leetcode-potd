class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>loser(100001,0);
        for(auto it : matches){
            int w=it[0];
            int l=it[1];
            if(loser[w]==0){
                loser[w]=-1;}
            if(loser[l]==-1){
               loser[l]=1; 
            } else {
            loser[l]++;
            }
        }

        vector<int>v1;
        vector<int>v2;

        for(int i=0;i<100001;i++){
         if(loser[i]==-1){
             v1.push_back(i);}
         else if(loser[i]==1){
             v2.push_back(i);}
        }
        return {v1,v2};

    }
};