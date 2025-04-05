#include <iostream>
using namespace std;

class BST {
    struct Node {
        int val;
        Node* left;
        Node* right;

        Node(int v) : val(v), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

 

    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->val) node->left = insert(node->left, val);
        else if (val > node->val) node->right = insert(node->right, val);
        return node;
    }

    Node* findMin(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    Node* findMax(Node* node) {
        while (node && node->right) node = node->right;
        return node;
    }

    Node* deleteNode(Node* node, int val) {
        if (!node) return nullptr;

        if (val < node->val) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->val) {
            node->right = deleteNode(node->right, val);
        } else {
            // Found node to delete
            if (!node->left && !node->right) {
                delete node;
                return nullptr;
            } else if (!node->left) {
                Node* tmp = node->right;
                delete node;
                return tmp;
            } else if (!node->right) {
                Node* tmp = node->left;
                delete node;
                return tmp;
            } else {
                Node* successor = findMin(node->right);
                node->val = successor->val;
                node->right = deleteNode(node->right, successor->val);
            }
        }
        return node;
    }

    void inOrder(Node* node) {
        if (!node) return;
        inOrder(node->left);
        cout << node->val << " ";
        inOrder(node->right);
    }

    void printTree(Node* node, string indent = "", bool isLeft = true) {
        if (node) {
            cout << indent;
            cout << (isLeft ? "├──" : "└──" );
            cout << node->val << endl;

            printTree(node->left, indent + (isLeft ? "│   " : "    "), true);
            printTree(node->right, indent + (isLeft ? "│   " : "    "), false);
        }
    }

public:
    
    void insert(int val) {
        root = insert(root, val);
    }

    void deleteVal(int val) {
        root = deleteNode(root, val);
    }

    int findMin() {
        Node* minNode = findMin(root);
        if (!minNode) throw runtime_error("Empty tree");
        return minNode->val;
    }

    int findMax() {
        Node* maxNode = findMax(root);
        if (!maxNode) throw runtime_error("Empty tree");
        return maxNode->val;
    }

    void inOrderTraversal() {
        inOrder(root);
        cout << endl;
    }

    void print() {
        printTree(root);
    }
};
int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal: ";
    tree.inOrderTraversal();

    cout << "Min: " << tree.findMin() << endl;
    cout << "Max: " << tree.findMax() << endl;

    cout << "\nCây hiện tại:\n";
    tree.print();

    tree.deleteVal(30);
    cout << "\nSau khi xoá 30:\n";
    tree.print();

    return 0;
}
