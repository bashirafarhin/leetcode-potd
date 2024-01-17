class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        if(n==1){return true;}
        sort(arr.begin(),arr.end());
        int count=1;
        vector<int> freqarr;
        for(int i=1;i<n;i++){
            if(arr[i-1]==arr[i]){count++;}
            else{
                freqarr.push_back(count);
                count=1;
            }
        }
        freqarr.push_back(count);
        sort(freqarr.begin(),freqarr.end());
        int m=freqarr.size();
        for(int i=1;i<m;i++){
            if(freqarr[i-1]==freqarr[i]){return false;}
        }
        
        return true;
       
    }
};