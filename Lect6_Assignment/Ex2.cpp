#include <iostream>
#include <vector>
#include <algorithm>
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

    void heapifyUp(int i) {
        while (i > 0 && maxHeap[i] > maxHeap[parent(i)]) {
            swap(maxHeap[i], maxHeap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < maxHeap.size() && maxHeap[left] > maxHeap[largest])
            largest = left;
        if (right < maxHeap.size() && maxHeap[right] > maxHeap[largest])
            largest = right;

        if (largest != i) {
            swap(maxHeap[i], maxHeap[largest]);
            heapifyDown(largest);
        }
    }

    int findIndex(int val) {
        for (int i = 0; i < maxHeap.size(); i++) {
            if (maxHeap[i] == val) return i;
        }
        return -1;
    }

    public:
        void insert(int v) {
            maxHeap.push_back(v);
            heapifyUp(maxHeap.size() - 1);
        }

        void deleteVal(int v) {
            int index = findIndex(v);
        
            maxHeap[index] = maxHeap.back();
            maxHeap.pop_back();
        
            if (index < maxHeap.size()) {
                heapifyDown(index);
                heapifyUp(index);
            }
        }

        void printHeap(){
            for (int i = 0; i < maxHeap.size(); i++) {
                cout << maxHeap[i] << " ";
            }
            cout << endl;
            }
        
};

int main(){
    freopen("input.txt", "r", stdin);   
    freopen("output.txt", "w", stdout);

    maxHeap mh;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int m;
        cin >> m;
        mh.insert(m);
    }

    mh.printHeap();

}


