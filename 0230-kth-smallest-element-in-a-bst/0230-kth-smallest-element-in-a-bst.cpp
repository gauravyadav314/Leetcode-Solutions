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
    // void inorder(TreeNode* root, TreeNode* leftMost, int& k, int& ans, bool& check)
    // {
    //     if(root == nullptr) return;
    //     if(root == leftMost) check = true;
    //     inorder(root->left, leftMost, k, ans, check);
    //     if(k>0 && check)
    //     {
    //         k--;
    //         if(k==0)
    //         {
    //             ans = root->val;
    //             return;
    //         } 
    //     }
    //     inorder(root->right, leftMost, k, ans, check);
    // }
    void inorder(TreeNode* root, vector<int>& in) {
        if(root==nullptr) return;
        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    int kthSmallest(TreeNode* root, int k) {
        // TreeNode* leftMost = root;
        // while(leftMost->left) leftMost = leftMost->left;
        // int ans=0;
        // bool check = false;
        // inorder(root, leftMost, k, ans, check);
        // return ans;
        vector<int> in;
        inorder(root, in);
        return in[k-1];
    }
};