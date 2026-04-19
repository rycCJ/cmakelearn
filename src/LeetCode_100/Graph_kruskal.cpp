#include <algorithm>
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


/*--------------AI给的kruskal算法模板-----------------

// 并查集结构
struct DSU {
    vector<int> parent;
    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]); // 路径压缩
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }
};

void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); // 1. 排序所有边
    DSU dsu(n);
    int mst_weight = 0;
    int edges_count = 0;

    cout << "Kruskal 选中的边：" << endl;
    for (auto& e : edges) {
        // 2. 如果 u 和 v 不连通，则选这条边
        if (dsu.find(e.u) != dsu.find(e.v)) {
            dsu.unite(e.u, e.v);
            mst_weight += e.w;
            edges_count++;
            cout << e.u << " - " << e.v << " (权值: " << e.w << ")" << endl;
        }
    }

    if (edges_count < n - 1) cout << "图不连通，无法生成树" << endl;
    else cout << "最小生成树总权重: " << mst_weight << endl;
}
    */
// 并查集结构
//1.将两个元素添加到同一个集合
//2.判断两个元素是否在同一个集合
struct DSU {
    vector<int> father;
    DSU(int n){
        father.resize(n+1);
        for(int i = 1;i<=n;i++){
            father[i] = i;
        }
    }
    int find(int x){
        if(father[x] == x) return x;
        father[x] = find(father[x]);
        return father[x];
        }
    void join(int a,int b){
        a = find(a);
        b = find(b);
        if(a == b) return;    
        father[a] = b;
    }
    bool issame(int a,int b){
        a = find(a);
        b = find(b);
        return a == b;
    }
    };

void kruskal(int n, vector<Edge>& edges) {
    DSU dsu(n);
    int weight_sum = 0;
    //排序
    sort(edges.begin(),edges.end());
    //遍历所有边
    for(auto e:edges){
        if(dsu.issame(e.u,e.v)) continue;
        dsu.join(e.u,e.v);
        cout<<"加入边: "<<e.u<<" - "<<e.v<<" 权重: "<<e.w<<endl;
        weight_sum+=e.w;
    }
    cout <<"最小生成树总权重: "<<weight_sum<<endl;
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

    cout << "--- Kruskal 运行 ---" << endl;
    kruskal(n, edgeList);

    return 0;

}