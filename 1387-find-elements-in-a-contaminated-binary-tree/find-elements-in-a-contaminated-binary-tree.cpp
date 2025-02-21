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
class FindElements {
public:
    unordered_map<int,bool>ump;
    void backtrack(TreeNode *cur,int x,int bias){
        if(cur==NULL) return;
        cur->val=(2*x)+bias;
        ump[cur->val]=1;
        backtrack(cur->left,cur->val,1);
        backtrack(cur->right,cur->val,2);
    }
    FindElements(TreeNode* root) {
        root->val=0;
        ump[root->val]=1;
        backtrack(root->left,root->val,1);
        backtrack(root->right,root->val,2);
    }
    
    bool find(int target) {
        if(ump.find(target)==ump.end()) return false;
        else return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */