class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>forward(n+1,0);
        vector<int>backward(n+1,0);
        for(auto sh : shifts){
            int l=sh[0];
            int r=sh[1];
            int dir=sh[2];
            if(dir){
                forward[l]+=1;
                forward[r+1]-=1;
            } else {
                backward[l]+=1;
                backward[r+1]-=1;
            }
        }
        //propogate the operation to the right indices
        for(int i=1;i<=n;i++){
            forward[i]+=forward[i-1];
            backward[i]+=backward[i-1];
        }
        //perform final operation
        for(int i=0;i<n;i++){
            int op=forward[i]-backward[i];
            int rotate = ((s[i] - 'a') + op % 26 + 26) % 26;
            s[i] = 'a' + rotate;
        }
        return s;
    }
};