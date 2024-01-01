class Solution {
public:
       int maximumLength(string s) {
        unordered_map<char,vector<int>> mp;
        int count=0;
        char lastChar=s[0];
        for(char c : s){
            if(lastChar==c){
                count++;
            } else {
                mp[lastChar].push_back(count);
                count=1;
                lastChar=c;
            }
        }
        mp[lastChar].push_back(count);
        
        int ans=-1;
        for(auto it : mp){
         vector<int> arr=it.second;
         sort(arr.begin(),arr.end(),greater<int>());
         int l1=0,l2=0,l3=0;

         if(arr.size()>=1){ l1=arr[0] ;}
         if (arr.size()>=2){ l2=arr[1] ;}
         if(arr.size()>=3){  l3=arr[2] ;}

         if(l1==l2 && l3<l1) l2--;
         if(l1+l2+l3>=3) ans=max({ans,l1-2,l2});

        }
        return (ans==0)? -1 : ans;
    }
};