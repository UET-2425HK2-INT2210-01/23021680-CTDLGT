#include <iostream>
using namespace std;

int sumOfDigits(int n) {
    if(n == 0) return 0;
    int sum = 0;
    return (n % 10) + sumOfDigits(n / 10); /* n % 10 la chu so hang don vi duoc loc ra,
     n/10 la key qua chia cho den  khi bang 0 */
    
}

int main() {
   int n;
   cin >> n;
   cout << sumOfDigits(n);
   return 0; 
}