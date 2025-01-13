class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<bool>remove(n,false);
        int ans=n;
        for(int i=1;i<n-1;i++){
            if(remove[i]){ continue; }
            int left=i-1;
            int right=i+1;
            while(left>=0 && s[left] !=s[i]){
                left--;
            }
            while(right<n && s[right] !=s[i]){
                right++;
            }
            if(left>=0 && right<n){
                remove[left]=true;
                remove[right]=true;
                ans-=2;
            }
        }
        return ans;
    }
};