class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int num=1;
        for(int i=0;i<target.size();i++){
            if(num==target[i]){ans.push_back("Push");}
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
                i--;}
            num++;
        }
        return ans;
    }
};