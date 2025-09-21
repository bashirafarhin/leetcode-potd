class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        int n=m.size();
        
        for(int i=0;i<n;i++){
            int s=0;
            int e=n-1;
            while(s<e){
                swap(m[i][s], m[i][e]);
                s++;
                e--;
            }
        }

        for(int i=0;i<n/2;i++){

            for(int j=i;j<n-i;j++){
                 swap(m[j][i], m[n-1-i][n-1-j]);
            }


            for(int j=i+1;j<n-i;j++){
                 swap(m[i][j], m[n-1-j][n-1-i]);
            }

        }
    
    }
};