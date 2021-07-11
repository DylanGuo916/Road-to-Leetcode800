/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start
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
    void recoverTree(TreeNode* root) {
      stack<TreeNode*> stk;
      TreeNode* x = nullptr;
      TreeNode* y = nullptr;
      TreeNode* pred = nullptr;

      while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
          stk.push(root);
          root = root->left;
        }
        root = stk.top();
        stk.pop();
        
        if (pred != nullptr && root->val < pred->val) {
          y = root;
          if (x == nullptr)
            x = pred;
          else
            break;
        }
        pred = root;
        root = root->right;

      }
      swap(x->val, y->val);
    }
};
// @lc code=end

