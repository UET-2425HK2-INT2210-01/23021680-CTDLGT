#include <iostream>

using namespace std;

void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

//lay end lam pivot
int partition(int a[], int lo, int hi){
    int pivot = a[hi];
    int i = lo - 1;

    for(int j = lo; j <= hi - 1; j++) {
        if(a[j] <= pivot) {
            i++; // increase
            swap(a[j], a[i]);
            }
        }
        i++ ;
        swap(a[i], a[hi]);
        return i; // swap cap cuoi
    }



void quicksortHelper(int a[], int lo, int hi ){
    if(hi <= lo) return;

    int pivot = partition(a, lo, hi);
    quicksortHelper(a, lo, pivot - 1); // khong tinh pivot o mang trai
    quicksortHelper(a, pivot + 1, hi);// khong tinh pivot o mang phai
}

void quicksort(int a[], int n) {
    quicksortHelper(a, 0, n- 1);
}




int main(){
    int n;
    cin >> n;
    int *a = new int[n]; 
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    quicksort(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    delete[] a;
    return 0; 

}