// int maxArea(vector<int>& height) {
//     int n = height.size();
//     int ans = 0;
//     for (int left = 0; left < n; left++) {
//         for (int right = left + 1; right < n; right++) {
//             int capacity = min(height[left], height[right]) * (right - left);
//             ans = max(ans, capacity);
//         }
//     }
//     return ans;
// }

class Solution {
public:
    // you cannot use algorithm because of these test cases 6,7,100,100,1,5
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int ans = 0;
        while (left <= right) {
            int capacity = min(height[left], height[right]) * (right - left);
            ans = max(ans, capacity);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
};