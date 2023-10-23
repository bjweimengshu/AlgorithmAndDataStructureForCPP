#include <iostream>
#include <stack>

// 二叉树节点定义
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// 非递归前序遍历
void iterativePreorderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    std::stack<TreeNode*> nodeStack;
    nodeStack.push(root);

    while (!nodeStack.empty()) {
        TreeNode* current = nodeStack.top();
        nodeStack.pop();

        std::cout << current->data << " "; // 输出当前节点的值

        // 注意：由于栈是后进先出（LIFO）的数据结构，
        // 所以我们首先将右子节点推入栈，然后左子节点，
        // 以确保在处理时先访问左子树。
        if (current->right) {
            nodeStack.push(current->right);
        }
        if (current->left) {
            nodeStack.push(current->left);
        }
    }
}

int main() {
    // 创建一个示例二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "iterative preorder traversal: ";
    iterativePreorderTraversal(root);
    std::cout << std::endl;

    // 释放内存，防止内存泄漏
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
