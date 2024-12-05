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
    int nodeKey;

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

    cout << "==============RESULTS==============\n";
    cout << "Here's your tree: " << endl;
    printBST(root);
    cout << "Your BST has " << nodesCount << " nodes." << endl;
    cout << "Your BST has " << leavesCount << " leaves." << endl;

    cout << "Which node do you wish to delete? ";
    cin >> nodeKey;
    removeNode(nodeKey, root);

    cout << "==============RESULTS==============" << endl;
    cout << "Here's your tree now: " << endl;
    printBST(root);

    cout << "==============TREE PRINTING ORDERS==============" << endl;
    cout << "By level:" << endl;
    showOrderByLevel(root);
    cout << endl;

    cout << "Pre Order: " << endl;
    preOrder(root);
    cout << endl;

    cout << "Post Order: " << endl;
    postOrder(root);
    cout << endl;

    cout << "Symmetrical: " << endl;
    symmetricalOrder(root);
    cout << endl;

    return 0;
}