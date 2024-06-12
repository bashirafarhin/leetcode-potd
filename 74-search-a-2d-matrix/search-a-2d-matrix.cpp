class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();
        int l=0;
        int h=r*c-1;
        while(l<=h){
            int mid=(l+h)/2;
            int ele=matrix[mid/c][mid%c];
            if(ele==target){ return true; }
            else if(target<ele){
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        return false;
    }
};