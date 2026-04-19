
#include <vector>
#include <queue>
#include <climits>
#include <iostream>

using namespace std;

// 定义：{距离, 顶点编号}
typedef pair<int, int> PII;
// 边的结构体
struct Edge {
    int u, v, w;
    // 排序规则：按权值从小到大
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};
void prim(int n, const vector<vector<PII>>& adj) {
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<bool> visited(n + 1, false);
    int mst_weight = 0;
    int count = 0;

    // 从 1 号点开始
    pq.push({0, 1});

    cout << "Prim 遍历过程：" << endl;
    while (!pq.empty() && count < n) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        mst_weight += w;
        count++;
        if (w > 0) cout << "加入顶点 " << u << "，边权: " << w << endl;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!visited[v]) {
                pq.push({weight, v});
            }
        }
    }

    if (count < n) cout << "图不连通" << endl;
    else cout << "最小生成树总权重: " << mst_weight << endl;
}

void prim2(int n, const vector<vector<PII>>& adj) {
    priority_queue<PII,vector<PII>,greater<PII>> pq;
    vector<bool> visited(n+1,false);
    pq.push({0,1});
    int count = 0;
    while(!pq.empty() && count<n){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(visited[node]) continue;//如果相邻的都已经看过了，就不用再操作，因为不能再加，再加就成了连接图
        visited[node] = true;
        cout<< "加入顶点 " << node << "，边权: " << d << endl;   
 
        count++;
 
        for(auto & edge:adj[node]){
            int v = edge.first;
            int weight = edge.second;
            if(!visited[v]){
                pq.push({weight,v});
               } 
       }       
    }
}

int main() {

    int n = 4, m = 5;
     // Kruskal 使用边列表
    vector<Edge> edgeList = {
        {1, 2, 10}, {1, 3, 6}, {1, 4, 5}, {2, 4, 15}, {3, 4, 4}
    };

    // Prim 使用邻接表
    vector<vector<PII>> adj(n + 1);
    for (auto& e : edgeList) {
        adj[e.u].push_back({e.v, e.w});
        adj[e.v].push_back({e.u, e.w});
    }
    cout << "\n--- Prim 运行 ---" << endl;
    prim2(n, adj);
    // cout << "--- Kruskal 运行 ---" << endl;
    // kruskal(n, edgeList);

    return 0;

}