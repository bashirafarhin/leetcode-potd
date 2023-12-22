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
            int flag=0;
            if(!contains[2] && !contains[3] && !contains[4] && !contains[5]){ans++;flag=1;}
            if(!contains[6] && !contains[7] && !contains[8] && !contains[9]){ans++;flag=1;}
            if(!flag && !contains[4] && !contains[5] && !contains[6] && !contains[7]){ans++;}}
            
        
    
    return ans;
    }
};