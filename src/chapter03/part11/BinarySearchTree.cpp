#include <iostream>

// 二叉树节点定义
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    // 插入节点
    void insert(int val) {
        root = insertRecursive(root, val);
    }

    // 查找节点
    bool search(int val) {
        return searchRecursive(root, val);
    }

    // 中序遍历
    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }

private:
    TreeNode* root;

    // 递归插入节点
    TreeNode* insertRecursive(TreeNode* current, int val) {
        if (current == nullptr) {
            return new TreeNode(val);
        }

        if (val < current->data) {
            current->left = insertRecursive(current->left, val);
        }
        else if (val > current->data) {
            current->right = insertRecursive(current->right, val);
        }

        return current;
    }

    // 递归查找节点
    bool searchRecursive(TreeNode* current, int val) {
        if (current == nullptr) {
            return false;
        }

        if (val == current->data) {
            return true;
        }
        else if (val < current->data) {
            return searchRecursive(current->left, val);
        }
        else {
            return searchRecursive(current->right, val);
        }
    }

    // 中序遍历
    void inorderTraversalRecursive(TreeNode* current) {
        if (current != nullptr) {
            inorderTraversalRecursive(current->left);
            std::cout << current->data << " ";
            inorderTraversalRecursive(current->right);
        }
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(8);
    bst.insert(1);
    bst.insert(4);

    std::cout << "inorder traversal:  ";
    bst.inorderTraversal();
    std::cout << std::endl;

    int valueToFind = 4;
    if (bst.search(valueToFind)) {
        std::cout << valueToFind << " is in the binary search tree." << std::endl;
    } else {
        std::cout << valueToFind << " is not in the binary search tree." << std::endl;
    }

    return 0;
}
