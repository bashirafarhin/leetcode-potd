class Solution {
public:
    TreeNode* solve(TreeNode* root,int key,int c){
        if(root==NULL){ return root; }
        if(root->val==key){

           TreeNode* r=root->right;
           TreeNode* l=root->left;
           delete root;

           if(!l){ return r; }
           if(!r){ return l; }

           TreeNode* rst=r->left;
           TreeNode* curr=l;
           while(curr->right !=NULL){ curr=curr->right; }
           curr->right=rst;
           r->left=l;
           return r;
        }
        root->left=solve(root->left,key,c);
        root->right=solve(root->right,key,c);
        return root;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key,0);
    }
};