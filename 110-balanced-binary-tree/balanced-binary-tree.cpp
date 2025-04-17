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
    int backtrack(TreeNode *cur){
        if(!cur) return 0;
        int left=backtrack(cur->left);
        int right=backtrack(cur->right);
        if(left<0 || right<0 || abs(left-right)>1) return -1;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        if(backtrack(root)==-1) return 0;
        return 1;
    }
};