class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
      int winner=arr[0];
      int wc=0;
      int n=arr.size();
      for(int i=1;i<n;i++){
          if(winner> arr[i]){wc++;}
          else{
              wc=1;
              winner=arr[i];}
         if(wc==k){return winner;}
      }
      return winner;
    }
};