class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
     vector<int> ans;
     vector<pair<int,int>> array;
     int n=arr.size();
     for(int i=0;i<n;i++){
         int num=arr[i];
         int count=0;
         while(num){
            if(num & 1){count++;}
            num=num>>1;
         }
         array.push_back({count,arr[i]});
     }
     sort(array.begin(),array.end());
     for(int i=0;i<n;i++){ans.push_back({array[i].second});}
     return ans;

    }
};