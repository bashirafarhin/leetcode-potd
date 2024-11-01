class Solution {
public:
    vector<long long>line(int& len, int& n){
        vector<long long>ans(n,0);
        for(int d=1;d<len;d++){
            ans[d-1]=len-d;
        }
        return ans;
    }
    vector<long long>cycle(int& len, int& n){
        vector<long long>ans(n,0);
        for(int d=1;d<len/2;d++){
            ans[d-1]=len;
        }
        if(len & 1){
            int d=len/2;
            if(d-1>=0){
                ans[d-1]=len;
            }
        } else {
            int d=len/2;
            if(d-1>=0){
                ans[d-1]=len/2;
            }
        }
        return ans;
    }
    vector<long long>lineAndCycle(int& lineLen, int& cycleLen, int& n){
        vector<long long>ans(n,0);
        for(int d=1;d<=lineLen;d++){
            long long mn=d+1;
            long long mx=d+(cycleLen/2);
            ans[mn-1]+=2;
            ans[mx-1]-=2;
        }
        long long mn=(cycleLen/2)+1;
        long long mx=(cycleLen/2)+lineLen;
        long long add=cycleLen & 1 ? 2 : 1;
        ans[mn-1]+=add;
        if(mx<n){
            ans[mx]-=add;
        }
        for(int i=1;i<n;i++){
            ans[i]+=ans[i-1];
        }
        for(int i=1;i<=lineLen;i++){
            ans[i-1]++;
        }
        return ans;
    }
    vector<long long>bothLine(int& len1, int& len2, int& x, int& y, int& n){
        if(len1>len2){
            bothLine(len2, len1, x, y, n);
        }
        int plus=x !=y ? 1 : 0;
        vector<long long>ans(n,0);
        for(int d=0;d<len1;d++){
            long long mn=d+plus+2;
            long long mx=d+plus+1+len2;
            ans[mn-1]++;
            if(mx<n){
                ans[mx]--;
            }
        }
        for(int d=1;d<n;d++){
            ans[d]+=ans[d-1];
        }
        return ans;
    }
    vector<long long> countOfPairs(int n, int x, int y) {
        if(x>y){
            return countOfPairs(n,y,x);
        }
        int leftLen=x-1;
        int rightLen=n-y;
        int cycleLen=y-x+1;
        vector<long long>leftAns=line(leftLen, n);
        vector<long long>rightAns=line(rightLen, n);
        vector<long long>cycleAns=cycle(cycleLen, n);
        vector<long long>leftLineAndCycle=lineAndCycle(leftLen, cycleLen, n);
        vector<long long>rightLineAndCycle=lineAndCycle(rightLen, cycleLen, n);
        vector<long long>leftAndRightLine=bothLine(leftLen, rightLen, x, y, n);
        vector<long long>dist(n,0);
        for(int i=0;i<n;i++){
        dist[i]=2*(leftAns[i]+rightAns[i]+cycleAns[i]+leftLineAndCycle[i]+rightLineAndCycle[i]+leftAndRightLine[i]);
        }
        return dist;
    }
};