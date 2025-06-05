class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int left=0;
        int right=products.size()-1;
        int n=searchWord.size();
        vector<vector<string>>arr(n);
        for(int i=0;i<n;i++){
            while(left<=right && products[left][i] !=searchWord[i]){ left++; }
            while(left<=right && products[right][i] !=searchWord[i]){ right--; }
            for(int j=left;j<=right && j-left<3;j++){
                arr[i].push_back(products[j]);
            }
        }
        return arr;
    }
};