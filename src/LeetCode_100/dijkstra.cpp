#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

// 定义：{距离, 顶点编号}
typedef pair<int, int> PII;

vector<int> dijkstra(int n, int start, const vector<vector<pair<int, int>>>& adj) {
    // 1. 初始化距离数组，全部设为无穷大
    vector<int> dist(n + 1, INT_MAX);
    dist[start] = 0;

    // 2. 定义优先队列（小根堆）：距离小的排在前面
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;    // 当前已知到 u 的最短距离
        int u = pq.top().second;   // 当前顶点
        pq.pop();

        // 如果弹出的距离已经大于记录的距离，说明是过时的信息，直接跳过
        if (d > dist[u]) continue;

        // 3. 遍历 u 的所有邻居 v
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            // 4. 松弛操作：如果通过 u 到达 v 的距离更短
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist; // 返回从 start 到所有点的最短距离
}
int main() {
    // 示例图：5个顶点，边权如下
    int n = 5;
    vector<vector<pair<int, int>>> adj(n + 1);
    adj[1].push_back({2, 10});
    adj[1].push_back({3, 5});
    adj[2].push_back({3, 2});
    adj[2].push_back({4, 1});
    adj[3].push_back({2, 3});
    adj[3].push_back({4, 9});
    adj[3].push_back({5, 2});
    adj[4].push_back({5, 4});
    adj[5].push_back({4, 6});

    int start = 1;
    vector<int> shortestDistances = dijkstra(n, start, adj);

    // 输出从 start 到每个顶点的最短距离
    for (int i = 1; i <= n; ++i) {
        if (shortestDistances[i] == INT_MAX) {
            std::cout << "Distance from " << start << " to " << i << ": INF" << std::endl;
        } else {
            std::cout << "Distance from " << start << " to " << i << ": " << shortestDistances[i] << std::endl;
        }
    }


    return 0;
}