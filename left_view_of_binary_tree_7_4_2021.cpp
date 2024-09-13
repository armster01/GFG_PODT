#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to return the left view of the binary tree
vector<int> leftView(TreeNode* root) {
    vector<int> result;
    if (root == NULL) return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();  // Number of nodes at current level
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();

            // Capture the first node of each level (leftmost node)
            if (i == 0) {
                result.push_back(node->data);
            }

            // Add the left and right children of the current node to the queue
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }
    }

    return result;
}

// Utility function to print the left view
void printLeftView(const vector<int>& view) {
    for (int val : view) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Get and print the left view of the tree
    vector<int> view = leftView(root);
    cout << "Left View of the Binary Tree: ";
    printLeftView(view);

    return 0;
}
