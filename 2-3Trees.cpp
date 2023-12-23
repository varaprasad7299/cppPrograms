#include <iostream>
using namespace std;

// Define a structure for a node in the 2-3 tree
struct Node {
    int key1;
    int key2;
    Node* left;
    Node* middle;
    Node* right;
};

// Function to create a new node
Node* createNode(int key) {
    Node* node = new Node;
    node->key1 = key;
    node->key2 = -1;
    node->left = nullptr;
    node->middle = nullptr;
    node->right = nullptr;
    return node;
}

// Function to insert a key into the 2-3 tree
Node* insert(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    } else if (root->key2 == -1) { // if node has only one key
        if (key < root->key1) {
            root->key2 = root->key1;
            root->key1 = key;
        } else {
            root->key2 = key;
        }
        return root;
    } else if (key < root->key1) {
        root->left = insert(root->left, key);
    } else if (key > root->key2) {
        root->right = insert(root->right, key);
    } else {
        root->middle = insert(root->middle, key);
    }

    // split the node if it has three keys
    if (root->middle != nullptr) {
        Node* left = createNode(root->key1);
        left->left = root->left;
        left->middle = root->middle->left;
        Node* right = createNode(root->key2);
        right->left = root->middle->right;
        right->right = root->right;
        root->key1 = root->middle->key1;
        root->key2 = -1;
        root->left = left;
        root->middle = right;
        root->right = nullptr;
    }

    return root;
}

// Function to print the 2-3 tree in-order traversal
void printInorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    printInorder(root->left);
    cout << root->key1 << " ";
    if (root->key2 != -1) {
        printInorder(root->middle);
        cout << root->key2 << " ";
    }
    printInorder(root->right);
}

int main() {
    // create a 2-3 tree and insert some keys
    Node* root = nullptr;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 7);
    root = insert(root, 17);
    root = insert(root, 9);
    root = insert(root, 10);

    // print the 2-3 tree
    cout << "Inorder traversal of the 2-3 tree: ";
    printInorder(root);

    return 0;
}

