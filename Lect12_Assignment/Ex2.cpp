#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
    bool operator<(const Edge &other) const {
        return w < other.w; // sắp theo trọng số tăng dần
    }
};

int findRoot(int u, vector<int> &parent) {
    if (u != parent[u])
        parent[u] = findRoot(parent[u], parent);
    return parent[u];
}

bool unionSets(int u, int v, vector<int> &parent, vector<int> &rank) {
    int rootU = findRoot(u, parent);
    int rootV = findRoot(v, parent);
    if (rootU == rootV) return false;
    if (rank[rootU] < rank[rootV]) parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV]) parent[rootV] = rootU;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
    return true;
}

int main() {
    ifstream fin("connection.txt");
    ofstream fout("connection.out");

    int n, m;
    fin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
        fin >> edges[i].u >> edges[i].v >> edges[i].w;

    sort(edges.begin(), edges.end());

    vector<int> parent(n + 1), rank(n + 1, 0);
    for (int i = 1; i <= n; ++i) parent[i] = i;

    int totalCost = 0;
    vector<Edge> mst;

    for (Edge e : edges) {
        if (unionSets(e.u, e.v, parent, rank)) {
            totalCost += e.w;
            mst.push_back(e);
        }
    }

    fout << totalCost << "\n";
    for (Edge e : mst)
        fout << e.u << " " << e.v << " " << e.w << "\n";

    fin.close();
    fout.close();
    return 0;
}
