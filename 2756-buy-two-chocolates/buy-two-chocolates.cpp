class Solution {
    int recur(vector<int>&prices,int i,int money,int buyed){
     if(buyed==0){return money;}
     if(money<=0 || i==prices.size()){return -1e9;}
     int take=-1e9;
     if(prices[i]<=money){
        take=recur(prices,i+1,money-prices[i],buyed-1);
     }
     int nottake=recur(prices,i+1,money,buyed);
     return max(take,nottake);
    }
public:
    int buyChoco(vector<int>& prices, int money) {
    int ans=recur(prices,0,money,2);
    if(ans==-1e9){return money;}
    return ans;
    }
};