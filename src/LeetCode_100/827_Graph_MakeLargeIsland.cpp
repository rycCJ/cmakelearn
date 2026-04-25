#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
/**
 * @brief 827. 最大人工岛
 * @param grid 二维网格，其中1表示陆地，0表示水域
 * @return int 最大人工岛的面积
 */
class Solution {
public:
    int dir[4][2] = {1,0,0,1,-1,0,0,-1}; 
    int area = 1;
    std::unordered_map<int,int> marked_area;
    /**
     * @param grid 二维网格，其中1表示陆地，0表示水域

     * @param x 当前横坐标
     * @param y 当前纵坐标
     * @param marked 键值
     */
    
    void dfs(std::vector<std::vector<int>> &grid,int x,int y,int &marked){
        // if(grid[x][y] != 0&&grid[x][y] != 1) return;
        for(int k = 0;k<4;k++){
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];
            if(nx<0||nx>=grid.size()||ny<0||ny>=grid[0].size()) continue;//越界判定
            if(grid[nx][ny] == 1){
                grid[nx][ny] = marked;
                area++;
                dfs(grid,nx,ny,marked);
            }
            continue;
        }     
        return;
    }
    int largestIsland(std::vector<std::vector<int>>& grid){
            
        int marked = 2;
        int areasum = 0;
        int n = grid.size();  
        int result = 0;
        std::unordered_set<int> isAddArea;  //<----------------*用于存放已经添加进总面积的岛屿，如果已经添加过，就不再重复添加
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j]==1){
                    grid[i][j] = marked;
                    dfs(grid,i,j,marked);
                    marked_area.insert({marked, area});
                    marked++;
                    area = 1;

                }
            }
        }
        std::cout << "result" << std::endl;
        for(auto& pair:marked_area){
                std::cout << "key:" << pair.first << "  value:" << pair.second << std::endl;
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 0){
                    isAddArea.clear();
                    for(int k = 0;k<4;k++){
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if(nx<0||nx>=grid.size()||ny<0||ny>=grid[0].size()) continue;//越界判定
                        if(grid[nx][ny]!=0 && isAddArea.count(grid[nx][ny])==0 ){
                            areasum += marked_area[grid[nx][ny]];
                            isAddArea.insert({grid[nx][ny]});
                                            }
                        continue;
                    }
                    result = std::max(areasum+1,result);
                    areasum = 0;
                }

                continue;
            }
        }
        std::cout << "after add 1, the max island is:"<< result << std::endl;
        return result == 0 ? n*n : result;           //压根没进去，全是marked


    }
};
int main(){
    std::vector<std::vector<int>> grid ={{0}};
    // std::vector<std::vector<int>> grid =  {{0,0,0,0,0,0,0},{0,1,1,1,1,0,0},{0,1,0,0,1,0,0},{1,0,1,0,1,0,0},{0,1,0,0,1,0,0},{0,1,0,0,1,0,0},{0,1,1,1,1,0,0}};
    // std::vector<std::vector<int>> grid = {{1,1,0,0},{1,1,0,0},{0,0,1,0},{0,0,0,1}};
    Solution sol;
    int result = sol.largestIsland(grid);
    return result;

}