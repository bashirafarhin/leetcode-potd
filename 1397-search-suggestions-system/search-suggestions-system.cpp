class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>>ans;
        sort(products.begin(),products.end());
        int l=0;
        int r=products.size()-1;
        int ind=0;
        for(int i=0;i<searchWord.size();i++){
            char ch=searchWord[i];
            while(l<=r && (products[l].size()<=ind || products[l][ind] !=ch)){ l++; }
            while(l<=r && (products[r].size()<=ind || products[r][ind] !=ch)){ r--; }
            vector<string>curr;
            for(int j=0; j<min(3,r-l+1) ;j++){
                curr.push_back(products[l+j]);
            }
            ans.push_back(curr);
            ind++;
        }
        return ans;
    }
};