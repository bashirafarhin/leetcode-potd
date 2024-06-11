class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
      map<int,int>mp;
      int n=arr1.size();
      for(int i=0;i<n;i++){ mp[arr1[i]]++; }

      int m=arr2.size();
      int j=0;
      for(int i=0;i<m;i++){
        int freq=mp[arr2[i]];
        while(freq--){
            arr1[j]=arr2[i];
            j++;
            mp[arr2[i]]--;
        }
      }


      for(auto it : mp){
        int freq=it.second;
        while(freq--){
            arr1[j]=it.first;
            j++;
        }
      }
      return arr1;
    }
};