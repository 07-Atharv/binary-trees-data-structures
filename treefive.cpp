/*Traversing iteratively for inorder traversal
Step 1 =  Take one stack to store the operations and single vector to store the order
Step 2 = We check the current root node and put it into the stack if it is not null
Step 3 = If there exists left then we put that into the stack and continue until the left side has not reached to not null
Step 4 = Now check the last leaf node if it has left and right both null then go back and print the top of the stack
(We first check the left then left of left is null go back and print top again check right if null then go back and print the root of that left subtree
Step 5 = Now move to the right side and do same comparision
Step 6 = The base condition for these is we have to stop when the stack is empty
)
*/
#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
vector<int> inorder(Node *root)
{
    stack<Node *> st;
    Node *node = root;
    vector<int> inorder;
    while (true)
    {
        // check if the current node is not null and move to the left until the condition fails
        if (node != NULL)
        {
            st.push(node);
            node = node->left;
        }
        // Check if the stack is empty and stop
        // These will execute when we have the left side null and we take the top element print and move to the right
        else
        {
            if (st.empty() == true)
            {
                break;
            }
            // Take the top of the stack
            node = st.top();
            // Remove that
            st.pop();
            // push it into the vector
            inorder.push_back(node->val);
            //
            node = node->right;
        }
    }
    return indorder;
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

    inoder(root);
}

// SC = TC = O(N)