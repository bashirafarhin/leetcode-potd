class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n=points.size();
        vector<pair<int,char>>arr;
        for(int i=0;i<n;i++){
            arr.push_back({max(abs(points[i][0]),abs(points[i][1])),s[i]});
        }
        sort(arr.begin(),arr.end());
        vector<int>vis(26,0);
        int pts=0;
        int i=0;
        while(i<n){
            //check if sq is valid
            int sq=arr[i].first;
            int currValidPts=0;
            while(i<n && sq==arr[i].first){
                if(vis[arr[i].second-'a']){
                    return pts;
                } else {
                    vis[arr[i].second-'a']=1;
                    currValidPts++;
                }
                i++;
            }
            pts+=currValidPts;
        }
        return pts;
    }
};