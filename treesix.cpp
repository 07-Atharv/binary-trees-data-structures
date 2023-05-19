// Iterative postorder traversal using two stack
// Algorithm
/*
Step 1 = Maitain two stack and one vector one to store the operations and another stack to store the order in lifo order and vector to store the order
Step 2 = Push the root of the node in stack1 remove the root and push it into stack2
Step 3 = Check the left and right if avaliable of the above step current root and then add it in stack1 first add left side first and then second side
Step 4 = Continue until stack1 is empty
Step 5 = Top the elements from the stack 2 and then push back into vector and print the vecor
*/
#include <iostream>
#include <stack>
#include <vector>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int value)
    {
        data = value;
    }
};
vector<int> iterpost(Node *root)
{
    vector<int> post;
    stack<Node *> stackone, stacktwo;
    stackone.push(root);
    while (stackone.empty() == true)
    {
        root = stackone.top();
        root.pop();
        stacktwo.push(root);
        if (root->left != NULL)
        {
            stackone.push(root->left);
        }
        if (root->right != NULL)
        {
            stackone.push(root->left);
        }
    }
    while (stacktwo.empty() == true)
    {
        post.push_back(stacktwo.top());
        stacktwo.pop();
    }
    return post;
}
int main()
{
    struct Node *root = new Node(100);
    root->leftT = new Node(200);
    root->rightT = new Node(300);
    root->leftT->leftT = new Node(400);
    root->leftT->rightT = new Node(500);
    root->rightT->rightT = new Node(700);
    root->rightT->leftT = new Node(600);

    iterpost(root);
}
