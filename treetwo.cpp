
// Implemenation of DFS using preorder postorder and inorder
// Using recursion
#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int inp)
    {
        data = inp;
        left = right = NULL;
    }
};
void preordertraversal(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << endl;
    preordertraversal(node->left);
    preordertraversal(node->right);
}
void inordertraversal(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inordertraversal(node->left);
    cout << node->data << endl;
    inordertraversal(node->right);
}
void postordertraversal(struct Node *node)
{
    if (node == NULL)
    {
        return;
    }
    postordertraversal(node->left);
    postordertraversal(node->right);
    cout << node->data << endl;
}
int main()
{
    struct Node *root = new Node(100);
    root->left = new Node(200);
    root->right = new Node(300);
    root->left->left = new Node(400);
    root->left->right = new Node(500);
    root->right->right = new Node(700);
    root->right->left = new Node(900);
    cout << "Tree created" << endl;
    cout << "Preoreder traversal for the current binary tree is " << endl;
    preordertraversal(root);
    cout << "Inorder traversal for the current binary tree is " << endl;
    inordertraversal(root);
    cout << "post traversal for the current binary tree is " << endl;
    postordertraversal(root);
}