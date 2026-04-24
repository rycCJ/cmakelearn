#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>
/*200. 岛屿数量
LCR 105 岛屿面积最大
*/
class Solution {
public:
    
    const int dir[4][2] = {1,0,0,1,-1,0,0,-1};  //四行指的是四个方向，两列指的是对x,y加的数据。所以方向是：右，下，左，上

        // int numIslands(std::vector<std::vector<int>>& grid) {
        
    // }
    
    /**
     * 深度优先搜索函数，用于遍历二维网格
     * @param grid 二维网格，其中1表示陆地，0表示水域
     * @param visited 访问标记数组，记录哪些位置已经被访问过
     * @param x 当前位置的x坐标（行索引）
     * @param y 当前位置的y坐标（列索引）
     */
    //dfs的两种写法
    void dfs(std::vector<std::vector<int>>& grid,std::vector<std::vector<bool>> &visited,int x,int y){
            for(int i = 0;i < 4;i++){
                int nextx = x + dir[i][0];
                int nexty = y + dir[i][1];
                if(nextx<0||nextx>=grid.size()||nexty<0||nexty>=grid[0].size()) continue;//边界判断  grid[.size()指的是行数
                if(grid[nextx][nexty] == 1 && !visited[nextx][nexty]){     
                    visited[nextx][nexty] = true;
                    dfs(grid,visited,nextx,nexty);
                }
                continue;
            }
        }
    void dfs2(std::vector<std::vector<int>>& grid,std::vector<std::vector<bool>> &visited,int x,int y){
        if(grid[x][y] == 0 || visited[x][y]) return;
        visited[x][y] = true;
        for(int i = 0;i < 4;i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx<0||nextx>=grid.size()||nexty<0||nexty>=grid[0].size()) continue;//边界判断  grid[.size()指的是行数
            dfs2(grid,visited,nextx,nexty);
            }
}
    void bfs(std::vector<std::vector<int>>& grid,std::vector<std::vector<bool>> &visited,int x,int y){
        std::queue<std::pair<int,int>> q;
        q.push({x,y});
        visited[x][y] = true;
        while(!q.empty()){
            std::pair<int,int> cur = q.front();
            q.pop();
            int m = cur.first;
            int n = cur.second;
            for(int i = 0;i < 4;i++){
                int nextx = m+dir[i][0];
                int nexty = n+dir[i][1];
                if(nextx<0||nextx>=grid.size()||nexty<0||nexty>=grid[0].size()) continue;
                if(grid[nextx][nexty] == 1 && !visited[nextx][nexty]){
                    q.push({nextx,nexty});
                    visited[nextx][nexty] = true;  //入了队列并且访问过了
                }

            }
        }

    }
    /**
     * 岛屿面积最大问题：深度优先搜索函数第一种解法，用于遍历二维网格
     * @param grid 二维网格，其中1表示陆地，0表示水域
     * @param visited 访问标记数组，记录哪些位置已经被访问过
     * @param x 当前位置的x坐标（行索引）
     * @param y 当前位置的y坐标（列索引）
     * @param area 当前岛屿的面积
     */
    void area_dfs(std::vector<std::vector<int>>& grid,std::vector<std::vector<bool>>& visited,int x,int y,int &area){
        for(int i = 0; i<4;i++){
            int nextx = x+dir[i][0];
            int nexty = y+dir[i][1];
            if(nextx<0 || nexty<0 || nextx>=grid.size() || nexty>=grid[0].size()) continue;
            if(visited[nextx][nexty] || grid[nextx][nexty] == 0) continue;
            area++;
            visited[nextx][nexty] = true;
            area_dfs(grid,visited,nextx,nexty,area);
        }

    }
    
        /**
     * 岛屿面积最大问题：深度优先搜索函数第二种解法，用于遍历二维网格
     * @param grid 二维网格，其中1表示陆地，0表示水域
     * @param visited 访问标记数组，记录哪些位置已经被访问过
     * @param x 当前位置的x坐标（行索引）
     * @param y 当前位置的y坐标（列索引）
     * @param area 当前岛屿的面积
     */
    void area_dfs2(std::vector<std::vector<int>>& grid,std::vector<std::vector<bool>> &visited,int x,int y,int &area){
        if(grid[x][y] == 0 || visited[x][y]) return;
        area++;
        visited[x][y] = true;
        for(int i = 0;i < 4;i++){
            int nextx = x + dir[i][0];
            int nexty = y + dir[i][1];
            if(nextx<0||nextx>=grid.size()||nexty<0||nexty>=grid[0].size()) continue;//边界判断  grid[.size()指的是行数
            area_dfs2(grid,visited,nextx,nexty,area);
            }
    }

};
int main(){
    
    std::vector<std::vector<bool>> visited(4,std::vector<bool>(5,false));
    std::vector<std::vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,1,0,0},{0,0,0,1,1}};
    int result = 0;
    std::vector<int> area_v;
    int area = 0; 

    Solution sol;
    for(int i = 0;i<4;i++){
        for(int j = 0;j<5;j++){
            if(!visited[i][j] && grid[i][j] == 1){
                result++;
                /*---------dfs-----------
                visited[i][j] = true;
                sol.dfs(grid,visited,i,j); 
                */
               /*---------dfs2-----------
                sol.dfs2(grid,visited,i,j);   //代码只负责当前点
               */
                area = 1; //当前点的面积
                visited[i][j] = true; //标记当前节点
                sol.area_dfs(grid,visited,i,j,area);   //代码只负责当前点
                /*---------area_dfs2-----------
                area = 0;  //遇到陆地先记0，到dfs中判断再加（进行了两次判断，是否会冗余？）
                sol.area_dfs2(grid,visited,i,j,area);   //代码只负责当前点
                */
                area_v.push_back(area);
                area = 0;
                    }
        }
        
    }
    int maxArea = *std::max_element(area_v.begin(), area_v.end());
   std::cout << "岛屿数量为："<< result << std::endl;
   std::cout << "岛屿最大面积为："<< maxArea << std::endl;
}
