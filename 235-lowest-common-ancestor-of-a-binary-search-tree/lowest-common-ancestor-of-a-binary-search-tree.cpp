/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* backtrack(TreeNode *cur,int p,int q){
        if(!cur){
            return NULL;
        }
        if(cur->val==p || cur->val==q || (cur->val>p && cur->val<q)){
            return cur;
        }
        TreeNode *left=backtrack(cur->left,p,q);
        if(left) return left;
        else return backtrack(cur->right,p,q);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return backtrack(root,min(p->val,q->val),max(p->val,q->val));
    }
};