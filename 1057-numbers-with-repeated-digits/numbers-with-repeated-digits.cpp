class Solution {
public:
    int unique(int ind, int tight, int mask, string& num){
        if(ind==num.size()){
            return 1;
        }
        int limit=tight ? num[ind]-'0' : 9;
        int start=ind ? 0 : 1;
        int ans=0;
        for(int digit=start;digit<=limit;digit++){
            if (mask & (1 << digit)) continue;
            ans+=unique(ind+1,tight && digit==limit,mask | (1<<digit),num);
        }
        return ans;
    }
    int numDupDigitsAtMostN(int n) {
        string num=to_string(n);
        int ans=0;
        int digits=9;
        int k=9;
        for(int size=1;size<num.size();size++){
            ans+=k;
            if(size>1){
                digits--;
            }
            k=k*digits;
        }
        ans+=unique(0,1,0,num);
        return n-ans;
    }
};