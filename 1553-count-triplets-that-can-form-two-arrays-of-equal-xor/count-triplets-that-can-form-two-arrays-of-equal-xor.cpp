class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        for(int k=1;k<n;k++){
             unordered_map<int,int>left;
             int l=k-1;
             int curr=0;
             while(l>=0){
                curr^=arr[l];
                left[curr]++;
                l--;
             }

             unordered_map<int,int>right;
             int r=k;
             curr=0;
             while(r<n){
                curr^=arr[r];
                right[curr]++;
                r++;
             }

             for(auto it : left){
                if(right.find(it.first) !=right.end()){
                    count+=(right[it.first]*left[it.first]);
                }
             }
        }
        return count;
    }
};