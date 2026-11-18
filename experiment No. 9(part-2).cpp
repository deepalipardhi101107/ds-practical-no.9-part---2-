
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

int longestPath(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = longestPath(root->left);
    int rightHeight = longestPath(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int findMin(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, value, choice;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter BST values:\n";

    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    do {
        cout << "\n\n===== BINARY SEARCH TREE =====\n";
        cout << "1. Insert New Node\n";
        cout << "2. Find Longest Path\n";
        cout << "3. Find Minimum Value\n";
        cout << "4. Display Inorder Traversal\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                cout << "Node inserted successfully!";
                break;

            case 2:
                cout << "Number of nodes in longest path: "
                     << longestPath(root);
                break;

            case 3:
                if (root == NULL) {
                    cout << "Tree is empty!";
                }
                else {
                    cout << "Minimum value: "
                         << findMin(root);
                }
                break;

            case 4:
                cout << "Inorder Traversal: ";
                inorder(root);
                break;

            case 5:
                cout << "Exiting Program...";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while (choice != 5);

    return 0;
}

