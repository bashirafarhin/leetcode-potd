class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>left(n,1);
        vector<int>right(n,1);

        stack<pair<int,int>> sleft;
        stack<pair<int,int>> sright;

        for(int i=0;i<n;i++){
           int cnt=1;
           while( !sleft.empty() && sleft.top().first > arr[i]) {
               cnt+=sleft.top().second;
               sleft.pop();
           }
            sleft.push({arr[i],cnt});
            left[i]=sleft.top().second;
        }

        for(int i=n-1;i>=0;i--){
           int cnt=1;
           while( !sright.empty() && sright.top().first >= arr[i]) {
               cnt+=sright.top().second;
               sright.pop();
           }
            sright.push({arr[i],cnt});
            right[i]=sright.top().second;
        }

        long mod=1000000007;
        long ans=0;
        for(int i=0;i<n;i++){
            ans = (ans + (long)arr[i]*left[i]*right[i] ) % mod;
        }
        return (int)ans;
        
    }
};