#include <iostream>

// 二叉树节点定义
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 前序遍历
void preorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    std::cout << root->data << " ";  // 访问当前节点
    preorderTraversal(root->left);   // 递归遍历左子树
    preorderTraversal(root->right);  // 递归遍历右子树
}

// 中序遍历
void inorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    inorderTraversal(root->left);    // 递归遍历左子树
    std::cout << root->data << " ";  // 访问当前节点
    inorderTraversal(root->right);   // 递归遍历右子树
}

// 后序遍历
void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    postorderTraversal(root->left);   // 递归遍历左子树
    postorderTraversal(root->right);  // 递归遍历右子树
    std::cout << root->data << " ";  // 访问当前节点
}

int main() {
    // 创建一个示例二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "preorder traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    std::cout << "inorder traversal: ";
    inorderTraversal(root);
    std::cout << std::endl;

    std::cout << "postorder traversal: ";
    postorderTraversal(root);
    std::cout << std::endl;

    // 释放内存，防止内存泄漏
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
