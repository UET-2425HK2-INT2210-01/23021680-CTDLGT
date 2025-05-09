#include <iostream>

using namespace std;

// Hàm hoán đổi giá trị của hai biến
void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(int a[], int lo, int hi){
    int pivot = a[lo]; // Chọn phần tử đầu tiên làm pivot
    int i = lo - 1; // truoc index lowest (min)
    int j = hi + 1; // sau index max

    //i va j di chuyen nguoc lai di gan voi nhau hon
    while (true) {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i >= j)
            return j;

        swap(a[i], a[j]);
    }
}

void quicksortHelper(int a[], int lo, int hi ){
    if(hi <= lo) return;

    //phan vung
    int pivot = partition(a, lo, hi);

    //de quy 2 mang trai phai
    quicksortHelper(a, lo, pivot);
    quicksortHelper(a, pivot + 1, hi);
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
