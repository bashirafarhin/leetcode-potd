class Solution {
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),cmp);
        int n=points.size();
        int ans=0;
      
        for(int i=0;i<n;i++){

            int cx=points[i][0];
            int cy=points[i][1];
            int h=-1e9-1; //benchmark height
            for(int j=i+1;j<n;j++){

              int tx=points[j][0];
              int ty=points[j][1];
              if(ty > cy){ continue;}
              if( ty>h ){
                  h=ty;
                  ans++;}
            }
        }
        return ans;  
    }
};