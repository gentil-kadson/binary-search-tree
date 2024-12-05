#include <iostream>
#include "functions.h"
#include <queue>
using namespace std;

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

void printBST(Node *root, int level)
{
    if (root != NULL)
    {
        printBST(root->right, level + 1);
        string space(4 * level, ' ');
        cout << space << "->" << root->key << endl;
        printBST(root->left, level + 1);
    }
}

Node *locateMin(Node *root)
{
    Node *min = root->left;
    Node *aux = NULL;
    cout << "Olha o min aqui ó: " << min->key << endl;

    if (root->left == NULL && root->right != NULL)
    {
        aux = root;
    }
    else
    {
        while (min != NULL)
        {
            aux = min;
            min = min->left;
        }
    }

    return aux;
}

void removeNode(int key, Node *&root)
{
    Node *aux;
    if (root == NULL)
    {
        return;
    }
    else if (key < root->key)
    {
        removeNode(key, root->left);
    }
    else if (key > root->key)
    {
        removeNode(key, root->right);
    }
    else if (root->left != NULL && root->right != NULL)
    {
        aux = locateMin(root->right);
        root->key = aux->key;
        removeNode(root->key, root->right);
    }
    else
    {
        aux = root;
        if (root->left != NULL)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}

void preOrder(Node *root)
{
    cout << root->key;
    if (root->left != NULL)
    {
        preOrder(root->left);
    }
    if (root->right != NULL)
    {
        preOrder(root->right);
    }
}

void symmetricalOrder(Node *root)
{
    if (root->left != NULL)
    {
        symmetricalOrder(root->left);
    }
    cout << root->key;
    if (root->right != NULL)
    {
        symmetricalOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root->left != NULL)
    {
        postOrder(root->left);
    }
    if (root->right != NULL)
    {
        postOrder(root->right);
    }
    cout << root->key;
}