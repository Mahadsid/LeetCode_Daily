// Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,2,3]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [1]
// Output: [1]
 
// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
// Intuition
// 3 ways to solve this problem

// Approach
// 1.Recursive approach
// Check if the current node is empty or Null.
// Display the data part of the root (or current node)
// Traverse the left subtree by recursively calling the preorder function.
// Traverse the right subtree by recursively calling the preorder function.

// 2.Iterative approach
// Create an empty stack and push the root node to it.
// Do the following while the stack is not empty
// Pop the top item from the stack and display it.
// Push the right child of the popped item to the stack.
// Push the left child of the popped item to the stack.
// Complexity
// Time complexity:O(N)
// Space complexity:O(H)H=height of binary tree

// 3.Morris traversal
// Initialize current as root
// While current is not null:
// If current does not have a left child:
// (i) Print current's data.
// (ii) Go to the right, i.e., current = current.right
// Else:
// (i)Make current as the right child of the rightmost node in current's left subtree.
// (ii)Go to this left child, i.e., current = current.left.

// Complexity
// Time complexity:O(N)
// Space complexity:O(1)

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
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*>st;
        while (root || !st.empty()) {
            if (root) {
                ans.push_back(root -> val);
                if (root -> right) {
                    st.push(root -> right);
                }
                root = root -> left;
            } else {
                root = st.top();
                st.pop();
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        while (root) {
            if (root -> left) {
                TreeNode* pre = root -> left;
                while (pre -> right && pre -> right != root) {
                    pre = pre -> right;
                }
                if (!pre -> right) {
                    pre -> right = root;
                    nodes.push_back(root -> val);
                    root = root -> left;
                } else {
                    pre -> right = NULL;
                    root = root -> right;
                }
            } else {
                nodes.push_back(root -> val);
                root = root -> right;
            }
        }
        return nodes;
    }
};
