class Solution {
    bool f(vector<int>& arr,vector<int> &flagarr,int i,int sum,int times,int side){
     if(sum==0){
        if(times==0){return true;}
         vector<int> arr1,arr2;
         for(int i=0;i<arr.size()-1;i++){
          if(flagarr[i]){arr1.push_back(arr[i]);}
          else{arr2.push_back(arr[i]);}}
          vector<int> flagarr1(arr1.size(),0);
          vector<int> flagarr2(arr2.size(),0);
          
      return f(arr1,flagarr1,arr1.size()-1,side,times-1,side) && f(arr2,flagarr2,arr2.size()-1,side,times-1,side);
      }


     if(i<0 || sum<0){return false;}
     bool take=false;
     flagarr[i]=1;
     take=f(arr,flagarr,i-1,sum-arr[i],times,side);
     flagarr[i]=0;
     bool nottake=f(arr,flagarr,i-1,sum,times,side);
     return take || nottake;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
    int n=matchsticks.size();
    if(n<4){return false;}
    int sum=0;
    for(int num : matchsticks){sum+=num;}
    int max=*max_element(matchsticks.begin(),matchsticks.end());
    if(sum%4 !=0 || max>(sum/4) ){return false;}
    vector<int>flagarr(n,0);
    return f(matchsticks,flagarr,n-1,sum/2,1,sum/4);
   
    }
};