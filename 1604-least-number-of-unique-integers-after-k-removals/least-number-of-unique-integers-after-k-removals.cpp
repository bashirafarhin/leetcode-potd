class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
      unordered_map<int,int>mp;
      for(int n: arr){
        mp[n]++;
      }
      vector<int>freq;
      for(auto it : mp){
        freq.push_back(it.second);
      }
      sort(freq.begin(),freq.end());
      int n=freq.size();
      int i=0;
      for(i=0;i<n;i++){
        if(freq[i]<=k){
            k-=freq[i];
        } else { break; }
      }
      return n-i;
    }
};