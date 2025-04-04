#include <iostream>
#include <vector>
using namespace std;

class maxHeap{
    private:
    vector<int> maxHeap;

    int parent(int i) {
        return (int) (i-1)/2;
    }

    int leftChild(int i) {
        return (int)int(2*i+1);
    }

    int rightChild(int i){
        return (int)int(2*i+2);
    }

    int 

    public:



};


