#include <iostream>
using namespace std;

// Implementation of the binary tree
// Create a node, which will contain two pointers to store the addresses of the child components and data

template<typename T>
struct Node
{
    T data;
    Node* leftNode;
    Node* rightNode;

    Node(const T& Data) // Declare the constructor to initialize the value of the member
    {
        data = Data;
        leftNode = nullptr;
        rightNode = nullptr;
    }
};

template<typename T>
class Tree
{
private:
    Node<T>* head;

    Node<T>* addNodeToTheBinaryTree(Node<T>* node, T data) // Create a function which will take a node and data
    {
        if(node == nullptr) // Check if the node is null
        {
            Node<T>* newnode = new Node<T>(data); // Initialize the data
            return newnode; // Return the address of the node to the head
        }
        else if(data > node->data) // If the data is greater than the root, insert the data into the right side
        {
            node->rightNode = addNodeToTheBinaryTree(node->rightNode, data);
        }
        else
        {
            node->leftNode = addNodeToTheBinaryTree(node->leftNode, data); // Otherwise, insert the data into the left side, call the function recursively
        }
        return node; // Return the address of the root
    }

public:
    Tree()
    {
        head = nullptr;
    }

    void addNodeToTheTree(T data)
    {
        head = addNodeToTheBinaryTree(head, data);
    }
};

int main()
{
    Tree<int> re;
    re.addNodeToTheTree(4);
    re.addNodeToTheTree(9);
    re.addNodeToTheTree(6);
    re.addNodeToTheTree(7);
    re.addNodeToTheTree(3);
    return 0;
}
