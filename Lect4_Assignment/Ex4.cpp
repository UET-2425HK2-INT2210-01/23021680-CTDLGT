#include <iostream>
using namespace std;

const int Table_size = 100;

struct Student {
    int ID;
    string Name;
    string Class;


    Student() : ID(0), Name(""), Class("") {}

    Student(int _ID, string _Name, string _Class) {
        ID = _ID;
        Name = _Name;
        Class = _Class;
    }
};

struct Node {
    Student data;
    Node * next;
    Node(Student s){
        data = s;
        next = nullptr;
    }
};

class hashTable {
    private:
    Node * table[Table_size];

    int hashFunction(int ID){
    return ID % Table_size;
    }

    public:
    hashTable() {
        for(int i =0; i < Table_size; i++) {
            table[i] = nullptr;
        }
    }

    void insert(Student s) {
        int i = hashFunction(s.ID);
        Node * newNode = new Node(s);
        newNode->next = table[i];
        table[i] = newNode;
    }

    void remove(int ID) {
        int i = hashFunction(ID);
        Node* curr = table[i];
        Node* prev = nullptr;

        while(curr) {
            if(curr->data.ID == ID) {
                if (prev) {
                    prev->next = curr->next;
                } else {
                    table[i] = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
            curr = curr->next;
        }
    }

    void infor(int ID) {
        int index = hashFunction(ID);
        Node* curr = table[index];
        
        while (curr) {
            if (curr->data.ID == ID) {
                cout << curr->data.Name << "," << curr->data.Class << endl;
                return;
            }
            curr = curr->next;
        }
        cout << "NA,NA" << endl;
    
    }
};

int main() {
    hashTable students;
    Student s1(1, "Tuan", "K61CS");
    Student s2(2, "Tuan", "K43C");
    students.insert(s1);
    students.insert(s2);
    students.infor(1);
    students.remove(1);
    students.infor(1);
    

  

}