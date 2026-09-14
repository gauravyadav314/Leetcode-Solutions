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
    TreeNode* makeTree(vector<int>& preorder, int prSt, int prEnd, vector<int>& inorder, int inSt, int inEnd, unordered_map<int, int>& mp) {
        if(prSt > prEnd || inSt > inEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[prSt]);
        int leftOver = mp[preorder[prSt]]-inSt;
        root->left = makeTree(preorder, prSt+1, prSt+leftOver, inorder, inSt, mp[preorder[prSt]]-1, mp);
        root->right = makeTree(preorder, prSt+leftOver+1, prEnd, inorder, mp[preorder[prSt]]+1, inEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int in = inorder.size();
        int pr = preorder.size(); 
        unordered_map<int, int> mp;
        for(int x=0; x<in; x++) mp[inorder[x]] = x;
        return makeTree(preorder, 0, pr-1, inorder, 0, in-1, mp);
    }
};