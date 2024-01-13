class Solution {
public:
    //answer will be always possible and maximum ans possible is n
    //as we are decreasing the number by 1 using n-1
    int integerReplacement(int n) {
        if(n==2147483647){
            n=n-1;
        }
        queue<int> q;
        int ans=0;
        unordered_map<int,int> vis;
        q.push(n);
        vis[n]=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int num=q.front();
                q.pop();
                if(num==1){return ans;}
                if( !(num%2) && !vis.count(num/2)){
                    vis[num/2]=1;
                    q.push(num/2);
                }
                if( (num%2) && !vis.count(num+1)){
                    vis[num+1]=1;
                    q.push(num+1);
                }
                if ( (num%2) &&!vis.count(num-1)){
                    vis[num-1]=1;
                    q.push(num-1);
                }
            }
            ans++;
        }
        return ans;
    }
};