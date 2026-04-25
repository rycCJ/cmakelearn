#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>

class Solution {
public:
    int dir[4][2] = {1,0,0,1,-1,0,0,-1};  //四行指的是四个方向，两列指的是对x,y加的数据。所以方向是：右，下，左，上
    int bfs(std::vector<std::vector<int>>& grid,std::queue<std::pair<int,int>>& q,int &result,int &freshnum){
        while(!q.empty()){
            int rotnum = q.size();  
            for(int i = 0;i<rotnum;i++){
                std::pair<int,int> cur = q.front();
                q.pop();
                for(int j = 0;j<4;j++){
                    int nextx = cur.first + dir[j][0];
                    int nexty = cur.second + dir[j][1];
                    if(nextx<0 || nexty<0 || nextx>=grid.size() || nexty>=grid[0].size()) continue;
                    if(grid[nextx][nexty] ==1){
                            q.push({nextx,nexty});
                            grid[nextx][nexty] = 2; //-------------->注意！变为2，最后才可以检查是否还有1存在
                            freshnum--;  //新鲜橘子变腐烂了
                    }
                    continue;
                }
            
            }
            if(!q.empty()) result++;              //------------------->没想到！
        }
        return result;    
    }
    // int orangesRotting(std::vector<std::vector<int>>& grid) {
        
    // }
};
int main(){
    std::vector<std::vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    std::queue<std::pair<int,int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int freshnum = 0;
    int result = 0;
    Solution sol;

    for(int i =0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2)
            {
            q.push({i,j});
            }
            if(grid[i][j] == 1) freshnum++;
        }
    }
    if(freshnum == 0) return 0; //---------------------->使用[[0]]，[[2]]这种情况,,[[1]]这种情况进bfs会直接返回0
    result = sol.bfs(grid,q,result,freshnum);

    return freshnum ? -1 : result;  //---------------------->如果还有新鲜橘子，返回-1，否则返回结果;
    std::cout << "Result: " << result << std::endl;
}