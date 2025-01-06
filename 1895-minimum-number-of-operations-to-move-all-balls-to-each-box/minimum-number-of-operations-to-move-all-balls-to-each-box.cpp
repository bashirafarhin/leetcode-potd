class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>prefix(n,0);
        int steps=0;
        int prevBalls=0;
        for(int i=0;i<n;i++){
            steps+=prevBalls;
            prefix[i]=steps;
            if(boxes[i]=='1'){ prevBalls++; }
        }

        vector<int>suffix(n,0);
        steps=0;
        prevBalls=0;
        for(int i=n-1;i>=0;i--){
            steps+=prevBalls;
            suffix[i]=steps;
            if(boxes[i]=='1'){ prevBalls++; }
        }

        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]+suffix[i];
        }
        return ans;
    }
};