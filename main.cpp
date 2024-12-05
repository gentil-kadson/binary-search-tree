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
    int printOrderOption;

    cout << "How many nodes do you want your BST to have? ";
    cin >> numberOfNodes;

    while (aux < numberOfNodes)
    {
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

    cout << "==============TREE PRINTING ORDER==============" << endl;
    cout << "Which printing method do you want to use?" << endl;
    cout << "[1] By level" << endl;
    cout << "[2] Pre Order" << endl;
    cout << "[3] Post Order" << endl;
    cout << "[4] Symmetrical" << endl;
    while (true)
    {
        cin >> printOrderOption;
        if (printOrderOption != 1 && printOrderOption != 2 && printOrderOption != 3 && printOrderOption != 4)
        {
            cout << "This is not a valid input value." << endl;
        }
        else
        {
            break;
        }
    }

    switch (printOrderOption)
    {
    case 1:
        cout << "By level:" << endl;
        showOrderByLevel(root);
        cout << endl;
        break;
    case 2:
        cout << "Pre Order: " << endl;
        preOrder(root);
        cout << endl;
        break;
    case 3:
        cout << "Post Order: " << endl;
        postOrder(root);
        cout << endl;
        break;
    case 4:
        cout << "Symmetrical: " << endl;
        symmetricalOrder(root);
        cout << endl;
        break;
    default:
        break;
    }

    return 0;
}