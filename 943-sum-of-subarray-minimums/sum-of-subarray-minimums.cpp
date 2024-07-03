class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        
        vector<int>left(n,0);        
        stack<pair<int,int>>sleft;
        for(int i=0;i<n;i++){
            int contributionToLeft=1;
            while(!sleft.empty() && sleft.top().first>arr[i]){
                contributionToLeft+=sleft.top().second;
                sleft.pop();
            }
            sleft.push({arr[i],contributionToLeft});
            left[i]=sleft.top().second;
        }

        vector<int>right(n,0);        
        stack<pair<int,int>>sright;
        for(int i=n-1;i>=0;i--){
            int contributionToright=1;
            while(!sright.empty() && sright.top().first>=arr[i]){
                contributionToright+=sright.top().second;
                sright.pop();
            }
            sright.push({arr[i],contributionToright});
            right[i]=sright.top().second;
        }

        long long ans=0;
        long long mod=1e9+7;
        for(int i=0;i<n;i++){
            ans=(ans%mod + ((long long)left[i]*(long long)right[i]*(long long)arr[i])%mod)%mod;
        }
        return (int)ans;
    }
};