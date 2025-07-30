#include <iostream>
#include <stdexcept>
#include <vector>

template <typename E>
class MyArrayList
{
private:
    // 真正存储数据的底层数组
    E *data;
    // 记录当前元素个数
    int size;
    // 最大元素容量
    int cap;
    // 默认初始容量
    static const int INIT_CAP = 1;

public:
    MyArrayList()
    {
        this->data = new E(INIT_CAP);
        this->size = 0;
        this->cap = INIT_CAP;
    }
    MyArrayList(int capacity)
    {
        this->data = new E(capacity);
        this->size = 0;
        this->cap = capacity;
    }
    // 增加元素
    void addLast(E e)
    {
        if (size == cap)
        {
            resize(2 * cap); //?/??????
        }
        data[size] = e;
        size++;
    }
    void add(int index, E e)
    {
        checkPositionIndex();
        if (size == cap)
        {
            resize(2 * cap); //?/??????
        }
    }
    // 将 data 的容量改为 newCap
    void resize(int newCap)
    {
        E *temp = new E(newCap);
        for (int i = 0; i < size; i++)
        {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        size = newCap;
    }
    bool isPositionIndex(int index)
    {
        return index > 0 && index < size;
    }
    void checkPositionIndex()
    {
    }
};

int main()
{
    // 初始容量设置为 3
    MyArrayList<int> arr(3);

    // 添加 5 个元素
    for (int i = 1; i <= 5; i++)
    {
        arr.addLast(i);
    }
    arr.add(1, 9);
    // arr.remove(3);
    // arr.add(1, 9);
    // arr.addFirst(100);
    // int val = arr.removeLast();

    // // 100 1 9 2 3
    // for (int i = 0; i < arr.getSize(); i++)
    // {
    //     std::cout << arr.get(i) << std::endl;
    // }

    return 0;
}