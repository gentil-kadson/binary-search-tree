#include <iostream>
#include "functions.h"
using namespace std;

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
    cout << "Here's your tree: " << endl;
    printBST(root);
    cout << "Your BST has " << nodesCount << " nodes." << endl;
    cout << "Your BST has " << leavesCount << " leaves." << endl;

    return 0;
}