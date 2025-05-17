#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n, X; cin >> n >> X;
    int w[n+1], v[n+1]; // mang luu gia tri va khoi luong cua tung item
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
   


    int dp[n+1][X+1]; // tao bang 2 chieu , max value lay tu i vat dau tien voi 
    //tong khoi luong <= j
    memset(dp, 0, sizeof(dp));


    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= X; j++) { // duyet qua tung gioi han khoi luong tu 0 -> X
            // Gia su ko chon do vat thu i
            dp[i][j] = dp[i-1][j];
            //Co the dua vao trong tui
            if(j>= w[i]) {
                 // So sánh giữa không chọn và chọn để lấy giá trị lớn nhất
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]] + v[i]); 
            }
        }
    }

    cout << dp[n][X];
    return 0;
}