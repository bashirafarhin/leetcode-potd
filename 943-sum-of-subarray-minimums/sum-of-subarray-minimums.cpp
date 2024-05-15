class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        /*
        we need to find contribution of each element on left and right side
        to build the left and right side array in O(N) we need to use monotonic stack
        */
        int n=arr.size();
        vector<int>left(n,1),right(n,1);
        stack<pair<int,int>> str,stl;

        for(int i=0;i<n;i++){
           int cnt=1;
           while( !stl.empty() && stl.top().first>arr[i]){
            cnt+=stl.top().second;
            stl.pop();
           }
           stl.push({arr[i],cnt});
           left[i]=cnt;
        }

        for(int i=n-1;i>=0;i--){
           int cnt=1;
           while( !str.empty() && str.top().first>=arr[i]){
            cnt+=str.top().second;
            str.pop();
           }
           str.push({arr[i],cnt});
           right[i]=cnt;
        }

        long mod=1e9+7;
        long sum=0;
        for(int i=0;i<n;i++){
            sum=( sum+ (long)arr[i]*left[i]*right[i] )%(mod);
        }
        return (int)sum;


    }
};