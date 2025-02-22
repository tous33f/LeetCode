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
    int cur;
    int find_depth(string str,int i){
        int cnt=0;
        while(i+cnt<str.length() && str[i+cnt]=='-') cnt++;
        return cnt;
    }
    int construct_number(string str,int i){
        int num=0;
        while(i<str.length() && str[i]!='-'){
            num*=10;
            num+=int(str[i++]-'0');
        }
        return num;
    }
    TreeNode* backtrack(string str,int cur_depth){
        int new_depth;
        TreeNode* cur_node=new TreeNode(construct_number(str,cur));
        while(cur+1<str.length() && str[cur+1]!='-') cur++;
        new_depth=find_depth(str,cur+1);
        if(new_depth==cur_depth+1){
            cur+=(new_depth+1);
            cur_node->left=backtrack(str,new_depth);
        }
        else{
            return cur_node;
        }
        new_depth=find_depth(str,cur+1);
        if(new_depth==cur_depth+1){
            cur+=(new_depth+1);
            cur_node->right=backtrack(str,new_depth);
        }
        return cur_node;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        TreeNode* root=backtrack(traversal,0);
        return root;
    }
};