#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> check;

void dfs(int node){
    check[node] = true;
    for (int i = 0; i < adj[node].size(); i++) { // check neighbor cua node do
        int neighbor = adj[node][i];
        if (!check[neighbor]) {
        //dfs de quy node neighbor
        dfs(neighbor);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    check.resize(n + 1, false);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }


    int connectedComponents = 0;
    
    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            dfs(i);
            connectedComponents++;
        }
    }

    cout << connectedComponents << endl;
    return 0;
}

