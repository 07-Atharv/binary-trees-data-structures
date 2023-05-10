#include <iostream>
using namespace std;
struct Node
{
    int data;
    // Creating the pointer for left and right subtree
    struct Node *leftT;
    struct Node *rightT;
    // Creating the constructor to assign the value to the node
    Node(int value)
    {
        data = value;
        leftT = rightT = NULL;
    }
};
int main()
{
    // Creating the root Node
    struct Node *root = new Node(100);
    root->leftT = new Node(200);
    root->rightT = new Node(300);
    root->leftT->leftT = new Node(400);
    root->leftT->rightT = new Node(500);
    root->rightT->rightT = new Node(700);
    root->rightT->leftT = new Node(600);

    // Printing the nodes in the tree
    cout << "Nodes in the tree are:-";
    cout << root->data << endl;
    cout << root->leftT->data << endl;
    cout << root->rightT->data << endl;
    cout << root->rightT->leftT->data << endl;
    cout << root->rightT->rightT->data << endl;
    cout << root->leftT->rightT->data << endl;
    cout << root->leftT->leftT->data << endl;
    cout << "Tree created" << endl;
    return 0;
}