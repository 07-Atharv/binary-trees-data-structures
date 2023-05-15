// preorder without recursion
/*Algorithm

Last in first Out
Step 1 = Push the root of tree in the stack
Step 2 = Take the top of the stack and print
Step 3 = Now take first Right of the root and Left of the Root and push it into the stack Then print the top of the stack(because the stack is fifo)



Take print check left and right agaian follow same process
*/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct TreeNode
{
    int value;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int data)
    {
        value = data;
    }
};
vector<int> preiterative(TreeNode *root)
{
    vector<int> vect;
    // Check the base condition
    if (root == NULL)
    {
        return vect;
    }
    // Stack to store the elements to traverse
    stack<TreeNode *> st;
    // Intially Put the element into the stack and then print that element and then add the right first and then second left in the stack
    st.push(root);
    while (!st.empty())
    {
        // Store the top of the element in the root variable
        root = st.top();
        // Remove the top of the element from the top of the stack
        st.pop();
        // Push the current root value in thee vector of preorder traversal
        vect.push_back(root->value);
        // Check the right first because we are using the Stack that is lifo so we will push right first
        if (root->right != NULL)
        {
            st.push(root->right);
        }
        // Check the left first second we are using the Stack that is lifo so we will push left second
        if (root->left != NULL)
        {
            st.push(root->left);
        }
    }
    return vect;
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
    preiterative(root);
    return 0;
}
//TC  - O(N) SC-O(N)