#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int _data, Node* _next){
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

    void insertBeginning(int value){
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

    void insertEnd(int value){
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

    void insert(int position, int value){
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




int main() {
    int n;
    cin >> n;

    LinkedList list;

    while( n-- ){
        string command;
        cin >> command;

        if(command =="insert") {
            int p, v;
            cin >> p >> v;
            list.insert(p,v);
        }

        else if(command == "delete") {
            int p;
            cin >> p ;
            list.deleteAt(p);
        }
        
    }


    list.print();
    return 0;


}