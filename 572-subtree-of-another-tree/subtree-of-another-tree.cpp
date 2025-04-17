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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode *>qp,qq;
        qp.push(p);
        qq.push(q);
        while(!qp.empty() && !qq.empty()){
            TreeNode *node_p=qp.front();
            qp.pop();
            TreeNode *node_q=qq.front();
            qq.pop();
            if( (!node_q && node_p) 
            || (!node_p && node_q) 
            || (node_p && node_q && node_p->val!=node_q->val) ){
                return 0;
            }
            else if( !node_q && !node_p ){
                continue;
            }

            //node p
            if(node_p->left) qp.push(node_p->left);
            else qp.push(NULL);
            if(node_p->right) qp.push(node_p->right);
            else qp.push(NULL);

            //node q
            if(node_q->left) qq.push(node_q->left);
            else qq.push(NULL);
            if(node_q->right) qq.push(node_q->right);
            else qq.push(NULL);
        }
        if(!qp.empty()) return 0;
        if(!qq.empty()) return 0;
        return 1;
    }
    bool backtrack(TreeNode *cur,TreeNode *check){
        if(!cur) return 0;
        if(isSameTree(cur,check) || backtrack(cur->left,check) || backtrack(cur->right,check)) return 1;
        return 0;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if((!root && !subRoot) || !subRoot) return 1;
        return backtrack(root,subRoot);
    }
};