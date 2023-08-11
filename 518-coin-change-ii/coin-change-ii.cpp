class Solution {
public:
    int change(int amount, vector<int>& coins) {
     vector<int> curr(amount+1,0);
     vector<int> prev(amount+1,0);
     int N=coins.size();
     for(int i=0;i<N;i++){
         for(int target=0;target<=amount;target++){
            if(target==0) {curr[target]=1;}
            else if (i==0){
                if(target%coins[0]==0){curr[target]=1;}
            }
            else{
             int take=0;
             if (coins[i]<=target){
              take=curr[target-coins[i]];}
             int nottake=prev[target];
             curr[target]=take+nottake;}
         }
         prev=curr;
     }
     return curr[amount];  
    }
};