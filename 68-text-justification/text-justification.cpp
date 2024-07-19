class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>ans;
        int n=words.size();
        int i=0;

        while(i<n){
            int j=i+1;
            int max_width=words[i].length();
            int gaddha=0;
            while(j<n && max_width+1+gaddha+words[j].length() <= maxWidth){
                max_width+=words[j].length();
                gaddha++;
                j++;
            }

            int remainingGaddha=maxWidth-max_width;

            int eachGaddhaSpace= gaddha==0? 0 : remainingGaddha/gaddha;
            int extraGaddhaSpace=  gaddha==0? 0 : remainingGaddha%gaddha;

            if(j==n){
                eachGaddhaSpace=1;
                extraGaddhaSpace=0;
            }

            string row="";
            for(int k=i;k<j;k++){
                row+=words[k];
                if(k==j-1){
                    break;
                }
                for(int s=0;s<eachGaddhaSpace;s++){
                    row+=" ";
                }
                if(extraGaddhaSpace>0){
                    row+=" ";
                    extraGaddhaSpace--;
                }
            }

            while(row.length()<maxWidth){
                row+=" ";
            }
            ans.push_back(row);
            i=j;

        }
        return ans;
    }
};