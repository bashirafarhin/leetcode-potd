class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        
        int n=points.size();
        int ans=0;
      
        for(int i=0;i<n;i++){

            int cx=points[i][0];
            int cy=points[i][1];

            for(int j=0;j<n;j++){

              int tx=points[j][0];
              int ty=points[j][1];

                if( i !=j && tx>=cx && ty<=cy ){
                   bool validPoint=true;
                   for(int k=0;k<n;k++){
                    if( k==i || k==j ){continue;}
                    if( cx<=points[k][0] && tx>=points[k][0] && ty<=points[k][1] && points[k][1]<=cy) {  validPoint=false; break ;}
                    }
                  if(validPoint){ans++;}
                }
            }
        }
        return ans;
    }
};