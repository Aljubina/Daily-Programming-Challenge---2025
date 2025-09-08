#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Helper function to check BST validity
bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTHelper(root->left, minVal, root->val) &&
           isValidBSTHelper(root->right, root->val, maxVal);
}

// Main function
bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
}

// -------- Test Driver Code --------
int main() {
    // Example 1: root = [2,1,3]
    TreeNode* root1 = new TreeNode(2);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(3);
    cout << (isValidBST(root1) ? "true" : "false") << endl;  // Output: true

    // Example 2: root = [5,1,4,null,null,3,6]
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(4);
    root2->right->left = new TreeNode(3);
    root2->right->right = new TreeNode(6);
    cout << (isValidBST(root2) ? "true" : "false") << endl;  // Output: false

    // Example 3: root = [10,5,15,null,null,6,20]
    TreeNode* root3 = new TreeNode(10);
    root3->left = new TreeNode(5);
    root3->right = new TreeNode(15);
    root3->right->left = new TreeNode(6);
    root3->right->right = new TreeNode(20);
    cout << (isValidBST(root3) ? "true" : "false") << endl;  // Output: false

    // Edge Case 1: Single Node
    TreeNode* root4 = new TreeNode(7);
    cout << (isValidBST(root4) ? "true" : "false") << endl;  // Output: true

    // Edge Case 2: Tree with repeated values
    TreeNode* root5 = new TreeNode(2);
    root5->left = new TreeNode(2);
    cout << (isValidBST(root5) ? "true" : "false") << endl;  // Output: false

    return 0;
}
