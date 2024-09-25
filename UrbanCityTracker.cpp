// Derives inspiration from 200. Number of Islands

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        if (grid.empty()){
            return 0;
        }

        int results = 0;

        for (int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '1'){
                    results++;
                    DFS(grid, i, j);
                }
            }
        }
        return results;
    }

    void DFS(vector<vector<char>>& grid, int i, int j){
        // Check boundary and base conditions
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1'){
            return;
        }

        // Mark the current cell as visited (backtracking)
        grid[i][j] = '0';

        // Recursively visit all adjacent land (up, down, left, right)
        DFS(grid, i + 1, j);
        DFS(grid, i - 1, j);
        DFS(grid, i, j + 1);
        DFS(grid, i, j - 1);
    }
};

int main() {
    // Sample grid representing urban (1) and non-urban (0) areas
    vector<vector<char>> cityGrid = {
        {'1', '1', '0', '0', '0'},
        {'1', '0', '0', '1', '1'},
        {'0', '0', '0', '1', '1'},
        {'0', '1', '1', '0', '0'}
    };

    Solution solution;
    int urbanClusters = solution.numIslands(cityGrid);

    cout << "Number of distinct urban clusters: " << urbanClusters << endl;

    return 0;
}
