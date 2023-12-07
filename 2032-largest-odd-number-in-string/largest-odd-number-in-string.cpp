class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int ans = -1;
        for(int i=n-1;i>=0;i--){
            char ch = num[i];
            int x = ch-'0';
            if(x%2!=0){
                ans = i;
                break;
            }
        }
        return num.substr(0,ans+1);
    }
};