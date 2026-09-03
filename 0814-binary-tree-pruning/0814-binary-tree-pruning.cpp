/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool treePrune(TreeNode* &root) {
        if(!root) return true;
        bool left = treePrune(root -> left);
        bool right = treePrune(root -> right);
        int data = root -> val;
        if(left && right && !data) {
            root = NULL;
            return true;
        }
        else return false;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool any = treePrune(root);
        return root;
    }
};