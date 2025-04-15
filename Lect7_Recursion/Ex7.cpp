#include <iostream>

using namespace std;

int reverseNum(int n, int rev){
    if(n == 0) return rev;
    return reverseNum(n/10, rev * 10 + n % 10); //  phan rev la lan luot add so o hang don vi vao
}

int reverse(int n) {
    return reverseNum(n, 0);
}


int main() {
    int n;
    cin >> n;
    cout << reverse(n);
    return 0;
}