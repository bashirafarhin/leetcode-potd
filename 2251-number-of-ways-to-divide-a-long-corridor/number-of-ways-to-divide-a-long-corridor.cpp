class Solution {
public:
    int numberOfWays(string corridor) {
        int s=0;
        vector<int> sv;  //0, 4
        vector<int> ev;  //1, 6
        for(int i=0;i<corridor.size();i++){
            if(corridor[i]=='S'){
                if(s==0){
                    sv.push_back(i);
                }
                s++;
            }
            if(s==2){
                s=0;
                ev.push_back(i);
            }
        }
        int ssize=sv.size();
        int esize=ev.size();
        if(ssize==0 || ssize!=esize){
            return 0;
        }
        if(ssize==1){
            return 1;
        }
        long ans=1;
        for(int i=1;i<ssize;i++){
            int ways=sv[i]-ev[i-1];
            ans=(ans*ways)%1000000007;
        }
        return ans;
    }
};