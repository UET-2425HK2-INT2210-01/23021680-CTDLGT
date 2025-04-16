#include <iostream>
#include <vector>

using namespace std;

void binaryList(int n, string s) {
    if (s.length() == n) {
        cout << s << endl;
        return;
    }

    binaryList(n,  s + "0");
    binaryList(n,  s + "1");
}


int main() {
    int n; 
    cin >> n;
    binaryList(n, "");
    return 0;
}