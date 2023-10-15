#include <iostream>
using namespace std;

template<typename T>  
struct Node  //declare a node
{
    T data;
    Node<T> *next = nullptr;
};

template<typename T>
class SingleLinkedList
{
private:
    Node<T>* head; // a head which it will point to the first node in the list 

public:
    SingleLinkedList()
    {
        head = nullptr;     //concstructure to inilize the head 
    }

    void addList(T data)
    {
        Node<T>* node = new Node<T>;
        node->data = data;

        Node<T>* tmp = head;

        if(head == nullptr)
        {
            head = node;
        }
        else
        {
            while (tmp->next != nullptr) //check the condition an
            {
                tmp = tmp->next;
            }
            tmp->next = node;
        }
    }

    void Display()
    {
        Node<T> *node = head;
        while(node != nullptr)
        {
            cout << node->data << " ";
            node = node->next;
        }
    }
};

int main()
{
    SingleLinkedList<int> li;
    li.addList(12);
    li.addList(13);
    li.addList(14);
    li.addList(15);
    li.Display();

    return 0;
}
