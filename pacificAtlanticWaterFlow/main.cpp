#include <iostream>
#include <vector>
using namespace std;
template <typename S>
ostream& operator<<(ostream& os, const vector<S>& vec)
{
    for (auto element: vec)
    {
        os << element << " ";
    }
    return os;
}
void dfs(vector<vector<int>>& heights,vector<vector<int>>& ocean, int row, int col,int pval) {
    int m = heights.size();
    int n = heights[0].size();
    //stop condition
    if ( row > m - 1 || col > n - 1 || row < 0 || col < 0 || ocean[row][col] == 1 || heights[row][col] < pval)
        return;
    //process
    ocean[row][col] = 1;
    //recursive call
    dfs(heights, ocean, row, col + 1, heights[row][col]);
    dfs(heights, ocean, row, col - 1, heights[row][col]);
    dfs(heights, ocean, row + 1, col, heights[row][col]);
    dfs(heights, ocean, row - 1, col, heights[row][col]);

}
//    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
//        int m = heights.size();
//        int n = heights[0].size();
//        vector<vector<int>> res;
//        vector<vector<set<char>>> can();
//        vector<pair<int,int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
//        auto atEdge = [&](int i , int j)
//        {
//            set<int> res;
//            if(i == m || j == n)    res.insert('A');
//            if(i == 0 || j == 0)    res.insert('P');
//            return res;
//        }
//        for(int i = 0; i < m < i++)
//        {
//            for(int j = 0; j < n; j++)
//            {
//
//                stack<pair<int,int>> s;
//                s.push(pair<int,int>{i,j});
//                while(!s.empty())
//                {
//                    pair<int,int> t = s.top();
//                    s.pop();
//                    for(auto dire:directions)
//                    {
//                        int newrow = i + dire.first;
//                        int newcol = j + dire.second;
//                        if(can[newrow][newcol].size()!=0)  continue;
//                        else if(!atEdge(newrow,newcol)) && heights[newrow][newcol] <= heights[i][j])
//                            {
//                                s.push(pair<int,int>{newrow,newcol});
//                            }
//
//
//                        }
//
//
//                    }
//                }
//
//            }
//        }
//    }
//};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pacific(m,vector<int>(n));
        vector<vector<int>> atlantic(m,vector<int>(n));
        for(int j = 0; j < n; j++)
        {
                dfs(heights,pacific,0,j,-100);
                dfs(heights,atlantic,m-1,j,-100);
        }
        for(int i = 0; i < m; i++)
        {
            dfs(heights,pacific,i,0,-100);
            dfs(heights,atlantic,i,n-1,-100);
        }
        vector<vector<int>> res;
        for(int i = 0; i< m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(pacific[i][j] == 1 && atlantic[i][j] == 1)
                {
                    res.push_back({i,j});
                }
            }
        }
        return res;

    }

int main() {
    vector<vector<int>> heights{{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    vector<vector<int>> ress = pacificAtlantic(heights);
    cout << ress << endl;
    return 0;
}
