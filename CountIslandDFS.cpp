//Given a grid of size n*m (n is the number of rows and m is
//the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land).
//Find the number of islands.

//Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

class Solution {
public:
    // Define the 8 directions (horizontal, vertical, and diagonal)
    const vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    const vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& visited, int n, int m) {
        visited[x][y] = true;
        
        for (int dir = 0; dir < 8; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            // Check bounds and if it's land and not visited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] == 'L' && !visited[nx][ny]) {
                dfs(nx, ny, grid, visited, n, m);
            }
        }
    }
    
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islandCount = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'L' && !visited[i][j]) {
                    // New island found
                    dfs(i, j, grid, visited, n, m);
                    islandCount++;
                }
            }
        }
        
        return islandCount;
    }
};
