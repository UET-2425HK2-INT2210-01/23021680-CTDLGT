#include <iostream>
using namespace std;

struct Node {
    int value;
    Node * next;

    Node() {
        value = 0;
        next = nullptr;

    }

    Node(int _value, Node * _next) {
        value = _value;
        next = _next;
    }
};

class LinkedList {
    private:
    Node * head;
    int size;

    public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    void append(int value){
        if( head == nullptr) {
            Node* newNode = new Node(value, nullptr);
            head = newNode;
            size++;
            return;
        }

        Node * temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        Node* newNode = new Node(value, nullptr);
        temp -> next = newNode;
        size++;
        return;
    }

    void search(int x) {
        Node * temp = head;
        int cnt = 0;
        while( temp->next != nullptr) {
            cnt++;
            if(temp->value == x) {
                cout << cnt;
                return;
            }
            temp = temp -> next;
        }
        cout << "NO";
        return;
    }

    void reverse(){
        Node * curr = head;
        Node * prev = nullptr;
        Node * tNext;

        while (curr != nullptr) {
              tNext = curr->next;
              curr->next = prev;
               prev = curr;
               curr = tNext;
        }
        head = prev;
        return;
    }

    void print(){
        Node * temp = head;
        while(temp != nullptr) {
            cout << temp -> value << " ";
            temp = temp->next;
        }
        return;
    }

};

int main() {
    LinkedList list;
    list.append(8);
    list.append(5);
    list.append(7);
    list.append(1);
    list.append(0);
    list.print();
    cout << endl;
    list.search(1);

    cout << endl;

    list.reverse();
    list.print();
    return 0;

}

    

