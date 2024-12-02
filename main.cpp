#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int item)
    {
        key = item;
        left = right = NULL;
    }
};

Node *search(Node *root, int key)
{
    if (root == NULL || root->key == key)
    {
        return root;
    }

    if (root->key < key)
    {
        return search(root->right, key);
    }

    return search(root->left, key);
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return new Node(key);
    }

    if (root->key == key)
    {
        return root;
    }

    if (root->key < key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        root->left = insert(root->left, key);
    }

    return root;
}

void getNumberOfNodes(Node *root, int *count)
{
    if (root == NULL)
    {
        return;
    }

    *count = *count + 1;
    getNumberOfNodes(root->left, count);
    getNumberOfNodes(root->right, count);
}

void getNumberOfLeaves(Node *root, int *count)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        *count = *count + 1;
    }
    getNumberOfLeaves(root->right, count);
    getNumberOfLeaves(root->left, count);
}

void printBST(Node *root, int level = 0)
{
    if (root == NULL)
    {
        return;
    }
}

int main()
{
    int numberOfNodes;
    int nodesCount = 0;
    int leavesCount = 0;
    int aux = 0;
    Node *root = NULL;

    cout << "How many nodes do you want your BST to have? ";
    cin >> numberOfNodes;

    while (aux < numberOfNodes)
    {
        int nodeKey;
        cout << "input node " << aux + 1 << ": ";
        cin >> nodeKey;
        Node *foundNode = search(root, nodeKey);
        if (foundNode == NULL)
        {
            root = insert(root, nodeKey);
            aux++;
        }
        else
        {
            cout << "This number is already in the BST." << endl;
        }
    }

    getNumberOfNodes(root, &nodesCount);
    getNumberOfLeaves(root, &leavesCount);

    cout << "=======RESULTS=======\n";
    cout << "Your BST has " << nodesCount << " nodes." << endl;
    cout << "Your BST has " << leavesCount << " leaves." << endl;

    return 0;
}