#include <iostream>
using namespace std;

int digits(int n) {
    if(n == 0) return 0;
    return 1 + digits(n/10); // lan luot chia cho 10 de loc ra cac chu so hang don vi roi cong de quy
}

int main() {
   int n;
   cin >> n;
   cout << digits(n);
   return 0; 
}