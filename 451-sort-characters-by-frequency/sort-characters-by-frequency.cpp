class Solution {
public:
    string frequencySort(string s) {
     vector<int>freq(256,0);
     for(char c : s){ freq[c]++; }
     vector<pair<int,char>> arr;
     for(int i=0;i<256;i++){
         if(freq[i] !=0){
             arr.push_back({freq[i],char(i)});
         }
     }
     sort(arr.begin(),arr.end(),greater<pair<int,char>>());
     string ans="";
     for(auto it : arr){
         while(it.first !=0){
         ans+=it.second;
         it.first--;
         }
     }
     return ans;
    }
};