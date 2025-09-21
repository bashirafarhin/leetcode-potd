class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int r = m.size();
        int c = m[0].size();
        bool fr=false;
        bool fc=false;

        for (int i = 0; i < r; i++) {
            if (m[i][0] == 0) {
                fc=true;
                break;
            }
        }

         for (int i = 0; i < c; i++) {
            if (m[0][i] == 0) {
                fr=true;
                break;
            }
        }

        cout<<fr<<" "<<fc<<endl;

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if(m[i][j] == 0) {
                    m[i][0] = 0;
                    m[0][j] = 0;
                }
            }
        }
        

        for (int i = 1; i < r; i++) {
            if (m[i][0] == 0) {
                for (int j = 1; j < c; j++) {
                    m[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < c; i++) {
            if (m[0][i] == 0) {
                for (int j = 1; j < r; j++) {
                    m[j][i] = 0;
                }
            }
        }


        if(fr){
            for (int i = 0; i < c; i++) {
            m[0][i] = 0;
        }
        }

         if(fc){
            for (int i = 0; i < r; i++) {
            m[i][0] = 0;
        }
        }
    }
};