#include <iostream>
#include <cstring>
using namespace std;
const int NODES_SIZE = 1000;

struct treeNode{
    int data;
    treeNode * firstChild; // Node goc
    treeNode * sibling;  //Anh chi em

    //constructor
    treeNode(int _data, treeNode * _firstChild, treeNode * _sibling) {
        data = _data;
        firstChild = _firstChild;
        sibling = _sibling; 
    }

    treeNode(int _data) {
        data = _data;
        firstChild = nullptr;
        sibling = nullptr;

    }

};

class Tree {
    private: 
    treeNode * root; // Node goc (lam moc)
    treeNode * nodeList[NODES_SIZE]; // Mang luu cac Node
    bool isChild[NODES_SIZE];  // Dung de find root

    public:
    Tree() {
        root = nullptr;
        for (int i = 0; i < NODES_SIZE; i++) isChild[i] = false;// tat ca phan tu la null
        for (int i = 0; i < NODES_SIZE; i++) nodeList[i] = nullptr; // tat ca phan tu la false 
    }

    void addChild(int parent, int child) {
        if(parent == child) {
            cout << "Error";
            return;
        }
        //kiem tra xem 2 node input vao da ton tai hay chua
        if(!nodeList[parent]) nodeList[parent] = new treeNode(parent);
        if(!nodeList[child]) nodeList [child] = new treeNode(child);

        //Lay ra de xet
        treeNode * parentNode = nodeList[parent];
        treeNode * childNode = nodeList[child];

        //Bat dau them vao con ca va cac em

        //Neu con ca la null thi child chinh la con ca
        if(!parentNode -> firstChild) {
            parentNode->firstChild = childNode;
        } else { //Neu khong thi lan luot them vao cac em
            treeNode * temp = parentNode ->firstChild; // anh chi em lien ket qua sibling
            while(temp -> sibling != nullptr) {
                temp = temp -> sibling;
            }
            temp-> sibling = childNode;
        }
        isChild[child] = true;
    }

    void findRoot(int totalNodes) {
        for(int i = 1; i < totalNodes; i++) {
            if(!isChild[i] && nodeList[i]) {
            root = nodeList[i]; // Gán root cho cây
            return;
            } // Kiem tra trong mang isChild neu co ca gia tri trong nodeList
        }
        root = nullptr;
    }

    int getHeight(treeNode* root) {
        if (!root) return -1;  // chieu cao la -1 neu null
    
        int maxChildHeight = -1;
        treeNode* temp = root->firstChild; // bat dau tu cay con dau
    
        while (temp) { // Duyệt tất cả các con
            maxChildHeight = max(maxChildHeight, getHeight(temp));
            temp = temp->sibling; 
        }
    
        return maxChildHeight + 1; //root;
    }
         
    void preorder(treeNode * root ) {
        if(!root) return;
        cout << root-> data << " "; // print data first;
        treeNode * child = root -> firstChild;
        while(child) {
            preorder(child); // duyet con
            child = child -> sibling;// sang anh chi
        }
    }

    void postorder(treeNode *node) {
        if (!node) return;
    
        treeNode *child = node->firstChild;
        while (child) {
            postorder(child);        
            child = child->sibling; 
        }
    
        cout << node->data << " ";  // print data last;

    }

    bool isBinary(treeNode * root) {
        if (!root) return true;
        int childCount = 0;
        treeNode *child = root->firstChild;
        while (child) { // check child of input
            childCount++;
            if (childCount > 2) return false;
            child = child->sibling;
        }
        treeNode *sibling = root->firstChild;
        while (sibling) { // check sibling sau
            if (!isBinary(sibling)) return false;
            sibling = sibling->sibling;
        }
        return true;
    }

    void inorder(treeNode * root) {
        if (!root) return;
        if (!isBinary(root)) {
            cout << "NOT BINARY TREE";
            return;
        }
        treeNode *left = root->firstChild;
        treeNode *right = left ? left->sibling : nullptr;
        inorder(left);
        cout << root->data << " "; // print o giua 
        inorder(right);
    }

    void processTree(int N) {
        findRoot(N);
        if (!root) {
            cout << "No root found!\n";
            return;
        }
        cout << "Height: " << getHeight(root) << endl;
        cout << "Preorder: "; preorder(root); cout << endl;
        cout << "Postorder: "; postorder(root); cout << endl;
        cout << "Inorder: "; inorder(root); cout << endl;
    }
        
};

int main() {

    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    Tree t;
    for(int i = 0 ; i < m; i++) { // them vao canh
        int u, v;
        cin >> u >> v;
        t.addChild(u, v);


    }

    t.processTree(n);
    return 0;
    
    

}