class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
     sort(nums.begin(),nums.end());
      int num=1;
      int n=nums.size();
      for(int i=0;i<n;i++){
          if(nums[i]<=0){continue;}
          
          else if(nums[i]==num){
              while(i<n && nums[i]==num){
                  i++;
              }
              
              num++;
              i--;}
    
          else{break;}
      }
     
      return num;   
    }
};