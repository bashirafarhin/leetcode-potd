class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
     unordered_map<int,int> mp;
     for(auto it : reservedSeats){
         int row=it[0];
         int col=it[1];
         if(mp.find(row)==mp.end()){ mp[row]=0;}
         mp[row]=mp[row] | (1<<col);} //marking 1 for the reserved seats
     int ans=(n-mp.size())*2; //maximum 2 families can be put empty row;
     for(auto it : mp){
         int seat=it.second;
         bool flag=true;
         if((seat & 0b0000111100)==0 )//2345
          {ans+=1; flag=false;}
         if( (seat & 0b1111000000 )==0 )//6789
          {ans+=1; flag=false;}
        
         if(flag && ((seat & 0b0011110000)==0) )//4567
          {ans+=1;}
     }
     return ans;
    }
};


