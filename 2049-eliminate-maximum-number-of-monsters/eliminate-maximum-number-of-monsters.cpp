class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<float> time;

        for(int i=0;i<n;i++){
            time.push_back(1.0*dist[i]/speed[i]);
        }

        sort(time.begin(),time.end());
        int t=0;
        int i=0;
        while( i<n && (time[i]-t>0) ){
            t++;
            i++;
        }
        return i;
    }
};