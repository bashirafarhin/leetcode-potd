class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        int num=0,count=0,i=0;
        while(num !=n+1){
            count=0;
            i=num;
            while(i !=0){
                i=(i & i-1);
                count++;
            }
            ans.push_back(count);
            num++;}
            return ans;
    }
};