#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int item) {
        key = item;
        left = right = NULL;
    }
};

Node* search(Node* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }

    if (root->key < key) {
        return search(root->right, key);
    }

    return search(root->left, key);
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return new Node(key);
    }

    if (root->key == key) {
        return root;
    }

    if (root->key < key) {
        root->right = insert(root->right, key);
    } else {
        root->left = insert(root->left, key);
    }

    return root;
}

void getNumberOfNodes(Node* root, int* count) {
    if (root == NULL) {
        return;
    }

    *count = *count + 1;
    getNumberOfNodes(root->left, count);
    getNumberOfNodes(root->right, count);
    
}

void getNumberOfLeaves(Node* root, int* count) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        *count = *count + 1;
    }
    getNumberOfLeaves(root->right, count);
    getNumberOfLeaves(root->left, count);
}

int main() {
    Node* root = new Node(100);
    int numberOfNodes = 0;
    int numberOfLeaves = 0;

    root = insert(root, 50);
    root = insert(root, 200);
    root = insert(root, 30);

    getNumberOfNodes(root, &numberOfNodes);
    getNumberOfLeaves(root, &numberOfLeaves);

    cout << "The number of nodes in this BST is " << numberOfNodes << endl;
    cout << "The number of leaves in this BST is " << numberOfLeaves << endl;

    return 0;
}