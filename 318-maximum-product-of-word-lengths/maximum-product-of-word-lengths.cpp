class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        int n=words.size();
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            for(char ch : words[i])  {arr[i] = arr[i] | (1<<(ch-'a') );}
            for(int j=0;j<i;j++){
             if( (arr[i] & arr[j])==0 ){
                 int prod=words[i].size()*words[j].size();
                 ans=max(ans,prod);}
            }
        }
        return ans;
    }
};