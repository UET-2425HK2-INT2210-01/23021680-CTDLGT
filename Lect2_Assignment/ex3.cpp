#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int _data, Node* _next = nullptr, Node* _prev = nullptr) {
        data = _data;
        next = _next;
        prev = _prev;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;
    int length;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    void insert(int x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;  
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;  
        }
        length++;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void countSum() {
        if (length < 3) {
            cout << 0 << endl;
            return;
        }

        int count = 0;
        Node* tmp = head->next;  

        while (tmp != nullptr && tmp->next != nullptr) {
            Node* tmp1 = tmp->prev;
            Node* tmp2 = tmp->next;
            if ((tmp->data + tmp1->data + tmp2->data) == 0) {
                count++;
            }
            tmp = tmp->next;
        }
        cout << count << endl;
    }
};

int main() {
    int n;
    cin >> n;
    LinkedList list;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        list.insert(x);
    }

    list.countSum();
    return 0;
}
