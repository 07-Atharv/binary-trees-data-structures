// Level order traversal in the c++ using queue and vector of vector
// Algorithm
// Step 1 Take the root node and push it into the queue
// Step 2 Now check the first left side exists or not if exists then add it into the queue and vice versa for right side
// Step 3 Now the level has complete then take the completed level node and put it into the vector
// Step 4 Now check the left and right of the  root node and push that into the queue continue until we reach till leaf node that is last level
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct TreeNode
{
    int value;
    sturct TreeNode *left;
    sturct TreeNode *right;
    TreeNode(int data)
    {
        value = data;
        left = right = NULL;
    }
};
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    // If we reach the last level or node with no childs
    if (root == NULL)
    {
        return ans;
    }
    // Now for storing the nodes in queue we will decalre the queue insided with node
    queue<TreeNode *> q;
    // Inserting the root element in the queue to begin with level 0
    q.push(root);
    // Declaring the level to store the nodes of particular level
    vector<int> level;
    // Loop until the while is not empty
    while (!q.empty())
    {
        // For each Node check the successor are present or not
        for (int i = 0; i < q.size(); i++)
        {
            // Store the current Node
            TreeNode *Node = q.front();
            // Remove it from the queue and start checking the successors
            q.pop();
            // Check if there is left successor or not
            if (Node->left != NULL)
            {
                q.push(Node);
            }
            // Check if there is right successor or not
            if (Node->right != NULL)
            {
                q.push(Node);
            }
            // Store the value in the level vector
            level.push_back(Node->value);
        }
        // Push the vector in the vector
        ans.push_back(level);
    }
    // return the vector
    return ans;
}
int main()
{
    return 0;
}
