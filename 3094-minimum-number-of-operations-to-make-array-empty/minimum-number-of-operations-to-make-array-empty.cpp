class Solution {
public:
    int minOperations(vector<int>& nums) {
     unordered_map<int,int> mp;
     for(int num : nums){
         mp[num]++;
     }
     int operations=0;
     for(auto it : mp){
         if(it.second==1){
             return -1;
         }
         else if( !(it.second%3) ){
          operations+=(it.second/3);
         }
         else{
          operations+=(it.second/3)+1;
         }
     }
     return operations;
    }
};