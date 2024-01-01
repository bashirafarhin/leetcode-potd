class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
     int n=arr.size();
     unordered_map<int,int> mp;
     for(int i=0;i<n;i++){

       int Remainder=arr[i]%k;
       if(Remainder<0){Remainder+=k;}
       if(Remainder==0){continue;}
         
       else if(mp.count(k-Remainder)){
           mp[k-Remainder]--;
           if(mp[k-Remainder]==0){mp.erase(k-Remainder);}
       }
       
       else {
           mp[Remainder]++;
       }
     }
     if(mp.empty()){return true;}
     return false; 
    }
};