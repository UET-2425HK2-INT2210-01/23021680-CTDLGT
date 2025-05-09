// subset sum problem, dynamic programming

#include <iostream>
#include <vector>

using namespace std;
bool has_subset(int n, int x, vector<int> & a) {
    vector<bool> dp(x+1, false); // kiem tra tu 0-> x nen co x+1 phan tu
    dp[0] = true;

    for (int i = 0; i < n; i++) { // lap tung phan tu trong mang, a[i] se xem xet co tao ra nhung tong nao moi khong
        for (int j = x; j >= a[i]; j--) { // cap nhat tu sau -> dau // backtracking
            if(dp[j - a[i]]) {
                dp[j] = true;
            }
        }
    }

    return dp[x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);     

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    cout << (has_subset(n, x, a) ? "YES" : "NO") << endl;
    return 0;
}

