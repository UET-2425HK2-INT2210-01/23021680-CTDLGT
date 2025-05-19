#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ifstream fin("jobs.txt");
    ofstream fout("jobs.out");

    int n, m;
    fin >> n >> m;

    vector<vector<int>> adj(n + 1); // Danh sách kề
    vector<int> indegree(n + 1, 0); // Bậc vào

    // Đọc các yêu cầu thứ tự
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    // Đưa các công việc không phụ thuộc vào hàng đợi
    for (int i = 1; i <= n; ++i)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> result;
    // Thuật toán sắp xếp tôpô
    while (!q.empty()) {
        int u = q.front(); q.pop();
        result.push_back(u);
        for (int v : adj[u]) {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }

    // Ghi kết quả ra file
    for (int job : result)
        fout << job << " ";

    fin.close();
    fout.close();
    return 0;
}
