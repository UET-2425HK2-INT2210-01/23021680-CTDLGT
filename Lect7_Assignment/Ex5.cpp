#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<int> &a, int start, int n) {
    if(start == n) {
        for(int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
        return;

    }

    for(int i = start; i < n; i++) {
            swap(a[start], a[i]);
            permutation(a, start + 1, n);
            swap(a[start], a[i]); // Backtrack
    }
    
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    permutation(a, 0, n);
    return 0;

    

}