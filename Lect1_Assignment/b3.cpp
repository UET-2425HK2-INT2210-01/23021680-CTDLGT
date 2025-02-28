#include <iostream>
using namespace std;

int UCLN(int a, int b) {
    if(a == 0 || b == 0) {
        return a+b;
    }

    int min;
    if(a < b) min = a;
    else min = b;

    for(int i = min; i > 0; i--) {
        if(a % i ==0 && b % i ==0) {
            return i;
        }
    }

    return 1;

}

int main (){
    int a, b;
    cin >> a >>  b;
    cout << UCLN(a, b);
    return 0;
}