class Solution {
public:
    TreeNode* solve(TreeNode* root, int val, int depth){
        if(depth==1 || root==NULL){ return root; }
        
        if(depth==2){
            TreeNode* Node1=new TreeNode(val);
            TreeNode* Node2=new TreeNode(val);

            TreeNode* l=root->left;
            TreeNode* r=root->right;

            root->left=Node1;
            Node1->left=solve(l,val,depth-1);

            root->right=Node2;
            Node2->right=solve(r,val,depth-1);
            return root;
        }

        
        cout<<root->val<<endl;
        root->left=solve(root->left,val,depth-1);
        root->right=solve(root->right,val,depth-1);
        return root;

    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* Node=new TreeNode(val);
            Node->left=root;
            return Node;
        }
        return solve(root,val,depth);        
    }
};