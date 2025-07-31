#include <vector>
#include <list>
#include <iostream>
#include <list>
#include <stdexcept>
/*环形数组*/
// 长度为 5 的数组
/*vector<int> arr = {1, 2, 3, 4, 5};
int i = 0;
// 模拟环形数组，这个循环永远不会结束
while (i < arr.size())
{
    cout << arr[i] << endl;
    i = (i + 1) % arr.size();
}*/
/*
#include <list>
std::list<int> lst;
lst.push_back(10);  // 尾部插入
lst.push_front(5);  // 头部插入
lst.pop_back();     // 删除尾部元素
lst.pop_front();    // 删除头部元素
//插入和删除
auto it = lst.begin();
std::advance(it, 1); // 移动迭代器
lst.insert(it, 20);  // 在位置 it 前插入 20
lst.erase(it);       // 删除位置 it 上的元素
//遍历
for (int x : lst) {
    std::cout << x << " ";
}
//迭代器
for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
    std::cout << *it << " ";
}
    //其他常用函数
lst.size();       // 元素个数
lst.empty();      // 判断是否为空
lst.clear();      // 清空所有元素
lst.front();      // 获取第一个元素
lst.back();       // 获取最后一个元素
lst.sort();       // 对链表排序
lst.reverse();    // 反转链表
lst.remove(10);   // 删除所有值为 10 的元素
*/
// 闭区间（inclusive）：指针指向的是有效数据的起点或终点元素本身。

// 开区间（exclusive）：指针指向的是数据范围的尾后位置，即下一个可写入的位置

template <typename T>
class CycleArray
{
    std::vector<T> arr;
    int start;
    int end;
    int count;

    // 自动扩缩容辅助函数
    void resize(int newSize)
    {
        // 创建新的数组并复制元素
        std::vector<T> newArr(newSize);
        for (int i = 0; i < count; ++i)
        {
            newArr[i] = arr[(start + i) % arr.size()];
        }
        arr = std::move(newArr);
        // 重置 start 和 end 指针
        start = 0;
        end = count;
    }

public:
    CycleArray() : CycleArray(1) {}

    explicit CycleArray(int size)
        : arr(size), start(0), end(0), count(0) {}

    // 在数组头部添加元素，时间复杂度 O(1)
    void addFirst(const T &val)
    {
        // 当数组满时，扩容为原来的两倍
        if (isFull())
        {
            resize(arr.size() * 2);
        }
        // 因为 start 是闭区间，所以先左移，再赋值
        // 表示将 start 指针向前移动一格，并且支持循环回绕，从而为空出一个新的位置用于头部插入。
        start = (start - 1 + arr.size()) % arr.size();
        arr[start] = val;
        count++;
    }

    // 删除数组头部元素，时间复杂度 O(1)
    void removeFirst()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Array is empty");
        }
        // 因为 start 是闭区间，所以先赋值，再右移
        arr[start] = T();
        start = (start + 1) % arr.size();
        count--;
        // 如果数组元素数量减少到原大小的四分之一，则减小数组大小为一半
        if (count > 0 && count == arr.size() / 4)
        {
            resize(arr.size() / 2);
        }
    }

    // 在数组尾部添加元素，时间复杂度 O(1)
    void addLast(const T &val)
    {
        if (isFull())
        {
            resize(arr.size() * 2);
        }
        // 因为 end 是开区间，所以是先赋值，再右移
        arr[end] = val;
        end = (end + 1) % arr.size();
        count++;
    }

    // 删除数组尾部元素，时间复杂度 O(1)
    void removeLast()
    {
        if (isEmpty())
        {
            throw std::runtime_error("Array is empty");
        }
        // 因为 end 是开区间，所以先左移，再赋值
        end = (end - 1 + arr.size()) % arr.size();
        arr[end] = T();
        count--;
        // 缩容
        if (count > 0 && count == arr.size() / 4)
        {
            resize(arr.size() / 2);
        }
    }

    // 获取数组头部元素，时间复杂度 O(1)
    T getFirst() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Array is empty");
        }
        return arr[start];
    }

    // 获取数组尾部元素，时间复杂度 O(1)
    T getLast() const
    {
        if (isEmpty())
        {
            throw std::runtime_error("Array is empty");
        }
        // end 是开区间，指向的是下一个元素的位置，所以要减 1
        return arr[(end - 1 + arr.size()) % arr.size()];
    }

    bool isFull() const
    {
        return count == arr.size();
    }

    int size() const
    {
        return count;
    }

    bool isEmpty() const
    {
        return count == 0;
    }
};
// 用链表   实现栈
// 队列的基本 API
template <typename E>
class MyQueue
{
public:
    // 向队尾插入元素，时间复杂度 O(1)
    void push(const E &e);

    // 从队头删除元素，时间复杂度 O(1)
    E pop();

    // 查看队头元素，时间复杂度 O(1)
    E peek() const;

    // 返回队列中的元素个数，时间复杂度 O(1)
    int size() const;
};

// 栈的基本 API
template <typename E>
class MyStack
{
public:
    // 向栈顶插入元素，时间复杂度 O(1)
    void push(const E &e);

    // 从栈顶删除元素，时间复杂度 O(1)
    E pop();

    // 查看栈顶元素，时间复杂度 O(1)
    E peek() const;

    // 返回栈中的元素个数，时间复杂度 O(1)
    int size() const;
};

template <typename E>
class MyLinkedStack
{
private:
    std::list<E> list;

public:
    // 向栈顶加入元素，时间复杂度 O(1)
    void push(const E &e)
    {
        list.push_back(e);
    }

    // 从栈顶弹出元素，时间复杂度 O(1)
    E pop()
    {
        E value = list.back();
        list.pop_back();
        return value;
        // 获取尾部元素且删除
    }

    // 查看栈顶元素，时间复杂度 O(1)
    E peek() const
    {
        return list.back();
    }

    // 返回栈中的元素个数，时间复杂度 O(1)
    int size() const
    {
        return list.size();
    }
};
// 用链表实现队列
template <typename E>
class MyLinkedQueue
{
private:
    std::list<E> list;

public:
    // 向队尾插入元素，时间复杂度 O(1)
    void push(const E &e)
    {
        list.push_back(e);
    }

    // 从队头删除元素，时间复杂度 O(1)
    E pop()
    {
        E front = list.front();
        list.pop_front(); // 获取队头元素且删除
        return front;
    }

    // 查看队头元素，时间复杂度 O(1)
    E peek()
    {
        return list.front();
    }

    // 返回队列中的元素个数，时间复杂度 O(1)
    int size()
    {
        return list.size();
    }
};
// 用数组作为底层数据结构实现栈

template <typename E>
class MyArrayStack
{
private:
    std::vector<E> list;

public:
    // 向栈顶加入元素，时间复杂度 O(1)
    void push(const E &e)
    {
        list.push_back(e);
    }

    // 从栈顶弹出元素，时间复杂度 O(1)
    E pop()
    {
        E topElement = list.back();
        list.pop_back();
        return topElement;
    }

    // 查看栈顶元素，时间复杂度 O(1)
    E peek() const
    {
        return list.back();
    }

    // 返回栈中的元素个数，时间复杂度 O(1)
    int size() const
    {
        return list.size();
    }
};

template <typename E>
class MyArrayQueue
{
private:
    CycleArray<E> arr;

public:
    MyArrayQueue()
    {
        arr = CycleArray<E>();
    }

    void push(E t)
    {
        arr.addLast(t);
    }

    E pop()
    {
        return arr.removeFirst();
    }

    E peek()
    {
        return arr.getFirst();
    }

    int size()
    {
        return arr.size();
    }
};

int main()
{
    // 测试栈
    MyLinkedStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    while (stack.size() > 0)
    {
        std::cout << stack.pop() << std::endl;
    }
    //    测试队列
    MyLinkedQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    std::cout << queue.peek() << std::endl; // 1
    std::cout << queue.pop() << std::endl;  // 1
    std::cout << queue.pop() << std::endl;  // 2
    std::cout << queue.peek() << std::endl; // 3

    return 0;
}