#include <iostream>

// 定义链表节点
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// 定义链表类
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // 插入元素到链表尾部
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // 删除指定元素
    void remove(int value) {
        Node* current = head;
        Node* prev = nullptr;

        while (current != nullptr) {
            if (current->data == value) {
                if (prev == nullptr) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // 修改指定元素
    void modify(int oldValue, int newValue) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldValue) {
                current->data = newValue;
                return;
            }
            current = current->next;
        }
    }

    // 查找元素是否存在
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    // 打印链表元素
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // 析构函数，释放内存
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList myList;

    myList.insert(1);
    myList.insert(2);
    myList.insert(3);
    myList.insert(4);

    std::cout << "Original List: ";
    myList.display();

    myList.remove(3);
    std::cout << "List after removing 3: ";
    myList.display();

    myList.modify(2, 5);
    std::cout << "List after modifying 2 to 5: ";
    myList.display();

    std::cout << "Is 4 in the list? " << (myList.search(4) ? "Yes" : "No") << std::endl;

    return 0;
}
