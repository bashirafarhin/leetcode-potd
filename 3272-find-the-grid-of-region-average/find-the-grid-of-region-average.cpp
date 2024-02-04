class Solution {
public:
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int threshold) {
        int n=image.size();
        int m=image[0].size();
        
        vector<vector<pair<int,int>>> temp(n,vector<pair<int,int>>(m));
        
        for(int r=0;r<=n-3;r++){
            for(int c=0;c<=m-3;c++){

                bool region=true;
                
                for(int i=r;i<(r+3);i++){
                    for(int j=c;j<(c+3);j++){
                        if( ! (i==r || abs(image[i][j]-image[i-1][j])<=threshold ) ) { region=false; }
                        if( ! (j==c || abs(image[i][j]-image[i][j-1])<=threshold) ){ region=false;}
                    } 
                }

                if(region){
                    int avg=(image[r][c]+image[r][c+1]+image[r][c+2]+image[r+1][c]+image[r+1][c+1]+image[r+1][c+2]+image[r+2][c]+image[r+2][c+1]+image[r+2][c+2])/9;
                    for(int i=r;i<(r+3);i++){
                        for(int j=c;j<(c+3);j++){
                            temp[i][j].first+=avg;
                            temp[i][j].second++;}
                    }
                }
                
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(temp[i][j].second !=0){
                image[i][j]=temp[i][j].first/temp[i][j].second;
                }
            }
        }
        return image;
    }
};