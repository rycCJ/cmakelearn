
#include <iostream>
#include <vector>
#include <queue>
/*-------------邻接矩阵 (Adjacency Matrix)--------------*/
/*
优点：查询两个顶点间是否有边非常快，时间复杂度 O(1)。
缺点：当图是稀疏图（顶点多，边少）时，非常浪费空间。空间复杂度 O(V²)。
*/
/*


int main() {
    // 5个顶点 (0, 1, 2, 3, 4)
    int numVertices = 5;

    // 初始化一个 5x5 的矩阵，所有值都是0
    // std::vector<std::vector<int>> graphMatrix(行数, std::vector<int>(列数,
初始值)); std::vector<std::vector<int>> graphMatrix(numVertices,
std::vector<int>(numVertices, 0));

    // 添加边
    // 对于无向图，如果(u, v)有边，那么 matrix[u][v] 和 matrix[v][u] 都为1
    graphMatrix[0][1] = 1; graphMatrix[1][0] = 1;
    graphMatrix[0][2] = 1; graphMatrix[2][0] = 1;
    graphMatrix[0][3] = 1; graphMatrix[3][0] = 1;
    graphMatrix[1][4] = 1; graphMatrix[4][1] = 1;
    graphMatrix[2][3] = 1; graphMatrix[3][2] = 1;

    // 打印邻接矩阵
    std::cout << "--- Adjacency Matrix ---" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << graphMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

*/

/*---------------邻接表 (Adjacency List)------------------*/
/*
优点：节省空间，空间复杂度为 O(V+E)，其中 V 是顶点数，E
是边数。获取一个顶点的所有邻居非常方便。 缺点：查询两个顶点 u, v
之间是否有边，需要遍历 u 的邻接表，时间复杂度为 O(degree(u))，最坏为 O(V)。
*/


// 辅助函数，用于添加边
void addEdge(std::vector<std::vector<int>>& adjList, int u, int v) {
    // 无向图，需要在两个顶点的邻接表中都添加对方
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}
/*
int main() {
    // 5个顶点
    int numVertices = 5;

    // 创建一个邻接表。它是一个vector，每个元素是另一个int型的vector。
    // adjList 的大小为 numVertices，代表有 numVertices 个顶点
    std::vector<std::vector<int>> adjList(numVertices);

    // 添加边
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);

    // 打印邻接表
    std::cout << "--- Adjacency List ---" << std::endl;
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ":";
        for (int neighbor : adjList[i]) { // 使用范围for循环遍历邻居
            std::cout << " -> " << neighbor;
        }
        std::cout << std::endl;
    }

    return 0;
}
*/
// BFS 函数
void bfs(const std::vector<std::vector<int>>& graph, int startNode) {
    int numVertices = graph.size();
    if (startNode >= numVertices) {
        std::cout << "Start node does not exist!" << std::endl;
        return;
    }

    // 1. visited 数组，记录访问过的节点
    std::vector<bool> visited(numVertices, false);

    // 2. 创建队列
    std::queue<int> q;

    // 3. 将起始节点入队，并标记为已访问
    q.push(startNode);
    visited[startNode] = true;

    // 4. 当队列不为空时循环
    while (!q.empty()) {
        // 从队首取出一个节点
        int currentNode = q.front();
        q.pop();

        std::cout << "Visiting: " << currentNode << std::endl;

        // 遍历该节点的所有邻居
        for (int neighbor : graph[currentNode]) {
            // 如果邻居没有被访问过
            if (!visited[neighbor]) {
                // 标记为已访问并入队
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

/*----------DFS 辅助函数 (递归)--------------*/
// 注意：visited 数组必须通过引用(&)传递，否则每次递归调用都会复制一份，状态无法共享
void dfsUtil(const std::vector<std::vector<int>>& graph, int currentNode, std::vector<bool>& visited) {
    // 标记当前节点为已访问
    visited[currentNode] = true;
    std::cout << "Visiting: " << currentNode << std::endl;

    // 遍历该节点的所有邻居
    for (int neighbor : graph[currentNode]) {
        // 如果邻居没有被访问过，则递归调用
        if (!visited[neighbor]) {
            dfsUtil(graph, neighbor, visited);
        }
    }
}

// DFS 主函数，用于初始化
void dfs(const std::vector<std::vector<int>>& graph, int startNode) {
    int numVertices = graph.size();
    if (startNode >= numVertices) {
        std::cout << "Start node does not exist!" << std::endl;
        return;
    }

    // 创建 visited 数组
    std::vector<bool> visited(numVertices, false);

    // 调用递归辅助函数
    dfsUtil(graph, startNode, visited);
}

int main() {
    // 5个顶点
    int numVertices = 5;

    // 创建一个邻接表。它是一个vector，每个元素是另一个int型的vector。
    // adjList 的大小为 numVertices，代表有 numVertices 个顶点
    std::vector<std::vector<int>> adjList(numVertices);

    // 添加边
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 2, 3);

    std::cout << "--- DFS Traversal ---" << std::endl;
    dfs(adjList, 0);
}