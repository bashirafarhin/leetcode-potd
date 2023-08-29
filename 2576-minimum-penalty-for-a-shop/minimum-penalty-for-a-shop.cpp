class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.length();
        vector<int> prefix(n+1,0);
        prefix[0]=0;
        vector<int> suffix(n+1,0);
        suffix[n]=0;

        for(int i=1;i<=n;i++){
         if(customers[i-1]=='N'){prefix[i]=prefix[i-1]+1;}
         else{prefix[i]=prefix[i-1];}
        }
        
        for(int i=n-1;i>=0;i--){
         if(customers[i]=='Y'){suffix[i]=suffix[i+1]+1;}
         else{suffix[i]=suffix[i+1];}
        }

        int minpenalty=1e9;
        int minhour=1e9;
        for(int i=0;i<=n;i++){
            if(prefix[i]+suffix[i]<minpenalty){
                minpenalty=prefix[i]+suffix[i];
                minhour=i;
            }
        }
        return minhour;
    }
};