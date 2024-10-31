class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        int leftMostCol=0;
        int rightMostCol=0;
        unordered_map<int,vector<int>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        mp[0]={root->val};
        while(!q.empty()){
            int size=q.size();
            unordered_map<int,vector<int>>levelwise;
            while(size--){
                TreeNode* node=q.front().first;
                int r=q.front().second.first;
                int c=q.front().second.second;
                q.pop();
                if(node->left){
                    q.push({node->left,{r+1,c-1}});
                    levelwise[c-1].push_back(node->left->val);
                }
                if(node->right){
                    q.push({node->right,{r+1,c+1}});
                    levelwise[c+1].push_back(node->right->val);
                }
            }
            for(auto it : levelwise){
                vector<int>curr=it.second;
                leftMostCol=min(leftMostCol,it.first);
                rightMostCol=max(rightMostCol,it.first);
                sort(curr.begin(),curr.end());
                for(int n : curr){
                    mp[it.first].push_back(n);
                }
            }
        }
        int n=abs(leftMostCol)+rightMostCol+1;
        vector<vector<int>>ans(n);
        for(auto it : mp){
            ans[abs(leftMostCol)+it.first]=it.second;
        }
        return ans;        
    }
};