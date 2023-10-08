#include <iostream>

class MyArray {
private:
    int* data;      // 存储数组元素的指针
    int size;       // 数组的当前大小
    int capacity;   // 数组的容量

public:
    MyArray(int initialCapacity = 10) : size(0), capacity(initialCapacity) {
        data = new int[capacity];
    }

    // 析构函数，释放动态分配的内存
    ~MyArray() {
        delete[] data;
    }

    // 添加元素到数组末尾
    void append(int value) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = value;
    }

    // 在指定位置插入元素
    void insert(int value, int index) {
        if (index < 0 || index > size) {
            std::cout << "index is wrong" << std::endl;
            return;
        }

        if (size >= capacity) {
            resize();
        }

        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }

        data[index] = value;
        size++;
    }

    // 删除指定位置的元素
    void remove(int index) {
        if (index < 0 || index >= size) {
            std::cout << "index is wrong" << std::endl;
            return;
        }

        for (int i = index; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
    }

    // 修改指定位置的元素
    void modify(int value, int index) {
        if (index < 0 || index >= size) {
            std::cout << "index is wrong" << std::endl;
            return;
        }

        data[index] = value;
    }

    // 查找元素的位置
    int find(int value) const {
        for (int i = 0; i < size; i++) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }

    // 获取数组大小
    int getSize() const {
        return size;
    }

    // 获取数组容量
    int getCapacity() const {
        return capacity;
    }

    // 重新分配内存以增加容量
    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    // 打印数组元素
    void print() const {
        std::cout << "array: ";
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MyArray arr;

    // 添加元素
    arr.append(1);
    arr.append(2);
    arr.append(3);

    // 打印数组元素
    arr.print();

    // 修改元素
    arr.modify(4, 1);

    // 打印修改后的数组
    arr.print();

    // 查找元素
    int searchValue = 4;
    int foundIndex = arr.find(searchValue);
    if (foundIndex != -1) {
        std::cout << "find value " << searchValue << ", index= " << foundIndex << std::endl;
    } else {
        std::cout << "not find " << searchValue << std::endl;
    }

    // 删除元素
    arr.remove(1);

    // 打印删除后的数组
    arr.print();

    // 插入元素
    arr.insert(5, 1);

    // 打印插入后的数组
    arr.print();

    // 打印数组大小和容量
    std::cout << "array size: " << arr.getSize() << std::endl;
    std::cout << "array capacity: " << arr.getCapacity() << std::endl;

    return 0;
}
