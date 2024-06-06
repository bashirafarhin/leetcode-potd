class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if( n % groupSize ){ return false; }
        map<int,int>mp;
        for(int i=0;i<n;i++){ mp[hand[i]]++; }

        for(auto it : mp){
            int freq=it.second;
            while(freq !=0){
             freq--;
             int next=it.first+1;
             int size=groupSize-1;
             while(size){
                if(mp.find(next)==mp.end() || mp[next]==0){ return false; }
                mp[next]--;
                size--;
                next++;
             }
            }
        }
        return true;
    }
};