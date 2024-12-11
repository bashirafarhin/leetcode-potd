class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int st=0;
        int end=height.size()-1;
        while(st<end){
            int h=min(height[st],height[end]);
            int width=end-st;
            ans=max(ans,h*width);
            if(height[st]<height[end]){
                st++;
            } else {
                end--;
            }
        }
        return ans;
    }
};