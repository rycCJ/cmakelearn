
#include <iostream>
using namespace std;

class Node
{
public:
    int Value;
    Node *Next;
};
class doubleNode
{
public:
    int Value;
    doubleNode *Next;
    doubleNode *Previous; // 双向链表
};

void printList(Node *n)
{
    cout << "----------now is: ----------" << endl;
    while (n != NULL)
    {
        cout << n->Value << endl;
        n = n->Next;
    }
}
void InsertattheBegin(Node **head, int value) // 要在函数里改变 “链表头指针” 的值(Node *head)。也就是说你要 修改指针变量，就必须传它的地址，也就是：Node **
                                              //   需要修改 head 指针
{
    Node *newNode = new Node();
    newNode->Value = value;
    newNode->Next = *head; // 将新节点的 Next 指向当前头节点    解引；

    // move the head of the list to the newnodee ***
    *head = newNode;
}

void Insertattheend(Node **head, int value)
{
    // 1.prepare a newnode
    Node *newnode = new Node();
    newnode->Value = value;
    newnode->Next = NULL;
    // 2. if the list is empty, newnode will be a head node
    if (*head == NULL)
    {
        *head = newnode; // ✅ 这才是真正修改原始 head  修改了原始的head，所以传的时候要是Node**而非Node*
        return;
    }
    Node *last = *head;
    // 3. if the list is not empty, traverse to the last node
    while (last->Next != NULL)
    {
        last = last->Next;
    }
    // 4. make the last node's Next point to newnode

    last->Next = newnode;
}
void after(Node **previous, int value) // 不需要改变head
{
    if (previous == NULL)
    {
        cout << "Previous can not find";
        return;
    }
    Node *newnode = new Node();
    newnode->Value = value;

    newnode->Next = (*previous)->Next;
    (*previous)->Next = newnode;
}
void zhixingNode()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->Value = 1;
    head->Next = second;
    second->Value = 2;
    second->Next = third;
    third->Value = 3;
    third->Next = NULL;
    InsertattheBegin(&head, -1);
    printList(head);
    Insertattheend(&head, 666);
    printList(head);
    after(&second, 55);
    printList(head);

    system("pause>0");
}
int main()
{
    // doubleNode *head = new doubleNode();
}