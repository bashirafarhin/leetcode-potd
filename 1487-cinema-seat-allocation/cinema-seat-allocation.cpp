class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
    //max 2 families can be seated in a row if whole row is empty
    unordered_map<int,vector<int>> mp;
    int len=reservedSeats.size();
    for(int i=0;i<len;i++){
        mp[reservedSeats[i][0]].push_back(reservedSeats[i][1]);}
    int ans=(n-mp.size())*2;
    for(auto it : mp){
            vector<int> contains(11,0);
            for(auto col : it.second){contains[col]=1;}
            int flag1=0;
            int flag2=0;
            if(!contains[2] && !contains[3] && !contains[4] && !contains[5]){ans++;flag1=1;}
            if(!flag1 && !contains[4] && !contains[5] && !contains[6] && !contains[7]){ans++;flag2=1;}
            if(!flag2 && !contains[6] && !contains[7] && !contains[8] && !contains[9]){ans++;}
            }
            //doing this as 2 families can seated only if seated in 2345 6789
    return ans;
    }
};