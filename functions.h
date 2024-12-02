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

Node *search(Node *root, int key);

Node *insert(Node *root, int key);

void getNumberOfNodes(Node *root, int *count);

void getNumberOfLeaves(Node *root, int *count);

void printBST(Node *root, int level = 0);

Node *locateMin(Node *root);
