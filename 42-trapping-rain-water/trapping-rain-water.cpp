class Solution {
public:
    int trap(vector<int>& height) {
        // min(leftMax,rightMax)-arr[i]=water units stored by arr[i]
        int n=height.size();
        vector<int>rightMax(n,-1);
        int maxHeight=height[n-1];
        for(int i=n-2;i>=0;i--){
            maxHeight=max(maxHeight,height[i]);
            rightMax[i]=maxHeight;
        }
        int result=0;
        int leftMax=height[0];
        for(int i=0;i<n;i++){
            leftMax=max(leftMax,height[i]);
            if(height[i]<leftMax && height[i]<rightMax[i]){
                int waterUnits=min(leftMax,rightMax[i])-height[i];
                result+=waterUnits;
            }
        }
        return result;
    }
};