class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n % groupSize==0){
            sort(hand.begin(),hand.end());
            vector<int>vis(n,0);
            for(int i=0;i<n;i++){
                if(vis[i]==1){ continue ; }
                    vis[i]=1;
                    int size=groupSize-1;
                    int next=hand[i]+1;
                    int j=i+1;
                    while(j<n && size>0){
                        if(hand[j]-next>=2){ return false; }
                        else if(hand[j]==next && vis[j]==0){
                            vis[j]=1;
                            next++;
                            size--;
                        }
                        j++;
                    }
                    if(size>0){ return false; }
            }
            return true;
        }
        return false;
    }
};