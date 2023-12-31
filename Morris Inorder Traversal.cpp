//Link - https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr -> left == NULL){
                in.push_back(curr -> val);
                curr = curr -> right;
            }
            else{
                TreeNode* prev = curr -> left;
                while(prev -> right and prev -> right != curr){
                    prev = prev -> right;
                }
                if(prev -> right == NULL){
                    prev -> right = curr;
                    curr = curr -> left;
                }
                else{
                    prev -> right = NULL;
                    in.push_back(curr -> val);
                    curr = curr -> right;
                }
            }
        }
        return in;
    }
};
