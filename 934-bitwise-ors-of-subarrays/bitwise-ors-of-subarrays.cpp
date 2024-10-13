class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>ans;
        unordered_set<int>prev;
        for(int i=0;i<n;i++){
            unordered_set<int>curr={arr[i]};
            for(int prevOr : prev){
                curr.insert(prevOr | arr[i]);
            }
            for(int currOr : curr){
                ans.insert(currOr);
            }
            prev=curr;
        }
        return ans.size();
    }
};