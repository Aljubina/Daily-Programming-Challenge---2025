#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;  // Found p and q in different subtrees
        return left ? left : right;      // Either left or right contains LCA
    }
};

// Helper function to build a tree from vector (level-order input)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // Left child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Find a node by value
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    TreeNode* left = findNode(root->left, val);
    if (left) return left;
    return findNode(root->right, val);
}

// -------------------- MAIN --------------------
int main() {
    Solution sol;

    // Test Case 1
    vector<int> nodes1 = {3,5,1,6,2,0,8,-1,-1,7,4};
    TreeNode* root1 = buildTree(nodes1);
    TreeNode* p1 = findNode(root1, 5);
    TreeNode* q1 = findNode(root1, 1);
    cout << "LCA of 5 and 1: " << sol.lowestCommonAncestor(root1, p1, q1)->val << endl;

    // Test Case 2
    TreeNode* p2 = findNode(root1, 5);
    TreeNode* q2 = findNode(root1, 4);
    cout << "LCA of 5 and 4: " << sol.lowestCommonAncestor(root1, p2, q2)->val << endl;

    // Test Case 3
    vector<int> nodes2 = {1,2};
    TreeNode* root2 = buildTree(nodes2);
    TreeNode* p3 = findNode(root2, 1);
    TreeNode* q3 = findNode(root2, 2);
    cout << "LCA of 1 and 2: " << sol.lowestCommonAncestor(root2, p3, q3)->val << endl;

    return 0;
}
