class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
     if(x>y){
         return countOfPairs(n,y,x);}
     vector<int>ans(n,0);
     for(int i=1;i<=n;i++){
         for(int j=i+1;j<=n;j++){
    //distance between src(i) to x + distance between x to y is always 1 + distance between y to destination(j)
          int dis=abs(i-x)+1+abs(y-j); 
          int d=min( abs(j-i),dis);
          if(1<=d<=n){
              ans[d-1]+=2;
          }
         }
     }
     return ans;
    }
};