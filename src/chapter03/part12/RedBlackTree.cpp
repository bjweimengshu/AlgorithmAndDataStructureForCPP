#include <iostream>

// 枚举类型表示节点颜色
enum class Color { RED, BLACK };

// 红黑树节点定义
struct Node {
    int data;     // 节点值
    Color color;  // 节点颜色
    Node* parent; // 父节点指针
    Node* left;   // 左子节点指针
    Node* right;  // 右子节点指针

    // 构造函数
    Node(int val, Color c, Node* p, Node* l, Node* r)
        : data(val), color(c), parent(p), left(l), right(r) {}
};

class RedBlackTree {
private:
    Node* root;
    Node* nil;

    // 左旋操作
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nil) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nil) {
            root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // 右旋操作
    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nil) {
            x->right->parent = y;
        }
        x->parent = y->parent;
        if (y->parent == nil) {
            root = x;
        } else if (y == y->parent->left) {
            y->parent->left = x;
        } else {
            y->parent->right = x;
        }
        x->right = y;
        y->parent = x;
    }

    // 插入修复操作
    void insertFixup(Node* z) {
        while (z->parent->color == Color::RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y->color == Color::RED) {
                    // Case 1: 重新着色
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        // Case 2: 左旋
                        z = z->parent;
                        leftRotate(z);
                    }
                    // Case 3: 重新着色和右旋
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                Node* y = z->parent->parent->left;
                if (y->color == Color::RED) {
                    // Case 1: 重新着色
                    z->parent->color = Color::BLACK;
                    y->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->left) {
                        // Case 2: 右旋
                        z = z->parent;
                        rightRotate(z);
                    }
                    // Case 3: 重新着色和左旋
                    z->parent->color = Color::BLACK;
                    z->parent->parent->color = Color::RED;
                    leftRotate(z->parent->parent);
                }
            }
        }
        root->color = Color::BLACK;
    }

    // 插入新节点
    void insert(Node* z) {
        Node* y = nil;
        Node* x = root;
        while (x != nil) {
            y = x;
            if (z->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        z->parent = y;
        if (y == nil) {
            root = z;
        } else if (z->data < y->data) {
            y->left = z;
        } else {
            y->right = z;
        }
    }

public:
    RedBlackTree() {
        nil = new Node(0, Color::BLACK, nullptr, nullptr, nullptr);
        root = nil;
    }

    // 插入新节点的公共接口
    void insert(int val) {
        Node* z = new Node(val, Color::RED, nil, nil, nil);
        insert(z);
        insertFixup(z);
    }

    // 中序遍历，用于显示树的内容
    void display(Node* x) {
        if (x == nil) return;
        display(x->left);
        std::cout << x->data << " (" << (x->color == Color::RED ? "RED" : "BLACK") << ") ";
        display(x->right);
    }

    void display() {
        display(root);
    }
};

int main() {
    RedBlackTree rbt;

    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(5);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);

    std::cout << "Red-Black Tree elements: ";
    rbt.display();
    std::cout << std::endl;

    return 0;
}
