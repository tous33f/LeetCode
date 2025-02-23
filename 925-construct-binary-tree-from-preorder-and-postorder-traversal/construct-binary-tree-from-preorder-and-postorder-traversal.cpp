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
    int post_cnt;
    int pre_cnt;
    TreeNode* backtrack(vector<int>& preorder, vector<int>& postorder){
        TreeNode* cur=new TreeNode(preorder[pre_cnt]);
        if(cur->val==postorder[post_cnt]){
            post_cnt++;
            pre_cnt++;
            return cur;
        }
        pre_cnt++;
        cur->left=backtrack(preorder,postorder);
        if(cur->val==postorder[post_cnt]){
            post_cnt++;
            return cur;
        }
        cur->right=backtrack(preorder,postorder);
        if(cur->val==postorder[post_cnt]){
            post_cnt++;
        }
        return cur;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        post_cnt=0;
        pre_cnt=0;
        return backtrack(preorder,postorder);
    }
};