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
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;
    TreeNode* prev;
    void inorder(TreeNode* root)
    {
        if(root==nullptr) return;
        inorder(root->left);
        if(root->val < prev->val)
        {
            if(first==nullptr)
            {
                first = prev;
                mid = root;
            }
            else last = root;
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        first = last = mid = nullptr;
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else swap(first->val, mid->val);
    }
};