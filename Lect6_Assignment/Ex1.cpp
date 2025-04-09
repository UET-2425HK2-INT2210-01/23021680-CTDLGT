#include <iostream>
using namespace std;

struct Node{
    int val;
    Node * left;
    Node * right;

    Node(){}

    Node(int _val) {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    Node(int _val, Node * _left, Node * _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};




class BST{
    private:
    
    Node * root = nullptr;

    void inOrderTraverse(Node * node) {
        if (node == nullptr) return;
        inOrderTraverse(node -> left);
        cout << node -> val << " ";
        inOrderTraverse(node ->right);
    }

    void preOrderTraverse(Node * node) {
        if (node == nullptr) return;
        cout << node -> val << " ";
        preOrderTraverse(node -> left);
        preOrderTraverse(node ->right);
    }

    void postOrderTraverse(Node * node) {
        if (node == nullptr) return;
        postOrderTraverse(node -> left);
        postOrderTraverse(node ->right);
        cout << node -> val << " ";
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

    Node * deleteNode(Node * node, int val) {
        if(!node) return nullptr;

        if(val > node -> val) node -> right = deleteNode(node-> right, val);
        
        else if(val < node -> val) node -> left = deleteNode(node-> left, val);
        
        else {
            if(!node -> left) {
                Node * temp = node -> right;
                delete node;
                return temp;
            }

            if(!node -> right) {
                Node * temp = node -> left;
                delete node;
                return temp;
            }

            Node * succ = node -> right;
            while(succ -> left) {
                succ = succ -> left;
            }

            node -> val = succ -> val;

            node->right = deleteNode(node->right, succ->val);
        }
        return node;



    }
    

    public:
    
    void insert(int val) {
        if(!root) {
            root = new Node(val);
            return;
        }
    
        Node * temp = root;
        while(true) {
            if(val < temp->val) {
                if(temp->left == nullptr) {
                    temp->left = new Node(val);
                    return;
                }
                temp = temp->left;
            } else if(val > temp->val) {
                if(temp->right == nullptr) {
                    temp->right = new Node(val);
                    return;
                }
                temp = temp->right;
            } else {
                
                return;
            }
        }
    }
    

    bool search(int val){
        Node * temp = root;
        while(temp != nullptr) {
        if(val == temp->val) return true;
        if(val < temp->val) temp = temp->left;
        else temp = temp->right;
    }
    return false;
    }

    int findMax(){
        if(!root) return -1000;
        Node* temp = root;
    while (temp->right != nullptr) {
        temp = temp->right;
    }
    return temp->val;
    }

    int findMin(){
        if(!root) return -1000;
        Node* temp = root;
        while (temp->left != nullptr) {
        temp = temp->left;
    }
        return temp->val;
    }

    void inOrder() {
        inOrderTraverse(root);
        cout << " ";
    }

    void preOrder() {
        preOrderTraverse(root);
        cout << " ";
    }

    void postOrder() {
        postOrderTraverse(root);
        cout << " ";
    }

    void deleteVal(int val) {
        root = deleteNode(root, val);
    }

    void print() {
        printTree(root);
    }
};

int main(int argc,char *argv[]) {
   BST tree;
   tree.insert(2);
   tree.insert(4);
   tree.insert(10);
   tree.insert(9);
   tree.insert(7);
   tree.insert(65);
   tree.insert(34);
   tree.insert(52);
   tree.insert(1);
   tree.insert(-5);

   tree.insert(13);
   tree.deleteVal(9);
   tree.deleteVal(7);
   tree.deleteVal(-1);
   tree.print();


//    tree.print();
//    cout << endl;
//    tree.preOrder();
//    cout << endl;
//    tree.inOrder();
//    cout << endl;
//    tree.postOrder();
//    cout << endl;
//    cout << tree.findMax(); cout << endl;
//    cout << tree.findMin();
//    cout << endl;

  
}