#include <iostream>

class MyQueue {
private:
    int* queue;
    int front;
    int rear;
    int maxSize;

public:
    MyQueue(int size) {
        maxSize = size + 1;  // 留一个空位以区分队列满和队列空的情况
        queue = new int[maxSize];
        front = 0;
        rear = 0;
    }

    ~MyQueue() {
        delete[] queue;
    }

    // 入队
    bool enqueue(int value) {
        if (isFull()) {
            std::cout << "队列已满，无法入队。" << std::endl;
            return false;
        } else {
            queue[rear] = value;
            rear = (rear + 1) % maxSize;
            return true;
        }
    }

    // 出队
    bool dequeue() {
        if (isEmpty()) {
            std::cout << "队列为空，无法出队。" << std::endl;
            return false;
        } else {
            front = (front + 1) % maxSize;
            return true;
        }
    }

    // 返回队头元素
    int frontElement() {
        if (isEmpty()) {
            std::cout << "队列为空。" << std::endl;
            return -1;  // 返回一个特殊值表示队列为空
        } else {
            return queue[front];
        }
    }

    // 检查队列是否为空
    bool isEmpty() {
        return front == rear;
    }

    // 检查队列是否已满
    bool isFull() {
        return (rear + 1) % maxSize == front;
    }
};

int main() {
    MyQueue queue(5);

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    std::cout << "head element: " << queue.frontElement() << std::endl;

    queue.dequeue();
    queue.enqueue(6);

    std::cout << "head element: " << queue.frontElement() << std::endl;

    while (!queue.isEmpty()) {
        std::cout << "dequeue element: " << queue.frontElement() << std::endl;
        queue.dequeue();
    }

    return 0;
}
