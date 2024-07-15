class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        stack<int>left;
        vector<int>leftSmaller(n,0);
        for(int i=0;i<n;i++){
            while(!left.empty() && heights[left.top()]>=heights[i]){
                left.pop();
            }
            if(!left.empty()){
                 leftSmaller[i]=left.top()+1;
            }
            left.push(i);
        }
        

        stack<int>right;
        vector<int>rightSmaller(n,n-1);
        for(int i=n-1;i>=0;i--){
            while(!right.empty() && heights[right.top()]>heights[i]){
                right.pop();
            }
            if(!right.empty()){
                 rightSmaller[i]=right.top()-1;
            }
            right.push(i);
        }

        int maxArea=0;
        for(int i=0;i<n;i++){
            int area=(rightSmaller[i]-leftSmaller[i]+1)*heights[i];
            maxArea=max(maxArea,area);
        }
        return maxArea;
    }
};