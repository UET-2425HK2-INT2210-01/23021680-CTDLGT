#include <iostream>
using namespace std;

struct Node {
    int value, priority;
    Node* next;
    Node* prev;

    Node(int _value, int _priority, Node* _next = nullptr, Node* _prev = nullptr) {
        value = _value;
        priority = _priority;
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

    void insert(int x, int p) {
        Node* newNode = new Node(x, p);
        
     
        if (head == nullptr || p < head->priority) {
            newNode->next = head;
            if (head != nullptr) head->prev = newNode;
            head = newNode;
            if (tail == nullptr) tail = newNode;
        } 
        else {
           
            Node* temp = head;
            while (temp->next != nullptr && temp->next->priority <= p) {
                temp = temp->next;
            }

            // Chèn sau temp
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr) temp->next->prev = newNode;
            temp->next = newNode;

            if (newNode->next == nullptr) tail = newNode;
        }
        length++;
    }

    void removeFirst() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) head->prev = nullptr;
        else tail = nullptr;  
        delete temp;
        length--;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->value << ", " << temp->priority << ")";
            if (temp->next != nullptr) cout << "; ";
            temp = temp->next;
        }
        cout << endl;
    }
};


class pQueue {
private:
    LinkedList list;

public:
    void enqueue(int x, int p) {
        list.insert(x, p);
    }

    void dequeue() {
        list.removeFirst();
    }

    void printQueue() {
        list.print();
    }
};

int main() {
    int n;
    cin >> n;

    pQueue pq;
    
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "enqueue") {
            int x, p;
            cin >> x >> p;
            pq.enqueue(x, p);
        } else if (command == "dequeue") {
            pq.dequeue();
        }
    }

    pq.printQueue();
    return 0;
}
