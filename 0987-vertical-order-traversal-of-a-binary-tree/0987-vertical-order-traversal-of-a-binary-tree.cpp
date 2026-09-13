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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; 
        if(root == nullptr) return ans;
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()) {
            auto kyu = q.front();
            q.pop();
            TreeNode* tempNode = kyu.first;
            int x = kyu.second.first;
            int y = kyu.second.second;
            nodes[x][y].insert(tempNode->val);
            if(tempNode->left) q.push({tempNode->left, {x-1, y+1}});
            if(tempNode->right) q.push({tempNode->right, {x+1, y+1}});
        }
        for(auto it : nodes) {
            vector<int> temp;
            for(auto i : it.second) {
                temp.insert(temp.end(), i.second.begin(), i.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};