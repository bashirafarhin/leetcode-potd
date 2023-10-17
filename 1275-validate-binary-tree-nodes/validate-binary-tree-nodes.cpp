class Solution {
public:
    void inorder(int start , vector<int> & left , vector<int> & right , int & nodes ){
        if(start==-1){
            return ;
        }
        inorder(left[start] , left , right , nodes);
        nodes--;
        inorder(right[start] , left , right , nodes);
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       
        vector<int> parent (n , -1);
    
        for(int i = 0 ; i<leftChild.size() ; i++){
            //this means this child was already visited by some other parent
            if( leftChild[i]!=-1 && parent[leftChild[i]]!=-1){
                return 0;
            }
            if( rightChild[i]!=-1 && parent[rightChild[i]]!=-1){
                return 0;
            }

            //just make the parent of this left & right Childs to be i
            if(leftChild[i]!=-1 && parent[leftChild[i]]==-1)
             parent[leftChild[i]]=i;
            if(rightChild[i]!=-1 && parent[rightChild[i]]==-1)
             parent[rightChild[i]]=i;
        }

        //from this you'll get the root and if the traversal of this tree
        //from root contains all the elements then it is a valid tree.
        bool flag = 0;
        int total = 0;
        int root = -1;
        for(int i = 0  ; i<n ; i++){
            int child = i;
            int par = parent[i];

            //this means ki ye banda 1st node hai jo root node ban skta
            if(par ==-1 && flag == 0 ){
                total++;
                flag = 1;
                //storing the root for further traversals
                root = i;
            }
            //agar 1 se zyada banda root ban skta mtlb valid tree nhi h
            //components honge
            else if(par ==-1 && flag == 1){
                return 0;
            }
        }

        int nodes = n;
        inorder(root , leftChild , rightChild , nodes);
        //this tests ki inorder se saare nodes cover hue ya nhi!
        return nodes==0;
    }
};
