#include <iostream>
using namespace std;

int main (){
   int n;
   cin >> n;
   int a[n];
   
   for(int i = 0; i < n; i++) {
    cin >> a[i];
   }

   for(int i = 0; i < n - 1; i++) {
        int min = a[i];;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[i]) {
                swap(a[i], a[j]);
            }
        }
   }

   for(int i = 0; i < n; i++) {
    cout << a[i] <<" ";
   }
   return 0;
}