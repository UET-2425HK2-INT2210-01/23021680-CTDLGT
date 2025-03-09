#include <iostream>

using namespace std;

struct Node{
    string data;
    Node* next;

    Node(char _data, Node* _next){
        data = _data;
        next = _next;
    }
    
};

class LinkedList {
    public:
    Node* head;
    int length = 0;

    LinkedList() { 
        head = nullptr;
        length = 0;
    }

    void insertBeginning(char value){
        if(head == nullptr) {
            Node* newNode = new Node(value, nullptr);
            head= newNode;
            length++;
            return;
        }
        
        Node* newNode = new Node(value, head);
        head = newNode;
        length++;
        return;
    }

    void insertEnd(char value){
        if( head == nullptr) {
            Node* newNode = new Node(value, nullptr);
            head = newNode;
            length++;
            return;
        }

        Node * temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        Node* newNode = new Node(value, nullptr);
        temp -> next = newNode;
        length++;
        return;
    }

    void insert(int position, char value){
        if(position < 0 || position > length) return;
        if(position == 0) {
            insertBeginning(value);
            return;
        } 
        if(position == length) {
            insertEnd(value);
            return;
        }

        Node* temp = head;
        for(int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node(value, temp->next);
        temp->next = newNode;
        length++;
    }

    void deleteBeginning(){
        if(head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    void deleteEnd(){
        if(head == nullptr) return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            length--;
            return;
        }
        Node* temp = head;
        while(temp->next->next != nullptr){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        length--;
    }

    void deleteAt(int position){
        if(position < 0 || position >= length) return;
        if(position == 0) {
            deleteBeginning();
            return;
        }
        if(position == length - 1) {
            deleteEnd();
            return;
        }
        Node* temp = head;
        for(int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        length--;
    }

    void print(){
        Node * temp = head;
        while(temp != nullptr) {
            cout << temp -> data << " ";
            temp = temp->next;
        }
        return;
    }
};

class Stack{
    LinkedList l;
    public:

    void pop() {
        l.deleteBeginning();
    }

    void push(char x) {
        l.insertBeginning(x);
    }

    void print() {
        printReversed(l.head); // do thu tu cua stack nguoc voi linked list.
        cout << endl;
    }

    string peek() {
        if (l.head == nullptr) return "";  
        return l.head->data;  
    }
    
    bool isEmpty() {
        if (l.head == nullptr) {
            return true;
        }

        return false;
    }

    void printReversed(Node * node) {
        if (node == nullptr) return;
        printReversed(node->next);
        cout << node->data << " ";
    }

    
};

int main() {
    Stack s;
    string in;
    cin >> in;
    for(int i = 0; i < in.length(); i++ ) {
        if(in[i] == '{' || in[i] == '(' || in[i] == '[') {
            s.push(in[i]);
        }

        if(in[i] == '}' || in[i] == ')' || in[i] == ']') {
            s.pop();
        }
    }

    if(s.isEmpty()) {
        cout <<  "Valid";
    } 
    else cout << "Invalid";

    return 0;


}