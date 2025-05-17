#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> Distance;

int bfs(int start, int end, int n) {
    queue<int> q;
    q.push(start);
    Distance[start] = 0; // khoang cach

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (Distance[neighbor] == -1) { // Neu chua duoc check qua 
                Distance[neighbor] = Distance[node] + 1; // dam ao dang tim canh ngan nhat
                q.push(neighbor); // push va o queue

                if (neighbor == end) {
                    return Distance[neighbor]; // tim thay
                }
            }
        }
    }

    return -1; // Khong tim thay
}

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    adj.resize(n + 1);
    Distance.resize(n + 1, -1);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }

    cout << bfs(X, Y, n) << endl;
    return 0;
}
