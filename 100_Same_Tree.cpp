// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Example 1:
// Input: p = [1,2,3], q = [1,2,3]
// Output: true

// Example 2:
// Input: p = [1,2], q = [1,null,2]
// Output: false

// Example 3:
// Input: p = [1,2,1], q = [1,1,2]
// Output: false

// Constraints:
// The number of nodes in both trees is in the range [0, 100].
// -104 <= Node.val <= 104

// Intuition
// We well use 2 method to solve this problem

// Recursive method
// Iterative method
// Approach
// method 1. Recursion
// 1. If one of the node is NULL then return the equality result of p an q.
// a. This boils down to if both are NULL then return true,
// b. if one of them is NULL but not the other one then return false

// 2. At this point both root nodes represent valid pointers(after checking the if condition).
// Return true if the root nodes have same value (p->val==q->val)
// Recursively check right subtrees of both trees p and q
// Recursively check left subtrees of both trees p and q

// 3. If the left or right subtrees are different, return false

// Here is image for more clearity

// Complexity
// Time complexity -->O(N)
// Space complexity -->O(H)H=height of binary tree

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)    return true;
        if(!p || !q)    return false;
            return (p->val == q->val && isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
    }
};

// Method 2. Iterative solution
// 1.  Create a stack and push the roots of both trees onto the stack as pairs.
// 2. While the stack is not empty
//  Pop a pair of nodes from the stack.
//  If both nodes are null, continue.
//  If one node is null or the values at the nodes are different, return false.
//  Push the left and right children of both nodes onto the stack as pairs.
// 3.  If the loop completes, return true.

// Complexity
// Time complexity -->O(N)
// Space complexity -->O(N)

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});
        while (!st.empty()) {
            auto [node1, node2] = st.top();
            st.pop();
            if (!node1 && !node2) continue;
            if (!node1 || !node2 || node1->val != node2->val) return false;
            st.push({node1->left, node2->left});
            st.push({node1->right, node2->right});
        }
        return true;
    }
};
