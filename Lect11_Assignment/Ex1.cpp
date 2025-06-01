#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

const long long INF = 1e18; //tranh tran so

//truy vet
void printPath(int startNode, int endNode, const std::vector<int>& parent, std::ofstream& outFile) {
    if (endNode == -1) { //ko co phat
        return;
    }
    std::vector<int> path;
    int currentNode = endNode;
    while (currentNode != -1) {
        path.push_back(currentNode + 1); 
        if (currentNode == startNode) break; // quay lai start 
        currentNode = parent[currentNode];
        if (path.size() > parent.size() && currentNode != startNode) { //lap vo han
            outFile << "No path or error in path reconstruction." << std::endl;
            return;
        }
    }
    std::reverse(path.begin(), path.end());
    for (size_t i = 0; i < path.size(); ++i) {
        outFile << path[i] << (i == path.size() - 1 ? "" : " ");
    }
    outFile << std::endl;
}


int main() {
    std::ifstream inFile("dirty.txt");
    std::ofstream outFile("dirty_out.txt");

    if (!inFile.is_open()) {
        std::cerr << "Error opening input file dirty.txt" << std::endl;
        return 1;
    }
    if (!outFile.is_open()) {
        std::cerr << "Error opening output file dirty.out" << std::endl;
        return 1;
    }

    int n, m, s, e;
    inFile >> n >> m >> s >> e;

    // Chuyển đổi s và e sang 0-based indexing
    s--;
    e--;

    struct Edge {
        int u, v, weight;
    };
    std::vector<Edge> edges;

    // Ma trận khoảng cách,  khởi tạo với INF
    std::vector<std::vector<long long>> dist_fw(n, std::vector<long long>(n, INF));

    for (int i = 0; i < n; ++i) {
        dist_fw[i][i] = 0; 
    }

    for (int i = 0; i < m; ++i) {
        int u, v, d;
        inFile >> u >> v >> d;
       
        u--;
        v--;
        edges.push_back({u, v, d});
        // Cập nhật ma trận cho 
        // Nếu có nhiều cạnh giữa u và v, chon canh trong so nho nhat
        dist_fw[u][v] = std::min(dist_fw[u][v], (long long)d);
    }

    // --- Phần a: Bellman-Ford để tìm đường đi ngắn nhất từ s đến e ---
    std::vector<long long> dist_bf(n, INF);
    std::vector<int> parent(n, -1); // -1 nghĩa là không có cha hoặc chưa được khám phá
    dist_bf[s] = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (const auto& edge : edges) {
            if (dist_bf[edge.u] != INF && dist_bf[edge.u] + edge.weight < dist_bf[edge.v]) {
                dist_bf[edge.v] = dist_bf[edge.u] + edge.weight;
                parent[edge.v] = edge.u;
            }
        }
    }

  
    // Nếu sau n-1 lần lặp, vẫn có thể tối ưu hóa, thì có chu trình âm.

 
    if (dist_bf[e] == INF) {
        outFile << "INF" << std::endl;
        outFile << "No path" << std::endl; 
    } else {
        outFile << dist_bf[e] << std::endl;
        printPath(s, e, parent, outFile);
    }

   
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist_fw[i][k] != INF && dist_fw[k][j] != INF) { 
                    if (dist_fw[i][k] + dist_fw[k][j] < dist_fw[i][j]) {
                        dist_fw[i][j] = dist_fw[i][k] + dist_fw[k][j];
                    }
                }
            }
        }
    }

 
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist_fw[i][j] == INF) {
                outFile << "INF";
            } else {
                outFile << dist_fw[i][j];
            }
            if (j < n - 1) {
                outFile << " ";
            }
        }
        outFile << std::endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}