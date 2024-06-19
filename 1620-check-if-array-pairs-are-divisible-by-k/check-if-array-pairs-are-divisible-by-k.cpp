class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int rem=arr[i] % k;
            if(rem<0){ rem+=k; }
            if(rem==0){ continue; }
            if(mp.find(k-rem) !=mp.end()){
                mp[k-rem]--;
                if(mp[k-rem]==0){ mp.erase(k-rem); }
            } else {
                mp[rem]++;
            }
        }

        for(auto it : mp){ cout<<it.first<<" "<<it.second<<" "<<endl; }
        return mp.size()==0 ? true : false ;
    }
};