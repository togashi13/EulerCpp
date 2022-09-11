#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int numIslands(vector<vector<char>>& grid)
{
    if(grid.empty() || grid[0].empty()) return 0;
    int ans = 0;
    int H = grid.size();
    int W = grid[0].size();
    vector<vector<bool>> vis(H, vector<bool>(W));
    vector<pair<int,int>> directions  {{1,0},{0,1},{-1,0},{0,-1}};
    auto inside = [&](int row, int col)
    {
        return row < H && row >= 0 && col < W && col >= 0;
    };
    for(int row = 0; row < H; row++)
    {
        for(int col = 0; col < W; col++)
        {
            if(!vis[row][col] && grid[row][col] == '1')
            {
                vis[row][col] = true;
                ans++;
                queue<pair<int,int>> q;
                q.push(pair<int,int>{row,col});
                while(!q.empty())
                {
                    pair<int,int> p = q.front();
                    q.pop();
                    for(pair<int,int> dir : directions)
                    {
                        int newrow = p.first + dir.first;
                        int newcol = p.second + dir.second;
                        if(inside(newrow,newcol) && !vis[newrow][newcol] && grid[newrow][newcol] == '1')
                        {
                            q.push({newrow,newcol});
                            vis[newrow][newcol] = true;
                        }
                    }
                }
            }
        }
    }
    return ans;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
